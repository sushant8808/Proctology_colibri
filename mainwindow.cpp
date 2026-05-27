#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userlogin.h"
#include "home.h"
#include "global.h"
#include "setting.h"
#include "pageindex.h"
#include <QStackedWidget>
#include <QVBoxLayout>
#include "hardwaremanagerprovider.h"
#include "error_popup.h"


MainWindow* MainWindow::instance = nullptr;


MainWindow::MainWindow(QWidget *parent, QLabel *statusLabel, QProgressBar *progressBar)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    instance = this;

    popup = new error_popup(this);
//    popup->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
//    popup->setWindowModality(Qt::ApplicationModal);

    QWidget* central = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(central);
    stackedWidget = new QStackedWidget(central);

    // Helper macro/lambda to update progress smoothly if pointers exist
    auto updateProgress = [&](int value, const QString &text) {
        if (statusLabel) statusLabel->setText(text);
        if (progressBar) progressBar->setValue(value);
        qApp->processEvents(); // Force UI update on Colibri screen
    };

    // -----------------------------
    // CREATE PAGES ONLY ONCE
    // -----------------------------

    //    homePage =
    //        new Home(stackedWidget);

    //    userloginPage =
    //        new Userlogin(stackedWidget, homePage);

    //    settingPage =
    //        new Setting(stackedWidget, homePage);

    //    pulseModePage =
    //        new PulseMode(stackedWidget, homePage);

    //    protocolSelectPage =
    //        new protocolselect(stackedWidget, homePage);

    //    newProtocolPage =
    //        new newcustomprotocol(stackedWidget, homePage);

    //    readyForSurgeryPage =
    //        new ReadyForSurgery(stackedWidget, homePage);

    //    surgeryDataPage =
    //        new Surgery_data(stackedWidget, homePage);

    //    usageAreaPage =
    //        new usage_area(stackedWidget, homePage);

    //    systemUsagesPage =
    //        new system_usages(stackedWidget, homePage);

    //    rentalInfoPage =
    //        new rental_info(stackedWidget, homePage);

    //    serviceEngineerPage =
    //        new service_engineer_area(stackedWidget, homePage);

    //    calibrationPage =
    //        new Calibration_screen(stackedWidget, homePage);

    //    setDateTimePage =
    //        new Set_date_time(stackedWidget, homePage);

    //    changePasswordPage =
    //        new changepassword(stackedWidget, homePage);

    updateProgress(75, "Loading Core Interface...");
    homePage = new Home(stackedWidget);
    userloginPage = new Userlogin(stackedWidget, homePage);
    settingPage = new Setting(stackedWidget, homePage);

    updateProgress(80, "Loading Laser Surgery Modules...");
    pulseModePage = new PulseMode(stackedWidget, homePage);
    protocolSelectPage = new protocolselect(stackedWidget, homePage);
    newProtocolPage = new newcustomprotocol(stackedWidget, homePage);

    updateProgress(85, "Initializing Surgery Data...");
    readyForSurgeryPage = new ReadyForSurgery(stackedWidget, homePage);
    surgeryDataPage = new Surgery_data(stackedWidget, homePage);
    usageAreaPage = new usage_area(stackedWidget, homePage);

    updateProgress(90, "Loading System Management...");
    systemUsagesPage = new system_usages(stackedWidget, homePage);
    rentalInfoPage = new rental_info(stackedWidget, homePage);
    serviceEngineerPage = new service_engineer_area(stackedWidget, homePage);

    updateProgress(95, "Finalizing Device Calibration...");
    calibrationPage = new Calibration_screen(stackedWidget, homePage);
    setDateTimePage = new Set_date_time(stackedWidget, homePage);
    changePasswordPage = new changepassword(stackedWidget, homePage);

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

    updateProgress(100, "System Ready!");

    // Your runtime connection handler
    connect(HardwareManagerProvider::instance(), &HardwareManager::interlockChanged,
            this, [this](bool status) {
        qDebug() << "Interlock loop status safely processed via Signal:" << status;
        interlock_popup(status);
    });

    // Your setup initialization handler
    QTimer::singleShot(100, this, [this]() {
        bool currentStatus = HardwareManagerProvider::instance()->gpioValue(133);
        qDebug() << "Initial Interlock status processed via explicit query:" << currentStatus;
        interlock_popup(currentStatus);
    });

    connect(popup, &error_popup::acknowledged,
            this,[this](){

        if(override_popup) {
            override_popup = 0;
            popup->hidePopup();
        }

        qDebug() << "ok";
    });

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

void MainWindow::interlock_popup(bool status)
{
    if(!status)
    {
        int currentIndex = stackedWidget->currentIndex();

        if(currentIndex == PAGE_READYFORSURGERY)
        {
            emit pause_surgery_interlock();
        }
        override_popup = 1;

        popup->showMessage(
                    "INTERLOCK KEY DISCONNECTED",
                    "Connect the key to proceed.\n"
                    "OR\n"
                    "Press override button.",
                    error_popup::Warning,
                    true
                    );

        popup->raise();
        popup->activateWindow();
    }else
    {
        override_popup = 0;
        popup->hidePopup();
    }

}
