/********************************************************************************
** Form generated from reading UI file 'userlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLOGIN_H
#define UI_USERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Userlogin
{
public:
    QFrame *Password_frame;
    QPushButton *B1_pass_ok;
    QPushButton *B1_pass_2;
    QPushButton *B1_pass_3;
    QPushButton *B1_pass_4;
    QPushButton *B1_pass_5;
    QPushButton *B1_pass_6;
    QPushButton *B1_pass_7;
    QPushButton *B1_pass_8;
    QPushButton *B1_pass_9;
    QPushButton *B1_pass_1;
    QPushButton *B1_pass_0;
    QPushButton *B1_pass_c;
    QLabel *L1_passprint;
    QLabel *L1_passcheck;
    QLabel *tital_1;

    void setupUi(QWidget *Userlogin)
    {
        if (Userlogin->objectName().isEmpty())
            Userlogin->setObjectName("Userlogin");
        Userlogin->resize(800, 480);
        Userlogin->setStyleSheet(QString::fromUtf8(""));
        Password_frame = new QFrame(Userlogin);
        Password_frame->setObjectName("Password_frame");
        Password_frame->setGeometry(QRect(260, 80, 280, 380));
        Password_frame->setStyleSheet(QString::fromUtf8(""));
        Password_frame->setFrameShape(QFrame::Shape::StyledPanel);
        Password_frame->setFrameShadow(QFrame::Shadow::Raised);
        B1_pass_ok = new QPushButton(Password_frame);
        B1_pass_ok->setObjectName("B1_pass_ok");
        B1_pass_ok->setGeometry(QRect(190, 310, 60, 60));
        B1_pass_2 = new QPushButton(Password_frame);
        B1_pass_2->setObjectName("B1_pass_2");
        B1_pass_2->setGeometry(QRect(110, 100, 60, 60));
        B1_pass_3 = new QPushButton(Password_frame);
        B1_pass_3->setObjectName("B1_pass_3");
        B1_pass_3->setGeometry(QRect(190, 100, 60, 60));
        B1_pass_3->setStyleSheet(QString::fromUtf8(""));
        B1_pass_4 = new QPushButton(Password_frame);
        B1_pass_4->setObjectName("B1_pass_4");
        B1_pass_4->setGeometry(QRect(30, 170, 60, 60));
        B1_pass_5 = new QPushButton(Password_frame);
        B1_pass_5->setObjectName("B1_pass_5");
        B1_pass_5->setGeometry(QRect(110, 170, 60, 60));
        B1_pass_6 = new QPushButton(Password_frame);
        B1_pass_6->setObjectName("B1_pass_6");
        B1_pass_6->setGeometry(QRect(190, 170, 60, 60));
        B1_pass_7 = new QPushButton(Password_frame);
        B1_pass_7->setObjectName("B1_pass_7");
        B1_pass_7->setGeometry(QRect(30, 240, 60, 60));
        B1_pass_8 = new QPushButton(Password_frame);
        B1_pass_8->setObjectName("B1_pass_8");
        B1_pass_8->setGeometry(QRect(110, 240, 60, 60));
        B1_pass_9 = new QPushButton(Password_frame);
        B1_pass_9->setObjectName("B1_pass_9");
        B1_pass_9->setGeometry(QRect(190, 240, 60, 60));
        B1_pass_1 = new QPushButton(Password_frame);
        B1_pass_1->setObjectName("B1_pass_1");
        B1_pass_1->setGeometry(QRect(30, 100, 60, 60));
        B1_pass_0 = new QPushButton(Password_frame);
        B1_pass_0->setObjectName("B1_pass_0");
        B1_pass_0->setGeometry(QRect(110, 310, 60, 60));
        B1_pass_c = new QPushButton(Password_frame);
        B1_pass_c->setObjectName("B1_pass_c");
        B1_pass_c->setGeometry(QRect(30, 310, 60, 60));
        L1_passprint = new QLabel(Password_frame);
        L1_passprint->setObjectName("L1_passprint");
        L1_passprint->setGeometry(QRect(55, 10, 170, 50));
        L1_passprint->setStyleSheet(QString::fromUtf8(""));
        L1_passprint->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        L1_passprint->setMargin(0);
        L1_passcheck = new QLabel(Password_frame);
        L1_passcheck->setObjectName("L1_passcheck");
        L1_passcheck->setGeometry(QRect(70, 70, 140, 20));
        L1_passcheck->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tital_1 = new QLabel(Userlogin);
        tital_1->setObjectName("tital_1");
        tital_1->setGeometry(QRect(230, 15, 340, 50));
        tital_1->setStyleSheet(QString::fromUtf8("font-size: 28pt;"));
        tital_1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(Userlogin);

        QMetaObject::connectSlotsByName(Userlogin);
    } // setupUi

    void retranslateUi(QWidget *Userlogin)
    {
        Userlogin->setWindowTitle(QCoreApplication::translate("Userlogin", "Form", nullptr));
        B1_pass_ok->setText(QCoreApplication::translate("Userlogin", "OK", nullptr));
        B1_pass_2->setText(QCoreApplication::translate("Userlogin", "2", nullptr));
        B1_pass_3->setText(QCoreApplication::translate("Userlogin", "3", nullptr));
        B1_pass_4->setText(QCoreApplication::translate("Userlogin", "4", nullptr));
        B1_pass_5->setText(QCoreApplication::translate("Userlogin", "5", nullptr));
        B1_pass_6->setText(QCoreApplication::translate("Userlogin", "6", nullptr));
        B1_pass_7->setText(QCoreApplication::translate("Userlogin", "7", nullptr));
        B1_pass_8->setText(QCoreApplication::translate("Userlogin", "8", nullptr));
        B1_pass_9->setText(QCoreApplication::translate("Userlogin", "9", nullptr));
        B1_pass_1->setText(QCoreApplication::translate("Userlogin", "1", nullptr));
        B1_pass_0->setText(QCoreApplication::translate("Userlogin", "0", nullptr));
        B1_pass_c->setText(QCoreApplication::translate("Userlogin", "C", nullptr));
        L1_passprint->setText(QString());
        L1_passcheck->setText(QString());
        tital_1->setText(QCoreApplication::translate("Userlogin", "Enter Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Userlogin: public Ui_Userlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLOGIN_H
