#include "home.h"
#include "ui_home.h"
#include "userlogin.h"
#include "global.h"
#include "soundpopupdialog.h"
#include "brightnesspopupdialog.h"
#include "aimingbeampopupdialog.h"
#include "setting.h"
#include "surgery_data.h"
#include "global.h"
#include "databaseinitializer.h"
#include "datetime_manager.h"
#include <QVector>
#include "mainwindow.h"
#include "pageindex.h"
#include <cmath>

Home::Home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);



    startup_done = true;

    ////qDebug()<<"in home constructor";
    ///
    qDebug()<<startup_done;

    stack = static_cast<QStackedWidget*>(parent);

    QTimer::singleShot(0, this, [this]() {
        originalEnergyShowPos = ui->L2_energy_show->pos();
        originalEnergyPos     = ui->L2_energy->pos();
        originalJoulesPos     = ui->L2_joules->pos();

        ////qDebug() << "Captured Positions (delayed):" << originalEnergyShowPos;
    });

    auto setupOverlay = [](QPushButton* button, CircularOverlay*& overlay) {
        overlay = new CircularOverlay(button->parentWidget());
        overlay->setGeometry(button->geometry());
        overlay->raise();
        overlay->show();
    };


    setupOverlay(ui->B2_sound, soundOverlay);

    setupOverlay(ui->B2_aimingbeam, aimingBeamOverlay);

    setupOverlay(ui->B2_brightness, brightnessOverlay);

    // soundOverlay->setProgress(soundIntensity);
    brightnessOverlay->setProgress(brightnessIntensity);
    aimingBeamOverlay->setProgress(aimingbeamIntensity);

    // 980
    setupHoldButton(ui->B2_980add, timer_980add, [this]() { on_B2_980add_clicked(); });
    setupHoldButton(ui->B2_980sub, timer_980sub, [this]() { on_B2_980sub_clicked(); });

    // 1470
    setupHoldButton(ui->B2_1470add, timer_1470add, [this]() { on_B2_1470add_clicked(); });
    setupHoldButton(ui->B2_1470sub, timer_1470sub, [this]() { on_B2_1470sub_clicked(); });

    // On Time
    setupHoldButton(ui->B2_on_time_add, timer_onTimeAdd, [this]() { on_B2_on_time_add_clicked(); });
    setupHoldButton(ui->B2_on_time_sub, timer_onTimeSub, [this]() { on_B2_on_time_sub_clicked(); });

    // Off Time
    setupHoldButton(ui->B2_off_time_add, timer_offTimeAdd, [this]() { on_B2_off_time_add_clicked(); });
    setupHoldButton(ui->B2_off_time_sub, timer_offTimeSub, [this]() { on_B2_off_time_sub_clicked(); });

    // Alarm Seconds
    setupHoldButton(ui->B2_alarm_sec_add, timer_alarmSecAdd, [this]() { on_B2_alarm_sec_add_clicked(); });
    setupHoldButton(ui->B2_alarm_sec_sub, timer_alarmSecSub, [this]() { on_B2_alarm_sec_sub_clicked(); });

    // Alarm Joules
    setupHoldButton(ui->B2_alarm_joule_add, timer_alarmJouleAdd, [this]() { on_B2_alarm_joule_add_clicked(); });
    setupHoldButton(ui->B2_alarm_joule_sub, timer_alarmJouleSub, [this]() { on_B2_alarm_joule_sub_clicked(); });

    setupHoldButton(ui->B2_timer_add, timer_onTimeAdd, [this]() { on_B2_timer_add_clicked(); });
    setupHoldButton(ui->B2_timer_sub, timer_onTimeSub, [this]() { on_B2_timer_sub_clicked(); });

    connect(ui->B2_SelPro, &QPushButton::clicked, this, &Home::openProtocolSelection);

    startup_done = false;

    protocolModified = false;

    connect(DateTimeManager::instance(),
            &DateTimeManager::dateTimeChanged,
            this,
            [=](const QDateTime &dt){
                ui->labelDateTime->setText(
                    dt.toString("dd-MM-yy HH:mm:ss"));
            });

    protocolselect* selWindow =
        (protocolselect*) stack->widget(PAGE_PROTOCOLSELECT);

    connect(selWindow,
            &protocolselect::protocolSelected,
            this,
            [=](const QString &name)
            {
                protocolName = name;

                updateFromGlobals();

                protocolModified = false;

                updateProtocolLabel();
            });

}

Home::~Home()
{
    delete ui;
}

void Home::switchToLogin()
{
    MainWindow::instance->switchPage(PAGE_LOGIN);
}

void Home::on_B2_980add_clicked()
{
    //qDebug() << Q_FUNC_INFO;
    double step;
    if (power980 < 1.0)
        step = 0.1;
    else if (power980 < 3.0)
        step = 0.2;
    else if (power980 < 15.0)
        step = 0.5;
    else
        step = 0.0;

    power980 += step;

    if (power980 > 15.0)
        power980 = 15.0;

    power980 = std::round(power980 * 10.0) / 10.0;

    updatePower980Label();
    updateJouleLabel();
    updateAvgEnergyLabel();
    markProtocolModified(Q_FUNC_INFO);
}

void Home::on_B2_980sub_clicked()
{
    double step;
    if (power980 <= 1.0)
        step = 0.1;
    else if (power980 <= 3.0)
        step = 0.2;
    else
        step = 0.5;

    power980 -= step;

    if (power980 < 0.0)
        power980 = 0.0;

    power980 = std::round(power980 * 10.0) / 10.0;

    updatePower980Label();
    updateJouleLabel();
    updateAvgEnergyLabel();
    markProtocolModified(Q_FUNC_INFO);
}

void Home::on_B2_1470add_clicked()
{
    double step;
    if (power1470 < 1.0)
        step = 0.1;
    else if (power1470 < 3.0)
        step = 0.2;
    else if (power1470 < 15.0)
        step = 0.5;
    else
        step = 0.0;

    power1470 += step;

    if (power1470 > 15.0)
        power1470 = 15.0;

    power1470 = std::round(power1470 * 10.0) / 10.0;

    updatePower1470Label();
    updateJouleLabel();
    updateAvgEnergyLabel();
    markProtocolModified(Q_FUNC_INFO);
}

void Home::on_B2_1470sub_clicked()
{
    double step;
    if (power1470 <= 1.0)
        step = 0.1;
    else if (power1470 <= 3.0)
        step = 0.2;
    else
        step = 0.5;

    power1470 -= step;

    if (power1470 < 0.0)
        power1470 = 0.0;

    power1470 = std::round(power1470 * 10.0) / 10.0;

    updatePower1470Label();
    updateJouleLabel();
    updateAvgEnergyLabel();
    markProtocolModified(Q_FUNC_INFO);
}

void Home::updatePower980Label()
{
    ui->L2_980_show->setText(QString::number(power980, 'f', 1));
}

void Home::updatePower1470Label()
{
    ui->L2_1470_show->setText(QString::number(power1470, 'f', 1));
}

void Home::on_B2_timer_on_clicked()
{
    update_B2_timer_on();
    markProtocolModified(Q_FUNC_INFO);
}

void Home::update_B2_timer_on(void)
{
    timerFlag = true;
    ui->L2_energy_show->show();
    ui->L2_timer_show->show();
    ui->L2_seconds->show();
    ui->B2_timer_add->setEnabled(true);
    ui->B2_timer_sub->setEnabled(true);
    updateTimerLabel();
}

void Home::on_B2_timer_off_clicked()
{
    update_B2_timer_off();
    markProtocolModified(Q_FUNC_INFO);
}

void Home::update_B2_timer_off(void)
{
    timerFlag = false;
    TimerSec = 0;
    ui->L2_energy_show->hide();
    ui->L2_timer_show->hide();
    ui->L2_seconds->hide();
    ui->B2_timer_add->setEnabled(false);
    ui->B2_timer_sub->setEnabled(false);
}

void Home::on_B2_timer_add_clicked()
{
    if (ui->B2_timer_on->isChecked()) {
        if (TimerSec < 120) TimerSec++;
        updateTimerLabel();
        updateJouleLabel();
        markProtocolModified(Q_FUNC_INFO);
    }

}

void Home::on_B2_timer_sub_clicked()
{
    if (ui->B2_timer_on->isChecked()) {
        if (TimerSec > 1) TimerSec--;
        updateTimerLabel();
        updateJouleLabel();
        markProtocolModified(Q_FUNC_INFO);
    }

}

void Home::updateTimerLabel()
{
    ui->L2_timer_show->setText(QString::number(TimerSec));
}

void Home::updateJouleLabel()
{
    currentJoule= TimerSec * (power980+power1470);
//    ui->L2_energy_show->setText(QString::number(currentJoule,'f', 1));
    QString formattedJoule = QString::number(currentJoule, 'f', 1);

    // 2. Combine it into the HTML string with different sizes
    ui->L2_energy_show->setText(
        QString("<span style='font-size: 42px; color: #00FF00;'>%1</span>"
                "<span style='font-size: 20px; color: #FFFFFF;'> J</span>")
        .arg(formattedJoule)
    );
}

void Home::on_B2_pulsemode_stateChanged(int arg1)
{
    bool enabled = (arg1 == Qt::Checked);

    pulseMode = enabled;

    updateAvgEnergyLabel();

    ui->B2_on_time_add->setEnabled(enabled);
    ui->B2_on_time_sub->setEnabled(enabled);
    ui->B2_off_time_add->setEnabled(enabled);
    ui->B2_off_time_sub->setEnabled(enabled);

    ui->L2_on_pulse_show->setVisible(enabled);
    ui->L2_off_pulse_show->setVisible(enabled);

    ui->L2_on_pulse_unit->setVisible(enabled);
    ui->L2_off_pulse_unit->setVisible(enabled);

    updatePulseLabels();

    markProtocolModified(Q_FUNC_INFO);
}

void Home::on_B2_on_time_add_clicked()
{
    pulseOnTime = incrementPulseValue(pulseOnTime);

    updatePulseLabels();
    updateAvgEnergyLabel();

    markProtocolModified(Q_FUNC_INFO);
}

void Home::on_B2_on_time_sub_clicked()
{
    pulseOnTime = decrementPulseValue(pulseOnTime);

    updatePulseLabels();
    updateAvgEnergyLabel();

    markProtocolModified(Q_FUNC_INFO);
}

void Home::on_B2_off_time_add_clicked()
{
    pulseOffTime = incrementPulseValue(pulseOffTime);

    updatePulseLabels();
    updateAvgEnergyLabel();

    markProtocolModified(Q_FUNC_INFO);
}

void Home::on_B2_off_time_sub_clicked()
{
    pulseOffTime = decrementPulseValue(pulseOffTime);

    updatePulseLabels();
    updateAvgEnergyLabel();

    markProtocolModified(Q_FUNC_INFO);
}


/*
 * Store everything internally in MICROSECONDS
 *
 * 50us   - 1000us    -> 50us step
 * 1ms    - 10ms      -> 1ms step
 * 10ms   - 50ms      -> 10ms step
 * 50ms   - 1000ms    -> 50ms step
 * 1s     - 12s       -> 0.5s step
 */

int Home::getStepForValue(int valueUs)
{
    // 50us -> 950us
    if (valueUs < 1000)
        return 50;

    // 1ms -> 9ms
    if (valueUs < 10000)
        return 1000;

    // 10ms -> 40ms
    if (valueUs < 50000)
        return 10000;

    // 50ms -> 950ms
    if (valueUs < 1000000)
        return 50000;

    // 1s -> 12s
    return 500000;
}


int Home::incrementPulseValue(int valueUs)
{
    // ----- Boundary transitions -----

    // 950us -> 1ms
    if (valueUs == 950)
        return 1000;

    // 9ms -> 10ms
    if (valueUs == 9000)
        return 10000;

    // 40ms -> 50ms
    if (valueUs == 40000)
        return 50000;

    // 950ms -> 1s
    if (valueUs == 950000)
        return 1000000;

    // ----- Normal increment -----

    valueUs += getStepForValue(valueUs);

    if (valueUs > pulseMaxLimit)
        valueUs = pulseMaxLimit;

    return valueUs;
}


int Home::decrementPulseValue(int valueUs)
{
    // ----- Boundary transitions -----

    // 1ms -> 950us
    if (valueUs == 1000)
        return 950;

    // 10ms -> 9ms
    if (valueUs == 10000)
        return 9000;

    // 50ms -> 40ms
    if (valueUs == 50000)
        return 40000;

    // 1s -> 950ms
    if (valueUs == 1000000)
        return 950000;

    // ----- Normal decrement -----

    valueUs -= getStepForValue(valueUs);

    if (valueUs < pulseMinLimit)
        valueUs = pulseMinLimit;

    return valueUs;
}

int Home::getMaxLimit()
{
    return 12000000; // 12 seconds in microseconds
}

int Home::incrementPulseRange(int valueUs)
{
    // Boundary transitions

    if (valueUs == 950)
        return 1000;

    if (valueUs == 9000)
        return 10000;

    if (valueUs == 40000)
        return 50000;

    if (valueUs == 950000)
        return 1000000;

    return valueUs + getStepForValue(valueUs);
}

int Home::decrementPulseRange(int valueUs)
{
    // Boundary transitions

    if (valueUs == 1000)
        return 950;

    if (valueUs == 10000)
        return 9000;

    if (valueUs == 50000)
        return 40000;

    if (valueUs == 1000000)
        return 950000;

    return valueUs - getStepForValue(valueUs);
}

QString Home::formatPulseTime(int valueUs)
{
    if (valueUs < 1000)
    {
        return QString::number(valueUs);
    }

    if (valueUs < 1000000)
    {
        double ms = valueUs / 1000.0;

        if (ms == static_cast<int>(ms))
        {
            return QString::number(static_cast<int>(ms));
        }

        return QString::number(ms, 'f', 1);
    }

    double sec = valueUs / 1000000.0;

    if (sec == static_cast<int>(sec))
    {
        return QString::number(static_cast<int>(sec));
    }

    return QString::number(sec, 'f', 1);
}

QString Home::getPulseUnit(int valueUs)
{
    if (valueUs < 1000)
        return "μs";

    if (valueUs < 1000000)
        return "ms";

    return "s";
}

void Home::updatePulseLabels()
{
    // ON time
    ui->L2_on_pulse_show->setText(
        formatPulseTime(pulseOnTime));

    ui->L2_on_pulse_unit->setText(
        getPulseUnit(pulseOnTime));

    // OFF time
    ui->L2_off_pulse_show->setText(
        formatPulseTime(pulseOffTime));

    ui->L2_off_pulse_unit->setText(
        getPulseUnit(pulseOffTime));
}

void Home::on_B2_audioalarm_stateChanged(int arg1)
{
    bool enabled = (arg1 == Qt::Checked);

    ui->B2_sec_alarm->setEnabled(enabled);
    ui->B2_joule_alarm->setEnabled(enabled);

    if (enabled)
    {
        ui->B2_sec_alarm->setChecked(alarmSeconds > 0);
        ui->B2_joule_alarm->setChecked(alarmJoules > 0);

        updateAlarmSecLabel();
        updateAlarmJouleLabel();
    }
    else
    {
        ui->B2_sec_alarm->setChecked(false);
        ui->B2_joule_alarm->setChecked(false);

        ui->L2_alarm_sec_show->setVisible(false);
        ui->L2_alarm_joule_show->setVisible(false);

        updateAlarmSecLabel();
        updateAlarmJouleLabel();
    }

    if(startup_done)
        markProtocolModified(Q_FUNC_INFO);

    dbinit.updateSingleColumn("device_setting","audio_mode",enabled,1);

    qDebug()<<alarmSeconds<<alarmJoules;
}


void Home::on_B2_sec_alarm_toggled(bool checked)
{
    if (checked)
    {
        // Disable joule alarm
        ui->B2_joule_alarm->setChecked(false);

        // Reset joules
        alarmJoules = 0;

        // Start seconds from minimum limit
        if (alarmSeconds <= 0)
            alarmSeconds = 1;
    }
    // else
    // {
    //     alarmSeconds = 0;
    // }

    ui->L2_alarm_sec_show->setVisible(checked);

    ui->B2_alarm_sec_add->setEnabled(checked);
    ui->B2_alarm_sec_sub->setEnabled(checked);

    ui->L2_alarm_joule_show->setVisible(!checked);

    ui->B2_alarm_joule_add->setEnabled(!checked);
    ui->B2_alarm_joule_sub->setEnabled(!checked);

    updateAlarmSecLabel();
    updateAlarmJouleLabel();
    qDebug()<<alarmSeconds<<alarmJoules;
}

void Home::on_B2_joule_alarm_toggled(bool checked)
{
    if (checked)
    {
        // Disable seconds alarm
        ui->B2_sec_alarm->setChecked(false);

        // Reset seconds
        alarmSeconds = 0;

        // Start joules from minimum limit
        if (alarmJoules <= 0)
            alarmJoules = 10;
    }
    // else
    // {
    //     alarmJoules = 0;
    // }

    ui->L2_alarm_joule_show->setVisible(checked);

    ui->B2_alarm_joule_add->setEnabled(checked);
    ui->B2_alarm_joule_sub->setEnabled(checked);

    ui->L2_alarm_sec_show->setVisible(!checked);

    ui->B2_alarm_sec_add->setEnabled(!checked);
    ui->B2_alarm_sec_sub->setEnabled(!checked);

    updateAlarmSecLabel();
    updateAlarmJouleLabel();
    qDebug()<<alarmSeconds<<alarmJoules;
}

void Home::on_B2_alarm_sec_add_clicked()
{
    const int maxAlarmSeconds = 20;

    if (alarmSeconds < maxAlarmSeconds)
        alarmSeconds += 1;

    updateAlarmSecLabel();
    dbinit.updateSingleColumn("device_setting","alarm_sec",alarmSeconds,1);
    dbinit.updateSingleColumn("device_setting","alarm_joule",0,1);
    markProtocolModified(Q_FUNC_INFO);
    qDebug()<<alarmSeconds<<alarmJoules;
}

void Home::on_B2_alarm_sec_sub_clicked()
{
    const int minAlarmSeconds = 0;

    if (alarmSeconds > minAlarmSeconds)
        alarmSeconds -= 1;

    updateAlarmSecLabel();
    dbinit.updateSingleColumn("device_setting","alarm_sec",alarmSeconds,1);
    dbinit.updateSingleColumn("device_setting","alarm_joule",0,1);
    markProtocolModified(Q_FUNC_INFO);
    qDebug()<<alarmSeconds<<alarmJoules;
}



void Home::updateAlarmSecLabel()
{
    ui->L2_alarm_sec_show->setText(QString::number(alarmSeconds));
}

void Home::on_B2_alarm_joule_add_clicked()
{
    QVector<int> steps = {10, 20, 50, 100};

    for (int i = 0; i < steps.size(); ++i)
    {
        if (alarmJoules < steps[i])
        {
            alarmJoules = steps[i];
            break;
        }
    }

    updateAlarmJouleLabel();
    dbinit.updateSingleColumn("device_setting","alarm_joule",alarmJoules,1);
    dbinit.updateSingleColumn("device_setting","alarm_sec",0,1);
    markProtocolModified(Q_FUNC_INFO);
    qDebug()<<alarmSeconds<<alarmJoules;
}

void Home::on_B2_alarm_joule_sub_clicked()
{
    QVector<int> steps = {10, 20, 50, 100};

    for (int i = steps.size() - 1; i >= 0; --i)
    {
        if (alarmJoules > steps[i])
        {
            alarmJoules = steps[i];
            break;
        }
    }

    updateAlarmJouleLabel();
    dbinit.updateSingleColumn("device_setting","alarm_joule",alarmJoules,1);
    dbinit.updateSingleColumn("device_setting","alarm_sec",0,1);
    markProtocolModified(Q_FUNC_INFO);
    qDebug()<<alarmSeconds<<alarmJoules;
}

void Home::updateAlarmJouleLabel()
{
    ui->L2_alarm_joule_show->setText(QString::number(alarmJoules));
}


void Home::on_B2_sound_clicked()
{
    DatabaseInitializer dbinit;

    QWidget *overlay = new QWidget(this);
    overlay->resize(this->size());
    overlay->setStyleSheet("background-color: rgba(0, 0, 0, 150);");
    overlay->show();

    SoundPopupDialog dialog(this);

    QRect rect = this->geometry();

    int centerX = rect.x() + rect.width() / 2;
    int centerY = rect.y() + rect.height() / 2;

    int popupX = centerX - dialog.width() / 2;
    int popupY = centerY - dialog.height() / 2;

    dialog.move(popupX, popupY);
    dialog.exec();

    overlay->hide();
    overlay->deleteLater();

    // ---- Update UI ----
    soundOverlay->setProgress(soundIntensity);
    // beepOverlay->setProgress(beepIntensity);   // NEW

    // ---- Save to database ----
    dbinit.updateSingleColumn("device_setting", "sound_intensity", soundIntensity, 1);
    dbinit.updateSingleColumn("device_setting", "beep_intensity", beepIntensity, 1);
}


void Home::on_B2_brightness_clicked()
{
    DatabaseInitializer dbinit;

    QWidget *overlay = new QWidget(this);
    overlay->resize(this->size());
    overlay->setStyleSheet("background-color: rgba(0, 0, 0, 150);");
    overlay->show();

    BrightnessPopupDialog dialog(this);

    QRect rect = this->geometry();

    int centerX = rect.x() + rect.width() / 2;
    int centerY = rect.y() + rect.height() / 2;

    int popupX = centerX - dialog.width() / 2;
    int popupY = centerY - dialog.height() / 2;

    dialog.move(popupX, popupY);
    dialog.exec();

    overlay->hide();
    overlay->deleteLater();

    brightnessOverlay->setProgress(brightnessIntensity);

    dbinit.updateSingleColumn("device_setting","screen_brightness",brightnessIntensity,1);
}


void Home::on_B2_aimingbeam_clicked()
{
    DatabaseInitializer dbinit;

    QWidget *overlay = new QWidget(this);
    overlay->resize(this->size());
    overlay->setStyleSheet("background-color: rgba(0, 0, 0, 150);");
    overlay->show();

    AimingBeamPopupDialog dialog(this);

    QRect rect = this->geometry();

    int centerX = rect.x() + rect.width() / 2;
    int centerY = rect.y() + rect.height() / 2;

    int popupX = centerX - dialog.width() / 2;
    int popupY = centerY - dialog.height() / 2;

    dialog.move(popupX, popupY);
    dialog.exec();

    aimingBeamOverlay->setProgress(aimingbeamIntensity);

    overlay->hide();
    overlay->deleteLater();

    dbinit.updateSingleColumn("device_setting","aiming_beam_intensity",aimingbeamIntensity,1);
}


void Home::switchToSetting()
{
    MainWindow::instance->switchPage(PAGE_SETTING);
}


void Home::on_B2_setting_clicked()
{
    switchToSetting();
}


void Home::setSimplifiedMode() {
    ui->T2_home->setCurrentIndex(0);
    ui->T2_home->setStyleSheet("::pane {border-top-left-radius: 30px;}");
    ui->L2_tab_hide->setHidden(false);

    // Reset positions to original
    ui->L2_energy_show->move(originalEnergyShowPos);
    ui->L2_energy->move(originalEnergyPos);
    ui->L2_joules->move(originalJoulesPos);
    ui->L2_avg_power->hide();
    ui->L2_avg_power_show->hide();
    ui->L2_avg_watts->hide();
    simpliAdvanMode = 0;
}

void Home::setAdvancedMode() {
    ui->T2_home->setStyleSheet("::pane {border-top-left-radius: 0px;}");
    ui->L2_tab_hide->setHidden(true);

    // Shift labels 100px to the right
    ui->L2_energy_show->move(originalEnergyShowPos.x() + 230, originalEnergyShowPos.y());
    ui->L2_energy->move(originalEnergyPos.x() + 230, originalEnergyPos.y());
    ui->L2_joules->move(originalJoulesPos.x() + 230, originalJoulesPos.y());
    ui->L2_avg_power->show();
    ui->L2_avg_power_show->show();
    ui->L2_avg_watts->show();
    simpliAdvanMode = 1;
}

void Home::updatedatabase() {
    dbinit.updateHomeData(
        1,  // ID
        std::round(power980 * 10.0) / 10.0,       // power980
        std::round(power1470 * 10.0) / 10.0,      // power1470
        TimerSec,                                  // timerSec
        timer_reset,                               // timer_reset
        timerFlag,                                 // timer_flag
        std::round(pulseOnTime * 10.0) / 10.0,    // pulseOnTimeMs
        std::round(pulseOffTime * 10.0) / 10.0,   // pulseOffTimeMs
        pulseMode,                                 // pulse_mode
        protocolName                               // protocol_name
        );
}


void Home::switchTosurgerydata()
{
    MainWindow::instance->switchPage(PAGE_SURGERYDATA);
}

void Home::on_B2_ready_for_surgery_clicked()
{
    updatedatabase();
    switchTosurgerydata();
}

void Home::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    static bool captured = false;
    if (!captured) {
        // Capture original positions
        originalEnergyShowPos = ui->L2_energy_show->pos();
        originalEnergyPos     = ui->L2_energy->pos();
        originalJoulesPos     = ui->L2_joules->pos();

        // Decide mode based on simpliAdvanMode flag
        if (simpliAdvanMode == 0) {
            setSimplifiedMode();
        } else {
            setAdvancedMode();
        }

        captured = true;
    }

    refreshPage();
}

void Home::updateAvgEnergyLabel()
{
    if(pulseMode)
        currentAvgPower = (static_cast<double>(pulseOnTime) / (pulseOnTime + pulseOffTime)) * (power980 + power1470);
    else
        currentAvgPower = (power980 + power1470);
    //qDebug()<<"*********"<<pulseOnTime<<pulseOffTime<<power980<<power1470<<"**********";
    ui->L2_avg_power_show->setText(QString::number(currentAvgPower, 'f', 1));
    //qDebug()<<currentAvgPower;
}

void Home::updateFromGlobals()
{
    ui->L2_protocol_show->setText(protocolName);

    updatePower980Label();
    updatePower1470Label();
    updateTimerLabel();
    updateJouleLabel();
    updatePulseLabels();
    updateAvgEnergyLabel();
    updateAlarmSecLabel();
    updateAlarmJouleLabel();

    ui->B2_pulsemode->setChecked(pulseMode);
    ui->B2_on_time_add->setEnabled(pulseMode);
    ui->B2_on_time_sub->setEnabled(pulseMode);
    ui->B2_off_time_add->setEnabled(pulseMode);
    ui->B2_off_time_sub->setEnabled(pulseMode);

    ui->B2_timer_on->setChecked(timerFlag);
    ui->B2_timer_off->setChecked(!timerFlag);

    ui->B2_audioalarm->setChecked(audioMode);

    ui->B2_sec_alarm->setChecked((alarmSeconds > 0) & audioMode);
    ui->B2_joule_alarm->setChecked((alarmJoules > 0) & audioMode);

    ui->B2_sec_alarm->setEnabled(audioMode);
    ui->B2_joule_alarm->setEnabled(audioMode);

    ui->L2_alarm_sec_show->setVisible((alarmSeconds > 0) & audioMode);
    ui->B2_alarm_sec_add->setEnabled((alarmSeconds > 0) & audioMode);
    ui->B2_alarm_sec_sub->setEnabled((alarmSeconds > 0) & audioMode);

    ui->L2_alarm_joule_show->setVisible((alarmJoules > 0) & audioMode);
    ui->B2_alarm_joule_add->setEnabled((alarmJoules > 0) & audioMode);
    ui->B2_alarm_joule_sub->setEnabled((alarmJoules > 0) & audioMode);

    setTimerResetState(timer_reset);

    soundOverlay->setProgress(soundIntensity);
    brightnessOverlay->setProgress(brightnessIntensity);
    aimingBeamOverlay->setProgress(aimingbeamIntensity);

    if (simpliAdvanMode == 0) {
        setSimplifiedMode();
    } else {
        setAdvancedMode();
    }
}



void Home::setTimerResetState(bool reset)
{
    ////qDebug() <<"timer_reset" <<static_cast<int>(reset);

    if (reset)
    {
        ui->B2_timer_reset->setStyleSheet(
            "color: rgb(255, 97, 34);"
            "border: 0px solid;"
            "border-top-left-radius: 25px;"
            "border-bottom-left-radius: 25px;"
            "font-size: 14pt;"
            );

        ui->B2_timer_noreset->setStyleSheet(
            "border: 0px solid;"
            "border-top-right-radius: 25px;"
            "border-bottom-right-radius: 25px;"
            "font-size: 14pt;"
            );
    }
    else
    {
        ui->B2_timer_noreset->setStyleSheet(
            "color: rgb(255, 97, 34);"
            "border: 0px solid;"
            "border-top-right-radius: 25px;"
            "border-bottom-right-radius: 25px;"
            "font-size: 14pt;"
            );

        ui->B2_timer_reset->setStyleSheet(
            "border: 0px solid;"
            "border-top-left-radius: 25px;"
            "border-bottom-left-radius: 25px;"
            "font-size: 14pt;"
            );
    }
}

// Update your button click slots to just call this function
void Home::on_B2_timer_reset_clicked()
{
    timer_reset = 1;
    setTimerResetState(timer_reset);
    markProtocolModified(Q_FUNC_INFO);
}

void Home::on_B2_timer_noreset_clicked()
{
    timer_reset = 0;
    setTimerResetState(timer_reset);
    markProtocolModified(Q_FUNC_INFO);
}


void Home::setupHoldButton(QPushButton *button, QTimer *&timer, const std::function<void()> &slotFunc)
{
    timer = new QTimer(this);
    timer->setInterval(500);
    connect(timer, &QTimer::timeout, slotFunc);
    connect(button, &QPushButton::pressed, timer, QOverload<>::of(&QTimer::start));
    connect(button, &QPushButton::released, timer, &QTimer::stop);
}


void Home::openProtocolSelection()
{

    protocolselect* selWindow = (protocolselect*) stack->widget(PAGE_PROTOCOLSELECT);

    stack->setCurrentIndex(PAGE_PROTOCOLSELECT);
}

void Home::markProtocolModified(QString fromFunction)
{
    // qDebug()<<Q_FUNC_INFO<<fromFunction;

    if (!protocolModified) {
        protocolModified = true;
        updateProtocolLabel();
    }
}

void Home::updateProtocolLabel()
{
    // Only append * once, after startup, and only if not already present
    if (protocolModified && !protocolName.endsWith("*") && !startup_done)
    {
        protocolName += "*";  // update global variable
    }

    // Always update label
    ui->L2_protocol_show->setText(protocolName);
}

void Home::refreshPage()
{
    qDebug() << "Refreshing Home Page";

    // ----------------------
    // Protocol
    // ----------------------

    updateProtocolLabel();

    // ----------------------
    // Timer
    // ----------------------

    updateTimerLabel();

    ui->B2_timer_on->setChecked(timerFlag);
    ui->B2_timer_off->setChecked(!timerFlag);

    ui->B2_timer_add->setEnabled(TimerSec > 0);
    ui->B2_timer_sub->setEnabled(TimerSec > 1);

    if(timerFlag)
    {
        update_B2_timer_on();
    }
    else
    {
        update_B2_timer_off();
    }

    // ----------------------
    // Power
    // ----------------------

    updatePower980Label();

    updatePower1470Label();

    // ----------------------
    // Joules
    // ----------------------

    updateJouleLabel();

    updateAvgEnergyLabel();

    // ----------------------
    // Pulse Mode
    // ----------------------

    ui->B2_pulsemode->setChecked(pulseMode);

    ui->B2_on_time_add->setEnabled(pulseMode);
    ui->B2_on_time_sub->setEnabled(pulseMode);

    ui->B2_off_time_add->setEnabled(pulseMode);
    ui->B2_off_time_sub->setEnabled(pulseMode);

    ui->L2_on_pulse_show->setVisible(pulseMode);
    ui->L2_off_pulse_show->setVisible(pulseMode);

    ui->L2_on_pulse_unit->setVisible(pulseMode);
    ui->L2_off_pulse_unit->setVisible(pulseMode);

    updatePulseLabels();

    // ----------------------
    // Alarm
    // ----------------------

    ui->B2_audioalarm->setChecked(audioMode);

    ui->B2_sec_alarm->setChecked((alarmSeconds > 0) && audioMode);

    ui->B2_joule_alarm->setChecked((alarmJoules > 0) && audioMode);

    ui->B2_sec_alarm->setEnabled(audioMode);

    ui->B2_joule_alarm->setEnabled(audioMode);

    ui->L2_alarm_sec_show->setVisible((alarmSeconds > 0) && audioMode);

    ui->L2_alarm_joule_show->setVisible((alarmJoules > 0) && audioMode);

    ui->B2_alarm_sec_add->setEnabled((alarmSeconds > 0) && audioMode);

    ui->B2_alarm_sec_sub->setEnabled((alarmSeconds > 0) && audioMode);

    ui->B2_alarm_joule_add->setEnabled((alarmJoules > 0) && audioMode);

    ui->B2_alarm_joule_sub->setEnabled((alarmJoules > 0) && audioMode);

    updateAlarmSecLabel();

    updateAlarmJouleLabel();

    // ----------------------
    // Timer Reset
    // ----------------------

    setTimerResetState(timer_reset);

    // ----------------------
    // Overlay Progress
    // ----------------------

    soundOverlay->setProgress(soundIntensity);

    brightnessOverlay->setProgress(brightnessIntensity);

    aimingBeamOverlay->setProgress(aimingbeamIntensity);

    // ----------------------
    // Mode
    // ----------------------

    if (simpliAdvanMode == 0)
    {
        setSimplifiedMode();
    }
    else
    {
        setAdvancedMode();
    }

    // ----------------------
    // Date Time
    // ----------------------

    ui->labelDateTime->setText(
        DateTimeManager::instance()
            ->currentDateTime()
            .toString("dd-MM-yy HH:mm:ss"));

    this->update();

    qDebug() << "Home Refresh Complete";
}

void Home::switchTonewprotocol()
{
    MainWindow::instance->switchPage(PAGE_NEWCUSTOMPROTOCOL);
}


void Home::on_B2_modify_protocol_clicked()
{
    new_protocol = false;
    modify_protocol = true;
    switchTonewprotocol();
}


