/********************************************************************************
** Form generated from reading UI file 'pulsemode.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PULSEMODE_H
#define UI_PULSEMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "home_button.h"

QT_BEGIN_NAMESPACE

class Ui_PulseMode
{
public:
    QFrame *F1_pulsemode;
    QFrame *F3_pulsemode;
    QLabel *change_low_value;
    home_button *inc_low_value;
    home_button *dec_low_value;
    QLabel *L2_min_pulse_unit;
    home_button *inc_high_value;
    QLabel *change_high_value;
    QLabel *L2_max_pulse_unit;
    home_button *dec_high_value;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *B3_back_to_setting;
    QLabel *label_8;

    void setupUi(QWidget *PulseMode)
    {
        if (PulseMode->objectName().isEmpty())
            PulseMode->setObjectName("PulseMode");
        PulseMode->resize(800, 480);
        F1_pulsemode = new QFrame(PulseMode);
        F1_pulsemode->setObjectName("F1_pulsemode");
        F1_pulsemode->setGeometry(QRect(20, 60, 760, 400));
        F1_pulsemode->setFrameShape(QFrame::Shape::StyledPanel);
        F1_pulsemode->setFrameShadow(QFrame::Shadow::Raised);
        F3_pulsemode = new QFrame(F1_pulsemode);
        F3_pulsemode->setObjectName("F3_pulsemode");
        F3_pulsemode->setGeometry(QRect(5, 90, 750, 220));
        F3_pulsemode->setFrameShape(QFrame::Shape::StyledPanel);
        F3_pulsemode->setFrameShadow(QFrame::Shadow::Raised);
        change_low_value = new QLabel(F3_pulsemode);
        change_low_value->setObjectName("change_low_value");
        change_low_value->setGeometry(QRect(305, 30, 131, 60));
        change_low_value->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 52pt;"));
        change_low_value->setAlignment(Qt::AlignmentFlag::AlignCenter);
        inc_low_value = new home_button(F3_pulsemode);
        inc_low_value->setObjectName("inc_low_value");
        inc_low_value->setGeometry(QRect(660, 40, 50, 50));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inc_low_value->sizePolicy().hasHeightForWidth());
        inc_low_value->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(22);
        inc_low_value->setFont(font);
        inc_low_value->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        inc_low_value->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        dec_low_value = new home_button(F3_pulsemode);
        dec_low_value->setObjectName("dec_low_value");
        dec_low_value->setGeometry(QRect(570, 40, 50, 50));
        dec_low_value->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        L2_min_pulse_unit = new QLabel(F3_pulsemode);
        L2_min_pulse_unit->setObjectName("L2_min_pulse_unit");
        L2_min_pulse_unit->setGeometry(QRect(440, 60, 31, 25));
        L2_min_pulse_unit->setStyleSheet(QString::fromUtf8("font-size:20pt;"));
        inc_high_value = new home_button(F3_pulsemode);
        inc_high_value->setObjectName("inc_high_value");
        inc_high_value->setGeometry(QRect(660, 140, 50, 50));
        sizePolicy.setHeightForWidth(inc_high_value->sizePolicy().hasHeightForWidth());
        inc_high_value->setSizePolicy(sizePolicy);
        inc_high_value->setFont(font);
        inc_high_value->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        inc_high_value->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        change_high_value = new QLabel(F3_pulsemode);
        change_high_value->setObjectName("change_high_value");
        change_high_value->setGeometry(QRect(305, 130, 131, 60));
        change_high_value->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 52pt;"));
        change_high_value->setAlignment(Qt::AlignmentFlag::AlignCenter);
        L2_max_pulse_unit = new QLabel(F3_pulsemode);
        L2_max_pulse_unit->setObjectName("L2_max_pulse_unit");
        L2_max_pulse_unit->setGeometry(QRect(440, 160, 31, 25));
        L2_max_pulse_unit->setStyleSheet(QString::fromUtf8("font-size:20pt;"));
        dec_high_value = new home_button(F3_pulsemode);
        dec_high_value->setObjectName("dec_high_value");
        dec_high_value->setGeometry(QRect(570, 140, 50, 50));
        dec_high_value->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        label_9 = new QLabel(F3_pulsemode);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 40, 170, 50));
        label_9->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_10 = new QLabel(F3_pulsemode);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 140, 170, 50));
        label_10->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        B3_back_to_setting = new QPushButton(PulseMode);
        B3_back_to_setting->setObjectName("B3_back_to_setting");
        B3_back_to_setting->setGeometry(QRect(20, 5, 51, 40));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(false);
        B3_back_to_setting->setFont(font1);
        B3_back_to_setting->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B3_back_to_setting->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8 = new QLabel(PulseMode);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(315, 10, 170, 40));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(PulseMode);

        QMetaObject::connectSlotsByName(PulseMode);
    } // setupUi

    void retranslateUi(QWidget *PulseMode)
    {
        PulseMode->setWindowTitle(QCoreApplication::translate("PulseMode", "Form", nullptr));
        change_low_value->setText(QCoreApplication::translate("PulseMode", "11.5", nullptr));
        inc_low_value->setText(QString());
        dec_low_value->setText(QString());
        L2_min_pulse_unit->setText(QCoreApplication::translate("PulseMode", "ms", nullptr));
        inc_high_value->setText(QString());
        change_high_value->setText(QCoreApplication::translate("PulseMode", "11.5", nullptr));
        L2_max_pulse_unit->setText(QCoreApplication::translate("PulseMode", "ms", nullptr));
        dec_high_value->setText(QString());
        label_9->setText(QCoreApplication::translate("PulseMode", "Min. Pulse Width", nullptr));
        label_10->setText(QCoreApplication::translate("PulseMode", "Max. Pulse Width", nullptr));
        B3_back_to_setting->setText(QCoreApplication::translate("PulseMode", "\360\237\241\220", nullptr));
        label_8->setText(QCoreApplication::translate("PulseMode", "Pulse Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PulseMode: public Ui_PulseMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PULSEMODE_H
