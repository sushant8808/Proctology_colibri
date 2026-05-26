#include "changevalue.h"
#include "ui_changevalue.h"
#include "global.h"
#include <cmath>


changevalue::changevalue(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::changevalue)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    if(timerFlag)
    {
        ui->B2_timer_on->setChecked(timerFlag);
        ui->B2_timer_off->setChecked(!timerFlag);
        update_B2_timer_on();
    }else
    {
        update_B2_timer_off();
        ui->B2_timer_on->setChecked(timerFlag);
        ui->B2_timer_off->setChecked(!timerFlag);
    }
    ui->B2_timer_add->setEnabled(true);
    ui->B2_timer_sub->setEnabled(true);
    ui->B2_on_time_add->setEnabled(false);
    ui->B2_on_time_sub->setEnabled(false);
    ui->B2_off_time_add->setEnabled(false);
    ui->B2_off_time_sub->setEnabled(false);
    ui->L2_on_pulse_show->hide();
    ui->L2_off_pulse_show->hide();
    ui->B2_pulsemode->setChecked(pulseMode);

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



    updatePower980Label();
    updatePower1470Label();
    updateTimerLabel();
    updateJouleLabel();
    updatePulseLabels(pulseMode);
    updateAlarmSecLabel();
    updateAlarmJouleLabel();

    QTimer::singleShot(0, this, [this]() {

    });

    if (simpliAdvanMode == 0)
        setSimplifiedMode();
    else
        setAdvancedMode();



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


    // qDebug() << "Timer reset value:" << timer_reset;

    setTimerResetState(timer_reset);
}

changevalue::~changevalue()
{
    delete ui;
}


void changevalue::on_B2_980sub_clicked()
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
}

void changevalue::on_B2_980add_clicked()
{
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
}


void changevalue::on_B2_1470sub_clicked()
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
}

void changevalue::on_B2_1470add_clicked()
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
}

void changevalue::on_B2_timer_off_clicked()
{
    new2_totalEnergyDelivered += new_totalEnergyDelivered;
    new_totalEnergyDelivered = 0.0f;
    last_energyPerPedal = energyAtRelease;
    update_B2_timer_off();
}

void changevalue::update_B2_timer_off()
{
    timerFlag = false;
    TimerSec = 0;
    ui->L2_timer_show->hide();
    ui->B2_timer_add->setEnabled(false);
    ui->B2_timer_sub->setEnabled(false);
    if(dark)
    {
        ui->B2_timer_sub->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/negative_dark_disabled.png);"
                "}");
        ui->B2_timer_add->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/positive_dark_disabled.png);"
                "}");
    }else
    {
        ui->B2_timer_sub->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/negative_light_disabled.png);"
                "}");
        ui->B2_timer_add->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/positive_light_disabled.png);"
                "}");
    }
}

void changevalue::on_B2_timer_on_clicked()
{
    new2_totalEnergyDelivered += new_totalEnergyDelivered;
    last_energyPerPedal = energyAtRelease;
    new_totalEnergyDelivered = 0.0f;
    update_B2_timer_on();
}

void changevalue::update_B2_timer_on()
{
    timerFlag = true;
    ui->L2_timer_show->show();
    ui->B2_timer_add->setEnabled(true);
    ui->B2_timer_sub->setEnabled(true);
    if(dark)
    {
        ui->B2_timer_sub->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/negative_dark_active.png);"
                "}");
        ui->B2_timer_add->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/positive_dark_active.png);"
                "}");
    }else
    {
        ui->B2_timer_sub->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/negative_light_active.png);"
                "}");
        ui->B2_timer_add->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/positive_light_active.png);"
                "}");
    }
    updateTimerLabel();
}

void changevalue::on_B2_timer_sub_clicked()
{
    if (ui->B2_timer_on->isChecked()) {
        if (TimerSec > 1) TimerSec--;
        updateTimerLabel();
        updateJouleLabel();
    }

}

void changevalue::on_B2_timer_add_clicked()
{
    if (ui->B2_timer_on->isChecked()) {
        if (TimerSec < 120) TimerSec++;
        updateTimerLabel();
        updateJouleLabel();
    }

}

void changevalue::on_B2_timer_reset_clicked()
{
    timer_reset = 1;
    new2_totalEnergyDelivered += new_totalEnergyDelivered;
    energyDelivered = new_totalEnergyDelivered + new2_totalEnergyDelivered - totalEnergyDelivered;
    setTimerResetState(timer_reset);
}

void changevalue::on_B2_timer_noreset_clicked()
{
    last_energyPerPedal = energyAtRelease;
    timer_reset = 0;
    setTimerResetState(timer_reset);
}

void changevalue::setTimerResetState(bool reset)
{
    // qDebug() <<"timer_reset" <<static_cast<int>(reset);

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

void changevalue::on_B2_pulsemode_stateChanged(int arg1)
{
    bool enabled = (arg1 == Qt::Checked);

    pulseMode = enabled;

    ui->B2_on_time_add->setEnabled(enabled);
    ui->B2_on_time_sub->setEnabled(enabled);
    ui->B2_off_time_add->setEnabled(enabled);
    ui->B2_off_time_sub->setEnabled(enabled);

    ui->L2_on_pulse_show->setVisible(enabled);
    ui->L2_off_pulse_show->setVisible(enabled);

    updatePulseLabels(pulseMode);
}


void changevalue::on_B2_on_time_sub_clicked()
{
    pulseOnTime = decrementPulseValue(pulseOnTime);

    updatePulseLabels(pulseMode);
}

void changevalue::on_B2_on_time_add_clicked()
{
    pulseOnTime = incrementPulseValue(pulseOnTime);

    updatePulseLabels(pulseMode);
}


void changevalue::on_B2_off_time_sub_clicked()
{
    pulseOffTime = decrementPulseValue(pulseOffTime);

    updatePulseLabels(pulseMode);
}

void changevalue::on_B2_off_time_add_clicked()
{
    pulseOffTime = incrementPulseValue(pulseOffTime);

    updatePulseLabels(pulseMode);
}

void changevalue::alarm_button_control()
{
    if(audioMode && alarmSeconds)
    {
        if(dark)
        {
            ui->B2_alarm_sec_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_active.png);"
                    "}");
            ui->B2_alarm_sec_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_active.png);"
                    "}");
        }else
        {
            ui->B2_alarm_sec_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_active.png);"
                    "}");
            ui->B2_alarm_sec_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_active.png);"
                    "}");
        }

    }else
    {
        if(dark)
        {
            ui->B2_alarm_sec_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_disabled.png);"
                    "}");
            ui->B2_alarm_sec_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_disabled.png);"
                    "}");
        }else
        {
            ui->B2_alarm_sec_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_disabled.png);"
                    "}");
            ui->B2_alarm_sec_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_disabled.png);"
                    "}");
        }
    }

    if(audioMode && alarmJoules)
    {
        if(dark)
        {
            ui->B2_alarm_joule_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_active.png);"
                    "}");
            ui->B2_alarm_joule_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_active.png);"
                    "}");
        }else
        {
            ui->B2_alarm_joule_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_active.png);"
                    "}");
            ui->B2_alarm_joule_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_active.png);"
                    "}");
        }
    }else
    {
        if(dark)
        {
            ui->B2_alarm_joule_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_disabled.png);"
                    "}");
            ui->B2_alarm_joule_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_disabled.png);"
                    "}");
        }else
        {
            ui->B2_alarm_joule_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_disabled.png);"
                    "}");
            ui->B2_alarm_joule_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_disabled.png);"
                    "}");
        }
    }
}

void changevalue::on_B2_audioalarm_stateChanged(int arg1)
{
    bool enabled = (arg1 == Qt::Checked);

    ui->B2_sec_alarm->setEnabled(enabled);
    ui->B2_joule_alarm->setEnabled(enabled);

    if (enabled)
    {
        ui->B2_sec_alarm->setChecked(alarmSeconds > 0);
        ui->B2_joule_alarm->setChecked(alarmJoules > 0);

        ui->L2_alarm_sec_show->setVisible(alarmSeconds > 0);
        ui->B2_alarm_sec_add->setEnabled(alarmSeconds > 0);
        ui->B2_alarm_sec_sub->setEnabled(alarmSeconds > 0);

        ui->L2_alarm_joule_show->setVisible(alarmJoules > 0);
        ui->B2_alarm_joule_add->setEnabled(alarmJoules > 0);
        ui->B2_alarm_joule_sub->setEnabled(alarmJoules > 0);
    }else
    {
        ui->B2_sec_alarm->setChecked(false);
        ui->B2_joule_alarm->setChecked(false);

        ui->L2_alarm_sec_show->setVisible(false);
        ui->B2_alarm_sec_add->setEnabled(false);
        ui->B2_alarm_sec_sub->setEnabled(false);
        ui->L2_alarm_joule_show->setVisible(false);
        ui->B2_alarm_joule_add->setEnabled(false);
        ui->B2_alarm_joule_sub->setEnabled(false);
    }

    audioMode = enabled;

    alarm_button_control();
}

void changevalue::on_B2_sec_alarm_clicked()
{
    ui->B2_sec_alarm->setChecked(true);

    ui->L2_alarm_sec_show->setVisible(true);

    ui->B2_alarm_sec_add->setEnabled(true);
    ui->B2_alarm_sec_sub->setEnabled(true);

    ui->L2_alarm_joule_show->setVisible(false);

    ui->B2_alarm_joule_add->setEnabled(false);
    ui->B2_alarm_joule_sub->setEnabled(false);

    ui->B2_alarm_joule_sub->setStyleSheet(
                "QPushButton {"
            "background-image:url(:/icons/negative_dark_disabled.png);"
            "}"
        );

    // Disable joule alarm
    ui->B2_joule_alarm->setChecked(false);

    // Reset joules
    alarmJoules = 0;

    // Start seconds from minimum limit
    if (alarmSeconds <= 0)
        alarmSeconds = 1;


    updateAlarmSecLabel();
    updateAlarmJouleLabel();
}

void changevalue::on_B2_joule_alarm_clicked()
{
    ui->B2_joule_alarm->setChecked(true);

    ui->L2_alarm_joule_show->setVisible(true);

    ui->B2_alarm_joule_add->setEnabled(true);
    ui->B2_alarm_joule_sub->setEnabled(true);

    ui->L2_alarm_sec_show->setVisible(false);

    ui->B2_alarm_sec_add->setEnabled(false);
    ui->B2_alarm_sec_sub->setEnabled(false);

    // Disable seconds alarm
    ui->B2_sec_alarm->setChecked(false);

    // Reset seconds
    alarmSeconds = 0;

    // Start joules from minimum limit
    if (alarmJoules <= 0)
        alarmJoules = 10;

    updateAlarmSecLabel();
    updateAlarmJouleLabel();
}

void changevalue::on_B2_alarm_sec_sub_clicked()
{
    const int minAlarmSeconds = 0;

    if (alarmSeconds > minAlarmSeconds)
        alarmSeconds -= 1;

    updateAlarmSecLabel();
}

void changevalue::on_B2_alarm_sec_add_clicked()
{
    const int maxAlarmSeconds = 20;

    if (alarmSeconds < maxAlarmSeconds)
        alarmSeconds += 1;

    updateAlarmSecLabel();
}


void changevalue::on_B2_alarm_joule_sub_clicked()
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
}

void changevalue::on_B2_alarm_joule_add_clicked()
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
}

void changevalue::updatePower980Label()
{
    ui->L2_980_show->setText(QString::number(power980, 'f', 1));
}

void changevalue::updatePower1470Label()
{
    ui->L2_1470_show->setText(QString::number(power1470, 'f', 1));
}

void changevalue::updateTimerLabel()
{
    ui->L2_timer_show->setText(QString::number(TimerSec));
}

void changevalue::updateJouleLabel()
{
    currentJoule= TimerSec * (power980+power1470);
}

void changevalue::updatePulseLabels(bool enabled)
{
    if(dark)
    {
        if(enabled)
        {
            ui->B2_on_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_active.png);"
                    "}");
            ui->B2_on_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_active.png);"
                    "}");
            ui->B2_off_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_active.png);"
                    "}");
            ui->B2_off_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_active.png);"
                    "}");
        }else
        {
            ui->B2_on_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_disabled.png);"
                    "}");
            ui->B2_on_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_disabled.png);"
                    "}");
            ui->B2_off_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_disabled.png);"
                    "}");
            ui->B2_off_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_disabled.png);"
                    "}");
        }

    }else
    {
        if(enabled)
        {
            ui->B2_on_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_active.png);"
                    "}");
            ui->B2_on_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_active.png);"
                    "}");
            ui->B2_off_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_active.png);"
                    "}");
            ui->B2_off_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_active.png);"
                    "}");
        }else
        {
            ui->B2_on_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_disabled.png);"
                    "}");
            ui->B2_on_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_disabled.png);"
                    "}");
            ui->B2_off_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_disabled.png);"
                    "}");
            ui->B2_off_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_disabled.png);"
                    "}");
        }
    }

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

void changevalue::updateAlarmSecLabel()
{

    alarm_button_control();
    ui->L2_alarm_sec_show->setText(QString::number(alarmSeconds));
}

void changevalue::updateAlarmJouleLabel()
{
    alarm_button_control();
    ui->L2_alarm_joule_show->setText(QString::number(alarmJoules));
}

void changevalue::setupHoldButton(QPushButton *button, QTimer *&timer, const std::function<void()> &slotFunc)
{
    timer = new QTimer(this);
    timer->setInterval(500);
    connect(timer, &QTimer::timeout, slotFunc);
    connect(button, &QPushButton::pressed, timer, QOverload<>::of(&QTimer::start));
    connect(button, &QPushButton::released, timer, &QTimer::stop);
}

void changevalue::setSimplifiedMode() {
    ui->T2_home->setCurrentIndex(0);
    ui->T2_home->setStyleSheet("::pane {border-top-left-radius: 30px;}");
    ui->L2_tab_hide->setHidden(false);
    simpliAdvanMode = 0;
}

void changevalue::setAdvancedMode() {
    ui->T2_home->setStyleSheet("::pane {border-top-left-radius: 0px;}");
    ui->L2_tab_hide->setHidden(true);

    simpliAdvanMode = 1;
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

int changevalue::getStepForValue(int valueUs)
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

int changevalue::getMaxLimit()
{
    return 12000000;
}

int changevalue::incrementPulseValue(int valueUs)
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


int changevalue::decrementPulseValue(int valueUs)
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

QString changevalue::formatPulseTime(int valueUs)
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

QString changevalue::getPulseUnit(int valueUs)
{
    if (valueUs < 1000)
        return "μs";

    if (valueUs < 1000000)
        return "ms";

    return "s";
}
