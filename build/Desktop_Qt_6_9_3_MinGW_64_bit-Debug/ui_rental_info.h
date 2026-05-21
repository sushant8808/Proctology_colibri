/********************************************************************************
** Form generated from reading UI file 'rental_info.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENTAL_INFO_H
#define UI_RENTAL_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "home_button.h"

QT_BEGIN_NAMESPACE

class Ui_rental_info
{
public:
    QPushButton *B3_back_to_setting;
    QFrame *settingframe_1;
    home_button *back_to_home;

    void setupUi(QWidget *rental_info)
    {
        if (rental_info->objectName().isEmpty())
            rental_info->setObjectName("rental_info");
        rental_info->resize(800, 480);
        B3_back_to_setting = new QPushButton(rental_info);
        B3_back_to_setting->setObjectName("B3_back_to_setting");
        B3_back_to_setting->setGeometry(QRect(20, 10, 51, 40));
        QFont font;
        font.setPointSize(22);
        font.setBold(false);
        B3_back_to_setting->setFont(font);
        B3_back_to_setting->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B3_back_to_setting->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        settingframe_1 = new QFrame(rental_info);
        settingframe_1->setObjectName("settingframe_1");
        settingframe_1->setGeometry(QRect(20, 60, 760, 400));
        settingframe_1->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_1->setFrameShadow(QFrame::Shadow::Raised);
        back_to_home = new home_button(rental_info);
        back_to_home->setObjectName("back_to_home");
        back_to_home->setGeometry(QRect(730, 5, 50, 50));

        retranslateUi(rental_info);

        QMetaObject::connectSlotsByName(rental_info);
    } // setupUi

    void retranslateUi(QWidget *rental_info)
    {
        rental_info->setWindowTitle(QCoreApplication::translate("rental_info", "Form", nullptr));
        B3_back_to_setting->setText(QCoreApplication::translate("rental_info", "\360\237\241\220", nullptr));
        back_to_home->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class rental_info: public Ui_rental_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENTAL_INFO_H
