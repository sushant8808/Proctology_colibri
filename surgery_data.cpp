#include "surgery_data.h"
#include "ui_surgery_data.h"
#include "readyforsurgery.h"
#include "global.h"
#include <QMessageBox>
#include "surgerycontext.h"
#include <QSqlQuery>
#include "userdatabaseinitializer.h"
#include "userdatabasemanager.h"
#include "mainwindow.h"
#include "pageindex.h"
#include <QIntValidator>

// ✅ Global variables
QString surgeonName;
QString patientName;
QString patientAge;
QString surgeryName;
QString patientID;
bool genderMale = false;
bool genderFemale = false;

Surgery_data::Surgery_data(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::Surgery_data)
    , home(home)
{
    ui->setupUi(this);

    loadSurgeonNames();

    this->setWindowFlags(Qt::FramelessWindowHint);

    // Optional: lock editing
    ui->LD4_surgery_name->setReadOnly(true);

    popup = new error_popup(this);

    // -------------------------------------------------------------
    // 💡 LOCK AGE FIELD TO NUMBERS ONLY
    // -------------------------------------------------------------
    // Configures the field to accept integers between 0 and 120 only
    QIntValidator *ageValidator = new QIntValidator(0, 120, this);
    ui->LD4_patient_age->setValidator(ageValidator);

    // -------------------------------------------------------------
    // EVENT FILTERS ON LINE EDITS
    // -------------------------------------------------------------
    ui->LD4_patient_ID->installEventFilter(this);
    ui->LD4_patient_name->installEventFilter(this);
    ui->LD4_patient_age->installEventFilter(this);

    if (ui->LD4_surgeon_name->lineEdit()) {
        ui->LD4_surgeon_name->lineEdit()->installEventFilter(this);
    }

    refreshPage();
}

Surgery_data::~Surgery_data()
{
    delete ui;
}

void Surgery_data::on_B4_save_clicked()
{
    surgeonName = ui->LD4_surgeon_name->currentText().trimmed();
    patientName = ui->LD4_patient_name->text().trimmed();
    patientAge  = ui->LD4_patient_age->text().trimmed();
    surgeryName = ui->LD4_surgery_name->text().trimmed();
    patientID   = ui->LD4_patient_ID->text().trimmed();

    genderMale   = ui->B4_male->isChecked();
    genderFemale = ui->B4_female->isChecked();

    bool genderSelected = (genderMale || genderFemale);

    if (surgeonName.isEmpty() || patientName.isEmpty() || patientAge.isEmpty() ||
            surgeryName.isEmpty() || patientID.isEmpty() || !genderSelected)
    {

        popup->showMessage(
                    "Missing Information",
                    "Please fill in all the fields.\n"
            "",
                    error_popup::Warning,
                    true
                    );

        return;
    }

    startNewSurgery();

    QString genderStr = genderMale ? "Male" : "Female";

    QSqlQuery query(UserDatabaseManager::instance().db());
    query.prepare(R"(
    INSERT INTO surgery_details
    (surgery_id, surgeon_name, patient_id, patient_name, patient_age, gender, surgery_name)
    VALUES (?, ?, ?, ?, ?, ?, ?)
)");

    query.addBindValue(g_surgeryId);
    query.addBindValue(surgeonName);
    query.addBindValue(patientID);
    query.addBindValue(patientName);
    query.addBindValue(patientAge.toInt());
    query.addBindValue(genderStr);
    query.addBindValue(protocolName);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error",
                              "Failed to save surgery details.");
        return;
    }

    MainWindow::instance->switchPage(PAGE_READYFORSURGERY);
}

void Surgery_data::on_B4_skip_clicked()
{
    startNewSurgery();

    QSqlQuery query(UserDatabaseManager::instance().db());

    query.prepare(R"(
    INSERT INTO surgery_details
    (surgery_id, surgeon_name, patient_id, patient_name, patient_age, gender, surgery_name)
    VALUES (?, ?, ?, ?, ?, ?, ?)
)");

    query.addBindValue(g_surgeryId);
    query.addBindValue("Skip");
    query.addBindValue("Skip");         // patient_id
    query.addBindValue("Skip");         // patient_name
    query.addBindValue(QVariant::fromValue(nullptr));     // age NULL
    query.addBindValue("Skip");         // gender
    query.addBindValue(protocolName);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error",
                              "Failed to save surgery details.");
        return;
    }

    MainWindow::instance->switchPage(PAGE_READYFORSURGERY);
}

void Surgery_data::switchToHome()
{
    MainWindow::instance->switchPage(PAGE_HOME);
}

void Surgery_data::on_B4_back_to_home_clicked()
{
    switchToHome();
}

void Surgery_data::loadSurgeonNames()
{
    QSqlQuery query(UserDatabaseManager::instance().db());

    query.prepare("SELECT DISTINCT surgeon_name FROM surgery_details WHERE surgeon_name != 'Skip'");

    if (!query.exec())
        return;

    ui->LD4_surgeon_name->clear();

    while (query.next())
    {
        QString name = query.value(0).toString();
        ui->LD4_surgeon_name->addItem(name);
    }

    // ✅ IMPORTANT: make it empty at start
    ui->LD4_surgeon_name->setCurrentIndex(-1);   // no selection
    ui->LD4_surgeon_name->setEditText("");       // clear text
}

void Surgery_data::on_B4_male_clicked()
{
    ui->B4_female->setChecked(false);
}
void Surgery_data::on_B4_female_clicked()
{
    ui->B4_male->setChecked(false);
}

void Surgery_data::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}

void Surgery_data::refreshPage()
{
    // ===== Reload surgeon names =====
    loadSurgeonNames();

    // ===== Refresh surgery/protocol name =====
    ui->LD4_surgery_name->setText(protocolName);

    // ===== Clear input fields =====
    ui->LD4_patient_name->clear();
    ui->LD4_patient_age->clear();
    ui->LD4_patient_ID->clear();

    // ===== Reset combo box =====
    ui->LD4_surgeon_name->setCurrentIndex(-1);
    ui->LD4_surgeon_name->setEditText("");

    // ===== Reset gender selection =====
    ui->B4_male->setChecked(false);
    ui->B4_female->setChecked(false);

    // ===== Reset globals =====
    surgeonName.clear();
    patientName.clear();
    patientAge.clear();
    surgeryName.clear();
    patientID.clear();

    genderMale = false;
    genderFemale = false;
}

// Add this function anywhere inside surgery_data.cpp

bool Surgery_data::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QLineEdit *targetLineEdit = nullptr;
        CustomKeyboard::KeyboardMode keyboardMode = CustomKeyboard::FullLayout; // Default layout

        if (watched == ui->LD4_patient_ID) {
            targetLineEdit = ui->LD4_patient_ID;
        }
        else if (watched == ui->LD4_patient_name) {
            targetLineEdit = ui->LD4_patient_name;
        }
        else if (watched == ui->LD4_patient_age) {
            targetLineEdit = ui->LD4_patient_age;
            keyboardMode = CustomKeyboard::NumericOnly; // 💡 Enforce numeric layout for age
        }
        else if (ui->LD4_surgeon_name->lineEdit() && watched == ui->LD4_surgeon_name->lineEdit()) {
            targetLineEdit = ui->LD4_surgeon_name->lineEdit();
        }

        if (targetLineEdit)
        {
            targetLineEdit->clearFocus();

            // Pass the layout flag directly into the parameterized constructor
            CustomKeyboard keyboard(this, keyboardMode);
            keyboard.setTarget(targetLineEdit);

            // Adjust placement calculation since the square numeric box profile is slightly taller
            if (keyboardMode == CustomKeyboard::NumericOnly) {
                keyboard.move(200, 60);
            } else {
                keyboard.move(0, 160);
            }

            keyboard.exec();
            return true;
        }
    }

    return QWidget::eventFilter(watched, event);
}

