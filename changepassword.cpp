#include "changepassword.h"
#include "ui_changepassword.h"
#include "global.h"        // userpass
#include <QMessageBox>
#include "mainwindow.h"
#include "pageindex.h"
#include <QShowEvent>
#include <QThread>
#include "databaseinitializer.h"

changepassword::changepassword(QWidget *parent, Home *home)
    : QWidget(parent)
    ,ui(new Ui::changepassword)
    , home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    /* Password fields setup */
    ui->current_pass->setEchoMode(QLineEdit::Password);
    ui->new_pass->setEchoMode(QLineEdit::Password);
    ui->confirm_new_pass->setEchoMode(QLineEdit::Password);

    ui->current_pass->setMaxLength(4);
    ui->new_pass->setMaxLength(4);
    ui->confirm_new_pass->setMaxLength(4);

    popup = new error_popup(this);

    connect(popup, &error_popup::acknowledged,
            this,[this](){
        if(success)
            switchToSetting();
        qDebug() << "ok";
    });

}

changepassword::~changepassword()
{
    delete ui;
}

/* --------------------------------------------------
 * Append digit to focused field
 * -------------------------------------------------- */
void changepassword::appendDigit(const QString &digit)
{
    QLineEdit *target = qobject_cast<QLineEdit*>(QApplication::focusWidget());

    if (!target)
        return;

    if (target != ui->current_pass &&
            target != ui->new_pass &&
            target != ui->confirm_new_pass)
        return;

    if (target->text().length() >= 4)
        return;

    target->insert(digit);
}


/* --------------------------------------------------
 * Number buttons
 * -------------------------------------------------- */
void changepassword::on_B1_pass_0_clicked() { appendDigit("0"); }
void changepassword::on_B1_pass_1_clicked() { appendDigit("1"); }
void changepassword::on_B1_pass_2_clicked() { appendDigit("2"); }
void changepassword::on_B1_pass_3_clicked() { appendDigit("3"); }
void changepassword::on_B1_pass_4_clicked() { appendDigit("4"); }
void changepassword::on_B1_pass_5_clicked() { appendDigit("5"); }
void changepassword::on_B1_pass_6_clicked() { appendDigit("6"); }
void changepassword::on_B1_pass_7_clicked() { appendDigit("7"); }
void changepassword::on_B1_pass_8_clicked() { appendDigit("8"); }
void changepassword::on_B1_pass_9_clicked() { appendDigit("9"); }

/* --------------------------------------------------
 * Clear button
 * -------------------------------------------------- */
void changepassword::on_B1_pass_c_clicked()
{
    if (ui->current_pass->hasFocus())
        ui->current_pass->clear();
    else if (ui->new_pass->hasFocus())
        ui->new_pass->clear();
    else if (ui->confirm_new_pass->hasFocus())
        ui->confirm_new_pass->clear();
}

/* --------------------------------------------------
 * OK button logic
 * -------------------------------------------------- */
void changepassword::on_B1_pass_ok_clicked()
{
    QString currentPass = ui->current_pass->text();
    QString newPass     = ui->new_pass->text();
    QString confirmPass = ui->confirm_new_pass->text();

    if (currentPass.length() != 4 ||
            newPass.length() != 4 ||
            confirmPass.length() != 4)
    {
        popup->showMessage(
                    "MISSING FIELDS",
                    "Please enter all 4-digit passwords.\n"
            "",
                    error_popup::Warning,
                    true
                    );
        return;
    }

    if (currentPass != loginpass)
    {
        popup->showMessage(
                    "INCORRECT",
                    "Current password is incorrect.\n"
            "",
                    error_popup::Warning,
                    true
                    );
        ui->current_pass->clear();
        ui->current_pass->setFocus();
        return;
    }

    if (newPass != confirmPass)
    {
        popup->showMessage(
                    "MISMATCH",
                    "New passwords do not match.\n"
            "",
                    error_popup::Warning,
                    true
                    );
        ui->new_pass->clear();
        ui->confirm_new_pass->clear();
        ui->new_pass->setFocus();
        return;
    }

    /* Update password */
    loginpass = newPass;

    DatabaseInitializer dbinit;

    qDebug()<<loginpass;

        dbinit.updatePassword(1,loginpass,"4321","1234");

//    bool success = dbinit.updatePassword(1, loginpass, "4321", "1234");

//    if (success) {
//        qDebug() << "Password update succeeded!";
//    } else {
//        qCritical() << "Password update failed!";
//    }

    popup->showMessage(
                "UPDATED",
                "Password changed successfully.",
                error_popup::Success,
                true
                );

    success = 1;

}

void changepassword::switchToSetting()
{
    MainWindow::instance->switchPage(PAGE_SETTING);
    success = 0;
}

void changepassword::on_B3_back_to_setting_clicked()
{
    switchToSetting();
}

void changepassword::refreshPage()
{
    // Clear all password fields
    ui->current_pass->clear();

    ui->new_pass->clear();

    ui->confirm_new_pass->clear();

    // Set focus back to current password
    ui->current_pass->setFocus();

    qDebug()<<loginpass;

    success = 0;
}

void changepassword::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}
