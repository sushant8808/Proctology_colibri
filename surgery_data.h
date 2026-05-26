#ifndef SURGERY_DATA_H
#define SURGERY_DATA_H

#include <QWidget>
#include "home.h"
#include "customkeyboard.h"
#include "error_popup.h"

namespace Ui {
class Surgery_data;
}

class Surgery_data : public QWidget
{
    Q_OBJECT

public:
    explicit Surgery_data(QWidget *parent = nullptr, Home *home = nullptr);
    ~Surgery_data();

protected:
    void showEvent(QShowEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void refreshPage();

private slots:

    void on_B4_save_clicked();

    void on_B4_skip_clicked();

    void on_B4_back_to_home_clicked();

    void switchToHome();

    // void on_LD4_surgeon_name_textEdited(const QString &arg1);

    // void on_LD4_patient_name_textEdited(const QString &arg1);

    // void on_LD4_patient_age_textEdited(const QString &arg1);

    // void on_LD4_surgery_name_textEdited(const QString &arg1);

    void on_B4_male_clicked();

    void on_B4_female_clicked();

    void loadSurgeonNames();

private:
    Ui::Surgery_data *ui;
    Home *home;

    error_popup *popup;
};

#endif // SURGERY_DATA_H
