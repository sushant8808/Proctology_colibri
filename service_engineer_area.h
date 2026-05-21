#ifndef SERVICE_ENGINEER_AREA_H
#define SERVICE_ENGINEER_AREA_H

#include <QWidget>
#include "setting.h"
#include "home.h"

namespace Ui {
class service_engineer_area;
}

class service_engineer_area : public QWidget
{
    Q_OBJECT

public:
    explicit service_engineer_area(QWidget *parent = nullptr, Home *home = nullptr);
    ~service_engineer_area();

protected:
    void showEvent(QShowEvent *event) override;

private:
    void refreshPage();

private slots:
    void on_calibration_clicked();

    void switchToSetting();

    void on_back_to_setting_clicked();

    void on_set_date_time_clicked();

    void on_system_usage_clicked();

private:
    Ui::service_engineer_area *ui;
    Home *home;
};

#endif // SERVICE_ENGINEER_AREA_H
