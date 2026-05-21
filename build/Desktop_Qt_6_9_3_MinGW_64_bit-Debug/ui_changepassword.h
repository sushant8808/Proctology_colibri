/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changepassword
{
public:
    QFrame *change_pass_frame_1;
    QPushButton *B1_pass_c;
    QPushButton *B1_pass_7;
    QPushButton *B1_pass_6;
    QPushButton *B1_pass_0;
    QPushButton *B1_pass_5;
    QPushButton *B1_pass_3;
    QPushButton *B1_pass_ok;
    QPushButton *B1_pass_9;
    QPushButton *B1_pass_8;
    QPushButton *B1_pass_2;
    QPushButton *B1_pass_4;
    QPushButton *B1_pass_1;
    QLineEdit *current_pass;
    QLineEdit *new_pass;
    QLineEdit *confirm_new_pass;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *B3_back_to_setting;
    QLabel *label_8;

    void setupUi(QWidget *changepassword)
    {
        if (changepassword->objectName().isEmpty())
            changepassword->setObjectName("changepassword");
        changepassword->resize(800, 480);
        change_pass_frame_1 = new QFrame(changepassword);
        change_pass_frame_1->setObjectName("change_pass_frame_1");
        change_pass_frame_1->setGeometry(QRect(20, 60, 760, 400));
        change_pass_frame_1->setStyleSheet(QString::fromUtf8(""));
        change_pass_frame_1->setFrameShape(QFrame::Shape::StyledPanel);
        change_pass_frame_1->setFrameShadow(QFrame::Shadow::Raised);
        B1_pass_c = new QPushButton(change_pass_frame_1);
        B1_pass_c->setObjectName("B1_pass_c");
        B1_pass_c->setGeometry(QRect(500, 250, 60, 60));
        B1_pass_c->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        B1_pass_7 = new QPushButton(change_pass_frame_1);
        B1_pass_7->setObjectName("B1_pass_7");
        B1_pass_7->setGeometry(QRect(460, 180, 60, 60));
        B1_pass_7->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        B1_pass_6 = new QPushButton(change_pass_frame_1);
        B1_pass_6->setObjectName("B1_pass_6");
        B1_pass_6->setGeometry(QRect(620, 110, 60, 60));
        B1_pass_6->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        B1_pass_0 = new QPushButton(change_pass_frame_1);
        B1_pass_0->setObjectName("B1_pass_0");
        B1_pass_0->setGeometry(QRect(580, 250, 60, 60));
        B1_pass_0->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        B1_pass_5 = new QPushButton(change_pass_frame_1);
        B1_pass_5->setObjectName("B1_pass_5");
        B1_pass_5->setGeometry(QRect(540, 110, 60, 60));
        B1_pass_5->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        B1_pass_3 = new QPushButton(change_pass_frame_1);
        B1_pass_3->setObjectName("B1_pass_3");
        B1_pass_3->setGeometry(QRect(620, 40, 60, 60));
        B1_pass_3->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        B1_pass_3->setStyleSheet(QString::fromUtf8(""));
        B1_pass_ok = new QPushButton(change_pass_frame_1);
        B1_pass_ok->setObjectName("B1_pass_ok");
        B1_pass_ok->setGeometry(QRect(500, 330, 150, 50));
        B1_pass_ok->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        B1_pass_ok->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"border: 0px solid;\n"
"border-radius: 25px;\n"
"background-color: rgb(255, 138, 21);"));
        B1_pass_9 = new QPushButton(change_pass_frame_1);
        B1_pass_9->setObjectName("B1_pass_9");
        B1_pass_9->setGeometry(QRect(620, 180, 60, 60));
        B1_pass_9->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        B1_pass_8 = new QPushButton(change_pass_frame_1);
        B1_pass_8->setObjectName("B1_pass_8");
        B1_pass_8->setGeometry(QRect(540, 180, 60, 60));
        B1_pass_8->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        B1_pass_2 = new QPushButton(change_pass_frame_1);
        B1_pass_2->setObjectName("B1_pass_2");
        B1_pass_2->setGeometry(QRect(540, 40, 60, 60));
        B1_pass_2->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        B1_pass_4 = new QPushButton(change_pass_frame_1);
        B1_pass_4->setObjectName("B1_pass_4");
        B1_pass_4->setGeometry(QRect(460, 110, 60, 60));
        B1_pass_4->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        B1_pass_1 = new QPushButton(change_pass_frame_1);
        B1_pass_1->setObjectName("B1_pass_1");
        B1_pass_1->setGeometry(QRect(460, 40, 60, 60));
        B1_pass_1->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        current_pass = new QLineEdit(change_pass_frame_1);
        current_pass->setObjectName("current_pass");
        current_pass->setGeometry(QRect(90, 60, 140, 35));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(5);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(current_pass->sizePolicy().hasHeightForWidth());
        current_pass->setSizePolicy(sizePolicy);
        QFont font;
        current_pass->setFont(font);
        current_pass->setTabletTracking(false);
        current_pass->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        current_pass->setAutoFillBackground(false);
        current_pass->setStyleSheet(QString::fromUtf8("font-size: 44px;"));
        current_pass->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly|Qt::InputMethodHint::ImhHiddenText|Qt::InputMethodHint::ImhNoAutoUppercase|Qt::InputMethodHint::ImhNoPredictiveText|Qt::InputMethodHint::ImhSensitiveData);
        current_pass->setMaxLength(4);
        current_pass->setEchoMode(QLineEdit::EchoMode::Password);
        current_pass->setAlignment(Qt::AlignmentFlag::AlignCenter);
        new_pass = new QLineEdit(change_pass_frame_1);
        new_pass->setObjectName("new_pass");
        new_pass->setGeometry(QRect(90, 200, 140, 35));
        new_pass->setFont(font);
        new_pass->setStyleSheet(QString::fromUtf8("font-size: 44px;"));
        new_pass->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly|Qt::InputMethodHint::ImhHiddenText|Qt::InputMethodHint::ImhNoAutoUppercase|Qt::InputMethodHint::ImhNoPredictiveText|Qt::InputMethodHint::ImhSensitiveData);
        new_pass->setMaxLength(4);
        new_pass->setEchoMode(QLineEdit::EchoMode::Password);
        new_pass->setAlignment(Qt::AlignmentFlag::AlignCenter);
        confirm_new_pass = new QLineEdit(change_pass_frame_1);
        confirm_new_pass->setObjectName("confirm_new_pass");
        confirm_new_pass->setGeometry(QRect(90, 310, 140, 35));
        confirm_new_pass->setFont(font);
        confirm_new_pass->setStyleSheet(QString::fromUtf8("font-size: 44px;"));
        confirm_new_pass->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly|Qt::InputMethodHint::ImhHiddenText|Qt::InputMethodHint::ImhNoAutoUppercase|Qt::InputMethodHint::ImhNoPredictiveText|Qt::InputMethodHint::ImhSensitiveData);
        confirm_new_pass->setMaxLength(4);
        confirm_new_pass->setEchoMode(QLineEdit::EchoMode::Password);
        confirm_new_pass->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(change_pass_frame_1);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 30, 200, 21));
        label->setStyleSheet(QString::fromUtf8("font-size: 18px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(change_pass_frame_1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 170, 200, 21));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 18px;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(change_pass_frame_1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 280, 200, 21));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 18px;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(change_pass_frame_1);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 70, 140, 30));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 38px;\n"
""));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5 = new QLabel(change_pass_frame_1);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(90, 210, 140, 30));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 38px;\n"
""));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_6 = new QLabel(change_pass_frame_1);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(90, 320, 140, 30));
        label_6->setStyleSheet(QString::fromUtf8("font-size: 38px;\n"
""));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_6->raise();
        label_5->raise();
        label_4->raise();
        B1_pass_c->raise();
        B1_pass_7->raise();
        B1_pass_6->raise();
        B1_pass_0->raise();
        B1_pass_5->raise();
        B1_pass_3->raise();
        B1_pass_ok->raise();
        B1_pass_9->raise();
        B1_pass_8->raise();
        B1_pass_2->raise();
        B1_pass_4->raise();
        B1_pass_1->raise();
        current_pass->raise();
        new_pass->raise();
        confirm_new_pass->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        B3_back_to_setting = new QPushButton(changepassword);
        B3_back_to_setting->setObjectName("B3_back_to_setting");
        B3_back_to_setting->setGeometry(QRect(20, 10, 51, 40));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(false);
        B3_back_to_setting->setFont(font1);
        B3_back_to_setting->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B3_back_to_setting->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8 = new QLabel(changepassword);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(280, 10, 240, 40));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(changepassword);

        QMetaObject::connectSlotsByName(changepassword);
    } // setupUi

    void retranslateUi(QWidget *changepassword)
    {
        changepassword->setWindowTitle(QCoreApplication::translate("changepassword", "Form", nullptr));
        B1_pass_c->setText(QCoreApplication::translate("changepassword", "C", nullptr));
        B1_pass_7->setText(QCoreApplication::translate("changepassword", "7", nullptr));
        B1_pass_6->setText(QCoreApplication::translate("changepassword", "6", nullptr));
        B1_pass_0->setText(QCoreApplication::translate("changepassword", "0", nullptr));
        B1_pass_5->setText(QCoreApplication::translate("changepassword", "5", nullptr));
        B1_pass_3->setText(QCoreApplication::translate("changepassword", "3", nullptr));
        B1_pass_ok->setText(QCoreApplication::translate("changepassword", "Confirm", nullptr));
        B1_pass_9->setText(QCoreApplication::translate("changepassword", "9", nullptr));
        B1_pass_8->setText(QCoreApplication::translate("changepassword", "8", nullptr));
        B1_pass_2->setText(QCoreApplication::translate("changepassword", "2", nullptr));
        B1_pass_4->setText(QCoreApplication::translate("changepassword", "4", nullptr));
        B1_pass_1->setText(QCoreApplication::translate("changepassword", "1", nullptr));
        label->setText(QCoreApplication::translate("changepassword", "Current Password", nullptr));
        label_2->setText(QCoreApplication::translate("changepassword", "New Password", nullptr));
        label_3->setText(QCoreApplication::translate("changepassword", "Confirm New Password", nullptr));
        label_4->setText(QCoreApplication::translate("changepassword", "_ _ _ _", nullptr));
        label_5->setText(QCoreApplication::translate("changepassword", "_ _ _ _", nullptr));
        label_6->setText(QCoreApplication::translate("changepassword", "_ _ _ _", nullptr));
        B3_back_to_setting->setText(QCoreApplication::translate("changepassword", "\360\237\241\220", nullptr));
        label_8->setText(QCoreApplication::translate("changepassword", "Change Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changepassword: public Ui_changepassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
