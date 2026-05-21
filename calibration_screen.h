#ifndef CALIBRATION_SCREEN_H
#define CALIBRATION_SCREEN_H

#include <QWidget>
#include "databaseinitializer.h"
#include "setting.h"
#include "home.h"


namespace Ui {
class Calibration_screen;
}

class Calibration_screen : public QWidget
{
    Q_OBJECT

public:
    explicit Calibration_screen(QWidget *parent = nullptr, Home *home = nullptr);
    ~Calibration_screen();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_pre_power_1470_clicked();

    void on_next_power_1470_clicked();

    void on_DAC_sub_1470_clicked();

    void on_DAC_add_1470_clicked();

    void on_pre_power_980_clicked();

    void on_next_power_980_clicked();

    void on_DAC_sub_980_clicked();

    void on_DAC_add_980_clicked();

    void on_save_1470_clicked();

    void on_save_980_clicked();

    void on_back_to_service_engineer_area_clicked();

    void switchToServiceEngArea();

    void on_test_1470_clicked();

    void on_test_980_clicked();

    void on_back_to_home_clicked();

    void switchToHome();

private:
    Ui::Calibration_screen *ui;
    Home *home;

    DatabaseInitializer db;

    double power_1470 = 0.0;
    double power_980 = 0.0;

    QTimer *timer_DAC_add;

    void refreshPage();

    void setupHoldButton(QPushButton *button, QTimer *&timer, const std::function<void()> &slotFunc);

};

#endif // CALIBRATION_SCREEN_H
