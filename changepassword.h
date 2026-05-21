#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>
#include "databaseinitializer.h"
#include "setting.h"
#include "home.h"

namespace Ui {
class changepassword;
}

class changepassword : public QWidget
{
    Q_OBJECT

public:
    explicit changepassword(QWidget *parent = nullptr, Home *home = nullptr);
    ~changepassword();

protected:
    void showEvent(QShowEvent *event) override;

private:
    void refreshPage();

private slots:

    void appendDigit(const QString &digit);

    void on_B1_pass_1_clicked();

    void on_B1_pass_2_clicked();

    void on_B1_pass_3_clicked();

    void on_B1_pass_4_clicked();

    void on_B1_pass_5_clicked();

    void on_B1_pass_6_clicked();

    void on_B1_pass_7_clicked();

    void on_B1_pass_8_clicked();

    void on_B1_pass_9_clicked();

    void on_B1_pass_c_clicked();

    void on_B1_pass_0_clicked();

    void on_B1_pass_ok_clicked();

    void switchToSetting();


    void on_B3_back_to_setting_clicked();

private:
    Ui::changepassword *ui;
    Home *home;

    enum PassStage {
        CURRENT_PASS,
        NEW_PASS,
        CONFIRM_PASS
    };

    PassStage activeStage;

    QString currentPass;
    QString newPass;
    QString confirmPass;

    void updateDisplay();


};

#endif // CHANGEPASSWORD_H
