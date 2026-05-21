/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QFrame *settingframe_1;
    QFrame *settingframe_2;
    QLabel *label;
    QPushButton *B3_pulse_mode;
    QPushButton *B3_simplified;
    QPushButton *B3_advanced;
    QPushButton *B3_custom;
    QFrame *settingframe_3;
    QLabel *label_2;
    QPushButton *B3_patientdata_enable;
    QPushButton *B3_patientdata_export;
    QFrame *settingframe_4;
    QLabel *label_3;
    QPushButton *B3_pass_enable;
    QPushButton *B3_pass_change;
    QFrame *settingframe_5;
    QLabel *label_4;
    QPushButton *B3_interlockkey_enable;
    QPushButton *B3_service_engineer_area;
    QPushButton *B3_usage_area;
    QPushButton *B3_dark_light;
    QPushButton *B3_back_to_home;
    QLabel *label_8;

    void setupUi(QWidget *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName("Setting");
        Setting->resize(800, 480);
        settingframe_1 = new QFrame(Setting);
        settingframe_1->setObjectName("settingframe_1");
        settingframe_1->setGeometry(QRect(20, 50, 760, 410));
        settingframe_1->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_1->setFrameShadow(QFrame::Shadow::Raised);
        settingframe_2 = new QFrame(settingframe_1);
        settingframe_2->setObjectName("settingframe_2");
        settingframe_2->setGeometry(QRect(10, 10, 365, 190));
        settingframe_2->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_2->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(settingframe_2);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 15, 141, 30));
        label->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));
        B3_pulse_mode = new QPushButton(settingframe_2);
        B3_pulse_mode->setObjectName("B3_pulse_mode");
        B3_pulse_mode->setGeometry(QRect(30, 120, 130, 50));
        B3_pulse_mode->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B3_simplified = new QPushButton(settingframe_2);
        B3_simplified->setObjectName("B3_simplified");
        B3_simplified->setGeometry(QRect(30, 60, 130, 50));
        B3_simplified->setStyleSheet(QString::fromUtf8("border: 0px solid;\n"
"border-top-left-radius: 25px;\n"
"border-bottom-left-radius: 25px;\n"
"font-size: 14pt;"));
        B3_advanced = new QPushButton(settingframe_2);
        B3_advanced->setObjectName("B3_advanced");
        B3_advanced->setGeometry(QRect(162, 60, 130, 50));
        B3_advanced->setStyleSheet(QString::fromUtf8("border: 0px solid;\n"
"border-top-right-radius: 25px;\n"
"border-bottom-right-radius: 25px;\n"
"font-size: 14pt;"));
        B3_custom = new QPushButton(settingframe_2);
        B3_custom->setObjectName("B3_custom");
        B3_custom->setGeometry(QRect(200, 120, 130, 50));
        B3_custom->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        settingframe_3 = new QFrame(settingframe_1);
        settingframe_3->setObjectName("settingframe_3");
        settingframe_3->setGeometry(QRect(385, 10, 365, 190));
        settingframe_3->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_3->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(settingframe_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 15, 171, 30));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));
        B3_patientdata_enable = new QPushButton(settingframe_3);
        B3_patientdata_enable->setObjectName("B3_patientdata_enable");
        B3_patientdata_enable->setGeometry(QRect(30, 60, 130, 50));
        B3_patientdata_enable->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B3_patientdata_export = new QPushButton(settingframe_3);
        B3_patientdata_export->setObjectName("B3_patientdata_export");
        B3_patientdata_export->setGeometry(QRect(30, 120, 130, 50));
        B3_patientdata_export->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        settingframe_4 = new QFrame(settingframe_1);
        settingframe_4->setObjectName("settingframe_4");
        settingframe_4->setGeometry(QRect(10, 210, 365, 130));
        settingframe_4->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_4->setFrameShadow(QFrame::Shadow::Raised);
        label_3 = new QLabel(settingframe_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 15, 141, 31));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));
        B3_pass_enable = new QPushButton(settingframe_4);
        B3_pass_enable->setObjectName("B3_pass_enable");
        B3_pass_enable->setGeometry(QRect(30, 60, 130, 50));
        B3_pass_enable->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B3_pass_change = new QPushButton(settingframe_4);
        B3_pass_change->setObjectName("B3_pass_change");
        B3_pass_change->setGeometry(QRect(200, 60, 130, 50));
        B3_pass_change->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        settingframe_5 = new QFrame(settingframe_1);
        settingframe_5->setObjectName("settingframe_5");
        settingframe_5->setGeometry(QRect(385, 210, 365, 130));
        settingframe_5->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_5->setFrameShadow(QFrame::Shadow::Raised);
        label_4 = new QLabel(settingframe_5);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 15, 181, 30));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));
        B3_interlockkey_enable = new QPushButton(settingframe_5);
        B3_interlockkey_enable->setObjectName("B3_interlockkey_enable");
        B3_interlockkey_enable->setGeometry(QRect(30, 60, 130, 50));
        B3_interlockkey_enable->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B3_service_engineer_area = new QPushButton(settingframe_1);
        B3_service_engineer_area->setObjectName("B3_service_engineer_area");
        B3_service_engineer_area->setGeometry(QRect(530, 350, 220, 50));
        B3_service_engineer_area->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B3_usage_area = new QPushButton(settingframe_1);
        B3_usage_area->setObjectName("B3_usage_area");
        B3_usage_area->setGeometry(QRect(10, 350, 220, 50));
        B3_usage_area->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B3_dark_light = new QPushButton(settingframe_1);
        B3_dark_light->setObjectName("B3_dark_light");
        B3_dark_light->setGeometry(QRect(355, 350, 50, 50));
        B3_dark_light->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B3_back_to_home = new QPushButton(Setting);
        B3_back_to_home->setObjectName("B3_back_to_home");
        B3_back_to_home->setGeometry(QRect(20, 5, 51, 40));
        QFont font;
        font.setPointSize(22);
        font.setBold(false);
        B3_back_to_home->setFont(font);
        B3_back_to_home->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B3_back_to_home->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8 = new QLabel(Setting);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(345, 10, 110, 31));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        retranslateUi(Setting);

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QWidget *Setting)
    {
        Setting->setWindowTitle(QCoreApplication::translate("Setting", "Form", nullptr));
        label->setText(QCoreApplication::translate("Setting", "Protocols", nullptr));
        B3_pulse_mode->setText(QCoreApplication::translate("Setting", "Pulse Mode", nullptr));
        B3_simplified->setText(QCoreApplication::translate("Setting", "Simplified", nullptr));
        B3_advanced->setText(QCoreApplication::translate("Setting", "Advanced", nullptr));
        B3_custom->setText(QCoreApplication::translate("Setting", "Custom", nullptr));
        label_2->setText(QCoreApplication::translate("Setting", "Patient Data", nullptr));
        B3_patientdata_enable->setText(QCoreApplication::translate("Setting", "Enable", nullptr));
        B3_patientdata_export->setText(QCoreApplication::translate("Setting", "Export", nullptr));
        label_3->setText(QCoreApplication::translate("Setting", "Password", nullptr));
        B3_pass_enable->setText(QCoreApplication::translate("Setting", "Enable", nullptr));
        B3_pass_change->setText(QCoreApplication::translate("Setting", "Change", nullptr));
        label_4->setText(QCoreApplication::translate("Setting", "Interlock Key", nullptr));
        B3_interlockkey_enable->setText(QCoreApplication::translate("Setting", "Enable", nullptr));
        B3_service_engineer_area->setText(QCoreApplication::translate("Setting", "Service Engineer Area", nullptr));
        B3_usage_area->setText(QCoreApplication::translate("Setting", "Usage Area", nullptr));
        B3_dark_light->setText(QString());
        B3_back_to_home->setText(QCoreApplication::translate("Setting", "\360\237\241\220", nullptr));
        label_8->setText(QCoreApplication::translate("Setting", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
