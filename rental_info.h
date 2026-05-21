#ifndef RENTAL_INFO_H
#define RENTAL_INFO_H

#include <QWidget>
#include "home.h"

namespace Ui {
class rental_info;
}

class rental_info : public QWidget
{
    Q_OBJECT

public:
    explicit rental_info(QWidget *parent = nullptr, Home *home = nullptr);
    ~rental_info();

private slots:

    void on_B3_back_to_setting_clicked();

    void on_back_to_home_clicked();

    void switchToServiceEngArea();

    void switchToHome();


private:
    Ui::rental_info *ui;
    Home *home;
};

#endif // RENTAL_INFO_H
