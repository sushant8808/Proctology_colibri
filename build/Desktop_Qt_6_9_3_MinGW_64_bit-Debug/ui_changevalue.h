/********************************************************************************
** Form generated from reading UI file 'changevalue.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEVALUE_H
#define UI_CHANGEVALUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <home_button.h>

QT_BEGIN_NAMESPACE

class Ui_changevalue
{
public:
    QTabWidget *T2_home;
    QWidget *T2_basic;
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
    QWidget *T2_advanced;
    QFrame *homeframe_4;
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
    QFrame *homeframe_6;
    home_button *B2_alarm_sec_add;
    home_button *B2_alarm_sec_sub;
    QCheckBox *B2_audioalarm;
    QRadioButton *B2_sec_alarm;
    QRadioButton *B2_joule_alarm;
    QLabel *L2_alarm_sec_show;
    QLabel *L2_alarm_joule_show;
    home_button *B2_alarm_joule_add;
    home_button *B2_alarm_joule_sub;
    QLabel *L2_tab_hide;

    void setupUi(QWidget *changevalue)
    {
        if (changevalue->objectName().isEmpty())
            changevalue->setObjectName("changevalue");
        changevalue->resize(761, 312);
        T2_home = new QTabWidget(changevalue);
        T2_home->setObjectName("T2_home");
        T2_home->setGeometry(QRect(0, 0, 761, 312));
        T2_home->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        T2_home->setStyleSheet(QString::fromUtf8(""));
        T2_home->setTabPosition(QTabWidget::TabPosition::North);
        T2_home->setTabShape(QTabWidget::TabShape::Rounded);
        T2_home->setTabsClosable(false);
        T2_home->setMovable(false);
        T2_home->setTabBarAutoHide(false);
        T2_basic = new QWidget();
        T2_basic->setObjectName("T2_basic");
        homeframe_1 = new QFrame(T2_basic);
        homeframe_1->setObjectName("homeframe_1");
        homeframe_1->setGeometry(QRect(0, 0, 760, 280));
        homeframe_1->setFrameShape(QFrame::Shape::StyledPanel);
        homeframe_1->setFrameShadow(QFrame::Shadow::Raised);
        homeframe_2 = new QFrame(homeframe_1);
        homeframe_2->setObjectName("homeframe_2");
        homeframe_2->setGeometry(QRect(5, 5, 372, 270));
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
        L2_watts->setGeometry(QRect(146, 120, 31, 21));
        L2_watts->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));
        L2_980nm = new QLabel(homeframe_2);
        L2_980nm->setObjectName("L2_980nm");
        L2_980nm->setGeometry(QRect(20, 60, 80, 20));
        L2_980nm->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        L2_1470nm = new QLabel(homeframe_2);
        L2_1470nm->setObjectName("L2_1470nm");
        L2_1470nm->setGeometry(QRect(20, 170, 95, 20));
        L2_1470nm->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        B2_980sub = new home_button(homeframe_2);
        B2_980sub->setObjectName("B2_980sub");
        B2_980sub->setGeometry(QRect(220, 100, 50, 50));
        B2_980sub->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        B2_980add = new home_button(homeframe_2);
        B2_980add->setObjectName("B2_980add");
        B2_980add->setGeometry(QRect(300, 100, 50, 50));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(B2_980add->sizePolicy().hasHeightForWidth());
        B2_980add->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(22);
        B2_980add->setFont(font1);
        B2_980add->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B2_980add->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        B2_1470sub = new home_button(homeframe_2);
        B2_1470sub->setObjectName("B2_1470sub");
        B2_1470sub->setGeometry(QRect(220, 205, 50, 50));
        B2_1470sub->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        B2_1470add = new home_button(homeframe_2);
        B2_1470add->setObjectName("B2_1470add");
        B2_1470add->setGeometry(QRect(300, 205, 50, 50));
        B2_1470add->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        L2_980_show = new QLabel(homeframe_2);
        L2_980_show->setObjectName("L2_980_show");
        L2_980_show->setGeometry(QRect(20, 90, 121, 60));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto")});
        font2.setPointSize(48);
        font2.setItalic(false);
        L2_980_show->setFont(font2);
        L2_980_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 48pt;"));
        L2_980_show->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        L2_1470_show = new QLabel(homeframe_2);
        L2_1470_show->setObjectName("L2_1470_show");
        L2_1470_show->setGeometry(QRect(20, 200, 121, 60));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto")});
        font3.setPointSize(48);
        L2_1470_show->setFont(font3);
        L2_1470_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 48pt;"));
        L2_1470_show->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        L2_watts_2 = new QLabel(homeframe_2);
        L2_watts_2->setObjectName("L2_watts_2");
        L2_watts_2->setGeometry(QRect(146, 230, 31, 21));
        L2_watts_2->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));
        homeframe_3 = new QFrame(homeframe_1);
        homeframe_3->setObjectName("homeframe_3");
        homeframe_3->setGeometry(QRect(383, 5, 372, 270));
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
        L2_seconds->setGeometry(QRect(149, 145, 31, 31));
        L2_seconds->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));
        B2_timer_add = new home_button(homeframe_3);
        B2_timer_add->setObjectName("B2_timer_add");
        B2_timer_add->setGeometry(QRect(300, 125, 50, 50));
        B2_timer_add->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        B2_timer_sub = new home_button(homeframe_3);
        B2_timer_sub->setObjectName("B2_timer_sub");
        B2_timer_sub->setGeometry(QRect(220, 125, 50, 50));
        B2_timer_sub->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        B2_timer_on = new QRadioButton(homeframe_3);
        B2_timer_on->setObjectName("B2_timer_on");
        B2_timer_on->setGeometry(QRect(20, 140, 90, 21));
        B2_timer_on->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        B2_timer_off = new QRadioButton(homeframe_3);
        B2_timer_off->setObjectName("B2_timer_off");
        B2_timer_off->setGeometry(QRect(20, 70, 90, 21));
        B2_timer_off->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        L2_timer_show = new QLabel(homeframe_3);
        L2_timer_show->setObjectName("L2_timer_show");
        L2_timer_show->setGeometry(QRect(36, 120, 111, 60));
        L2_timer_show->setFont(font3);
        L2_timer_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 48pt;"));
        L2_timer_show->setAlignment(Qt::AlignmentFlag::AlignCenter);
        B2_timer_reset = new QPushButton(homeframe_3);
        B2_timer_reset->setObjectName("B2_timer_reset");
        B2_timer_reset->setGeometry(QRect(18, 200, 130, 50));
        B2_timer_reset->setStyleSheet(QString::fromUtf8("border: 0px solid;\n"
"border-top-left-radius: 25px;\n"
"border-bottom-left-radius: 25px;\n"
"font-size: 14pt;"));
        B2_timer_reset->setAutoExclusive(false);
        B2_timer_noreset = new QPushButton(homeframe_3);
        B2_timer_noreset->setObjectName("B2_timer_noreset");
        B2_timer_noreset->setGeometry(QRect(150, 200, 130, 50));
        B2_timer_noreset->setStyleSheet(QString::fromUtf8("border: 0px solid;\n"
"border-top-right-radius: 25px;\n"
"border-bottom-right-radius: 25px;\n"
"font-size: 14pt;"));
        B2_timer_noreset->setAutoExclusive(false);
        T2_home->addTab(T2_basic, QString());
        T2_advanced = new QWidget();
        T2_advanced->setObjectName("T2_advanced");
        homeframe_4 = new QFrame(T2_advanced);
        homeframe_4->setObjectName("homeframe_4");
        homeframe_4->setGeometry(QRect(0, 0, 760, 280));
        homeframe_4->setFrameShape(QFrame::Shape::StyledPanel);
        homeframe_4->setFrameShadow(QFrame::Shadow::Raised);
        homeframe_5 = new QFrame(homeframe_4);
        homeframe_5->setObjectName("homeframe_5");
        homeframe_5->setGeometry(QRect(5, 5, 372, 270));
        homeframe_5->setStyleSheet(QString::fromUtf8(""));
        homeframe_5->setFrameShape(QFrame::Shape::StyledPanel);
        homeframe_5->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(homeframe_5);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 131, 20));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        label = new QLabel(homeframe_5);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 170, 151, 20));
        label->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        B2_on_time_sub = new home_button(homeframe_5);
        B2_on_time_sub->setObjectName("B2_on_time_sub");
        B2_on_time_sub->setGeometry(QRect(220, 100, 50, 50));
        B2_on_time_sub->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        B2_on_time_add = new home_button(homeframe_5);
        B2_on_time_add->setObjectName("B2_on_time_add");
        B2_on_time_add->setGeometry(QRect(300, 100, 50, 50));
        sizePolicy.setHeightForWidth(B2_on_time_add->sizePolicy().hasHeightForWidth());
        B2_on_time_add->setSizePolicy(sizePolicy);
        B2_on_time_add->setFont(font1);
        B2_on_time_add->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B2_on_time_add->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        B2_off_time_sub = new home_button(homeframe_5);
        B2_off_time_sub->setObjectName("B2_off_time_sub");
        B2_off_time_sub->setGeometry(QRect(220, 205, 50, 50));
        B2_off_time_sub->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        B2_off_time_add = new home_button(homeframe_5);
        B2_off_time_add->setObjectName("B2_off_time_add");
        B2_off_time_add->setGeometry(QRect(300, 205, 50, 50));
        B2_off_time_add->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        L2_on_pulse_show = new QLabel(homeframe_5);
        L2_on_pulse_show->setObjectName("L2_on_pulse_show");
        L2_on_pulse_show->setGeometry(QRect(20, 90, 131, 60));
        L2_on_pulse_show->setFont(font2);
        L2_on_pulse_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 48pt;"));
        L2_on_pulse_show->setAlignment(Qt::AlignmentFlag::AlignCenter);
        L2_off_pulse_show = new QLabel(homeframe_5);
        L2_off_pulse_show->setObjectName("L2_off_pulse_show");
        L2_off_pulse_show->setGeometry(QRect(20, 200, 131, 60));
        L2_off_pulse_show->setFont(font3);
        L2_off_pulse_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 48pt;"));
        L2_off_pulse_show->setAlignment(Qt::AlignmentFlag::AlignCenter);
        B2_pulsemode = new QCheckBox(homeframe_5);
        B2_pulsemode->setObjectName("B2_pulsemode");
        B2_pulsemode->setGeometry(QRect(20, 15, 141, 21));
        B2_pulsemode->setMouseTracking(false);
        B2_pulsemode->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        L2_on_pulse_unit = new QLabel(homeframe_5);
        L2_on_pulse_unit->setObjectName("L2_on_pulse_unit");
        L2_on_pulse_unit->setGeometry(QRect(150, 120, 31, 21));
        L2_on_pulse_unit->setStyleSheet(QString::fromUtf8("font-size:20px;"));
        L2_off_pulse_unit = new QLabel(homeframe_5);
        L2_off_pulse_unit->setObjectName("L2_off_pulse_unit");
        L2_off_pulse_unit->setGeometry(QRect(150, 230, 31, 21));
        L2_off_pulse_unit->setStyleSheet(QString::fromUtf8("font-size:20px;"));
        homeframe_6 = new QFrame(homeframe_4);
        homeframe_6->setObjectName("homeframe_6");
        homeframe_6->setGeometry(QRect(383, 5, 372, 270));
        homeframe_6->setStyleSheet(QString::fromUtf8(""));
        homeframe_6->setFrameShape(QFrame::Shape::StyledPanel);
        homeframe_6->setFrameShadow(QFrame::Shadow::Raised);
        B2_alarm_sec_add = new home_button(homeframe_6);
        B2_alarm_sec_add->setObjectName("B2_alarm_sec_add");
        B2_alarm_sec_add->setGeometry(QRect(300, 100, 50, 50));
        B2_alarm_sec_add->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        B2_alarm_sec_sub = new home_button(homeframe_6);
        B2_alarm_sec_sub->setObjectName("B2_alarm_sec_sub");
        B2_alarm_sec_sub->setGeometry(QRect(220, 100, 50, 50));
        B2_alarm_sec_sub->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        B2_audioalarm = new QCheckBox(homeframe_6);
        B2_audioalarm->setObjectName("B2_audioalarm");
        B2_audioalarm->setGeometry(QRect(20, 15, 141, 21));
        B2_audioalarm->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        B2_sec_alarm = new QRadioButton(homeframe_6);
        B2_sec_alarm->setObjectName("B2_sec_alarm");
        B2_sec_alarm->setGeometry(QRect(20, 60, 121, 21));
        B2_sec_alarm->setMouseTracking(false);
        B2_sec_alarm->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        B2_sec_alarm->setAutoExclusive(false);
        B2_joule_alarm = new QRadioButton(homeframe_6);
        B2_joule_alarm->setObjectName("B2_joule_alarm");
        B2_joule_alarm->setGeometry(QRect(20, 170, 91, 21));
        B2_joule_alarm->setMouseTracking(false);
        B2_joule_alarm->setStyleSheet(QString::fromUtf8("font-size: 16pt;"));
        B2_joule_alarm->setAutoExclusive(false);
        L2_alarm_sec_show = new QLabel(homeframe_6);
        L2_alarm_sec_show->setObjectName("L2_alarm_sec_show");
        L2_alarm_sec_show->setGeometry(QRect(20, 90, 201, 60));
        L2_alarm_sec_show->setFont(font2);
        L2_alarm_sec_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 48pt;"));
        L2_alarm_sec_show->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        L2_alarm_joule_show = new QLabel(homeframe_6);
        L2_alarm_joule_show->setObjectName("L2_alarm_joule_show");
        L2_alarm_joule_show->setGeometry(QRect(20, 200, 201, 60));
        L2_alarm_joule_show->setFont(font2);
        L2_alarm_joule_show->setStyleSheet(QString::fromUtf8("color: rgb(50, 155, 255);\n"
"font-size: 48pt;"));
        L2_alarm_joule_show->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        B2_alarm_joule_add = new home_button(homeframe_6);
        B2_alarm_joule_add->setObjectName("B2_alarm_joule_add");
        B2_alarm_joule_add->setGeometry(QRect(300, 205, 50, 50));
        B2_alarm_joule_add->setStyleSheet(QString::fromUtf8("image: url(:/icons/plus.svg);"));
        B2_alarm_joule_sub = new home_button(homeframe_6);
        B2_alarm_joule_sub->setObjectName("B2_alarm_joule_sub");
        B2_alarm_joule_sub->setGeometry(QRect(220, 205, 50, 50));
        B2_alarm_joule_sub->setStyleSheet(QString::fromUtf8("image: url(:/icons/negative.svg);"));
        T2_home->addTab(T2_advanced, QString());
        L2_tab_hide = new QLabel(changevalue);
        L2_tab_hide->setObjectName("L2_tab_hide");
        L2_tab_hide->setGeometry(QRect(0, 0, 381, 32));
        L2_tab_hide->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(changevalue);

        T2_home->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(changevalue);
    } // setupUi

    void retranslateUi(QWidget *changevalue)
    {
        changevalue->setWindowTitle(QCoreApplication::translate("changevalue", "Form", nullptr));
        L2_power->setText(QCoreApplication::translate("changevalue", "Power", nullptr));
        L2_watts->setText(QCoreApplication::translate("changevalue", "W", nullptr));
        L2_980nm->setText(QCoreApplication::translate("changevalue", "980 nm", nullptr));
        L2_1470nm->setText(QCoreApplication::translate("changevalue", "1470 nm", nullptr));
        B2_980sub->setText(QString());
        B2_980add->setText(QString());
        B2_1470sub->setText(QString());
        B2_1470add->setText(QString());
        L2_980_show->setText(QCoreApplication::translate("changevalue", "15.0", nullptr));
        L2_1470_show->setText(QCoreApplication::translate("changevalue", "15.0", nullptr));
        L2_watts_2->setText(QCoreApplication::translate("changevalue", "W", nullptr));
        L2_timer->setText(QCoreApplication::translate("changevalue", "Timer", nullptr));
        L2_seconds->setText(QCoreApplication::translate("changevalue", "S", nullptr));
        B2_timer_add->setText(QString());
        B2_timer_sub->setText(QString());
        B2_timer_on->setText(QString());
        B2_timer_off->setText(QCoreApplication::translate("changevalue", "Off", nullptr));
        L2_timer_show->setText(QCoreApplication::translate("changevalue", "120", nullptr));
        B2_timer_reset->setText(QCoreApplication::translate("changevalue", "Reset", nullptr));
        B2_timer_noreset->setText(QCoreApplication::translate("changevalue", "No Reset", nullptr));
        T2_home->setTabText(T2_home->indexOf(T2_basic), QCoreApplication::translate("changevalue", "Basic", nullptr));
        label_2->setText(QCoreApplication::translate("changevalue", "ON time", nullptr));
        label->setText(QCoreApplication::translate("changevalue", "OFF time", nullptr));
        B2_on_time_sub->setText(QString());
        B2_on_time_add->setText(QString());
        B2_off_time_sub->setText(QString());
        B2_off_time_add->setText(QString());
        L2_on_pulse_show->setText(QCoreApplication::translate("changevalue", "11.5", nullptr));
        L2_off_pulse_show->setText(QCoreApplication::translate("changevalue", "11.5", nullptr));
        B2_pulsemode->setText(QCoreApplication::translate("changevalue", "Pulse Mode", nullptr));
        L2_on_pulse_unit->setText(QCoreApplication::translate("changevalue", "ms", nullptr));
        L2_off_pulse_unit->setText(QCoreApplication::translate("changevalue", "ms", nullptr));
        B2_alarm_sec_add->setText(QString());
        B2_alarm_sec_sub->setText(QString());
        B2_audioalarm->setText(QCoreApplication::translate("changevalue", "Audio Alarm", nullptr));
        B2_sec_alarm->setText(QCoreApplication::translate("changevalue", "Seconds", nullptr));
        B2_joule_alarm->setText(QCoreApplication::translate("changevalue", "Joules", nullptr));
        L2_alarm_sec_show->setText(QCoreApplication::translate("changevalue", "0.0", nullptr));
        L2_alarm_joule_show->setText(QCoreApplication::translate("changevalue", "0.0", nullptr));
        B2_alarm_joule_add->setText(QString());
        B2_alarm_joule_sub->setText(QString());
        T2_home->setTabText(T2_home->indexOf(T2_advanced), QCoreApplication::translate("changevalue", "Advanced", nullptr));
        L2_tab_hide->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class changevalue: public Ui_changevalue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEVALUE_H
