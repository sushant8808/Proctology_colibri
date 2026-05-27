#include "userlogin.h"
#include "ui_userlogin.h"
#include "home.h"
#include <QTimer>
#include "global.h"
#include "service_engineer_area.h"
#include "usage_area.h"
#include "mainwindow.h"
#include "pageindex.h"
#include "hardwaremanagerprovider.h"

Userlogin::Userlogin(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::Userlogin)
, home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

}

Userlogin::~Userlogin()
{
    delete ui;
}

void Userlogin::switchToHome()
{
    MainWindow::instance->switchPage(PAGE_HOME);
}

void Userlogin::switchToServiceEngArea()
{
    MainWindow::instance->switchPage(PAGE_SERVICEENGINEER);
}

void Userlogin::switchToUsageArea()
{
    MainWindow::instance->switchPage(PAGE_USAGEAREA);
}



void Userlogin::appendDigit(const QString &digit)
{
    if (enteredPassword.length() >= 4)
        return;

    enteredPassword += digit;
    ui->L1_passprint->setText(QString("•").repeated(enteredPassword.length()));
    ui->L1_passcheck->setText("");
}

void Userlogin::on_B1_pass_0_clicked() { appendDigit("0"); TOUCH_BEEP();}
void Userlogin::on_B1_pass_1_clicked() { appendDigit("1"); TOUCH_BEEP();}
void Userlogin::on_B1_pass_2_clicked() { appendDigit("2"); TOUCH_BEEP();}
void Userlogin::on_B1_pass_3_clicked() { appendDigit("3"); TOUCH_BEEP();}
void Userlogin::on_B1_pass_4_clicked() { appendDigit("4"); TOUCH_BEEP();}
void Userlogin::on_B1_pass_5_clicked() { appendDigit("5"); TOUCH_BEEP();}
void Userlogin::on_B1_pass_6_clicked() { appendDigit("6"); TOUCH_BEEP();}
void Userlogin::on_B1_pass_7_clicked() { appendDigit("7"); TOUCH_BEEP();}
void Userlogin::on_B1_pass_8_clicked() { appendDigit("8"); TOUCH_BEEP();}
void Userlogin::on_B1_pass_9_clicked() { appendDigit("9"); TOUCH_BEEP();}

void Userlogin::on_B1_pass_ok_clicked()
{
    if (enteredPassword.length() != 4) {
        ui->L1_passcheck->setText("Enter 4 digits");
        WARNING_BEEP();
        return;
    }

    if ((enteredPassword == loginpass) && (user_admin_mode == 0)) {
        ui->L1_passcheck->setText("Correct");
        SUCCESS_BEEP()
        QTimer::singleShot(0, this, &Userlogin::switchToHome);
    }else if((enteredPassword == adminpass) && (user_admin_mode == 1))
    {
        ui->L1_passcheck->setText("Correct");
        SUCCESS_BEEP()
        QTimer::singleShot(0, this, &Userlogin::switchToServiceEngArea);
    }else if((enteredPassword == userpass) && (user_admin_mode == 2))
    {
        ui->L1_passcheck->setText("Correct");
        SUCCESS_BEEP()
        QTimer::singleShot(0, this, &Userlogin::switchToUsageArea);
    }else {
        ui->L1_passcheck->setText("Incorrect password");
        WARNING_BEEP();
        enteredPassword.clear();
        ui->L1_passprint->setText("");
    }
}

void Userlogin::on_B1_pass_c_clicked()
{
    TOUCH_BEEP();
    enteredPassword.clear();
    ui->L1_passprint->setText("");
    ui->L1_passcheck->setText("");
}

void Userlogin::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}

void Userlogin::refreshPage()
{
    // ===== Clear password buffer =====

    enteredPassword.clear();

    // ===== Clear UI =====

    ui->L1_passprint->clear();

    ui->L1_passcheck->clear();

    if(user_admin_mode == 0)
    {
        ui->tital_2->setText("Login");
        ui->back_to_setting->setVisible(false);
        ui->back_to_setting->setEnabled(false);
    }else if(user_admin_mode == 2)
    {
        ui->tital_2->setText("Usage Area");
        ui->back_to_setting->setVisible(true);
        ui->back_to_setting->setEnabled(true);
    }else if(user_admin_mode == 1)
    {
        ui->tital_2->setText("Service Eng. Area");
        ui->back_to_setting->setVisible(true);
        ui->back_to_setting->setEnabled(true);
    }

    // ===== Optional focus =====

    this->setFocus();
}


void Userlogin::on_back_to_setting_clicked()
{
    MainWindow::instance->switchPage(PAGE_SETTING);
}

