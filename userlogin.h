#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>
#include "thememanager.h"
#include "home.h"

namespace Ui {
class Userlogin;
}

class Userlogin : public QWidget
{
    Q_OBJECT

public:
    explicit Userlogin(QWidget *parent = nullptr, Home *home = nullptr);
    ~Userlogin();

protected:
    void showEvent(QShowEvent *event) override;

private:
    void refreshPage();

private slots:
    void on_B1_pass_0_clicked();
    void on_B1_pass_1_clicked();
    void on_B1_pass_2_clicked();
    void on_B1_pass_3_clicked();
    void on_B1_pass_4_clicked();
    void on_B1_pass_5_clicked();
    void on_B1_pass_6_clicked();
    void on_B1_pass_7_clicked();
    void on_B1_pass_8_clicked();
    void on_B1_pass_9_clicked();
    void on_B1_pass_ok_clicked();
    void on_B1_pass_c_clicked();
    // void on_L1_passcheck_linkActivated(const QString &link);
    void on_back_to_setting_clicked();

private:
    Ui::Userlogin *ui;
    Home *home;
    QString enteredPassword;

    void switchToHome();
    void switchToServiceEngArea();
    void switchToUsageArea();
    void appendDigit(const QString &digit);

    ThemeManager theme;
};

#endif // USERLOGIN_H
