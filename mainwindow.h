#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QStackedWidget>
#include <QLabel>
#include <QProgressBar>

#include "userlogin.h"
#include "home.h"
#include "setting.h"
#include "pulsemode.h"
#include "protocolselect.h"
#include "newcustomprotocol.h"
#include "readyforsurgery.h"
#include "surgery_data.h"
#include "usage_area.h"
#include "system_usages.h"
#include "rental_info.h"
#include "service_engineer_area.h"
#include "calibration_screen.h"
#include "set_date_time.h"
#include "changepassword.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr,
                        QLabel *statusLabel = nullptr,
                        QProgressBar *progressBar = nullptr);
    ~MainWindow();

    static MainWindow* instance;

    void switchPage(int index);

private:
    Ui::MainWindow *ui;

    QStackedWidget* stackedWidget;

public:

    Home* homePage;

    Userlogin* userloginPage;

    Setting* settingPage;

    PulseMode* pulseModePage;

    protocolselect* protocolSelectPage;

    newcustomprotocol* newProtocolPage;

    ReadyForSurgery* readyForSurgeryPage;

    Surgery_data* surgeryDataPage;

    usage_area* usageAreaPage;

    system_usages* systemUsagesPage;

    rental_info* rentalInfoPage;

    service_engineer_area* serviceEngineerPage;

    Calibration_screen* calibrationPage;

    Set_date_time* setDateTimePage;

    changepassword* changePasswordPage;

};
#endif // MAINWINDOW_H
