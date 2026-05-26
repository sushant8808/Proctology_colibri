#ifndef CHANGEVALUE_H
#define CHANGEVALUE_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <functional>


namespace Ui {
class changevalue;
}

class changevalue : public QWidget
{
    Q_OBJECT

public:
    explicit changevalue(QWidget *parent = nullptr);
    ~changevalue();

private slots:

    void on_B2_980sub_clicked();

    void on_B2_980add_clicked();

    void on_B2_1470sub_clicked();

    void on_B2_1470add_clicked();

    void on_B2_timer_off_clicked();

    void on_B2_timer_on_clicked();

    void on_B2_timer_sub_clicked();

    void on_B2_timer_add_clicked();

    void on_B2_timer_reset_clicked();

    void on_B2_timer_noreset_clicked();

    void on_B2_pulsemode_stateChanged(int arg1);

    void on_B2_on_time_sub_clicked();

    void on_B2_on_time_add_clicked();

    void on_B2_off_time_sub_clicked();

    void on_B2_off_time_add_clicked();

    void alarm_button_control();

    void on_B2_audioalarm_stateChanged(int arg1);

    void on_B2_alarm_sec_sub_clicked();

    void on_B2_alarm_sec_add_clicked();

    void on_B2_alarm_joule_sub_clicked();

    void on_B2_alarm_joule_add_clicked();

    void update_B2_timer_on(void);

    void update_B2_timer_off(void);

    int getStepForValue(int valueUs);
    int getMaxLimit();

    int incrementPulseValue(int valueUs);
    int decrementPulseValue(int valueUs);

    QString formatPulseTime(int valueUs);
    QString getPulseUnit(int valueUs);

    void on_B2_sec_alarm_clicked();

    void on_B2_joule_alarm_clicked();

private:
    Ui::changevalue *ui;

    void updatePower980Label();
    void updatePower1470Label();
    void updateJouleLabel();
    void updateAvgEnergyLabel();
    void updateTimerLabel();
    void updatePulseLabels(bool enabled);
    void updateAlarmSecLabel();
    void updateAlarmJouleLabel();
    void setTimerResetState(bool reset);
    void setupHoldButton(QPushButton *button, QTimer *&timer, const std::function<void()> &slotFunc);
    void setSimplifiedMode();
    void setAdvancedMode();

    QTimer *timer_980add;
    QTimer *timer_980sub;
    QTimer *timer_1470add;
    QTimer *timer_1470sub;
    QTimer *timer_onTimeAdd;
    QTimer *timer_onTimeSub;
    QTimer *timer_offTimeAdd;
    QTimer *timer_offTimeSub;
    QTimer *timer_alarmSecAdd;
    QTimer *timer_alarmSecSub;
    QTimer *timer_alarmJouleAdd;
    QTimer *timer_alarmJouleSub;
};

#endif // CHANGEVALUE_H
