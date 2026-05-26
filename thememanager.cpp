#include "thememanager.h"
#include "error_popup.h"
#include <QEventLoop>
#include <QTimer>
#include "global.h"

error_popup *popup;

ThemeManager::ThemeManager(QObject *parent) : QObject(parent)
{
}

void ThemeManager::applyDarkTheme()
{

    // ===============================
    // 🎨 CENTRAL COLOR DEFINITIONS
    // ===============================

    QString mainBg        = "black";
    QString primaryBg     = "rgb(50,50,50)";
    QString secondaryBg   = "rgb(90,90,90)";
    QString textColor     = "white";
    QString accentColor   = "rgb(255,97,34)";
    QString borderColor   = primaryBg;

    // ===============================
    // 🎨 PALETTE
    // ===============================

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(0,0,0));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(0,0,0));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(0,0,0));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::Highlight, QColor(255,97,34));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);

    // ===============================
    // 🎨 STYLESHEET BUILDER
    // ===============================

    QString style =

            // QPushButton
            "QPushButton {"
        " border:0px;"
        " border-radius:30px;"
        " background-color:" + mainBg + ";"
                   " font-size:24pt;"
                   "}"
                   "QPushButton:pressed {"
                   " background-color:" + secondaryBg + ";"
                        "}"

                        // Frames
            "#Password_frame, #homeframe_1, #homeframe_4, #settingframe_1,#homeframe_7,#homeframe_8,#homeframe_9,"
                        "#surgerydata_1, #readysurgery_1, #change_pass_frame_1,"
                        "#confirm_new_pass, #current_pass, #new_pass, #F1_pulsemode {"
                        " background-color:" + primaryBg + ";"
                      " border-radius:30px;"
                      "}"

                      "#homeframe_2, #homeframe_3, #homeframe_5, #homeframe_6,"
                      "#settingframe_2, #settingframe_3, #settingframe_4,"
                      "#settingframe_5, #settingframe_6, #readysurgery_2,"
                      "#readysurgery_3, #readysurgery_4, #F2_pulsemode, #F3_pulsemode {"
                      " background-color:" + mainBg + ";"
                   " border-radius:30px;"
                   "}"

                   // Labels
            "#L1_passprint {"
                   " color:" + textColor + ";"
                      " background-color:" + mainBg + ";"
                   " border-radius:20px;"
                   " font-size:32pt;"
                   "}"

                   "#L2_protocol_show, #L5_ready {"
                   " background-color:" + primaryBg + ";"
                      " border-radius:15px;"
                      " font-size:16pt;"
                      " padding-left:10px;"
                      "}"

                      "#L_model, #L_serial_no, #version_show {"
                      " background-color:" + primaryBg + ";"
                      " border-radius:20px;"
                      " font-size:14pt;"
                      " padding-left:10px;"
                      "}"

                      "#L5_store_1,#L5_store_2,#L5_store_3,#L5_store_4,"
                      "#L5_store_5,#L5_store_6,#L5_store_7,#L5_store_8 {"
                      " background-color:" + primaryBg + ";"
                      " border-radius:5px;"
                      "}"

                      // Home buttons (class based)
            "*[class=\"home_button\"] {"
                      " background-color:" + primaryBg + ";"
                      " border-radius:25px;"
                      "}"
                      "*[class=\"home_button\"]:pressed {"
                      " background-color:" + secondaryBg + ";"
                        "}"

                        // keyboard open buttons (class based)
            "*[class=\"keyboard_bt\"] {"
                        "background-image:url(:/icons/keyboard_drop_dark.png);"
                        " background-color:" + secondaryBg + ";"
                      " border-radius:15px;"
                      "}"
                      "*[class=\"keyboard_bt\"]:pressed {"
                      " background-color:" + mainBg + ";"
                        "}"




                   "#B3_simplified, #B3_advanced, #B3_usage_area, "
                   "#B3_service_engineer_area, #B5_to_standby, #B5_pause, #B5_change {"
                   " background-color:" + primaryBg + ";"
                      "}"

                      "#B3_simplified:pressed, #B3_advanced:pressed, "
                      "#B3_usage_area:pressed, #B3_service_engineer_area:pressed, "
                      "#B5_to_standby:pressed, #B5_pause:pressed, #B5_change:pressed {"
                      " background-color:" + secondaryBg + ";"
                        "}"

                        "#B2_timer_reset, #B2_timer_noreset {"
                        " background-color:" + primaryBg + ";"
                      "}"

                      "#B2_timer_reset:pressed, #B2_timer_noreset:pressed {"
                      " background-color:" + secondaryBg + ";"
                        "}"

                        "#L2_tab_hide {"
                        " background-color:" + mainBg + ";"
                   "}"

                   "QPushButton[type=\"customAction\"] {"
                   " background-color:" + primaryBg + ";"
                      " color:" + textColor + ";"
                      " border:1px solid " + accentColor + ";"
                        " border-radius:20px;"
                        " font-size:14pt;"
                        " padding:8px 20px;"
                        "}"

                        "QPushButton[type=\"customAction\"]:pressed {"
                        " background-color:" + secondaryBg + ";"
                        " color:black;"
                        "}"

                        // QCheckBox
            "QCheckBox::indicator {"
                        "    width: 16px;"
                        "    height: 16px;"
                        "    border: 2px solid " + secondaryBg + ";"
                        "    background-color: " + mainBg + ";"
                   "}"

                   "QCheckBox::indicator:checked {"
                   // "    background-color: " + accentColor + ";"
            "background-image:url(:/icons/check_dark.png);"
                        "    border: 2px solid " + secondaryBg + ";"
                        "}"

                        "QCheckBox::indicator:unchecked {"
                        "    background-color: " + mainBg + ";"
                   "    border: 2px solid " + secondaryBg + ";"
                        "}"

                        // Tabs (T2_home)
            "#T2_home QTabBar::tab {"
                        " padding:4px 5px 5px 5px;"
                        " font-size:20px;"
                        "  max-width: 500px;"
                        "  min-width: 120px;"
                        " color:" + textColor + ";"
                       " background-color:" + mainBg + ";"
                       " border:2px solid " + primaryBg + ";"
                      " border-top-left-radius: 15px;"
                      " border-top-right-radius: 15px;"
                      "}"

                      "#T2_home QTabBar::tab:selected {"
                      " color:" + accentColor + ";"
                        " background-color:" + primaryBg + ";"
                        " border:2px solid " + accentColor + ";"
                      "}"

                      "#T2_home::pane {"
                      " background-color:" + primaryBg + ";"
                      " border-radius:30px;"
                      "}"

                      // Main Tab

            "#Main_Tab QTabBar::tab { "
                      "padding:10px 20px; "
                      "font-size:26px; "
                        "  max-width: 500px;"
                        "  min-width: 120px;"
                        " color:" + textColor + ";"
                       " background-color:" + mainBg + ";"
                       " border:2px solid " + primaryBg + ";"
                      " border-top-left-radius: 15px;"
                      " border-top-right-radius: 15px;"
                        "border-bottom: none;"
                      "}"

                      "#Main_Tab QTabBar::tab:selected {"
                      " color:" + accentColor + ";"
                        " background-color:" + primaryBg + ";"
                      " border-radius:20px;"
                      " border-bottom-left-radius:0px;"
                      " border-bottom-right-radius:0px;"
                      " border:2px solid " + accentColor + ";"
                      "}"

                      "#Main_Tab QTabBar::tab:!selected {"
                      " color:" + textColor + ";"
                      " background-color:" + mainBg + ";"
                   "}"

                   "#Main_Tab::pane { "
                   "background-color:" + mainBg + "; "
                   "border: 2px solid " + primaryBg + ";"
                      " border-bottom-left-radius:20px;"
                      " border-bottom-right-radius:20px;"
                      "}"

                      // Sub Tab
            "#Sub_Tab QTabBar::tab { "
                      "padding:5px 0px 5px 0px; "
                      "font-size:19px; "
                        "  max-width: 500px;"
                        "  min-width: 108px;"
                        " min-height: 30px;"
                        " color:" + textColor + ";"
                       " background-color:" + mainBg + ";"
                       " border:0px solid " + primaryBg + ";"
                      " border-top-left-radius: 0px;"
                      " border-top-right-radius: 0px;"
                      "}"

                      "#Sub_Tab QTabBar::tab:selected {"
                      " color:" + accentColor + ";"
                        " border-radius:0px;"
                        " background-color:" + primaryBg + ";"
                        " border:0px solid " + primaryBg + ";"
                      "}"

                      "#Sub_Tab QTabBar::tab:!selected {"
                      " color:" + textColor + ";"
                      " background-color:" + mainBg + ";"
                   "}"

                   "#Sub_Tab::pane { "
                   "background-color:" + mainBg + "; "
                   "border: 0px solid " + primaryBg + ";"
                      "border-top: 2px solid " + primaryBg + ";"
                      " border-bottom-left-radius:30px;"
                      " border-bottom-right-radius:30px;"
                      "}"


                      // RadioButton
            "QRadioButton::indicator {"
                      " width:12px; height:12px;"
                      " border:2px solid " + borderColor + ";"
                        " border-radius:6px;"
                        " background-color:" + mainBg + ";"
                   "}"

                   "QRadioButton::indicator:checked {"
                   " background-color:" + accentColor + ";"
                        "}"

                        // Slider
            "QSlider::groove:horizontal {"
                        " height:6px;"
                        " background:white;"
                        " border-radius:3px;"
                        "}"

                        "QSlider::handle:horizontal {"
                        " background:rgb(0, 255, 0);"
                        " border:2px solid " + borderColor + ";"
                        " height:18px; width:18px;"
                        " border-radius:9px;"
                        " margin:-7px 0;"
                        "}"

                        "QSlider::sub-page:horizontal {"
                        " background:rgb(0, 255, 0);"
                        " border-radius:3px;"
                        "}"

                        // LineEdit
            "QLineEdit {"
                        " border-radius:20px;"
                        " font-size:12pt;"
                        " padding:4px;"
                        " background-color:" + secondaryBg + ";"
                        " color:" + textColor + ";"
                      "}"

                      // ComboBox
            "QComboBox {"
                      " border-radius:20px;"
                      " font-size:12pt;"
                      " padding:4px;"
                      " background-color:" + secondaryBg + ";"
                        " color:" + textColor + ";"
                      "}"

                      "QComboBox::drop-down {"
                      " subcontrol-origin: padding;"
                      " subcontrol-position: top right;"
                      " width:20px;"
                      "}"

                      // Dialog
            "QDialog {"
                      " background-color:" + mainBg + ";"
                   " color:" + textColor + ";"
                      " border:4px solid " + primaryBg + ";"
                      " border-radius:15px;"
                      "}"

                      // QTableWidget

            // Table Header
            "QHeaderView::section {"
                      " background-color:" + mainBg + ";"
                   " color:" + textColor + ";"
                      " border:none;"
                      " font: 10pt 'Roboto';"
                      "border: 1px solid " + primaryBg + ";"
                      "border-radius: 12px;"
                      "}"

                      "QTableWidget {"
                      " background-color:" + mainBg + ";"
                   " color:" + textColor + ";"
                      " font: 10pt 'Roboto';"
                    "border: 1px solid " + mainBg + ";"
                      " outline:none;"
                      "}"

                      "QTableWidget::item:hover {"
                      " background-color:transparent;"
                      " color:" + textColor + ";"
                      "}"

                      "QTableWidget::item:selected {"
                      " background-color:transparent;"
                      " color:" + textColor + ";"
                      "}"

                      "QTableWidget::item:focus {"
                      " outline:none;"
                      " border:none;"
                      "}"

                      "QTableWidget::indicator {"
                      " width:14px;"
                      " height:14px;"
                      " border:2px solid " + textColor + ";"
                      " background-color:" + mainBg + ";"
                   "}"

                   "QTableWidget::indicator:checked {"
                   " background-color:" + accentColor + ";"
                        " border:2px solid " + textColor + ";"
                      "}"

                      "QTableWidget::indicator:unchecked {"
                      " background-color:" + mainBg + ";"
                   " border:2px solid " + textColor + ";"
                      "}"

                      // ===============================
            // CUSTOM KEYBOARD
            // ===============================

            "QDialog#CustomKeyboard {"
                      " background-color: rgb(18,18,18);"
                      " border: 2px solid rgb(60,60,60);"
                      " border-radius: 18px;"
                      "}"

                      "QLineEdit#KeyboardDisplay {"
                      " background-color: rgb(8,8,8);"
                      " color: white;"
                      " border: 2px solid rgb(255,97,34);"
                      " border-radius: 10px;"
                      " padding-left: 10px;"
                      " font-size: 20px;"
                      " min-height: 40px;"
                      "}"

                      "QPushButton[keyboardButton=\"true\"] {"
                      " background-color: rgb(35,35,35);"
                      " color: white;"
                      " border: 1px solid rgb(70,70,70);"
                      " border-radius: 10px;"
                      " font-size: 16px;"
                      " font-weight: 600;"
                      "}"

                      "QPushButton[keyboardButton=\"true\"]:pressed {"
                      " background-color: rgb(255,97,34);"
                      " color: black;"
                      "}"

                      "QPushButton[keyboardSpecial=\"true\"] {"
                      " background-color: rgb(60,60,60);"
                      " color: white;"
                      " border: 1px solid rgb(90,90,90);"
                      " border-radius: 10px;"
                      " font-size: 15px;"
                      " font-weight: bold;"
                      "}"

                      "QPushButton[keyboardSpecial=\"true\"]:pressed,"
                      "QPushButton[keyboardSpecial=\"true\"]:checked {"
                      " background-color: rgb(255,97,34);"
                      " color: black;"
                      "}"

                      "QPushButton[keyboardEnter=\"true\"] {"
                      " background-color: rgb(255,97,34);"
                      " color: black;"
                      " border-radius: 10px;"
                      " font-size: 16px;"
                      " font-weight: bold;"
                      "}"

                      "QPushButton[keyboardEnter=\"true\"]:pressed {"
                      " background-color: rgb(255,140,80);"
                      "}"

                      "QPushButton[keyboardSpace=\"true\"] {"
                      " background-color: rgb(28,28,28);"
                      " border: 1px solid rgb(70,70,70);"
                      " border-radius: 10px;"
                      "}"

/* ========================================== */
            /* 🌙 TOUCH DATE-TIME PICKER (DARK)          */
            /* ========================================== */
            "#lblHeader{"
        " background: transparent;"
        " font-size: 13pt;"
        " font-weight: 600;"
        " color: rgb(150,150,150);"
        " letter-spacing: 1px;"
        "}"
        "#lblPickerDisplay{"
        " background: transparent;"
        " font-size: 24pt;"
        " font-weight: bold;"
        " color: " + textColor + ";"
        " min-width: 75px;"
        "}"
        "#btnPickerArrow {"
        " background-color: " + primaryBg + ";"
        " color: " + textColor + ";"
        " border: 1px solid rgb(70,70,70);"
        " border-radius: 8px;"
        " font-size: 18pt;"
        " font-weight: bold;"
        " min-width: 75px;"
        " min-height: 55px;"
        "}"
        "#btnPickerArrow:pressed {"
        " background-color: " + accentColor + ";"
        " color: black;"
        " border: 1px solid rgb(255,120,50);"
        "}"
        "#applyButton {"
        " background-color: " + accentColor + ";"
        " color: black;"
        " border-radius: 12px;"
        " font-size: 16pt;"
        " min-height: 55px;"
        " margin-top: 10px;"
        " font-weight: bold;"
        "}"
        "#applyButton:pressed {"
        " background-color: rgb(215,75,20);"
        " color: white;"
        "}"

                      // Icons
            "#B3_dark_light { background-image:url(:/icons/sun.png); }"
                      "#B2_modify_protocol { background-image:url(:/icons/save_dark.png); }"
                      "#B2_back_to_home,#back_to_home { background-image:url(:/icons/home_dark.png); }"
                      "#B2_aimingbeam,#B5_aimingbeam { background-image:url(:/icons/laser_dark.png); }"
                      "#B2_sound,#B5_sound { background-image:url(:/icons/volume_dark.png); }"
                      "#B2_brightness,#B5_brightness { background-image:url(:/icons/brightness_dark.png); }"
                      "#B2_setting { background-image:url(:/icons/setting_dark.png); }"

                      "#B2_980add, #B2_1470add, #B2_timer_add, #B2_on_time_add, #B2_off_time_add, "
                        "#B2_alarm_sec_add, #B2_alarm_joule_add, #inc_low_value, #inc_high_value, "
                        "#next_power_1470, #next_power_980, #DAC_add_1470, #DAC_add_980"
                       " { background-image:url(:/icons/positive_dark_active.png); }"

                      "#B2_980sub, #B2_1470sub, #B2_timer_sub, #B2_on_time_sub, #B2_off_time_sub, "
                        "#B2_alarm_sec_sub, #B2_alarm_joule_sub, #dec_low_value, #dec_high_value, "
                        "#pre_power_1470, #pre_power_980, #DAC_sub_1470, #DAC_sub_980"
                      "{ background-image:url(:/icons/negative_dark_active.png); }"

        ;

    qApp->setStyleSheet(style);

}

void ThemeManager::applyLightTheme()
{

    // ===============================
    // 🎨 CENTRAL COLOR DEFINITIONS
    // ===============================

    QString mainBg        = "white";
    QString primaryBg     = "rgb(200,200,200)";
    QString secondaryBg   = "rgb(120,120,120)";
    QString textColor     = "black";
    QString accentColor   = "rgb(255,97,34)";
    QString borderColor   = primaryBg;

    // ===============================
    // 🎨 PALETTE
    // ===============================

    QPalette lightPalette;
    lightPalette.setColor(QPalette::Window, QColor(255,255,255));
    lightPalette.setColor(QPalette::WindowText, Qt::black);
    lightPalette.setColor(QPalette::Base, Qt::white);
    lightPalette.setColor(QPalette::AlternateBase, QColor(200,200,200));
    lightPalette.setColor(QPalette::Text, Qt::black);
    lightPalette.setColor(QPalette::Button, Qt::white);
    lightPalette.setColor(QPalette::ButtonText, Qt::black);
    lightPalette.setColor(QPalette::Highlight, QColor(255,97,34));
    lightPalette.setColor(QPalette::HighlightedText, Qt::white);

    qApp->setPalette(lightPalette);

    // ===============================
    // 🎨 STYLESHEET BUILDER
    // ===============================

    QString style =

            // QPushButton
            "QPushButton {"
        " border:0px;"
        " border-radius:30px;"
        " background-color:" + mainBg + ";"
                   " font-size:24pt;"
                   "}"
                   "QPushButton:pressed {"
                   " background-color:" + secondaryBg + ";"
                        "}"

                        // Frames
            "#Password_frame, #homeframe_1, #homeframe_4, #settingframe_1,#homeframe_7,#homeframe_8,#homeframe_9,"
                        "#surgerydata_1, #readysurgery_1, #change_pass_frame_1,"
                        "#confirm_new_pass, #current_pass, #new_pass, #F1_pulsemode {"
                        " background-color:" + primaryBg + ";"
                      " border-radius:30px;"
                      "}"

                      "#homeframe_2, #homeframe_3, #homeframe_5, #homeframe_6,"
                      "#settingframe_2, #settingframe_3, #settingframe_4,"
                      "#settingframe_5, #settingframe_6, #readysurgery_2,"
                      "#readysurgery_3, #readysurgery_4, #F2_pulsemode, #F3_pulsemode {"
                      " background-color:" + mainBg + ";"
                   " border-radius:30px;"
                   "}"

                   // Labels
            "#L1_passprint {"
                   " color:" + textColor + ";"
                      " background-color:" + mainBg + ";"
                   " border-radius:20px;"
                   " font-size:32pt;"
                   "}"

                   "#L2_protocol_show, #L5_ready {"
                   " background-color:" + primaryBg + ";"
                      " border-radius:15px;"
                      " font-size:16pt;"
                      " padding-left:10px;"
                      "}"

                      "#L_model, #L_serial_no, #version_show {"
                      " background-color:" + primaryBg + ";"
                      " border-radius:20px;"
                      " font-size:14pt;"
                      " padding-left:10px;"
                      "}"

                      "#L5_store_1,#L5_store_2,#L5_store_3,#L5_store_4,"
                      "#L5_store_5,#L5_store_6,#L5_store_7,#L5_store_8 {"
                      " background-color:" + primaryBg + ";"
                      " border-radius:5px;"
                      "}"

                      // Home Buttons
            "*[class=\"home_button\"] {"
                      " background-color:" + primaryBg + ";"
                      " border-radius:25px;"
                      "}"
                      "*[class=\"home_button\"]:pressed {"
                      " background-color:" + secondaryBg + ";"
                        "}"

                        // keyboard open buttons (class based)
            "*[class=\"keyboard_bt\"] {"
                        "background-image:url(:/icons/keyboard_drop_light.png);"
                        " background-color:" + secondaryBg + ";"
                        " border-radius:15px;"
                        "}"
                        "*[class=\"keyboard_bt\"]:pressed {"
                        " background-color:" + mainBg + ";"
                      "}"


                   "#B3_simplified, #B3_advanced, #B3_usage_area, "
                   "#B3_service_engineer_area, #B5_to_standby, #B5_pause, #B5_change {"
                   " background-color:" + primaryBg + ";"
                      "}"

                      "#B3_simplified:pressed, #B3_advanced:pressed, "
                      "#B3_usage_area:pressed, #B3_service_engineer_area:pressed, "
                      "#B5_to_standby:pressed, #B5_pause:pressed, #B5_change:pressed {"
                      " background-color:" + secondaryBg + ";"
                        "}"

                        "#B2_timer_reset, #B2_timer_noreset {"
                        " background-color:" + primaryBg + ";"
                      "}"

                      "#B2_timer_reset:pressed, #B2_timer_noreset:pressed {"
                      " background-color:" + secondaryBg + ";"
                        "}"

                        "#L2_tab_hide {"
                        " background-color:" + mainBg + ";"
                   "}"

                   "QPushButton[type=\"customAction\"] {"
                   " background-color:" + primaryBg + ";"
                      " color:" + textColor + ";"
                      " border:1px solid " + accentColor + ";"
                        " border-radius:20px;"
                        " font-size:14pt;"
                        " padding:8px 20px;"
                        "}"


                        "QPushButton[type=\"customAction\"]:pressed {"
                        " background-color:" + secondaryBg + ";"
                        " color:black;"
                        "}"

                        // QCheckBox
            "QCheckBox::indicator {"
                        "    width: 16px;"
                        "    height: 16px;"
                        "    border: 2px solid " + secondaryBg + ";"
                        "    background-color: " + mainBg + ";"
                   "}"

                   "QCheckBox::indicator:checked {"
                   // "    background-color: " + accentColor + ";"
            "background-image:url(:/icons/check_light.png);"
                        "    border: 2px solid " + secondaryBg + ";"
                        "}"

                        "QCheckBox::indicator:unchecked {"
                        "    background-color: " + mainBg + ";"
                   "    border: 2px solid " + secondaryBg + ";"
                        "}"

                        // Tabs (T2_home)
            "#T2_home QTabBar::tab {"
                        " padding:4px 5px 5px 5px;"
                        " font-size:20px;"
                        "  max-width: 500px;"
                        "  min-width: 120px;"
                        " color:" + textColor + ";"
                       " background-color:" + mainBg + ";"
                       " border:2px solid " + primaryBg + ";"
                      " border-top-left-radius: 15px;"
                      " border-top-right-radius: 15px;"
                      "}"

                      "#T2_home QTabBar::tab:selected {"
                      " color:" + accentColor + ";"
                        " background-color:" + primaryBg + ";"
                        " border:2px solid " + accentColor + ";"
                      "}"

                      "#T2_home::pane {"
                      " background-color:" + primaryBg + ";"
                      " border-radius:30px;"
                      "}"

                      // Main Tab
            "#Main_Tab QTabBar::tab { "
                      "padding:10px 20px; "
                      "font-size:26px; "
                        "  max-width: 500px;"
                        "  min-width: 120px;"
                        " color:" + textColor + ";"
                       " background-color:" + mainBg + ";"
                       " border:2px solid " + primaryBg + ";"
                      " border-top-left-radius: 15px;"
                      " border-top-right-radius: 15px;"
                        "border-bottom: none;"
                      "}"

                      "#Main_Tab QTabBar::tab:selected {"
                      " color:" + accentColor + ";"
                        " background-color:" + primaryBg + ";"
                      " border-radius:20px;"
                      " border-bottom-left-radius:0px;"
                      " border-bottom-right-radius:0px;"
                        " border:2px solid " + accentColor + ";"
                      "}"

                      "#Main_Tab QTabBar::tab:!selected {"
                      " color:" + textColor + ";"
                      " background-color:" + mainBg + ";"
                   "}"

                   "#Main_Tab::pane { "
                   "background-color:" + mainBg + "; "
                   "border: 2px solid " + primaryBg + ";"
                      " border-bottom-left-radius:20px;"
                      " border-bottom-right-radius:20px;"
                      "}"

                      // Sub Tab
            "#Sub_Tab QTabBar::tab { "
                      "padding:5px 0px 5px 0px; "
                      "font-size:19px; "
                        "  max-width: 500px;"
                        "  min-width: 108px;"
                        " min-height: 30px;"
                        " color:" + textColor + ";"
                       " background-color:" + mainBg + ";"
                       " border:0px solid " + primaryBg + ";"
                      " border-top-left-radius: 0px;"
                      " border-top-right-radius: 0px;"
                      "}"

                      "#Sub_Tab QTabBar::tab:selected {"
                      " color:" + accentColor + ";"
                        " border-radius:0px;"
                        " background-color:" + primaryBg + ";"
                        " border:0px solid " + primaryBg + ";"
                      "}"

                      "#Sub_Tab QTabBar::tab:!selected {"
                      " color:" + textColor + ";"
                      " background-color:" + mainBg + ";"
                   "}"

                   "#Sub_Tab::pane { "
                   "background-color:" + mainBg + "; "
                   "border: 0px solid " + primaryBg + ";"
                      "border-top: 2px solid " + primaryBg + ";"
                      " border-bottom-left-radius:30px;"
                      " border-bottom-right-radius:30px;"
                      "}"

                      // RadioButton
            "QRadioButton::indicator {"
                      " width:12px; height:12px;"
                      " border:2px solid " + borderColor + ";"
                        " border-radius:6px;"
                        " background-color:" + mainBg + ";"
                   "}"

                   "QRadioButton::indicator:checked {"
                   " background-color:" + accentColor + ";"
                        "}"

                        // Slider
            "QSlider::groove:horizontal {"
                        " height:6px;"
                        " background:black;"
                        " border-radius:3px;"
                        "}"

                        "QSlider::handle:horizontal {"
                        " background:rgb(0, 255, 0);"
                        " border:2px solid " + borderColor + ";"
                        " height:18px; width:18px;"
                        " border-radius:9px;"
                        " margin:-7px 0;"
                        "}"

                        "QSlider::sub-page:horizontal {"
                        " background:rgb(0, 255, 0);"
                        " border-radius:3px;"
                        "}"

                        // LineEdit
            "QLineEdit {"
                        " border-radius:20px;"
                        " font-size:12pt;"
                        " padding:4px;"
                        " background-color:" + secondaryBg + ";"
                        " color:" + textColor + ";"
                      "}"

                      // ComboBox
            "QComboBox {"
                      " border-radius:20px;"
                      " font-size:12pt;"
                      " padding:4px;"
                      " background-color:" + secondaryBg + ";"
                        " color:" + textColor + ";"
                      "}"

                      "QComboBox::drop-down {"
                      " subcontrol-origin: padding;"
                      " subcontrol-position: top right;"
                      " width:20px;"
                      "}"

                      // Dialog
            "QDialog {"
                      " background-color:" + mainBg + ";"
                   " color:" + textColor + ";"
                      " border:4px solid " + primaryBg + ";"
                      " border-radius:15px;"
                      "}"

                      // QTableWidget

            // Table Header
            "QHeaderView::section {"
                      " background-color:" + mainBg + ";"
                   " color:" + textColor + ";"
                      " border:none;"
                      " font: 10pt 'Roboto';"
                      "border: 1px solid " + primaryBg + ";"
                      "border-radius: 12px;"
                      "}"

                      "QTableWidget {"
                      " background-color:" + mainBg + ";"
                   " color:" + textColor + ";"
                      " font: 10pt 'Roboto';"
                        "border: 1px solid " + mainBg + ";"
                      " outline:none;"
                      "}"

                      "QTableWidget::item:hover {"
                      " background-color:transparent;"
                      " color:" + textColor + ";"
                      "}"

                      "QTableWidget::item:selected {"
                      " background-color:transparent;"
                      " color:" + textColor + ";"
                      "}"

                      "QTableWidget::item:focus {"
                      " outline:none;"
                      " border:none;"
                      "}"

                      "QTableWidget::indicator {"
                      " width:14px;"
                      " height:14px;"
                      " border:2px solid " + textColor + ";"
                      " background-color:" + mainBg + ";"
                   "}"

                   "QTableWidget::indicator:checked {"
                   " background-color:" + accentColor + ";"
                        " border:2px solid " + textColor + ";"
                      "}"

                      "QTableWidget::indicator:unchecked {"
                      " background-color:" + mainBg + ";"
                   " border:2px solid " + textColor + ";"
                      "}"

                      // ===============================
            // CUSTOM KEYBOARD
            // ===============================

            "QDialog#CustomKeyboard {"
                      " background-color: rgb(245,245,245);"
                      " border: 2px solid rgb(180,180,180);"
                      " border-radius: 18px;"
                      "}"

                      "QLineEdit#KeyboardDisplay {"
                      " background-color: white;"
                      " color: black;"
                      " border: 2px solid rgb(255,97,34);"
                      " border-radius: 10px;"
                      " padding-left: 10px;"
                      " font-size: 20px;"
                      " min-height: 40px;"
                      "}"

                      "QPushButton[keyboardButton=\"true\"] {"
                      " background-color: rgb(230,230,230);"
                      " color: black;"
                      " border: 1px solid rgb(180,180,180);"
                      " border-radius: 10px;"
                      " font-size: 16px;"
                      " font-weight: 600;"
                      "}"

                      "QPushButton[keyboardButton=\"true\"]:pressed {"
                      " background-color: rgb(255,97,34);"
                      " color: white;"
                      "}"

                      "QPushButton[keyboardSpecial=\"true\"] {"
                      " background-color: rgb(200,200,200);"
                      " color: black;"
                      " border: 1px solid rgb(170,170,170);"
                      " border-radius: 10px;"
                      " font-size: 15px;"
                      " font-weight: bold;"
                      "}"

                      "QPushButton[keyboardSpecial=\"true\"]:pressed,"
                      "QPushButton[keyboardSpecial=\"true\"]:checked {"
                      " background-color: rgb(255,97,34);"
                      " color: white;"
                      "}"

                      "QPushButton[keyboardEnter=\"true\"] {"
                      " background-color: rgb(255,97,34);"
                      " color: white;"
                      " border-radius: 10px;"
                      " font-size: 16px;"
                      " font-weight: bold;"
                      "}"

                      "QPushButton[keyboardEnter=\"true\"]:pressed {"
                      " background-color: rgb(255,140,80);"
                      "}"

                      "QPushButton[keyboardSpace=\"true\"] {"
                      " background-color: rgb(235,235,235);"
                      " border: 1px solid rgb(180,180,180);"
                      " border-radius: 10px;"
                      "}"

            /* ========================================== */
            /* ☀️ TOUCH DATE-TIME PICKER (LIGHT)         */
            /* ========================================== */
            "#lblHeader {"
        " background: transparent;"
        " font-size: 13pt;"
        " font-weight: 600;"
        " color: rgb(100,100,100);"
        " letter-spacing: 1px;"
        "}"
        "#lblPickerDisplay {"
        " background: transparent;"
        " font-size: 24pt;"
        " font-weight: bold;"
        " color: " + textColor + ";"
        " min-width: 75px;"
        "}"
        "#btnPickerArrow {"
        " background-color: " + primaryBg + ";"
        " color: " + textColor + ";"
        " border: 1px solid rgb(180,180,180);"
        " border-radius: 8px;"
        " font-size: 18pt;"
        " font-weight: bold;"
        " min-width: 75px;"
        " min-height: 55px;"
        "}"
        "#btnPickerArrow:pressed {"
        " background-color: " + accentColor + ";"
        " color: white;"
        " border: 1px solid rgb(255,120,50);"
        "}"
        "#applyButton {"
        " background-color: " + accentColor + ";"
        " color: white;"
        " border-radius: 12px;"
        " font-size: 16pt;"
        " min-height: 55px;"
        " margin-top: 10px;"
        " font-weight: bold;"
        "}"
        "#applyButton:pressed {"
        " background-color: rgb(215,75,20);"
        " color: white;"
        "}"

                      // Icons
            "#B3_dark_light { background-image:url(:/icons/moon.png); }"
                      "#B2_modify_protocol { background-image:url(:/icons/save_light.png); }"
                      "#B2_back_to_home,#back_to_home { background-image:url(:/icons/home_light.png); }"
                      "#B2_aimingbeam,#B5_aimingbeam { background-image:url(:/icons/laser_light.png); }"
                      "#B2_sound,#B5_sound { background-image:url(:/icons/volume_light.png); }"
                      "#B2_brightness,#B5_brightness { background-image:url(:/icons/brightness_light.png); }"
                      "#B2_setting { background-image:url(:/icons/setting_light.png); }"

                      "#B2_980add, #B2_1470add, #B2_timer_add, #B2_on_time_add, #B2_off_time_add, "
                        "#B2_alarm_sec_add, #B2_alarm_joule_add, #inc_low_value, #inc_high_value, "
                        "#next_power_1470, #next_power_980, #DAC_add_1470, #DAC_add_980"
                       " { background-image:url(:/icons/positive_light_active.png); }"

                      "#B2_980sub, #B2_1470sub, #B2_timer_sub, #B2_on_time_sub, #B2_off_time_sub, "
                        "#B2_alarm_sec_sub, #B2_alarm_joule_sub, #dec_low_value, #dec_high_value, "
                        "#pre_power_1470, #pre_power_980, #DAC_sub_1470, #DAC_sub_980"
                      "{ background-image:url(:/icons/negative_light_active.png); }"

        ;

    qApp->setStyleSheet(style);

}

void ThemeManager::Dark_theme(void)
{
    if(Adv_Sim_fromSetting)
    {
        error_popup localPopup;
        localPopup.showMessage(
                    "DARK THEME",
                    "Switching to Dark Theme.",
                    error_popup::Info,
                    false
                    );

        QEventLoop loop;
        QTimer::singleShot(10, &loop, &QEventLoop::quit);
        loop.exec();

        applyDarkTheme();

        QTimer::singleShot(5, &loop, &QEventLoop::quit);
        loop.exec();

        localPopup.forceHide();
    }
    else
    {
        applyDarkTheme();
    }
}

void ThemeManager::Light_theme(void)
{
    if(Adv_Sim_fromSetting)
    {
        error_popup localPopup;
        localPopup.showMessage(
                    "LIGHT THEME",
                    "Switching to Light Theme.",
                    error_popup::Info,
                    false
                    );

        QEventLoop loop;
        QTimer::singleShot(10, &loop, &QEventLoop::quit);
        loop.exec();

        applyLightTheme();

        QTimer::singleShot(5, &loop, &QEventLoop::quit);
        loop.exec();

        localPopup.forceHide();
    }
    else
    {
        applyLightTheme();
    }
}
