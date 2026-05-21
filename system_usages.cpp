#include "system_usages.h"
#include "ui_system_usages.h"
#include "runtime_manager.h"
#include "databaseinitializer.h"
#include "service_engineer_area.h"
#include "mainwindow.h"
#include "pageindex.h"

system_usages::system_usages(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::system_usages)
    , home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    refreshPage();
}

system_usages::~system_usages()
{
    delete ui;
}

void system_usages::on_back_to_home_clicked()
{
    switchToHome();
}


void system_usages::on_back_to_service_engineer_area_clicked()
{
    switchToServiceEngArea();
}

void system_usages::update_UI()
{
    DatabaseInitializer db;

    db.fetchSystemTimer(1);

    ui->system_timer->setText(QString::number(g_totalSystemMinutes)+ " min");

    double minutes1470 = g_diode1470Ms / 60000.0;
    ui->active_timer_1470->setText(QString::number(minutes1470, 'f', 2)+ " min");

    double minutes980 = g_diode980Ms / 60000.0;
    ui->active_timer_980->setText(QString::number(minutes980, 'f', 2)+ " min");

}

void system_usages::switchToHome()
{
    MainWindow::instance->switchPage(PAGE_HOME);
}

void system_usages::switchToServiceEngArea()
{
    MainWindow::instance->switchPage(PAGE_SERVICEENGINEER);
}

void system_usages::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}

void system_usages::refreshPage()
{
    DatabaseInitializer db;

    // ===== Refresh latest runtime values =====
    db.fetchSystemTimer(1);

    // ===== System total runtime =====
    ui->system_timer->setText(
        QString::number(g_totalSystemMinutes) + " min");

    // ===== 1470 diode usage =====
    double minutes1470 = g_diode1470Ms / 60000.0;

    ui->active_timer_1470->setText(
        QString::number(minutes1470, 'f', 2) + " min");

    // ===== 980 diode usage =====
    double minutes980 = g_diode980Ms / 60000.0;

    ui->active_timer_980->setText(
        QString::number(minutes980, 'f', 2) + " min");
}
