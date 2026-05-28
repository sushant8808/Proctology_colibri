#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QTabBar>
#include <QLayout>
#include <QDialog>
#include "thememanager.h"
#include "circularoverlay.h"
#include "databaseinitializer.h"
#include "protocolselect.h"
#include "newcustomprotocol.h"
#include <QStackedWidget>

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

    void setSimplifiedMode();
    void setAdvancedMode();
    void updatedatabase();

    int getStepForValue(int valueUs);
    int incrementPulseValue(int valueUs);
    int decrementPulseValue(int valueUs);
    int incrementPulseRange(int valueUs);
    int decrementPulseRange(int valueUs);

    QString formatPulseTime(int valueUs);
    QString getPulseUnit(int valueUs);

    void updateInterlockUi(bool status);




private slots:

    void switchToLogin();

    void switchToSetting();

    void switchTosurgerydata();

    void on_B2_980sub_clicked();

    void on_B2_980add_clicked();

    void on_B2_1470sub_clicked();

    void on_B2_1470add_clicked();

    void updatePower1470Label();

    void updatePower980Label();

    void updateTimerLabel();

    void updateJouleLabel();

    void on_B2_timer_on_clicked();

    void on_B2_timer_off_clicked();

    void on_B2_timer_add_clicked();

    void on_B2_timer_sub_clicked();

    void on_B2_pulsemode_stateChanged(int arg1);

    void on_B2_on_time_sub_clicked();

    void on_B2_on_time_add_clicked();

    void on_B2_off_time_sub_clicked();

    void on_B2_off_time_add_clicked();

    void updatePulseLabels(bool enabled);

    void alarm_button_control();

    void on_B2_audioalarm_stateChanged(int arg1);

    void on_B2_alarm_sec_sub_clicked();

    void on_B2_alarm_sec_add_clicked();

    void on_B2_alarm_joule_sub_clicked();

    void on_B2_alarm_joule_add_clicked();

    void updateAlarmSecLabel();

    void updateAlarmJouleLabel();

    void on_B2_sound_clicked();

    void on_B2_brightness_clicked();

    void on_B2_aimingbeam_clicked();

    void on_B2_setting_clicked();

    void on_B2_ready_for_surgery_clicked();

    void updateAvgEnergyLabel();

    void on_B2_timer_reset_clicked();

    void on_B2_timer_noreset_clicked();

    void setTimerResetState(bool reset);

    void updateFromGlobals();

    void openProtocolSelection();

    void update_B2_timer_on(void);

    void update_B2_timer_off(void);

    void on_B2_modify_protocol_clicked();

    void switchTonewprotocol();

    void markProtocolModified(QString fromFunction);

    void updateProtocolLabel();

    int getMaxLimit();

    void on_B2_sec_alarm_clicked();

    void on_B2_joule_alarm_clicked();




protected:
    void showEvent(QShowEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::Home *ui;
    DatabaseInitializer dbinit;
    QPoint originalEnergyShowPos;
    QPoint originalEnergyPos;
    QPoint originalJoulesPos;

    CircularOverlay *aimingBeamOverlay = nullptr;
    CircularOverlay *soundOverlay = nullptr;
    CircularOverlay *brightnessOverlay = nullptr;

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

    void setupHoldButton(QPushButton *button, QTimer *&timer, const std::function<void()> &slotFunc);

    QStackedWidget* stack;

    void refreshPage();

};

#endif // HOME_H
