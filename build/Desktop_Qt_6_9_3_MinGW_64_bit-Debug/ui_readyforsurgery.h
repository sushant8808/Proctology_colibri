/********************************************************************************
** Form generated from reading UI file 'readyforsurgery.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READYFORSURGERY_H
#define UI_READYFORSURGERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "home_button.h"

QT_BEGIN_NAMESPACE

class Ui_ReadyForSurgery
{
public:
    QFrame *readysurgery_1;
    QFrame *readysurgery_2;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *L5_980nm;
    QLabel *L5_1470nm;
    QLabel *L5_timer_sec;
    QLabel *L5_timer_state;
    QLabel *L5_pulse_on;
    QLabel *L5_energy;
    QLabel *label_7;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *L5_pulse_off;
    QFrame *line_5;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *L2_on_pulse_unit;
    QLabel *L2_off_pulse_unit;
    QFrame *readysurgery_3;
    QPushButton *B5_reset;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *L5_store_1;
    QLabel *L5_store_5;
    QLabel *L5_store_2;
    QLabel *L5_store_3;
    QLabel *L5_store_4;
    QLabel *L5_store_6;
    QLabel *L5_store_7;
    QLabel *L5_store_8;
    QLabel *L5_total_energy;
    QLabel *L5_energy_deliverd;
    QPushButton *pushButton;
    QFrame *readysurgery_4;
    QLabel *label_17;
    QLabel *label_16;
    QFrame *F5_timer;
    QPushButton *B5_to_standby;
    QPushButton *B5_pause;
    QPushButton *B5_change;
    QLabel *L5_ready;
    QFrame *homeframe_7;
    home_button *B5_aimingbeam;
    home_button *B5_sound;
    home_button *B5_brightness;

    void setupUi(QWidget *ReadyForSurgery)
    {
        if (ReadyForSurgery->objectName().isEmpty())
            ReadyForSurgery->setObjectName("ReadyForSurgery");
        ReadyForSurgery->resize(800, 480);
        ReadyForSurgery->setStyleSheet(QString::fromUtf8(""));
        readysurgery_1 = new QFrame(ReadyForSurgery);
        readysurgery_1->setObjectName("readysurgery_1");
        readysurgery_1->setGeometry(QRect(20, 70, 760, 390));
        readysurgery_1->setFrameShape(QFrame::Shape::StyledPanel);
        readysurgery_1->setFrameShadow(QFrame::Shadow::Raised);
        readysurgery_2 = new QFrame(readysurgery_1);
        readysurgery_2->setObjectName("readysurgery_2");
        readysurgery_2->setGeometry(QRect(5, 5, 280, 325));
        readysurgery_2->setStyleSheet(QString::fromUtf8(""));
        readysurgery_2->setFrameShape(QFrame::Shape::StyledPanel);
        readysurgery_2->setFrameShadow(QFrame::Shadow::Raised);
        label_1 = new QLabel(readysurgery_2);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(20, 10, 70, 25));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto")});
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        label_1->setFont(font);
        label_1->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        label_2 = new QLabel(readysurgery_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 45, 31, 21));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        label_6 = new QLabel(readysurgery_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(250, 119, 31, 21));
        label_6->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        label_5 = new QLabel(readysurgery_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 115, 70, 25));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        label_8 = new QLabel(readysurgery_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 154, 131, 25));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto")});
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("font-size: 12pt;"));
        label_9 = new QLabel(readysurgery_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 228, 141, 25));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        label_11 = new QLabel(readysurgery_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(250, 194, 31, 21));
        label_11->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        label_10 = new QLabel(readysurgery_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 185, 81, 31));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        label_3 = new QLabel(readysurgery_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 77, 61, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto")});
        font2.setPointSize(12);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("font-size: 12pt;"));
        label_4 = new QLabel(readysurgery_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 40, 71, 20));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("font-size: 12pt;"));
        L5_980nm = new QLabel(readysurgery_2);
        L5_980nm->setObjectName("L5_980nm");
        L5_980nm->setGeometry(QRect(140, 72, 101, 31));
        L5_980nm->setStyleSheet(QString::fromUtf8("font-size:22pt;\n"
"color: rgb(50, 155, 255);"));
        L5_980nm->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        L5_1470nm = new QLabel(readysurgery_2);
        L5_1470nm->setObjectName("L5_1470nm");
        L5_1470nm->setGeometry(QRect(140, 35, 101, 31));
        L5_1470nm->setStyleSheet(QString::fromUtf8("font-size:22pt;\n"
"color: rgb(50, 155, 255);"));
        L5_1470nm->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop|Qt::AlignmentFlag::AlignTrailing);
        L5_timer_sec = new QLabel(readysurgery_2);
        L5_timer_sec->setObjectName("L5_timer_sec");
        L5_timer_sec->setGeometry(QRect(140, 110, 101, 31));
        L5_timer_sec->setStyleSheet(QString::fromUtf8("font-size:22pt;\n"
"color: rgb(50, 155, 255);"));
        L5_timer_sec->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        L5_timer_state = new QLabel(readysurgery_2);
        L5_timer_state->setObjectName("L5_timer_state");
        L5_timer_state->setGeometry(QRect(160, 150, 91, 26));
        L5_timer_state->setStyleSheet(QString::fromUtf8("font-size: 18pt;\n"
"color: rgb(50, 155, 255);"));
        L5_timer_state->setAlignment(Qt::AlignmentFlag::AlignCenter);
        L5_pulse_on = new QLabel(readysurgery_2);
        L5_pulse_on->setObjectName("L5_pulse_on");
        L5_pulse_on->setGeometry(QRect(140, 250, 101, 31));
        L5_pulse_on->setStyleSheet(QString::fromUtf8("font-size:22pt;\n"
"color: rgb(50, 155, 255);"));
        L5_pulse_on->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        L5_energy = new QLabel(readysurgery_2);
        L5_energy->setObjectName("L5_energy");
        L5_energy->setGeometry(QRect(140, 185, 101, 31));
        L5_energy->setStyleSheet(QString::fromUtf8("font-size:22pt;\n"
"color: rgb(50, 155, 255);"));
        L5_energy->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_7 = new QLabel(readysurgery_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(250, 80, 31, 21));
        label_7->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        line = new QFrame(readysurgery_2);
        line->setObjectName("line");
        line->setGeometry(QRect(20, 65, 240, 10));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(readysurgery_2);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(20, 100, 240, 10));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(readysurgery_2);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(20, 178, 240, 10));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(readysurgery_2);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(20, 213, 240, 10));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        L5_pulse_off = new QLabel(readysurgery_2);
        L5_pulse_off->setObjectName("L5_pulse_off");
        L5_pulse_off->setGeometry(QRect(140, 290, 101, 31));
        L5_pulse_off->setStyleSheet(QString::fromUtf8("font-size:22pt;\n"
"color: rgb(50, 155, 255);"));
        L5_pulse_off->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        line_5 = new QFrame(readysurgery_2);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(20, 280, 240, 10));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        label_18 = new QLabel(readysurgery_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(30, 260, 71, 20));
        label_18->setFont(font2);
        label_18->setStyleSheet(QString::fromUtf8("font-size: 12pt;"));
        label_19 = new QLabel(readysurgery_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(30, 299, 71, 20));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("font-size: 12pt;"));
        L2_on_pulse_unit = new QLabel(readysurgery_2);
        L2_on_pulse_unit->setObjectName("L2_on_pulse_unit");
        L2_on_pulse_unit->setGeometry(QRect(250, 260, 31, 21));
        L2_on_pulse_unit->setStyleSheet(QString::fromUtf8("font-size:14pt;"));
        L2_off_pulse_unit = new QLabel(readysurgery_2);
        L2_off_pulse_unit->setObjectName("L2_off_pulse_unit");
        L2_off_pulse_unit->setGeometry(QRect(250, 300, 31, 21));
        L2_off_pulse_unit->setStyleSheet(QString::fromUtf8("font-size:14pt;"));
        readysurgery_3 = new QFrame(readysurgery_1);
        readysurgery_3->setObjectName("readysurgery_3");
        readysurgery_3->setGeometry(QRect(290, 5, 465, 265));
        readysurgery_3->setStyleSheet(QString::fromUtf8(""));
        readysurgery_3->setFrameShape(QFrame::Shape::StyledPanel);
        readysurgery_3->setFrameShadow(QFrame::Shadow::Raised);
        B5_reset = new QPushButton(readysurgery_3);
        B5_reset->setObjectName("B5_reset");
        B5_reset->setGeometry(QRect(320, 40, 131, 50));
        B5_reset->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        label_13 = new QLabel(readysurgery_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(125, 58, 31, 21));
        label_13->setStyleSheet(QString::fromUtf8("font-size: 14pt;"));
        label_12 = new QLabel(readysurgery_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 10, 191, 25));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        label_15 = new QLabel(readysurgery_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(150, 230, 31, 21));
        label_15->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        label_14 = new QLabel(readysurgery_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 175, 141, 31));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        L5_store_1 = new QLabel(readysurgery_3);
        L5_store_1->setObjectName("L5_store_1");
        L5_store_1->setGeometry(QRect(25, 104, 85, 25));
        L5_store_1->setStyleSheet(QString::fromUtf8("font-size:20pt;"));
        L5_store_5 = new QLabel(readysurgery_3);
        L5_store_5->setObjectName("L5_store_5");
        L5_store_5->setGeometry(QRect(25, 139, 85, 25));
        L5_store_5->setStyleSheet(QString::fromUtf8("font-size:20pt;"));
        L5_store_2 = new QLabel(readysurgery_3);
        L5_store_2->setObjectName("L5_store_2");
        L5_store_2->setGeometry(QRect(135, 104, 85, 25));
        L5_store_2->setStyleSheet(QString::fromUtf8("font-size:20pt;"));
        L5_store_3 = new QLabel(readysurgery_3);
        L5_store_3->setObjectName("L5_store_3");
        L5_store_3->setGeometry(QRect(245, 104, 85, 25));
        L5_store_3->setStyleSheet(QString::fromUtf8("font-size:20pt;"));
        L5_store_4 = new QLabel(readysurgery_3);
        L5_store_4->setObjectName("L5_store_4");
        L5_store_4->setGeometry(QRect(355, 104, 85, 25));
        L5_store_4->setStyleSheet(QString::fromUtf8("font-size:20pt;"));
        L5_store_6 = new QLabel(readysurgery_3);
        L5_store_6->setObjectName("L5_store_6");
        L5_store_6->setGeometry(QRect(135, 139, 85, 25));
        L5_store_6->setStyleSheet(QString::fromUtf8("font-size:20pt;"));
        L5_store_7 = new QLabel(readysurgery_3);
        L5_store_7->setObjectName("L5_store_7");
        L5_store_7->setGeometry(QRect(245, 139, 85, 25));
        L5_store_7->setStyleSheet(QString::fromUtf8("font-size:20pt;"));
        L5_store_8 = new QLabel(readysurgery_3);
        L5_store_8->setObjectName("L5_store_8");
        L5_store_8->setGeometry(QRect(355, 139, 85, 25));
        L5_store_8->setStyleSheet(QString::fromUtf8("font-size:20pt;"));
        L5_total_energy = new QLabel(readysurgery_3);
        L5_total_energy->setObjectName("L5_total_energy");
        L5_total_energy->setGeometry(QRect(20, 203, 120, 61));
        L5_total_energy->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 40pt;"));
        L5_total_energy->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing);
        L5_energy_deliverd = new QLabel(readysurgery_3);
        L5_energy_deliverd->setObjectName("L5_energy_deliverd");
        L5_energy_deliverd->setGeometry(QRect(50, 50, 70, 30));
        L5_energy_deliverd->setStyleSheet(QString::fromUtf8("font-size:24pt;\n"
"color: rgb(50, 155, 255);"));
        L5_energy_deliverd->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        pushButton = new QPushButton(readysurgery_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(370, 180, 81, 71));
        pushButton->setStyleSheet(QString::fromUtf8("font-size:22px;"));
        readysurgery_4 = new QFrame(readysurgery_1);
        readysurgery_4->setObjectName("readysurgery_4");
        readysurgery_4->setGeometry(QRect(535, 275, 220, 110));
        readysurgery_4->setStyleSheet(QString::fromUtf8(""));
        readysurgery_4->setFrameShape(QFrame::Shape::StyledPanel);
        readysurgery_4->setFrameShadow(QFrame::Shadow::Raised);
        label_17 = new QLabel(readysurgery_4);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(20, 60, 71, 20));
        label_17->setStyleSheet(QString::fromUtf8("font-size: 12pt;"));
        label_16 = new QLabel(readysurgery_4);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 30, 70, 25));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        F5_timer = new QFrame(readysurgery_4);
        F5_timer->setObjectName("F5_timer");
        F5_timer->setGeometry(QRect(120, 10, 90, 90));
        F5_timer->setFrameShape(QFrame::Shape::StyledPanel);
        F5_timer->setFrameShadow(QFrame::Shadow::Raised);
        B5_to_standby = new QPushButton(readysurgery_1);
        B5_to_standby->setObjectName("B5_to_standby");
        B5_to_standby->setGeometry(QRect(310, 335, 200, 50));
        B5_to_standby->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B5_pause = new QPushButton(readysurgery_1);
        B5_pause->setObjectName("B5_pause");
        B5_pause->setGeometry(QRect(310, 275, 200, 50));
        B5_pause->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B5_change = new QPushButton(readysurgery_1);
        B5_change->setObjectName("B5_change");
        B5_change->setGeometry(QRect(65, 335, 160, 50));
        B5_change->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        L5_ready = new QLabel(ReadyForSurgery);
        L5_ready->setObjectName("L5_ready");
        L5_ready->setGeometry(QRect(20, 20, 271, 30));
        homeframe_7 = new QFrame(ReadyForSurgery);
        homeframe_7->setObjectName("homeframe_7");
        homeframe_7->setGeometry(QRect(590, 5, 190, 60));
        homeframe_7->setFrameShape(QFrame::Shape::StyledPanel);
        homeframe_7->setFrameShadow(QFrame::Shadow::Raised);
        B5_aimingbeam = new home_button(homeframe_7);
        B5_aimingbeam->setObjectName("B5_aimingbeam");
        B5_aimingbeam->setGeometry(QRect(10, 5, 50, 50));
        B5_sound = new home_button(homeframe_7);
        B5_sound->setObjectName("B5_sound");
        B5_sound->setGeometry(QRect(70, 5, 50, 50));
        B5_sound->setStyleSheet(QString::fromUtf8(""));
        B5_brightness = new home_button(homeframe_7);
        B5_brightness->setObjectName("B5_brightness");
        B5_brightness->setGeometry(QRect(130, 5, 50, 50));

        retranslateUi(ReadyForSurgery);

        QMetaObject::connectSlotsByName(ReadyForSurgery);
    } // setupUi

    void retranslateUi(QWidget *ReadyForSurgery)
    {
        ReadyForSurgery->setWindowTitle(QCoreApplication::translate("ReadyForSurgery", "Form", nullptr));
        label_1->setText(QCoreApplication::translate("ReadyForSurgery", "Power", nullptr));
        label_2->setText(QCoreApplication::translate("ReadyForSurgery", "W", nullptr));
        label_6->setText(QCoreApplication::translate("ReadyForSurgery", "S", nullptr));
        label_5->setText(QCoreApplication::translate("ReadyForSurgery", "Timer", nullptr));
        label_8->setText(QCoreApplication::translate("ReadyForSurgery", "Timer State", nullptr));
        label_9->setText(QCoreApplication::translate("ReadyForSurgery", "Pulse Mode", nullptr));
        label_11->setText(QCoreApplication::translate("ReadyForSurgery", "J", nullptr));
        label_10->setText(QCoreApplication::translate("ReadyForSurgery", "Energy", nullptr));
        label_3->setText(QCoreApplication::translate("ReadyForSurgery", "980 nm", nullptr));
        label_4->setText(QCoreApplication::translate("ReadyForSurgery", "1470 nm", nullptr));
        L5_980nm->setText(QCoreApplication::translate("ReadyForSurgery", "15.0", nullptr));
        L5_1470nm->setText(QCoreApplication::translate("ReadyForSurgery", "15.0", nullptr));
        L5_timer_sec->setText(QCoreApplication::translate("ReadyForSurgery", "120", nullptr));
        L5_timer_state->setText(QCoreApplication::translate("ReadyForSurgery", "Reset", nullptr));
        L5_pulse_on->setText(QCoreApplication::translate("ReadyForSurgery", "000", nullptr));
        L5_energy->setText(QCoreApplication::translate("ReadyForSurgery", "0000.0", nullptr));
        label_7->setText(QCoreApplication::translate("ReadyForSurgery", "W", nullptr));
        L5_pulse_off->setText(QCoreApplication::translate("ReadyForSurgery", "000", nullptr));
        label_18->setText(QCoreApplication::translate("ReadyForSurgery", "ON Time", nullptr));
        label_19->setText(QCoreApplication::translate("ReadyForSurgery", "OFF Time", nullptr));
        L2_on_pulse_unit->setText(QCoreApplication::translate("ReadyForSurgery", "ms", nullptr));
        L2_off_pulse_unit->setText(QCoreApplication::translate("ReadyForSurgery", "ms", nullptr));
        B5_reset->setText(QCoreApplication::translate("ReadyForSurgery", "Reset", nullptr));
        label_13->setText(QCoreApplication::translate("ReadyForSurgery", "J", nullptr));
        label_12->setText(QCoreApplication::translate("ReadyForSurgery", "Delivered Energy", nullptr));
        label_15->setText(QCoreApplication::translate("ReadyForSurgery", "J", nullptr));
        label_14->setText(QCoreApplication::translate("ReadyForSurgery", "Total Energy", nullptr));
        L5_store_1->setText(QString());
        L5_store_5->setText(QString());
        L5_store_2->setText(QString());
        L5_store_3->setText(QString());
        L5_store_4->setText(QString());
        L5_store_6->setText(QString());
        L5_store_7->setText(QString());
        L5_store_8->setText(QString());
        L5_total_energy->setText(QCoreApplication::translate("ReadyForSurgery", "0000", nullptr));
        L5_energy_deliverd->setText(QCoreApplication::translate("ReadyForSurgery", "000", nullptr));
        pushButton->setText(QCoreApplication::translate("ReadyForSurgery", "Laser\n"
"OFF", nullptr));
        label_17->setText(QCoreApplication::translate("ReadyForSurgery", "(Seconds)", nullptr));
        label_16->setText(QCoreApplication::translate("ReadyForSurgery", "Timer", nullptr));
        B5_to_standby->setText(QCoreApplication::translate("ReadyForSurgery", "End Surgery", nullptr));
        B5_pause->setText(QCoreApplication::translate("ReadyForSurgery", " Pause\n"
"Surgery", nullptr));
        B5_change->setText(QCoreApplication::translate("ReadyForSurgery", "Change", nullptr));
        L5_ready->setText(QString());
        B5_aimingbeam->setText(QString());
        B5_sound->setText(QString());
        B5_brightness->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ReadyForSurgery: public Ui_ReadyForSurgery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READYFORSURGERY_H
