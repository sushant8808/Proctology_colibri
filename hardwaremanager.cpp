#include "hardwaremanager.h"

#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QDebug>
#include <unistd.h>
#include "global.h"

static bool writeSysfs(const QString &path, const QString &value)
{
    QFile f(path);
    if (!f.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to write" << path;
        return false;
    }
    f.write(value.toUtf8());
    f.close();
    return true;
}

inline int volumeToDutyNs(int periodNs, int volumePercent)
{
    volumePercent = qBound(10, volumePercent, 80); // clamp
    return periodNs * volumePercent / 100;
}

inline int freqToPeriodNs(int freq)
{
    return 1'000'000'000 / freq;  // 1 second = 1e9 ns
}
int volume[]={10, 20, 40, 60, 80 };
int BrightnessLevel[] = {6,5,4,3,1};
int AimingBeamLevel[] = {3700, 3900, 4000, 4100, 4200};
#define AIMING_BEAM_PERIOD  10000

const QString brightnessPath = "/sys/class/backlight/backlight/brightness";
const QString aimingBeamPwmPath = "/sys/class/pwmchip4/pwm0";
const QString fanSpeedPwmPath = "/sys/class/pwmchip2/pwm0";

HardwareManager::HardwareManager(QObject *parent)
    : QObject(parent)
{
}

HardwareManager::~HardwareManager()
{
    for (auto &g : m_gpios) {
        if (g.notifier)
            delete g.notifier;
        if (g.gpiodLine)
            gpiod_line_release(g.gpiodLine);
    }
}

bool HardwareManager::initGPIO()
{
    /*
     * ⚠️ REPLACE THESE MAPPINGS WITH REAL ONES
     * Format:
     * { SODIMM_PIN, "gpiochipX", LINE_NUMBER }
     */
    struct Mapping {
        int sodimm;
        const char *chip;
        int line;
    };

    const Mapping mappings[] = {
        {129, "gpiochip0", 2}, //MS-S - FP_Detect
        {131, "gpiochip4", 5}, //MS-1 - FP_Button
        {133, "gpiochip3", 14},//MS-2 - Interlock Hardware line
        {135, "gpiochip0", 24},//MS-3
        {71,  "gpiochip0", 11},  //SS-S
        {73,  "gpiochip1", 4},   //SS-1
        {75,  "gpiochip3", 17},
        {77,  "gpiochip0", 25},
    };

    for (const auto &m : mappings) {
        gpiod_chip *chip = gpiod_chip_open_by_name(m.chip);
        if (!chip) {
            qCritical() << "Failed to open" << m.chip;
            return false;
        }

        gpiod_line *line = gpiod_chip_get_line(chip, m.line);
        if (!line) {
            qCritical() << "Failed to get line" << m.line;
            return false;
        }

        if (gpiod_line_request_both_edges_events(line, "qt-gpio") < 0) {
            qCritical() << "Failed to request IRQ on" << m.sodimm;
            return false;
        }

        int fd = gpiod_line_event_get_fd(line);
        auto *notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);

        connect(notifier, &QSocketNotifier::activated,
                this, &HardwareManager::handleGpioEvent);

        m_gpios[m.sodimm] = {
            m.sodimm,
            m.chip,
            m.line,
            line,
            notifier
        };
        //        qDebug()<<Q_FUNC_INFO<<m_gpios[m.sodimm].sodimmPin \
        //               <<m_gpios[m.sodimm].chip \
        //              <<m_gpios[m.sodimm].gpiodLine \
        //                  << m_gpios[m.sodimm].line \
        //                << m_gpios[m.sodimm].notifier;
    }

    return true;
}

void HardwareManager::handleGpioEvent(int fd)
{
    for (auto &g : m_gpios) {
        if (g.notifier->socket() == fd) {
            struct gpiod_line_event event;
            gpiod_line_event_read(g.gpiodLine, &event);

            bool value = gpiod_line_get_value(g.gpiodLine);
            emit gpioChanged(g.sodimmPin, value);

            if(g.sodimmPin == 131){
                emit fpChanged(value);
                qDebug()<<Q_FUNC_INFO<<g.sodimmPin<<value<<"FP changed";
            }

            if (g.sodimmPin == 133) {
                emit interlockChanged(value);
                interlock_status = value;
                qDebug() << Q_FUNC_INFO << g.sodimmPin << value << "Interlock status changed";
            }

            //            qDebug()<<Q_FUNC_INFO<<g.sodimmPin<<value;
            break;
        }
    }
}

bool HardwareManager::gpioValue(int sodimmPin) const
{
    if (!m_gpios.contains(sodimmPin))
        return false;

    return gpiod_line_get_value(m_gpios[sodimmPin].gpiodLine);
}

void HardwareManager::setBrightness(int level)
{


    // Clamp level to known range
    level = qBound(1, level, 5);
    int val = static_cast<int>(BrightnessLevel[level-1]);
    //    val = qBound(0, val, 4);

    QFile f(brightnessPath);
    if (!f.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to open backlight brightness file";
        return;
    }

    f.write(QByteArray::number(val));
    f.close();

    qDebug() << "Backlight brightness set to" << val;
}

void HardwareManager::demoAimingBeam(int level, bool timeout)
{
    const auto &pwm = m_pwms['E']; // PWM E for Aiming Beam

    setPwmSafe(pwm, AimingBeamLevel[level-1] , AIMING_BEAM_PERIOD);

    if(timeout){
        QTimer::singleShot(2000, this, [this]() {
            writeSysfs(m_pwms['E'].pwmPath + "/enable", "0");
        });
    }
}

void HardwareManager::setAimingBeam(bool val)
{
    writeSysfs(m_pwms['E'].pwmPath + "/enable", val ? "1" : "0");
}

/* ================= PWM ================= */

bool HardwareManager::initPWM()
{

    /*
         * Mapping:
         * PWM A → pwmchip0/pwm0
         * PWM B → pwmchip1/pwm0
         * PWM C → pwmchip2/pwm0   (buzzer)
         * PWM D → pwmchip3/pwm0
         * PWM E → pwmchip4/pwm0
         *
         * ⚠️ VERIFY on your board
         */
    //        m_pwms['A'] = { "/sys/class/pwm/pwmchip0",
    //                        "/sys/class/pwm/pwmchip0/pwm0" };
    m_pwms['B'] = { "/sys/class/pwm/pwmchip1",
                    "/sys/class/pwm/pwmchip1/pwm0" };
    m_pwms['C'] = { "/sys/class/pwm/pwmchip2",
                    "/sys/class/pwm/pwmchip2/pwm0" };
    m_pwms['D'] = { "/sys/class/pwm/pwmchip3",
                    "/sys/class/pwm/pwmchip3/pwm0" };
    m_pwms['E'] = { "/sys/class/pwm/pwmchip4",
                    "/sys/class/pwm/pwmchip4/pwm0" };

    for (auto it = m_pwms.begin(); it != m_pwms.end(); ++it) {
        const auto &pwm = it.value();

        // Export pwm0 if not already exported
        if (!QFile::exists(pwm.pwmPath)) {
            if (!writeSysfs(pwm.chipPath + "/export", "0"))
                return false;
        }

        // Disable before configuring (required by kernel)
        writeSysfs(pwm.pwmPath + "/enable", "0");
    }

    return true;


}

//void HardwareManager::startPwm(int dutyNs, int periodNs, int durationMs)
//{
//    QFile period(m_pwmPath + "/period");
//    QFile duty(m_pwmPath + "/duty_cycle");

//    if (period.open(QIODevice::WriteOnly)) {
//        period.write(QByteArray::number(periodNs));
//        period.close();
//    }

//    if (duty.open(QIODevice::WriteOnly)) {
//        duty.write(QByteArray::number(dutyNs));
//        duty.close();
//    }

//    QTimer::singleShot(durationMs, this, [this]() {
//        QFile duty(m_pwmPath + "/duty_cycle");
//        if (duty.open(QIODevice::WriteOnly)) {
//            duty.write("0");
//            duty.close();
//        }
//    });
//}

void HardwareManager::setPwmSafe(const PwmChannel &pwm, int dutyNs, int periodNs)
{
    // Clamp duty <= period
    if (dutyNs > periodNs)
        dutyNs = periodNs;

    // 1️⃣ Disable PWM before changing anything
    writeSysfs(pwm.pwmPath + "/enable", "0");

    // 2️⃣ Temporarily increase period if needed
    int currentPeriod = periodNs;
    if (dutyNs > periodNs) {
        // use very large period to safely assign duty
        writeSysfs(pwm.pwmPath + "/period", "1000000000"); // 1 second
    }

    // 3️⃣ Assign duty
    writeSysfs(pwm.pwmPath + "/duty_cycle", QString::number(dutyNs));

    // 4️⃣ Assign final period
    writeSysfs(pwm.pwmPath + "/period", QString::number(periodNs));

    // 5️⃣ Enable PWM
    writeSysfs(pwm.pwmPath + "/enable", "1");
}

void HardwareManager::setPwm(const PwmChannel &pwm,
                             int dutyNs,
                             int periodNs)
{
    writeSysfs(pwm.pwmPath + "/enable", "0");
    writeSysfs(pwm.pwmPath + "/period", QString::number(periodNs));
    writeSysfs(pwm.pwmPath + "/duty_cycle", QString::number(dutyNs));
    writeSysfs(pwm.pwmPath + "/enable", "1");
}
/* ================= BUZZER ================= */

void HardwareManager::beep(BuzzerType type)
{
    const auto &pwm = m_pwms['C']; // PWM C for buzzer

    struct Tone {
        int freqHz;
        int dutyPercent;
        int durationMs;
    };

    QList<Tone> tones;

    int setVolume = volume[beepIntensity-1];
    switch (type) {
    case TouchBeep:
        tones.append({1200, setVolume, 50});  // single short beep
        break;

    case ErrorBeep:
        // dual-tone: 1200Hz 300ms + 2400Hz 300ms
        tones.append({2400, setVolume, 100});
        tones.append({2400, setVolume, 100});
        tones.append({2400, setVolume, 100});
        break;

    case WarningBeep:
        // dual-tone shorter
        tones.append({1200, setVolume, 150});
        tones.append({2400, setVolume, 100});
        break;

    case SuccessBeep:
        // two short pulses
        tones.append({1200, setVolume, 80});
        tones.append({1200, setVolume, 80});
        break;
    }

    // Chain tones sequentially using QTimer
    int delay = 0;
    for (const auto &t : tones) {
        QTimer::singleShot(delay, this, [this, pwm, t]() {
            int periodNs = freqToPeriodNs(t.freqHz);
            int dutyNs = volumeToDutyNs(periodNs, t.dutyPercent);

            // Configure PWM
            writeSysfs(pwm.pwmPath + "/enable", "0");
            //                writeSysfs(pwm.pwmPath + "/period", QString::number(periodNs));
            //                writeSysfs(pwm.pwmPath + "/duty_cycle", QString::number(dutyNs));
            //                writeSysfs(pwm.pwmPath + "/enable", "1");
            setPwmSafe(pwm, dutyNs, periodNs);

            // Stop after duration
            QTimer::singleShot(t.durationMs, this, [pwm]() {
                writeSysfs(pwm.pwmPath + "/enable", "0");
            });
        });
        delay += t.durationMs + 20; // small gap between tones
    }
}
