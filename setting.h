#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include "thememanager.h"
#include "home.h"
#include "newcustomprotocol.h"
#include "changepassword.h"
#include "error_popup.h"



namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr, Home *home = nullptr);
    ~Setting();

protected:
    void showEvent(QShowEvent *event) override;

private:
    void refreshPage();

private slots:

    void switchToHome();

    void on_B3_back_to_home_clicked();

    void on_B3_simplified_clicked();

    void on_B3_advanced_clicked();

    void on_B3_pulse_mode_clicked();

    void on_B3_custom_clicked();

    void on_B3_pass_enable_clicked();

    void on_B3_pass_change_clicked();

    void on_B3_interlockkey_enable_clicked();

    void on_B3_dark_light_clicked();

    void on_B3_usage_area_clicked();

    void on_B3_service_engineer_area_clicked();

    void update_simp_adva_mode(void);

    void switchTonewprotocol(void);

    void toggle_pass_enable();

    void toggle_interlockkey_enable();

    void switchTonewPulseMode();

    void on_B3_clear_data_clicked();

    void on_B3_patientdata_export_clicked();

    void on_B3_patientdata_enable_clicked();

    void clear_data_form_userdb();

    void export_status(int ex_st);

    bool exportPatientDataToCSV();

    bool exportPatientWiseCSV();

    void toggle_patientdata_enable();

private:
    Ui::Setting *ui;
    ThemeManager theme;
    Home *home;

    error_popup *popup;

};

#endif // SETTING_H
