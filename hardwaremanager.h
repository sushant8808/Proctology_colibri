#ifndef HARDWAREMANAGER_H
#define HARDWAREMANAGER_H

#include <QObject>
#include <QMap>
#include <QSocketNotifier>

#include <gpiod.h>

class HardwareManager : public QObject
{
    Q_OBJECT
public:
    explicit HardwareManager(QObject *parent = nullptr);
    ~HardwareManager();

    bool initGPIO();
    bool initPWM();

    bool gpioValue(int sodimmPin) const;

    // Buzzer
    enum BuzzerType {
        TouchBeep,
        ErrorBeep,
        WarningBeep,
        SuccessBeep
    };



    void setBrightness(int level);
    void demoAimingBeam(int level, bool timeout);
    void setAimingBeam(bool val);
    void beep(BuzzerType type);

signals:
    void gpioChanged(int sodimmPin, bool value);
    void fpChanged(bool value);
    void interlockChanged(bool status);

private slots:
    void handleGpioEvent(int fd);

private:
    struct GpioInfo {
        int sodimmPin;
        QString chip;
        int line;
        gpiod_line *gpiodLine;
        QSocketNotifier *notifier;
    };

    QMap<int, GpioInfo> m_gpios;

    // PWM
    QString m_pwmPath;

    struct PwmChannel {
            QString chipPath;   // /sys/class/pwm/pwmchipX
            QString pwmPath;    // /sys/class/pwm/pwmchipX/pwm0
        };

    QMap<char, PwmChannel> m_pwms; // A,B,C,D,E

    bool exportPwm(const QString &chipPath);
    void setPwm(const PwmChannel &pwm, int dutyNs, int periodNs);
//    void startPwm(int dutyNs, int periodNs, int durationMs);
    void setPwmSafe(const PwmChannel &pwm,
                    int dutyNs,
                    int periodNs);
};

#endif // HARDWAREMANAGER_H
