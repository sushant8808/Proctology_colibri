#include "calibration_screen.h"
#include "ui_calibration_screen.h"
#include "service_engineer_area.h"
#include "global.h"
#include "mainwindow.h"
#include "pageindex.h"
#include <QShowEvent>
#include <cmath>

Calibration_screen::Calibration_screen(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::Calibration_screen)
    , home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    setupHoldButton(ui->DAC_sub_1470, timer_DAC_add, [this]() { dacAValue -= 10;
    ui->DAC_change_1470->setText(QString::number(dacAValue)); });

    setupHoldButton(ui->DAC_add_1470, timer_DAC_add, [this]() { dacAValue += 10;
    ui->DAC_change_1470->setText(QString::number(dacAValue)); });


    setupHoldButton(ui->DAC_sub_980, timer_DAC_add, [this]() {     dacBValue -= 10;
    ui->DAC_change_980->setText(QString::number(dacBValue)); });

    setupHoldButton(ui->DAC_add_980, timer_DAC_add, [this]() {     dacBValue += 10;
    ui->DAC_change_980->setText(QString::number(dacBValue)); });
}

Calibration_screen::~Calibration_screen()
{
    delete ui;
}

void Calibration_screen::setupHoldButton(QPushButton *button, QTimer *&timer, const std::function<void()> &slotFunc)
{
    timer = new QTimer(this);
    timer->setInterval(200);
    connect(timer, &QTimer::timeout, slotFunc);
    connect(button, &QPushButton::pressed, timer, QOverload<>::of(&QTimer::start));
    connect(button, &QPushButton::released, timer, &QTimer::stop);
}

void Calibration_screen::on_pre_power_1470_clicked()
{

    double step;
    if (power_1470 <= 1.0)
        step = 0.1;
    else if (power_1470 <= 3.0)
        step = 0.2;
    else
        step = 0.5;

    power_1470 -= step;

    if (power_1470 < 0.0)
        power_1470 = 0.0;

    power_1470 = std::round(power_1470 * 10.0) / 10.0;

    ui->power_change_1470->setText(QString::number(power_1470, 'f', 1));

    db.fetchDACByPower(power_1470,1470);

    ui->DAC_change_1470->setText(QString::number(dacAValue));

}


void Calibration_screen::on_next_power_1470_clicked()
{
    double step;
    if (power_1470 < 1.0)
        step = 0.1;
    else if (power_1470 < 3.0)
        step = 0.2;
    else if (power_1470 < 15.0)
        step = 0.5;
    else
        step = 0.0;

    power_1470 += step;

    if (power_1470 > 15.0)
        power_1470 = 15.0;

    power_1470 = std::round(power_1470 * 10.0) / 10.0;

    ui->power_change_1470->setText(QString::number(power_1470, 'f', 1));

    db.fetchDACByPower(power_1470,1470);

    ui->DAC_change_1470->setText(QString::number(dacAValue));
}


void Calibration_screen::on_DAC_sub_1470_clicked()
{
    dacAValue -= 1;
    ui->DAC_change_1470->setText(QString::number(dacAValue));
}


void Calibration_screen::on_DAC_add_1470_clicked()
{
    dacAValue += 1;
    ui->DAC_change_1470->setText(QString::number(dacAValue));
}

void Calibration_screen::on_pre_power_980_clicked()
{
    double step;
    if (power_980 <= 1.0)
        step = 0.1;
    else if (power_980 <= 3.0)
        step = 0.2;
    else
        step = 0.5;

    power_980 -= step;

    qDebug()<<power_980;

    if (power_980 < 0.0)
        power_980 = 0.0;

    power_980 = std::round(power_980 * 10.0) / 10.0;

    ui->power_change_980->setText(QString::number(power_980, 'f', 1));

    db.fetchDACByPower(power_980,980);

    ui->DAC_change_980->setText(QString::number(dacBValue));
}


void Calibration_screen::on_next_power_980_clicked()
{
    double step;
    if (power_980 < 0.9)
        step = 0.1000000;
    else if (power_980 < 2.9)
        step = 0.2000000;
    else if (power_980 < 15.0)
        step = 0.5000000;
    else
        step = 0.0;

    power_980 += step;

    qDebug()<<power_980;

    if (power_980 > 15.0)
        power_980 = 15.0;

    // power_980 = std::round(power_980 * 10.0) / 10.0;

    ui->power_change_980->setText(QString::number(power_980, 'f', 1));

    db.fetchDACByPower(power_980,980);

    ui->DAC_change_980->setText(QString::number(dacBValue));
}


void Calibration_screen::on_DAC_sub_980_clicked()
{
    dacBValue -= 1;
    ui->DAC_change_980->setText(QString::number(dacBValue));
}


void Calibration_screen::on_DAC_add_980_clicked()
{
    dacBValue += 1;
    ui->DAC_change_980->setText(QString::number(dacBValue));
}


void Calibration_screen::on_save_1470_clicked()
{
    db.updateDACByPowerAndDiode(power_1470,1470,dacAValue);
}


void Calibration_screen::on_save_980_clicked()
{
    db.updateDACByPowerAndDiode(power_980,980,dacBValue);
}

void Calibration_screen::switchToServiceEngArea()
{
    MainWindow::instance->switchPage(PAGE_SERVICEENGINEER);
}


void Calibration_screen::on_back_to_service_engineer_area_clicked()
{
    switchToServiceEngArea();
}


void Calibration_screen::on_test_1470_clicked()
{

}


void Calibration_screen::on_test_980_clicked()
{

}

void Calibration_screen::switchToHome()
{
    MainWindow::instance->switchPage(PAGE_HOME);
}


void Calibration_screen::on_back_to_home_clicked()
{
    switchToHome();
}

void Calibration_screen::refreshPage()
{

    power_1470 = 0.0;
    power_980  = 0.0;

    // Refresh 1470 section
    ui->power_change_1470->setText(
        QString::number(power_1470, 'f', 1));

    db.fetchDACByPower(power_1470, 1470);

    ui->DAC_change_1470->setText(
        QString::number(dacAValue));

    // Refresh 980 section
    ui->power_change_980->setText(
        QString::number(power_980, 'f', 1));

    db.fetchDACByPower(power_980, 980);

    ui->DAC_change_980->setText(
        QString::number(dacBValue));
}

void Calibration_screen::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}

