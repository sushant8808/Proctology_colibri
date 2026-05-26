#include "set_date_time.h"
#include "ui_set_date_time.h"
#include "datetime_manager.h"
#include "service_engineer_area.h"
#include "mainwindow.h"
#include "pageindex.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDateTime>

Set_date_time::Set_date_time(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::Set_date_time)
    , home(home)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 1. Fetch current time values safely
    QDateTime currentDT = DateTimeManager::instance()->currentDateTime();
    m_year   = currentDT.date().year();
    m_month  = currentDT.date().month();
    m_day    = currentDT.date().day();
    m_hour   = currentDT.time().hour();
    m_minute = currentDT.time().minute();


    if (!ui->layoutContainer) {
        return;
    }

    QVBoxLayout *mainLayout = ui->layoutContainer;
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(20);

    QHBoxLayout *pickersLayout = new QHBoxLayout();
    pickersLayout->setSpacing(12);

    // Lambda helper engine with assigned specific tracking IDs
    auto createPickerColumn = [this, &pickersLayout](QString title, int &val, int min, int max, QTimer* &tAdd, QTimer* &tSub) -> QLabel* {
        QVBoxLayout *col = new QVBoxLayout();
        col->setSpacing(8);

        QLabel *header = new QLabel(title);
        header->setObjectName("lblHeader"); // Matches the scoped CSS header entry
        header->setAlignment(Qt::AlignCenter);

        QPushButton *btnUp = new QPushButton("▲");
        btnUp->setObjectName("btnPickerArrow"); // Matches the scoped CSS button entry

        QLabel *display = new QLabel();
        display->setObjectName("lblPickerDisplay"); // Matches the scoped CSS numeric entry
        display->setAlignment(Qt::AlignCenter);
        display->setText(QString("%1").arg(val, 2, 10, QChar('0')));

        QPushButton *btnDown = new QPushButton("▼");
        btnDown->setObjectName("btnPickerArrow"); // Matches the scoped CSS button entry

        col->addWidget(header);
        col->addWidget(btnUp);
        col->addWidget(display);
        col->addWidget(btnDown);
        pickersLayout->addLayout(col);

        this->setupHoldButton(btnUp, tAdd, [this, &val, min, max, display]() {
            if (++val > max) val = min;
            display->setText(QString("%1").arg(val, 2, 10, QChar('0')));
        });

        this->setupHoldButton(btnDown, tSub, [this, &val, min, max, display]() {
            if (--val < min) val = max;
            display->setText(QString("%1").arg(val, 2, 10, QChar('0')));
        });

        return display;
    };

    m_lblYear  = createPickerColumn("YEAR",  m_year,   2025, 2045, t_yrAdd, t_yrSub);
    m_lblMonth = createPickerColumn("MONTH", m_month,  1,    12,   t_moAdd, t_moSub);
    m_lblDay   = createPickerColumn("DAY",   m_day,    1,    31,   t_daAdd, t_daSub);

    QFrame *divider = new QFrame();
    divider->setFrameShape(QFrame::VLine);
    divider->setStyleSheet("border: 1px solid rgb(40, 40, 40); min-width: 1px; max-width: 1px; background-color: rgb(40, 40, 40);");
    pickersLayout->addWidget(divider);

    m_lblHour  = createPickerColumn("HOUR",  m_hour,   0,    23,   t_hrAdd, t_hrSub);
    m_lblMin   = createPickerColumn("MIN",   m_minute, 0,    59,   t_miAdd, t_miSub);

    mainLayout->addLayout(pickersLayout);

    QPushButton *applyBtn = new QPushButton("Apply System Changes");
    applyBtn->setObjectName("applyButton");
    mainLayout->addWidget(applyBtn);

    connect(applyBtn, &QPushButton::clicked, this, [=]() {
        QDate selectedDate(m_year, m_month, m_day);
        QTime selectedTime(m_hour, m_minute, 0);
        if (selectedDate.isValid()) {
            QDateTime newDateTime(selectedDate, selectedTime);
            DateTimeManager::instance()->setDateTime(newDateTime);
        }
        switchToServiceEngArea();

    });
}

Set_date_time::~Set_date_time()
{
    delete ui;
}

void Set_date_time::setupHoldButton(QPushButton *button, QTimer *&timer, const std::function<void()> &slotFunc)
{
    timer = new QTimer(this);
    timer->setInterval(120);
    connect(timer, &QTimer::timeout, slotFunc);
    connect(button, &QPushButton::pressed, this, [slotFunc, timer]() {
        slotFunc();
        timer->start();
    });
    connect(button, &QPushButton::released, timer, &QTimer::stop);
}

void Set_date_time::refreshPage()
{
    QDateTime currentDT = DateTimeManager::instance()->currentDateTime();
    m_year   = currentDT.date().year();
    m_month  = currentDT.date().month();
    m_day    = currentDT.date().day();
    m_hour   = currentDT.time().hour();
    m_minute = currentDT.time().minute();

    updateUIDisplays();
}

void Set_date_time::updateUIDisplays()
{
    // ✅ CRASH PREVENTION: Only touch text components if pointers exist
    if(m_lblYear)  m_lblYear->setText(QString("%1").arg(m_year));
    if(m_lblMonth) m_lblMonth->setText(QString("%1").arg(m_month, 2, 10, QChar('0')));
    if(m_lblDay)   m_lblDay->setText(QString("%1").arg(m_day, 2, 10, QChar('0')));
    if(m_lblHour)  m_lblHour->setText(QString("%1").arg(m_hour, 2, 10, QChar('0')));
    if(m_lblMin)   m_lblMin->setText(QString("%1").arg(m_minute, 2, 10, QChar('0')));
}

void Set_date_time::on_back_to_home_clicked() { switchToHome(); }
void Set_date_time::on_back_to_service_engineer_area_clicked() { switchToServiceEngArea(); }
void Set_date_time::switchToHome() { MainWindow::instance->switchPage(PAGE_HOME); }
void Set_date_time::switchToServiceEngArea() { MainWindow::instance->switchPage(PAGE_SERVICEENGINEER); }
void Set_date_time::showEvent(QShowEvent *event) { QWidget::showEvent(event); refreshPage(); }
