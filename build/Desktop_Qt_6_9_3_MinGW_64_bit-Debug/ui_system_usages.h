/********************************************************************************
** Form generated from reading UI file 'system_usages.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEM_USAGES_H
#define UI_SYSTEM_USAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "home_button.h"

QT_BEGIN_NAMESPACE

class Ui_system_usages
{
public:
    home_button *back_to_home;
    QLabel *label_8;
    QFrame *settingframe_1;
    QFrame *settingframe_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *system_timer;
    QLabel *active_timer_1470;
    QLabel *active_timer_980;
    QLabel *label_5;
    QPushButton *back_to_service_engineer_area;

    void setupUi(QWidget *system_usages)
    {
        if (system_usages->objectName().isEmpty())
            system_usages->setObjectName("system_usages");
        system_usages->resize(800, 480);
        back_to_home = new home_button(system_usages);
        back_to_home->setObjectName("back_to_home");
        back_to_home->setGeometry(QRect(730, 5, 50, 50));
        label_8 = new QLabel(system_usages);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(300, 10, 221, 40));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        settingframe_1 = new QFrame(system_usages);
        settingframe_1->setObjectName("settingframe_1");
        settingframe_1->setGeometry(QRect(20, 60, 760, 400));
        settingframe_1->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_1->setFrameShadow(QFrame::Shadow::Raised);
        settingframe_2 = new QFrame(settingframe_1);
        settingframe_2->setObjectName("settingframe_2");
        settingframe_2->setGeometry(QRect(180, 50, 365, 300));
        settingframe_2->setStyleSheet(QString::fromUtf8(""));
        settingframe_2->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_2->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(settingframe_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 90, 131, 41));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        label_3 = new QLabel(settingframe_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 150, 131, 41));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        label_4 = new QLabel(settingframe_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 210, 131, 41));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        system_timer = new QLabel(settingframe_2);
        system_timer->setObjectName("system_timer");
        system_timer->setGeometry(QRect(180, 90, 181, 41));
        system_timer->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 16pt;\n"
""));
        system_timer->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        active_timer_1470 = new QLabel(settingframe_2);
        active_timer_1470->setObjectName("active_timer_1470");
        active_timer_1470->setGeometry(QRect(180, 150, 181, 41));
        active_timer_1470->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 16pt;"));
        active_timer_980 = new QLabel(settingframe_2);
        active_timer_980->setObjectName("active_timer_980");
        active_timer_980->setGeometry(QRect(180, 210, 171, 41));
        active_timer_980->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 16pt;"));
        label_5 = new QLabel(settingframe_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 10, 241, 51));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        back_to_service_engineer_area = new QPushButton(system_usages);
        back_to_service_engineer_area->setObjectName("back_to_service_engineer_area");
        back_to_service_engineer_area->setGeometry(QRect(20, 10, 51, 40));
        QFont font;
        font.setPointSize(22);
        font.setBold(false);
        back_to_service_engineer_area->setFont(font);
        back_to_service_engineer_area->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        back_to_service_engineer_area->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));

        retranslateUi(system_usages);

        QMetaObject::connectSlotsByName(system_usages);
    } // setupUi

    void retranslateUi(QWidget *system_usages)
    {
        system_usages->setWindowTitle(QCoreApplication::translate("system_usages", "Form", nullptr));
        back_to_home->setText(QString());
        label_8->setText(QCoreApplication::translate("system_usages", "System Usages", nullptr));
        label_2->setText(QCoreApplication::translate("system_usages", "Total          :", nullptr));
        label_3->setText(QCoreApplication::translate("system_usages", "1470 nm   :", nullptr));
        label_4->setText(QCoreApplication::translate("system_usages", "980 nm     :", nullptr));
        system_timer->setText(QCoreApplication::translate("system_usages", "0", nullptr));
        active_timer_1470->setText(QCoreApplication::translate("system_usages", "0", nullptr));
        active_timer_980->setText(QCoreApplication::translate("system_usages", "0", nullptr));
        label_5->setText(QCoreApplication::translate("system_usages", "System Usage", nullptr));
        back_to_service_engineer_area->setText(QCoreApplication::translate("system_usages", "\360\237\241\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class system_usages: public Ui_system_usages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEM_USAGES_H
