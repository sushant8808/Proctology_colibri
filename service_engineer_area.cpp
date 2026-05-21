#include "service_engineer_area.h"
#include "ui_service_engineer_area.h"
#include "calibration_screen.h"
#include "system_usages.h"
#include "set_date_time.h"
#include "mainwindow.h"
#include "pageindex.h"

service_engineer_area::service_engineer_area(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::service_engineer_area)
    , home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

}

service_engineer_area::~service_engineer_area()
{
    delete ui;
}

void service_engineer_area::on_calibration_clicked()
{
    MainWindow::instance->switchPage(PAGE_CALIBRATION);
}


void service_engineer_area::switchToSetting()
{
    MainWindow::instance->switchPage(PAGE_SETTING);
}


void service_engineer_area::on_back_to_setting_clicked()
{
    switchToSetting();
}

void service_engineer_area::on_set_date_time_clicked()
{
    MainWindow::instance->switchPage(PAGE_SETDATETIME);
}


void service_engineer_area::on_system_usage_clicked()
{
    MainWindow::instance->switchPage(PAGE_SYSTEMUSAGES);
}

void service_engineer_area::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}

void service_engineer_area::refreshPage()
{
    ui->version_show->setText(version);

    ui->L_model->setText(model);

    ui->L_serial_no->setText(serial_no);
}

