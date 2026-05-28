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

    popup1 = new error_popup(this);

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

    connect(popup1, &error_popup::acknowledged,
            this,[this](){

        if(override_popup == 1) {
            override_popup = 2;
            popup1->hidePopup();
            qDebug() << "override_popup"<<override_popup;
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
    if (!status) // Interlock Key is DISCONNECTED
    {
        qDebug() << "override_popup"<<override_popup;

        if (override_popup == 2) {
            return;
        }

        int currentIndex = stackedWidget->currentIndex();
        if(currentIndex == PAGE_READYFORSURGERY)
        {
            emit pause_surgery_interlock();
        }

        override_popup = 1; // Mark that the warning is currently active

        popup1->showMessage(
                    "INTERLOCK KEY DISCONNECTED",
                    "Connect the key to proceed.\n"
                    "OR\n"
                    "Press override button.",
                    error_popup::Warning,
                    true
                    );

        popup1->raise();
        popup1->activateWindow();
    }
    else // Interlock Key is SAFELY CONNECTED
    {
        // Only completely reset the state when the physical key returns!
        override_popup = 0;
        popup1->hidePopup();
        qDebug() << "🔒 Interlock loop physically closed. Resetting override status.";
    }

}
