#include "set_date_time.h"
#include "ui_set_date_time.h"
#include "datetime_manager.h"
#include "service_engineer_area.h"
#include "mainwindow.h"
#include "pageindex.h"

Set_date_time::Set_date_time(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::Set_date_time)
    , home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);


    connect(ui->applyButton, &QPushButton::clicked, this, [=]() {

        QDate selectedDate = ui->dateEdit->date();
        QTime selectedTime = ui->timeEdit->time();

        QDateTime newDateTime(selectedDate, selectedTime);

        DateTimeManager::instance()->setDateTime(newDateTime);
    });
}

Set_date_time::~Set_date_time()
{
    delete ui;
}

void Set_date_time::on_back_to_home_clicked()
{
    switchToHome();
}


void Set_date_time::on_back_to_service_engineer_area_clicked()
{
    switchToServiceEngArea();
}

void Set_date_time::switchToHome()
{
    MainWindow::instance->switchPage(PAGE_HOME);
}

void Set_date_time::switchToServiceEngArea()
{
    MainWindow::instance->switchPage(PAGE_SERVICEENGINEER);
}

void Set_date_time::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}

void Set_date_time::refreshPage()
{
    QDateTime currentDT =
        DateTimeManager::instance()->currentDateTime();

    ui->dateEdit->setDate(currentDT.date());

    ui->timeEdit->setTime(currentDT.time());
}

