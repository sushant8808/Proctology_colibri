/********************************************************************************
** Form generated from reading UI file 'set_date_time.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_DATE_TIME_H
#define UI_SET_DATE_TIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include "home_button.h"

QT_BEGIN_NAMESPACE

class Ui_Set_date_time
{
public:
    home_button *back_to_home;
    QFrame *settingframe_1;
    QFrame *settingframe_2;
    QLabel *label_5;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QPushButton *applyButton;
    QLabel *label_8;
    QPushButton *back_to_service_engineer_area;

    void setupUi(QWidget *Set_date_time)
    {
        if (Set_date_time->objectName().isEmpty())
            Set_date_time->setObjectName("Set_date_time");
        Set_date_time->resize(800, 480);
        back_to_home = new home_button(Set_date_time);
        back_to_home->setObjectName("back_to_home");
        back_to_home->setGeometry(QRect(730, 5, 50, 50));
        settingframe_1 = new QFrame(Set_date_time);
        settingframe_1->setObjectName("settingframe_1");
        settingframe_1->setGeometry(QRect(20, 60, 760, 400));
        settingframe_1->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_1->setFrameShadow(QFrame::Shadow::Raised);
        settingframe_2 = new QFrame(settingframe_1);
        settingframe_2->setObjectName("settingframe_2");
        settingframe_2->setGeometry(QRect(5, 140, 750, 120));
        settingframe_2->setStyleSheet(QString::fromUtf8(""));
        settingframe_2->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_2->setFrameShadow(QFrame::Shadow::Raised);
        label_5 = new QLabel(settingframe_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 10, 241, 41));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        timeEdit = new QTimeEdit(settingframe_2);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(50, 60, 151, 41));
        dateEdit = new QDateEdit(settingframe_2);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(270, 60, 181, 41));
        applyButton = new QPushButton(settingframe_2);
        applyButton->setObjectName("applyButton");
        applyButton->setGeometry(QRect(530, 60, 121, 40));
        applyButton->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 20px;"));
        label_8 = new QLabel(Set_date_time);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(300, 10, 221, 40));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        back_to_service_engineer_area = new QPushButton(Set_date_time);
        back_to_service_engineer_area->setObjectName("back_to_service_engineer_area");
        back_to_service_engineer_area->setGeometry(QRect(20, 10, 51, 40));
        QFont font;
        font.setPointSize(22);
        font.setBold(false);
        back_to_service_engineer_area->setFont(font);
        back_to_service_engineer_area->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        back_to_service_engineer_area->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));

        retranslateUi(Set_date_time);

        QMetaObject::connectSlotsByName(Set_date_time);
    } // setupUi

    void retranslateUi(QWidget *Set_date_time)
    {
        Set_date_time->setWindowTitle(QCoreApplication::translate("Set_date_time", "Form", nullptr));
        back_to_home->setText(QString());
        label_5->setText(QCoreApplication::translate("Set_date_time", "Date & Time", nullptr));
        applyButton->setText(QCoreApplication::translate("Set_date_time", "Apply", nullptr));
        label_8->setText(QCoreApplication::translate("Set_date_time", "Set Date & Time", nullptr));
        back_to_service_engineer_area->setText(QCoreApplication::translate("Set_date_time", "\360\237\241\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Set_date_time: public Ui_Set_date_time {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_DATE_TIME_H
