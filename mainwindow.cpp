#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userlogin.h"
#include "home.h"
#include "global.h"
#include "setting.h"
#include "pageindex.h"
#include <QStackedWidget>
#include <QVBoxLayout>

MainWindow* MainWindow::instance = nullptr;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    instance = this;

    QWidget* central = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(central);
    stackedWidget = new QStackedWidget(central);

    // -----------------------------
    // CREATE PAGES ONLY ONCE
    // -----------------------------

    homePage =
        new Home(stackedWidget);

    userloginPage =
        new Userlogin(stackedWidget, homePage);

    settingPage =
        new Setting(stackedWidget, homePage);

    pulseModePage =
        new PulseMode(stackedWidget, homePage);

    protocolSelectPage =
        new protocolselect(stackedWidget, homePage);

    newProtocolPage =
        new newcustomprotocol(stackedWidget, homePage);

    readyForSurgeryPage =
        new ReadyForSurgery(stackedWidget, homePage);

    surgeryDataPage =
        new Surgery_data(stackedWidget, homePage);

    usageAreaPage =
        new usage_area(stackedWidget, homePage);

    systemUsagesPage =
        new system_usages(stackedWidget, homePage);

    rentalInfoPage =
        new rental_info(stackedWidget, homePage);

    serviceEngineerPage =
        new service_engineer_area(stackedWidget, homePage);

    calibrationPage =
        new Calibration_screen(stackedWidget, homePage);

    setDateTimePage =
        new Set_date_time(stackedWidget, homePage);

    changePasswordPage =
        new changepassword(stackedWidget, homePage);

    // -----------------------------
    // ADD TO STACKED WIDGET
    // -----------------------------

    stackedWidget->addWidget(homePage);

    stackedWidget->addWidget(userloginPage);

    stackedWidget->addWidget(settingPage);

    stackedWidget->addWidget(pulseModePage);

    stackedWidget->addWidget(protocolSelectPage);

    stackedWidget->addWidget(newProtocolPage);

    stackedWidget->addWidget(readyForSurgeryPage);

    stackedWidget->addWidget(surgeryDataPage);

    stackedWidget->addWidget(usageAreaPage);

    stackedWidget->addWidget(systemUsagesPage);

    stackedWidget->addWidget(rentalInfoPage);

    stackedWidget->addWidget(serviceEngineerPage);

    stackedWidget->addWidget(calibrationPage);

    stackedWidget->addWidget(setDateTimePage);

    stackedWidget->addWidget(changePasswordPage);

    // -----------------------------
    // START PAGE
    // -----------------------------

    layout->addWidget(stackedWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setCentralWidget(central);

    if(password_enable == 0)
    {
        switchPage(PAGE_HOME);
    }else
    {
        switchPage(PAGE_LOGIN);

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchPage(int index)
{
    if (!stackedWidget)
        return;

    if (index < 0 || index >= stackedWidget->count())
        return;

    stackedWidget->setCurrentIndex(index);
}
