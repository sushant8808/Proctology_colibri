#ifndef SYSTEM_USAGES_H
#define SYSTEM_USAGES_H

#include <QWidget>
#include "home.h"

namespace Ui {
class system_usages;
}

class system_usages : public QWidget
{
    Q_OBJECT

public:
    explicit system_usages(QWidget *parent = nullptr, Home *home = nullptr);
    ~system_usages();

protected:
    void showEvent(QShowEvent *event) override;

private:
    void refreshPage();

private slots:
    void on_back_to_home_clicked();

    void on_back_to_service_engineer_area_clicked();

    void update_UI();

    void switchToServiceEngArea();

    void switchToHome();

private:
    Ui::system_usages *ui;
    Home *home;

};

#endif // SYSTEM_USAGES_H
