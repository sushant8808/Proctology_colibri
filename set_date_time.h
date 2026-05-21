#ifndef SET_DATE_TIME_H
#define SET_DATE_TIME_H

#include <QWidget>
#include "home.h"

namespace Ui {
class Set_date_time;
}

class Set_date_time : public QWidget
{
    Q_OBJECT

public:
    explicit Set_date_time(QWidget *parent = nullptr, Home *home = nullptr);
    ~Set_date_time();

protected:
    void showEvent(QShowEvent *event) override;

private:
    void refreshPage();

private slots:

    void on_back_to_home_clicked();

    void on_back_to_service_engineer_area_clicked();

    void switchToServiceEngArea();

    void switchToHome();

private:
    Ui::Set_date_time *ui;
    Home *home;

};

#endif // SET_DATE_TIME_H
