/********************************************************************************
** Form generated from reading UI file 'newcustomprotocol.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCUSTOMPROTOCOL_H
#define UI_NEWCUSTOMPROTOCOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include "home_button.h"
#include "keyboard_bt.h"

QT_BEGIN_NAMESPACE

class Ui_newcustomprotocol
{
public:
    QFrame *homeframe_1;
    QFrame *homeframe_2;
    QLabel *L2_power;
    QLabel *L2_watts;
    QLabel *L2_980nm;
    QLabel *L2_1470nm;
    home_button *B2_980sub;
    home_button *B2_980add;
    home_button *B2_1470sub;
    home_button *B2_1470add;
    QLabel *L2_980_show;
    QLabel *L2_1470_show;
    QLabel *L2_watts_2;
    QFrame *homeframe_5;
    QLabel *label_2;
    QLabel *label;
    home_button *B2_on_time_sub;
    home_button *B2_on_time_add;
    home_button *B2_off_time_sub;
    home_button *B2_off_time_add;
    QLabel *L2_on_pulse_show;
    QLabel *L2_off_pulse_show;
    QCheckBox *B2_pulsemode;
    QLabel *L2_on_pulse_unit;
    QLabel *L2_off_pulse_unit;
    QFrame *homeframe_3;
    QLabel *L2_timer;
    QLabel *L2_seconds;
    home_button *B2_timer_add;
    home_button *B2_timer_sub;
    QRadioButton *B2_timer_on;
    QRadioButton *B2_timer_off;
    QLabel *L2_timer_show;
    QPushButton *B2_timer_reset;
    QPushButton *B2_timer_noreset;
    QPushButton *B2_save;
    QPushButton *B2_cancel;
    QLineEdit *Surgery_name;
    keyboard_bt *bt_surgery_name;
    QPushButton *B3_back_to_setting;
    home_button *B2_back_to_home;
    QLabel *new_protocol_label;
    QLabel *modify_protocol_label;

    void setupUi(QWidget *newcustomprotocol)
    {
        if (newcustomprotocol->objectName().isEmpty())
            newcustomprotocol->setObjectName("newcustomprotocol");
        newcustomprotocol->resize(800, 480);
        newcustomprotocol->setStyleSheet(QString::fromUtf8(""));
        homeframe_1 = new QFrame(newcustomprotocol);
        homeframe_1->setObjectName("homeframe_1");
        homeframe_1->setGeometry(QRect(20, 60, 760, 400));
        homeframe_1->setStyleSheet(QString::fromUtf8(""));
        homeframe_1->setFrameShape(QFrame::Shape::StyledPanel);
        homeframe_1->setFrameShadow(QFrame::Shadow::Raised);
        homeframe_2 = new QFrame(homeframe_1);
        homeframe_2->setObjectName("homeframe_2");
        homeframe_2->setGeometry(QRect(5, 5, 372, 190));
        homeframe_2->setStyleSheet(QString::fromUtf8(""));
        homeframe_2->setFrameShape(QFrame::Shape::StyledPanel);
        homeframe_2->setFrameShadow(QFrame::Shadow::Raised);
        L2_power = new QLabel(homeframe_2);
        L2_power->setObjectName("L2_power");
        L2_power->setGeometry(QRect(20, 15, 90, 25));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto")});
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        L2_power->setFont(font);
        L2_power->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        L2_watts = new QLabel(homeframe_2);
        L2_watts->setObjectName("L2_watts");
        L2_watts->setGeometry(QRect(212, 73, 31, 21));
        L2_watts->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        L2_980nm = new QLabel(homeframe_2);
        L2_980nm->setObjectName("L2_980nm");
        L2_980nm->setGeometry(QRect(30, 65, 80, 20));
        L2_980nm->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        L2_1470nm = new QLabel(homeframe_2);
        L2_1470nm->setObjectName("L2_1470nm");
        L2_1470nm->setGeometry(QRect(30, 130, 80, 20));
        L2_1470nm->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        B2_980sub = new home_button(homeframe_2);
        B2_980sub->setObjectName("B2_980sub");
        B2_980sub->setGeometry(QRect(250, 55, 40, 40));
        B2_980sub->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);border: 0px solid;\n"
"border-radius: 20px;"));
        B2_980add = new home_button(homeframe_2);
        B2_980add->setObjectName("B2_980add");
        B2_980add->setGeometry(QRect(310, 55, 40, 40));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(B2_980add->sizePolicy().hasHeightForWidth());
        B2_980add->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(9);
        B2_980add->setFont(font1);
        B2_980add->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B2_980add->setStyleSheet(QString::fromUtf8("border: 0px solid;\n"
"border-radius: 20px;\n"
"image: url(:/icons/plus.svg);\n"
""));
        B2_1470sub = new home_button(homeframe_2);
        B2_1470sub->setObjectName("B2_1470sub");
        B2_1470sub->setGeometry(QRect(250, 120, 40, 40));
        B2_1470sub->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);border: 0px solid;\n"
"border-radius: 20px;"));
        B2_1470add = new home_button(homeframe_2);
        B2_1470add->setObjectName("B2_1470add");
        B2_1470add->setGeometry(QRect(310, 120, 40, 40));
        B2_1470add->setStyleSheet(QString::fromUtf8("border: 0px solid;\n"
"border-radius: 20px;\n"
"image: url(:/icons/plus.svg);"));
        L2_980_show = new QLabel(homeframe_2);
        L2_980_show->setObjectName("L2_980_show");
        L2_980_show->setGeometry(QRect(110, 50, 101, 50));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto")});
        font2.setPointSize(40);
        font2.setItalic(false);
        L2_980_show->setFont(font2);
        L2_980_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 40pt;"));
        L2_980_show->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        L2_1470_show = new QLabel(homeframe_2);
        L2_1470_show->setObjectName("L2_1470_show");
        L2_1470_show->setGeometry(QRect(110, 115, 101, 50));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto")});
        font3.setPointSize(40);
        L2_1470_show->setFont(font3);
        L2_1470_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 40pt;"));
        L2_1470_show->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        L2_watts_2 = new QLabel(homeframe_2);
        L2_watts_2->setObjectName("L2_watts_2");
        L2_watts_2->setGeometry(QRect(212, 138, 31, 21));
        L2_watts_2->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        homeframe_5 = new QFrame(homeframe_1);
        homeframe_5->setObjectName("homeframe_5");
        homeframe_5->setGeometry(QRect(383, 5, 372, 251));
        homeframe_5->setStyleSheet(QString::fromUtf8(""));
        homeframe_5->setFrameShape(QFrame::Shape::StyledPanel);
        homeframe_5->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(homeframe_5);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 151, 31));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        label = new QLabel(homeframe_5);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 150, 151, 31));
        label->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        B2_on_time_sub = new home_button(homeframe_5);
        B2_on_time_sub->setObjectName("B2_on_time_sub");
        B2_on_time_sub->setGeometry(QRect(250, 90, 40, 40));
        B2_on_time_sub->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);border: 0px solid;\n"
"border-radius: 20px;"));
        B2_on_time_add = new home_button(homeframe_5);
        B2_on_time_add->setObjectName("B2_on_time_add");
        B2_on_time_add->setGeometry(QRect(310, 90, 40, 40));
        sizePolicy.setHeightForWidth(B2_on_time_add->sizePolicy().hasHeightForWidth());
        B2_on_time_add->setSizePolicy(sizePolicy);
        B2_on_time_add->setFont(font1);
        B2_on_time_add->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B2_on_time_add->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);border: 0px solid;\n"
"border-radius: 20px;"));
        B2_off_time_sub = new home_button(homeframe_5);
        B2_off_time_sub->setObjectName("B2_off_time_sub");
        B2_off_time_sub->setGeometry(QRect(250, 190, 40, 40));
        B2_off_time_sub->setStyleSheet(QString::fromUtf8("border: 0px solid;\n"
"image: url(:/icons/negative.svg);\n"
"border-radius: 20px;"));
        B2_off_time_add = new home_button(homeframe_5);
        B2_off_time_add->setObjectName("B2_off_time_add");
        B2_off_time_add->setGeometry(QRect(310, 190, 40, 40));
        B2_off_time_add->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);border: 0px solid;\n"
"border-radius: 20px;"));
        L2_on_pulse_show = new QLabel(homeframe_5);
        L2_on_pulse_show->setObjectName("L2_on_pulse_show");
        L2_on_pulse_show->setGeometry(QRect(20, 80, 111, 60));
        L2_on_pulse_show->setFont(font2);
        L2_on_pulse_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 40pt;"));
        L2_on_pulse_show->setAlignment(Qt::AlignmentFlag::AlignCenter);
        L2_off_pulse_show = new QLabel(homeframe_5);
        L2_off_pulse_show->setObjectName("L2_off_pulse_show");
        L2_off_pulse_show->setGeometry(QRect(20, 180, 111, 60));
        L2_off_pulse_show->setFont(font3);
        L2_off_pulse_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 40pt;"));
        L2_off_pulse_show->setAlignment(Qt::AlignmentFlag::AlignCenter);
        B2_pulsemode = new QCheckBox(homeframe_5);
        B2_pulsemode->setObjectName("B2_pulsemode");
        B2_pulsemode->setGeometry(QRect(20, 15, 141, 21));
        B2_pulsemode->setMouseTracking(false);
        B2_pulsemode->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        L2_on_pulse_unit = new QLabel(homeframe_5);
        L2_on_pulse_unit->setObjectName("L2_on_pulse_unit");
        L2_on_pulse_unit->setGeometry(QRect(130, 107, 31, 21));
        L2_on_pulse_unit->setStyleSheet(QString::fromUtf8("font-size:20px;"));
        L2_off_pulse_unit = new QLabel(homeframe_5);
        L2_off_pulse_unit->setObjectName("L2_off_pulse_unit");
        L2_off_pulse_unit->setGeometry(QRect(130, 205, 31, 21));
        L2_off_pulse_unit->setStyleSheet(QString::fromUtf8("font-size:20px;"));
        homeframe_3 = new QFrame(homeframe_1);
        homeframe_3->setObjectName("homeframe_3");
        homeframe_3->setGeometry(QRect(5, 200, 372, 195));
        homeframe_3->setStyleSheet(QString::fromUtf8(""));
        homeframe_3->setFrameShape(QFrame::Shape::StyledPanel);
        homeframe_3->setFrameShadow(QFrame::Shadow::Raised);
        L2_timer = new QLabel(homeframe_3);
        L2_timer->setObjectName("L2_timer");
        L2_timer->setGeometry(QRect(20, 15, 80, 25));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Roboto")});
        font4.setPointSize(22);
        font4.setBold(false);
        L2_timer->setFont(font4);
        L2_timer->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        L2_seconds = new QLabel(homeframe_3);
        L2_seconds->setObjectName("L2_seconds");
        L2_seconds->setGeometry(QRect(150, 120, 31, 21));
        L2_seconds->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        B2_timer_add = new home_button(homeframe_3);
        B2_timer_add->setObjectName("B2_timer_add");
        B2_timer_add->setGeometry(QRect(310, 100, 40, 40));
        B2_timer_add->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);border: 0px solid;\n"
"border-radius: 20px;"));
        B2_timer_sub = new home_button(homeframe_3);
        B2_timer_sub->setObjectName("B2_timer_sub");
        B2_timer_sub->setGeometry(QRect(250, 100, 40, 40));
        B2_timer_sub->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);border: 0px solid;\n"
"border-radius: 20px;"));
        B2_timer_on = new QRadioButton(homeframe_3);
        B2_timer_on->setObjectName("B2_timer_on");
        B2_timer_on->setGeometry(QRect(20, 110, 90, 21));
        B2_timer_on->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        B2_timer_off = new QRadioButton(homeframe_3);
        B2_timer_off->setObjectName("B2_timer_off");
        B2_timer_off->setGeometry(QRect(20, 60, 90, 21));
        B2_timer_off->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        L2_timer_show = new QLabel(homeframe_3);
        L2_timer_show->setObjectName("L2_timer_show");
        L2_timer_show->setGeometry(QRect(50, 95, 110, 50));
        L2_timer_show->setFont(font3);
        L2_timer_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 40pt;"));
        L2_timer_show->setAlignment(Qt::AlignmentFlag::AlignCenter);
        B2_timer_reset = new QPushButton(homeframe_3);
        B2_timer_reset->setObjectName("B2_timer_reset");
        B2_timer_reset->setGeometry(QRect(20, 155, 100, 30));
        B2_timer_reset->setStyleSheet(QString::fromUtf8("border: 0px solid;\n"
"border-top-left-radius: 15px;\n"
"border-bottom-left-radius: 15px;\n"
"font-size: 14pt;"));
        B2_timer_reset->setAutoExclusive(false);
        B2_timer_noreset = new QPushButton(homeframe_3);
        B2_timer_noreset->setObjectName("B2_timer_noreset");
        B2_timer_noreset->setGeometry(QRect(122, 155, 100, 30));
        B2_timer_noreset->setStyleSheet(QString::fromUtf8("border: 0px solid;\n"
"border-top-right-radius: 15px;\n"
"border-bottom-right-radius: 15px;\n"
"font-size: 14pt;"));
        B2_timer_noreset->setAutoExclusive(false);
        B2_save = new QPushButton(homeframe_1);
        B2_save->setObjectName("B2_save");
        B2_save->setGeometry(QRect(595, 340, 120, 40));
        B2_save->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 20px;"));
        B2_cancel = new QPushButton(homeframe_1);
        B2_cancel->setObjectName("B2_cancel");
        B2_cancel->setGeometry(QRect(425, 340, 120, 40));
        B2_cancel->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 20px;"));
        Surgery_name = new QLineEdit(homeframe_1);
        Surgery_name->setObjectName("Surgery_name");
        Surgery_name->setGeometry(QRect(383, 280, 321, 40));
        bt_surgery_name = new keyboard_bt(homeframe_1);
        bt_surgery_name->setObjectName("bt_surgery_name");
        bt_surgery_name->setGeometry(QRect(715, 285, 30, 30));
        B3_back_to_setting = new QPushButton(newcustomprotocol);
        B3_back_to_setting->setObjectName("B3_back_to_setting");
        B3_back_to_setting->setGeometry(QRect(20, 10, 51, 40));
        QFont font5;
        font5.setPointSize(22);
        font5.setBold(false);
        B3_back_to_setting->setFont(font5);
        B3_back_to_setting->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B3_back_to_setting->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        B2_back_to_home = new home_button(newcustomprotocol);
        B2_back_to_home->setObjectName("B2_back_to_home");
        B2_back_to_home->setGeometry(QRect(730, 5, 50, 50));
        new_protocol_label = new QLabel(newcustomprotocol);
        new_protocol_label->setObjectName("new_protocol_label");
        new_protocol_label->setGeometry(QRect(210, 10, 380, 41));
        new_protocol_label->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        modify_protocol_label = new QLabel(newcustomprotocol);
        modify_protocol_label->setObjectName("modify_protocol_label");
        modify_protocol_label->setGeometry(QRect(210, 10, 380, 40));
        modify_protocol_label->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));

        retranslateUi(newcustomprotocol);

        QMetaObject::connectSlotsByName(newcustomprotocol);
    } // setupUi

    void retranslateUi(QWidget *newcustomprotocol)
    {
        newcustomprotocol->setWindowTitle(QCoreApplication::translate("newcustomprotocol", "Form", nullptr));
        L2_power->setText(QCoreApplication::translate("newcustomprotocol", "Power", nullptr));
        L2_watts->setText(QCoreApplication::translate("newcustomprotocol", "W", nullptr));
        L2_980nm->setText(QCoreApplication::translate("newcustomprotocol", "980 nm", nullptr));
        L2_1470nm->setText(QCoreApplication::translate("newcustomprotocol", "1470 nm", nullptr));
        B2_980sub->setText(QString());
        B2_980add->setText(QString());
        B2_1470sub->setText(QString());
        B2_1470add->setText(QString());
        L2_980_show->setText(QCoreApplication::translate("newcustomprotocol", "15.0", nullptr));
        L2_1470_show->setText(QCoreApplication::translate("newcustomprotocol", "15.0", nullptr));
        L2_watts_2->setText(QCoreApplication::translate("newcustomprotocol", "W", nullptr));
        label_2->setText(QCoreApplication::translate("newcustomprotocol", "ON time", nullptr));
        label->setText(QCoreApplication::translate("newcustomprotocol", "OFF time", nullptr));
        B2_on_time_sub->setText(QString());
        B2_on_time_add->setText(QString());
        B2_off_time_sub->setText(QString());
        B2_off_time_add->setText(QString());
        L2_on_pulse_show->setText(QCoreApplication::translate("newcustomprotocol", "11.5", nullptr));
        L2_off_pulse_show->setText(QCoreApplication::translate("newcustomprotocol", "11.5", nullptr));
        B2_pulsemode->setText(QCoreApplication::translate("newcustomprotocol", "Pulse Mode", nullptr));
        L2_on_pulse_unit->setText(QCoreApplication::translate("newcustomprotocol", "ms", nullptr));
        L2_off_pulse_unit->setText(QCoreApplication::translate("newcustomprotocol", "ms", nullptr));
        L2_timer->setText(QCoreApplication::translate("newcustomprotocol", "Timer", nullptr));
        L2_seconds->setText(QCoreApplication::translate("newcustomprotocol", "S", nullptr));
        B2_timer_add->setText(QString());
        B2_timer_sub->setText(QString());
        B2_timer_on->setText(QString());
        B2_timer_off->setText(QCoreApplication::translate("newcustomprotocol", "Off", nullptr));
        L2_timer_show->setText(QCoreApplication::translate("newcustomprotocol", "120", nullptr));
        B2_timer_reset->setText(QCoreApplication::translate("newcustomprotocol", "Reset", nullptr));
        B2_timer_noreset->setText(QCoreApplication::translate("newcustomprotocol", "No Reset", nullptr));
        B2_save->setText(QCoreApplication::translate("newcustomprotocol", "Save", nullptr));
        B2_cancel->setText(QCoreApplication::translate("newcustomprotocol", "Cancel", nullptr));
        bt_surgery_name->setText(QString());
        B3_back_to_setting->setText(QCoreApplication::translate("newcustomprotocol", "\360\237\241\220", nullptr));
        B2_back_to_home->setText(QString());
        new_protocol_label->setText(QCoreApplication::translate("newcustomprotocol", "New Custom Protocol", nullptr));
        modify_protocol_label->setText(QCoreApplication::translate("newcustomprotocol", "Modify Custom Protocol", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newcustomprotocol: public Ui_newcustomprotocol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCUSTOMPROTOCOL_H
