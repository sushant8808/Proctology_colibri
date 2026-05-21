#include "pulsemode.h"
#include "ui_pulsemode.h"
#include "setting.h"
#include "global.h"
#include "databaseinitializer.h"
#include "mainwindow.h"
#include "pageindex.h"

PulseMode::PulseMode(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::PulseMode)
    , home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
}

PulseMode::~PulseMode()
{
    delete ui;
}

void PulseMode::on_B3_back_to_setting_clicked()
{
    DatabaseInitializer dbinit;

    dbinit.savePulseRanges();

    MainWindow::instance->switchPage(PAGE_SETTING);
}

void PulseMode::on_dec_low_value_clicked()
{
    int newValue =
        home->decrementPulseRange(pulseMinLimit);

    // Absolute minimum
    if (newValue < 50)
        newValue = 50;

    // Must stay below max
    if (newValue >= pulseMaxLimit)
        return;

    pulseMinLimit = newValue;

    // Clamp active pulse values
    if (pulseOnTime < pulseMinLimit)
        pulseOnTime = pulseMinLimit;

    if (pulseOffTime < pulseMinLimit)
        pulseOffTime = pulseMinLimit;

    updateRangeLabels();
}

void PulseMode::on_inc_low_value_clicked()
{
    int newValue =
        home->incrementPulseRange(pulseMinLimit);

    // Min must always stay below max
    if (newValue >= pulseMaxLimit)
        return;

    pulseMinLimit = newValue;

    // Clamp active pulse values
    if (pulseOnTime < pulseMinLimit)
        pulseOnTime = pulseMinLimit;

    if (pulseOffTime < pulseMinLimit)
        pulseOffTime = pulseMinLimit;

    updateRangeLabels();
}

void PulseMode::on_dec_high_value_clicked()
{
    int newValue =
        home->decrementPulseRange(pulseMaxLimit);

    // Max must always stay above min
    if (newValue <= pulseMinLimit)
        return;

    pulseMaxLimit = newValue;

    // Clamp active pulse values
    if (pulseOnTime > pulseMaxLimit)
        pulseOnTime = pulseMaxLimit;

    if (pulseOffTime > pulseMaxLimit)
        pulseOffTime = pulseMaxLimit;

    updateRangeLabels();
}

void PulseMode::on_inc_high_value_clicked()
{
    int newValue =
        home->incrementPulseRange(pulseMaxLimit);

    // Absolute maximum
    if (newValue > 12000000)
        newValue = 12000000;

    // Must stay above min
    if (newValue <= pulseMinLimit)
        return;

    pulseMaxLimit = newValue;

    updateRangeLabels();
}

QString PulseMode::formatPulseTime(int valueUs)
{
    if (valueUs < 1000)
    {
        return QString::number(valueUs);
    }

    if (valueUs < 1000000)
    {
        double ms = valueUs / 1000.0;

        if (ms == static_cast<int>(ms))
        {
            return QString::number(static_cast<int>(ms));
        }

        return QString::number(ms, 'f', 1);
    }

    double sec = valueUs / 1000000.0;

    if (sec == static_cast<int>(sec))
    {
        return QString::number(static_cast<int>(sec));
    }

    return QString::number(sec, 'f', 1);
}

QString PulseMode::getPulseUnit(int valueUs)
{
    if (valueUs < 1000)
        return "μs";

    if (valueUs < 1000000)
        return "ms";

    return "s";
}

void PulseMode::updateRangeLabels()
{
    // MIN value
    ui->change_low_value->setText(
        formatPulseTime(pulseMinLimit));

    ui->L2_min_pulse_unit->setText(
        getPulseUnit(pulseMinLimit));

    // MAX value
    ui->change_high_value->setText(
        formatPulseTime(pulseMaxLimit));

    ui->L2_max_pulse_unit->setText(
        getPulseUnit(pulseMaxLimit));
}

void PulseMode::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}

void PulseMode::refreshPage()
{
    qDebug() << "Refreshing Pulse Mode Page";

    updateRangeLabels();

    qDebug() << "Pulse Mode Refresh Complete";
}

