/********************************************************************************
** Form generated from reading UI file 'calibration_screen.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATION_SCREEN_H
#define UI_CALIBRATION_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "home_button.h"

QT_BEGIN_NAMESPACE

class Ui_Calibration_screen
{
public:
    QFrame *settingframe_1;
    QFrame *settingframe_2;
    QLabel *label_5;
    QLabel *power_change_1470;
    QLabel *DAC_change_1470;
    home_button *pre_power_1470;
    home_button *next_power_1470;
    home_button *DAC_sub_1470;
    home_button *DAC_add_1470;
    QPushButton *save_1470;
    QPushButton *test_1470;
    QFrame *settingframe_4;
    QLabel *label_7;
    QLabel *power_change_980;
    QLabel *DAC_change_980;
    home_button *pre_power_980;
    home_button *next_power_980;
    home_button *DAC_sub_980;
    home_button *DAC_add_980;
    QPushButton *save_980;
    QPushButton *test_980;
    QPushButton *back_to_service_engineer_area;
    QLabel *label_8;
    home_button *back_to_home;

    void setupUi(QWidget *Calibration_screen)
    {
        if (Calibration_screen->objectName().isEmpty())
            Calibration_screen->setObjectName("Calibration_screen");
        Calibration_screen->resize(800, 480);
        settingframe_1 = new QFrame(Calibration_screen);
        settingframe_1->setObjectName("settingframe_1");
        settingframe_1->setGeometry(QRect(20, 60, 760, 400));
        settingframe_1->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_1->setFrameShadow(QFrame::Shadow::Raised);
        settingframe_2 = new QFrame(settingframe_1);
        settingframe_2->setObjectName("settingframe_2");
        settingframe_2->setGeometry(QRect(5, 5, 750, 192));
        settingframe_2->setStyleSheet(QString::fromUtf8(""));
        settingframe_2->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_2->setFrameShadow(QFrame::Shadow::Raised);
        label_5 = new QLabel(settingframe_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 15, 141, 30));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));
        power_change_1470 = new QLabel(settingframe_2);
        power_change_1470->setObjectName("power_change_1470");
        power_change_1470->setGeometry(QRect(75, 75, 155, 80));
        power_change_1470->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 52pt;"));
        power_change_1470->setAlignment(Qt::AlignmentFlag::AlignCenter);
        DAC_change_1470 = new QLabel(settingframe_2);
        DAC_change_1470->setObjectName("DAC_change_1470");
        DAC_change_1470->setGeometry(QRect(395, 90, 150, 50));
        DAC_change_1470->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 32pt;"));
        DAC_change_1470->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pre_power_1470 = new home_button(settingframe_2);
        pre_power_1470->setObjectName("pre_power_1470");
        pre_power_1470->setGeometry(QRect(25, 90, 50, 50));
        pre_power_1470->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        next_power_1470 = new home_button(settingframe_2);
        next_power_1470->setObjectName("next_power_1470");
        next_power_1470->setGeometry(QRect(235, 90, 50, 50));
        next_power_1470->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        DAC_sub_1470 = new home_button(settingframe_2);
        DAC_sub_1470->setObjectName("DAC_sub_1470");
        DAC_sub_1470->setGeometry(QRect(335, 90, 50, 50));
        DAC_sub_1470->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        DAC_add_1470 = new home_button(settingframe_2);
        DAC_add_1470->setObjectName("DAC_add_1470");
        DAC_add_1470->setGeometry(QRect(555, 90, 50, 50));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DAC_add_1470->sizePolicy().hasHeightForWidth());
        DAC_add_1470->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(22);
        DAC_add_1470->setFont(font);
        DAC_add_1470->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        DAC_add_1470->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        save_1470 = new QPushButton(settingframe_2);
        save_1470->setObjectName("save_1470");
        save_1470->setGeometry(QRect(625, 90, 101, 51));
        save_1470->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        test_1470 = new QPushButton(settingframe_2);
        test_1470->setObjectName("test_1470");
        test_1470->setGeometry(QRect(390, 10, 161, 51));
        test_1470->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        settingframe_4 = new QFrame(settingframe_1);
        settingframe_4->setObjectName("settingframe_4");
        settingframe_4->setGeometry(QRect(5, 203, 750, 192));
        settingframe_4->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_4->setFrameShadow(QFrame::Shadow::Raised);
        label_7 = new QLabel(settingframe_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 15, 141, 31));
        label_7->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));
        power_change_980 = new QLabel(settingframe_4);
        power_change_980->setObjectName("power_change_980");
        power_change_980->setGeometry(QRect(75, 75, 155, 80));
        power_change_980->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 52pt;"));
        power_change_980->setAlignment(Qt::AlignmentFlag::AlignCenter);
        DAC_change_980 = new QLabel(settingframe_4);
        DAC_change_980->setObjectName("DAC_change_980");
        DAC_change_980->setGeometry(QRect(395, 90, 150, 50));
        DAC_change_980->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 32pt;"));
        DAC_change_980->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pre_power_980 = new home_button(settingframe_4);
        pre_power_980->setObjectName("pre_power_980");
        pre_power_980->setGeometry(QRect(25, 90, 50, 50));
        pre_power_980->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        next_power_980 = new home_button(settingframe_4);
        next_power_980->setObjectName("next_power_980");
        next_power_980->setGeometry(QRect(235, 90, 50, 50));
        next_power_980->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        DAC_sub_980 = new home_button(settingframe_4);
        DAC_sub_980->setObjectName("DAC_sub_980");
        DAC_sub_980->setGeometry(QRect(335, 90, 50, 50));
        DAC_sub_980->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        DAC_add_980 = new home_button(settingframe_4);
        DAC_add_980->setObjectName("DAC_add_980");
        DAC_add_980->setGeometry(QRect(555, 90, 50, 50));
        sizePolicy.setHeightForWidth(DAC_add_980->sizePolicy().hasHeightForWidth());
        DAC_add_980->setSizePolicy(sizePolicy);
        DAC_add_980->setFont(font);
        DAC_add_980->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        DAC_add_980->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        save_980 = new QPushButton(settingframe_4);
        save_980->setObjectName("save_980");
        save_980->setGeometry(QRect(625, 90, 101, 51));
        save_980->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        test_980 = new QPushButton(settingframe_4);
        test_980->setObjectName("test_980");
        test_980->setGeometry(QRect(390, 20, 161, 51));
        test_980->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        back_to_service_engineer_area = new QPushButton(Calibration_screen);
        back_to_service_engineer_area->setObjectName("back_to_service_engineer_area");
        back_to_service_engineer_area->setGeometry(QRect(20, 10, 51, 40));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(false);
        back_to_service_engineer_area->setFont(font1);
        back_to_service_engineer_area->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        back_to_service_engineer_area->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8 = new QLabel(Calibration_screen);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(300, 10, 221, 40));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        back_to_home = new home_button(Calibration_screen);
        back_to_home->setObjectName("back_to_home");
        back_to_home->setGeometry(QRect(730, 5, 50, 50));

        retranslateUi(Calibration_screen);

        QMetaObject::connectSlotsByName(Calibration_screen);
    } // setupUi

    void retranslateUi(QWidget *Calibration_screen)
    {
        Calibration_screen->setWindowTitle(QCoreApplication::translate("Calibration_screen", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("Calibration_screen", "1470 nm", nullptr));
        power_change_1470->setText(QCoreApplication::translate("Calibration_screen", "00.0", nullptr));
        DAC_change_1470->setText(QCoreApplication::translate("Calibration_screen", "00000", nullptr));
        pre_power_1470->setText(QString());
        next_power_1470->setText(QString());
        DAC_sub_1470->setText(QString());
        DAC_add_1470->setText(QString());
        save_1470->setText(QCoreApplication::translate("Calibration_screen", "save", nullptr));
        test_1470->setText(QCoreApplication::translate("Calibration_screen", "Test", nullptr));
        label_7->setText(QCoreApplication::translate("Calibration_screen", "980 nm", nullptr));
        power_change_980->setText(QCoreApplication::translate("Calibration_screen", "00.0", nullptr));
        DAC_change_980->setText(QCoreApplication::translate("Calibration_screen", "00000", nullptr));
        pre_power_980->setText(QString());
        next_power_980->setText(QString());
        DAC_sub_980->setText(QString());
        DAC_add_980->setText(QString());
        save_980->setText(QCoreApplication::translate("Calibration_screen", "save", nullptr));
        test_980->setText(QCoreApplication::translate("Calibration_screen", "Test", nullptr));
        back_to_service_engineer_area->setText(QCoreApplication::translate("Calibration_screen", "\360\237\241\220", nullptr));
        label_8->setText(QCoreApplication::translate("Calibration_screen", "Calibration", nullptr));
        back_to_home->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Calibration_screen: public Ui_Calibration_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATION_SCREEN_H
