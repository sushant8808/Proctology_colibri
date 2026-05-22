#include "setting.h"
#include "ui_setting.h"
#include "global.h"
#include <QMessageBox>
#include "databaseinitializer.h"
#include "userdatabaseinitializer.h"
#include "userdatabasemanager.h"
#include <QDateTime>
#include <QDebug>
#include "pulsemode.h"
#include "service_engineer_area.h"
#include "userlogin.h"
#include "usage_area.h"
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStandardPaths>
#include <QDir>
#include "mainwindow.h"
#include "pageindex.h"


Setting::Setting(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::Setting)
    , home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    popup = new error_popup(this);

    connect(popup, &error_popup::yesClicked,
            this, [this]() {
                clear_data_form_userdb();
                qDebug() << "Yes";
            });

    connect(popup, &error_popup::noClicked,
            this, [this]() {
                clear_data = 0;
                qDebug() << "No";
            });


    connect(popup, &error_popup::acknowledged,
            this,[](){
                qDebug() << "ok";
            });

    refreshPage();
}

Setting::~Setting()
{
    delete ui;
}

void Setting::switchToHome()
{
    MainWindow::instance->switchPage(PAGE_HOME);
}


void Setting::switchTonewprotocol()
{
    MainWindow::instance->switchPage(PAGE_NEWCUSTOMPROTOCOL);
}


void Setting::on_B3_back_to_home_clicked()
{
    switchToHome();
}


void Setting::on_B3_simplified_clicked()
{
    if (home) {
        home->setSimplifiedMode();
    }
    update_simp_adva_mode();

}



void Setting::on_B3_advanced_clicked()
{
    if (home) {
        home->setAdvancedMode();
    }
    update_simp_adva_mode();

}

void Setting::update_simp_adva_mode(void)
{
    DatabaseInitializer dbinit;

    dbinit.updateSingleColumn("device_setting","simpli_advan_mode",simpliAdvanMode,1);

    if(simpliAdvanMode == 0)
    {
        ui->B3_simplified->setStyleSheet(
            "color: rgb(255, 97, 34);"
            "border: 0px solid;"
            "border-top-left-radius: 25px;"
            "border-bottom-left-radius: 25px;"
            "font-size: 14pt;"
            );

        ui->B3_advanced->setStyleSheet(
            "border: 0px solid;"
            "border-top-right-radius: 25px;"
            "border-bottom-right-radius: 25px;"
            "font-size: 14pt;"
            );
    }
    if(simpliAdvanMode == 1)
    {
        ui->B3_advanced->setStyleSheet(
            "color: rgb(255, 97, 34);"
            "border: 0px solid;"
            "border-top-right-radius: 25px;"
            "border-bottom-right-radius: 25px;"
            "font-size: 14pt;"
            );

        ui->B3_simplified->setStyleSheet(
            "border: 0px solid;"
            "border-top-left-radius: 25px;"
            "border-bottom-left-radius: 25px;"
            "font-size: 14pt;"
            );
    }
}


void Setting::on_B3_pulse_mode_clicked()
{
    switchTonewPulseMode();
}

void Setting::switchTonewPulseMode()
{
    MainWindow::instance->switchPage(PAGE_PULSEMODE);
}




void Setting::on_B3_custom_clicked()
{
    new_protocol = true;
    modify_protocol = false;
    switchTonewprotocol();
}

void Setting::on_B3_pass_enable_clicked()
{
    toggle_pass_enable();
}

void Setting::toggle_pass_enable(void)
{
    //qDebug() << Q_FUNC_INFO;

    DatabaseInitializer dbinit;

    password_enable = !password_enable;

    if (password_enable) {
        //qDebug() << "Enable";
        dbinit.updateSingleColumn("device_setting","password_enable",password_enable,1);
        ui->B3_pass_enable->setText("Disable");
    } else {
        //qDebug() << "Disable";
        dbinit.updateSingleColumn("device_setting","password_enable",password_enable,1);
        ui->B3_pass_enable->setText("Enable");
    }

}



void Setting::on_B3_pass_change_clicked()
{
    MainWindow::instance->switchPage(PAGE_CHANGEPASSWORD);
}


void Setting::on_B3_interlockkey_enable_clicked()
{
    toggle_interlockkey_enable();
}

void Setting::toggle_interlockkey_enable(void)
{
    DatabaseInitializer dbinit;

    interlock_key = !interlock_key;

    if (interlock_key) {
        //qDebug() << "Enable";
        dbinit.updateSingleColumn("device_setting","interlock_key",interlock_key,1);
        ui->B3_interlockkey_enable->setText("Disable");
    } else {
        //qDebug() << "Disable";
        dbinit.updateSingleColumn("device_setting","interlock_key",interlock_key,1);
        ui->B3_interlockkey_enable->setText("Enable");
    }

}


void Setting::on_B3_dark_light_clicked()
{
    DatabaseInitializer dbinit;

    if (dark) {
        dbinit.updateSingleColumn("device_setting","theme",dark,1);
        theme.applyDarkTheme();
    } else {
        dbinit.updateSingleColumn("device_setting","theme",dark,1);
        theme.applyLightTheme();
    }
    dark = !dark;
}


void Setting::on_B3_usage_area_clicked()
{

    user_admin_mode = 2;

    MainWindow::instance->switchPage(PAGE_LOGIN);
}


void Setting::on_B3_service_engineer_area_clicked()
{
    user_admin_mode = 1;

    MainWindow::instance->switchPage(PAGE_LOGIN);

}

void Setting::on_B3_clear_data_clicked()
{
    popup->showMessage(
        "CLEAR USER DATA",
        "Are you sure you want to clear all patient data?\n"
        "Data export recommended.",
        error_popup::Validation,
        true
        );

    clear_data = 1;
}

void Setting::clear_data_form_userdb()
{
    if(clear_data == 1)
    {
        UserDatabaseInitializer user_db;
        user_db.deleteAllUserData();
        clear_data = 0;
    }
}

void Setting::on_B3_patientdata_enable_clicked()
{
    toggle_patientdata_enable();
}

void Setting::toggle_patientdata_enable()
{
    DatabaseInitializer dbinit;

    patient_data = !patient_data;

    if (patient_data) {
        //qDebug() << "Enable";
        dbinit.updateSingleColumn("device_setting","patient_data",patient_data,1);
        ui->B3_patientdata_enable->setText("Disable");
    } else {
        //qDebug() << "Disable";
        dbinit.updateSingleColumn("device_setting","patient_data",patient_data,1);
        ui->B3_patientdata_enable->setText("Enable");
    }

}


void Setting::on_B3_patientdata_export_clicked()
{
    bool ok1 = exportPatientDataToCSV();    // master CSV
    bool ok2 = exportPatientWiseCSV();      // patient-wise

    if (ok1 && ok2) {
        QMessageBox::information(this,
                                 "Export Complete",
                                 "All CSV files exported successfully.");
    } else {
        QMessageBox::warning(this,
                             "Export Warning",
                             "Some files could not be exported.");
    }
}

void Setting::export_status(int ex_st)
{
    QMessageBox msgBox;

    if (ex_st) {
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Export complete");
        msgBox.setText("Patient data is exported successfully.");
    } else {
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Export Failed");
        msgBox.setText("Patient data export failed.\nPlease try again.");
    }

    QPushButton *okBtn = msgBox.addButton("OK", QMessageBox::AcceptRole);

    // Make the button smaller
    okBtn->setFixedSize(50, 25);  // width, height
    okBtn->setStyleSheet("font-size: 20px;");


    msgBox.exec();
}

bool Setting::exportPatientDataToCSV()
{
    // 1️⃣ Fixed base path (YOUR PATH)
    QString baseDir =
        "D:/OneDrive - Udyamlabs LLP/Qt projects/laser_ui_2/Patient_Export";

    // 2️⃣ Create directory if it does not exist
    QDir dir(baseDir);
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qDebug() << "❌ Failed to create export directory:" << baseDir;
            return false;
        }
    }

    // 3️⃣ Create CSV file with timestamp
    QString filePath = baseDir + "/Patient_Data_"
                       + QDateTime::currentDateTime()
                             .toString("yyyyMMdd_hhmmss")
                       + ".csv";

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "❌ Failed to create export file:" << filePath;
        return false;
    }

    QTextStream out(&file);

    // 4️⃣ CSV Header
    out << "Surgery ID,Surgeon Name,Patient Name,Patient Age,Gender,"
           "Surgery Name,Protocol Name,"
           "Power 980,Power 1470,Power 650,"
           "Energy Per Pedal,Total Energy,"
           "Stored Energy 1,Stored Energy 2,Stored Energy 3,Stored Energy 4,"
           "Stored Energy 5,Stored Energy 6,Stored Energy 7,Stored Energy 8,"
           "Date\n";

    // 5️⃣ Fetch patient-wise data
    QSqlQuery query(UserDatabaseManager::instance().db());
    query.exec(R"(
        SELECT
            d.surgery_id,
            d.surgeon_name,
            d.patient_name,
            d.patient_age,
            d.gender,
            d.surgery_name,
            l.protocol_name,
            l.power_980,
            l.power_1470,
            l.power_650,
            l.energy_per_pedal,
            l.total_energy,
            l.stored_energy_1,
            l.stored_energy_2,
            l.stored_energy_3,
            l.stored_energy_4,
            l.stored_energy_5,
            l.stored_energy_6,
            l.stored_energy_7,
            l.stored_energy_8,
            l.created_at
        FROM surgery_details d
        JOIN surgery_log_by_id l
        ON d.surgery_id = l.surgery_id
        ORDER BY d.surgery_id, l.created_at
    )");

    // 6️⃣ Write rows
    while (query.next()) {
        for (int i = 0; i < query.record().count(); ++i) {
            out << query.value(i).toString();
            if (i != query.record().count() - 1)
                out << ",";
        }
        out << "\n";
    }

    file.close();

    qDebug() << "✅ Patient data exported successfully to:";
    qDebug() << filePath;

    return true;
}

bool Setting::exportPatientWiseCSV()
{
    QString baseDir =
        "D:/OneDrive - Udyamlabs LLP/Qt projects/laser_ui_2/Patient_Export";

    QDir dir(baseDir);
    if (!dir.exists() && !dir.mkpath(".")) {
        qDebug() << "Failed to create directory";
        return false;
    }

    QSqlQuery query(UserDatabaseManager::instance().db());
    query.exec(R"(
        SELECT
            d.surgery_id,
            d.patient_name,
            d.patient_age,
            d.gender,
            d.surgeon_name,
            d.surgery_name,
            l.protocol_name,
            l.power_980,
            l.power_1470,
            l.power_650,
            l.energy_per_pedal,
            l.total_energy,
            l.stored_energy_1,
            l.stored_energy_2,
            l.stored_energy_3,
            l.stored_energy_4,
            l.stored_energy_5,
            l.stored_energy_6,
            l.stored_energy_7,
            l.stored_energy_8,
            l.created_at
        FROM surgery_details d
        JOIN surgery_log_by_id l
        ON d.surgery_id = l.surgery_id
        ORDER BY d.surgery_id, l.created_at
    )");

    QFile file;
    QTextStream out;
    qint64 lastSurgeryId = -1;

    while (query.next()) {

        qint64 surgeryId = query.value(0).toLongLong();

        if (surgeryId != lastSurgeryId) {

            if (file.isOpen())
                file.close();

            QString patient = query.value(1).toString().simplified().replace(" ", "_");

            QString filePath =
                baseDir + "/" + patient + "_" + QString::number(surgeryId) + ".csv";

            file.setFileName(filePath);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                continue;

            out.setDevice(&file);

            // 🔹 Patient info (ONCE)
            out << "Patient Name," << query.value(1).toString() << "\n";
            out << "Age," << query.value(2).toString() << "\n";
            out << "Gender," << query.value(3).toString() << "\n";
            out << "Surgeon," << query.value(4).toString() << "\n";
            out << "Surgery Name," << query.value(5).toString() << "\n";
            out << "Surgery ID," << surgeryId << "\n\n";

            // 🔹 Log table header
            out << "Protocol,Power980,Power1470,Power650,"
                   "EnergyPerPedal,TotalEnergy,"
                   "Stored1,Stored2,Stored3,Stored4,"
                   "Stored5,Stored6,Stored7,Stored8,Date\n";

            lastSurgeryId = surgeryId;
        }

        // 🔹 Log row only
        for (int i = 6; i < query.record().count(); ++i) {
            out << query.value(i).toString();
            if (i != query.record().count() - 1)
                out << ",";
        }
        out << "\n";
    }

    if (file.isOpen())
        file.close();

    return true;
}

// ================= CPP =================

// Add anywhere in setting.cpp

void Setting::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}

void Setting::refreshPage()
{
    // ===== Refresh simplified / advanced mode =====
    if(simpliAdvanMode == 0)
    {
        ui->B3_simplified->setStyleSheet(
            "color: rgb(255, 97, 34);"
            "border: 0px solid;"
            "border-top-left-radius: 25px;"
            "border-bottom-left-radius: 25px;"
            "font-size: 14pt;"
            );

        ui->B3_advanced->setStyleSheet(
            "border: 0px solid;"
            "border-top-right-radius: 25px;"
            "border-bottom-right-radius: 25px;"
            "font-size: 14pt;"
            );
    }
    else
    {
        ui->B3_advanced->setStyleSheet(
            "color: rgb(255, 97, 34);"
            "border: 0px solid;"
            "border-top-right-radius: 25px;"
            "border-bottom-right-radius: 25px;"
            "font-size: 14pt;"
            );

        ui->B3_simplified->setStyleSheet(
            "border: 0px solid;"
            "border-top-left-radius: 25px;"
            "border-bottom-left-radius: 25px;"
            "font-size: 14pt;"
            );
    }

    // ===== Refresh password enable button =====
    if(password_enable)
    {
        ui->B3_pass_enable->setText("Disable");
    }
    else
    {
        ui->B3_pass_enable->setText("Enable");
    }

    // ===== Refresh interlock key button =====
    if(interlock_key)
    {
        ui->B3_interlockkey_enable->setText("Disable");
    }
    else
    {
        ui->B3_interlockkey_enable->setText("Enable");
    }

    // ===== Refresh patient data button =====
    if(patient_data)
    {
        ui->B3_patientdata_enable->setText("Disable");
    }
    else
    {
        ui->B3_patientdata_enable->setText("Enable");
    }

    // ===== Reset temporary flags =====
    clear_data = 0;
}

