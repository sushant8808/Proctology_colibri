/********************************************************************************
** Form generated from reading UI file 'service_engineer_area.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICE_ENGINEER_AREA_H
#define UI_SERVICE_ENGINEER_AREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_service_engineer_area
{
public:
    QFrame *settingframe_1;
    QPushButton *calibration;
    QFrame *settingframe_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *L_serial_no;
    QLabel *L_model;
    QLabel *version_show;
    QPushButton *set_date_time;
    QPushButton *system_usage;
    QPushButton *back_to_setting;
    QLabel *label_8;

    void setupUi(QWidget *service_engineer_area)
    {
        if (service_engineer_area->objectName().isEmpty())
            service_engineer_area->setObjectName("service_engineer_area");
        service_engineer_area->resize(800, 480);
        settingframe_1 = new QFrame(service_engineer_area);
        settingframe_1->setObjectName("settingframe_1");
        settingframe_1->setGeometry(QRect(20, 60, 760, 400));
        settingframe_1->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_1->setFrameShadow(QFrame::Shadow::Raised);
        calibration = new QPushButton(settingframe_1);
        calibration->setObjectName("calibration");
        calibration->setGeometry(QRect(485, 63, 220, 50));
        calibration->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        settingframe_2 = new QFrame(settingframe_1);
        settingframe_2->setObjectName("settingframe_2");
        settingframe_2->setGeometry(QRect(5, 5, 420, 390));
        settingframe_2->setStyleSheet(QString::fromUtf8(""));
        settingframe_2->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_2->setFrameShadow(QFrame::Shadow::Raised);
        label_5 = new QLabel(settingframe_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 20, 241, 41));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        label_6 = new QLabel(settingframe_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 110, 160, 41));
        label_6->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        label_7 = new QLabel(settingframe_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 190, 160, 41));
        label_7->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        label_9 = new QLabel(settingframe_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 270, 160, 41));
        label_9->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        L_serial_no = new QLabel(settingframe_2);
        L_serial_no->setObjectName("L_serial_no");
        L_serial_no->setGeometry(QRect(190, 190, 210, 40));
        L_serial_no->setStyleSheet(QString::fromUtf8(""));
        L_model = new QLabel(settingframe_2);
        L_model->setObjectName("L_model");
        L_model->setGeometry(QRect(190, 110, 210, 40));
        L_model->setStyleSheet(QString::fromUtf8(""));
        version_show = new QLabel(settingframe_2);
        version_show->setObjectName("version_show");
        version_show->setGeometry(QRect(190, 270, 210, 40));
        version_show->setStyleSheet(QString::fromUtf8(""));
        set_date_time = new QPushButton(settingframe_1);
        set_date_time->setObjectName("set_date_time");
        set_date_time->setGeometry(QRect(485, 175, 220, 50));
        set_date_time->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        system_usage = new QPushButton(settingframe_1);
        system_usage->setObjectName("system_usage");
        system_usage->setGeometry(QRect(485, 287, 220, 50));
        system_usage->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        back_to_setting = new QPushButton(service_engineer_area);
        back_to_setting->setObjectName("back_to_setting");
        back_to_setting->setGeometry(QRect(20, 10, 51, 40));
        QFont font;
        font.setPointSize(22);
        font.setBold(false);
        back_to_setting->setFont(font);
        back_to_setting->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        back_to_setting->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8 = new QLabel(service_engineer_area);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(230, 10, 331, 40));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(service_engineer_area);

        QMetaObject::connectSlotsByName(service_engineer_area);
    } // setupUi

    void retranslateUi(QWidget *service_engineer_area)
    {
        service_engineer_area->setWindowTitle(QCoreApplication::translate("service_engineer_area", "Form", nullptr));
        calibration->setText(QCoreApplication::translate("service_engineer_area", "Calibration", nullptr));
        label_5->setText(QCoreApplication::translate("service_engineer_area", "System Info", nullptr));
        label_6->setText(QCoreApplication::translate("service_engineer_area", "Model", nullptr));
        label_7->setText(QCoreApplication::translate("service_engineer_area", "Serial Number", nullptr));
        label_9->setText(QCoreApplication::translate("service_engineer_area", "Firmware Version", nullptr));
        L_serial_no->setText(QString());
        L_model->setText(QString());
        version_show->setText(QString());
        set_date_time->setText(QCoreApplication::translate("service_engineer_area", " Set Date and Time", nullptr));
        system_usage->setText(QCoreApplication::translate("service_engineer_area", "System Usage", nullptr));
        back_to_setting->setText(QCoreApplication::translate("service_engineer_area", "\360\237\241\220", nullptr));
        label_8->setText(QCoreApplication::translate("service_engineer_area", "Service Engineer Area", nullptr));
    } // retranslateUi

};

namespace Ui {
    class service_engineer_area: public Ui_service_engineer_area {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_ENGINEER_AREA_H
