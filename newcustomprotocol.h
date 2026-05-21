#ifndef NEWCUSTOMPROTOCOL_H
#define NEWCUSTOMPROTOCOL_H

#include <QWidget>
#include "global.h"
#include <QPushButton>
#include <QTimer>
#include <functional>
#include "home.h"
#include "setting.h"


namespace Ui {
class newcustomprotocol;
}

class newcustomprotocol : public QWidget
{
    Q_OBJECT

public:
    explicit newcustomprotocol(QWidget *parent = nullptr, Home *home = nullptr);
    ~newcustomprotocol();

protected:
    void showEvent(QShowEvent *event) override;

private:
    void refreshPage();


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

    void on_B2_cancel_clicked();

    void on_B2_save_clicked();

    void on_B3_back_to_setting_clicked();

    void on_B2_back_to_home_clicked();

    void on_Surgery_name_textChanged(const QString &arg1);

    bool isProtocolNameExists(const QString &name);

    void on_bt_surgery_name_clicked();

private:
    Ui::newcustomprotocol *ui;
    Home *home;

    void updatePower980Label();
    void updatePower1470Label();
    void updateJouleLabel();
    void updateAvgEnergyLabel();
    void updateTimerLabel();
    void updatePulseLabels();
    void setTimerResetState(bool reset);
    void setupHoldButton(QPushButton *button, QTimer *&timer, const std::function<void()> &slotFunc);
    void setSimplifiedMode();
    void setAdvancedMode();
    void update_B2_timer_on(void);
    void update_B2_timer_off(void);
    void switchToHome(void);
    void switchToSetting(void);

    int getStepForValue(int valueUs);
    int incrementPulseValue(int valueUs);
    int decrementPulseValue(int valueUs);
    QString formatPulseTime(int valueUs);
    QString getPulseUnit(int valueUs);

    QTimer *timer_980add;
    QTimer *timer_980sub;
    QTimer *timer_1470add;
    QTimer *timer_1470sub;
    QTimer *timer_onTimeAdd;
    QTimer *timer_onTimeSub;
    QTimer *timer_offTimeAdd;
    QTimer *timer_offTimeSub;

    // ===== LOCAL (TEMPORARY) VARIABLES =====
    QString l_name;
    double l_power980;
    double l_power1470;
    int    l_TimerSec;
    bool   l_timerFlag;
    bool   l_timer_reset;
    bool   l_pulseMode;
    int    l_pulseOnTime;
    int    l_pulseOffTime;


};

#endif // NEWCUSTOMPROTOCOL_H
