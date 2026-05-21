/********************************************************************************
** Form generated from reading UI file 'surgery_data.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURGERY_DATA_H
#define UI_SURGERY_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include "keyboard_bt.h"

QT_BEGIN_NAMESPACE

class Ui_Surgery_data
{
public:
    QFrame *surgerydata_1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QRadioButton *B4_male;
    QRadioButton *B4_female;
    QLineEdit *LD4_patient_name;
    QLineEdit *LD4_patient_age;
    QLineEdit *LD4_surgery_name;
    QLineEdit *LD4_patient_ID;
    QLabel *label_6;
    QComboBox *LD4_surgeon_name;
    keyboard_bt *bt_patient_id;
    keyboard_bt *bt_patient_name;
    keyboard_bt *bt_patient_age;
    keyboard_bt *bt_Surgery_name;
    keyboard_bt *bt_Surgeon_name;
    QPushButton *B4_skip;
    QPushButton *B4_save;
    QLabel *L4_tital;
    QPushButton *B4_back_to_home;

    void setupUi(QWidget *Surgery_data)
    {
        if (Surgery_data->objectName().isEmpty())
            Surgery_data->setObjectName("Surgery_data");
        Surgery_data->resize(800, 480);
        surgerydata_1 = new QFrame(Surgery_data);
        surgerydata_1->setObjectName("surgerydata_1");
        surgerydata_1->setGeometry(QRect(20, 60, 760, 340));
        surgerydata_1->setStyleSheet(QString::fromUtf8(""));
        surgerydata_1->setFrameShape(QFrame::Shape::StyledPanel);
        surgerydata_1->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(surgerydata_1);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 20, 131, 30));
        label->setStyleSheet(QString::fromUtf8("font-size:18px;"));
        label_2 = new QLabel(surgerydata_1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 120, 141, 30));
        label_2->setStyleSheet(QString::fromUtf8("font-size:18px;"));
        label_3 = new QLabel(surgerydata_1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 220, 121, 30));
        label_3->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        label_4 = new QLabel(surgerydata_1);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(400, 120, 131, 30));
        label_4->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        label_5 = new QLabel(surgerydata_1);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 220, 81, 30));
        label_5->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
""));
        B4_male = new QRadioButton(surgerydata_1);
        B4_male->setObjectName("B4_male");
        B4_male->setGeometry(QRect(400, 270, 90, 20));
        B4_male->setStyleSheet(QString::fromUtf8("font-size:18px;"));
        B4_male->setAutoExclusive(false);
        B4_female = new QRadioButton(surgerydata_1);
        B4_female->setObjectName("B4_female");
        B4_female->setGeometry(QRect(500, 270, 90, 20));
        B4_female->setStyleSheet(QString::fromUtf8("font-size:18px;"));
        B4_female->setAutoExclusive(false);
        LD4_patient_name = new QLineEdit(surgerydata_1);
        LD4_patient_name->setObjectName("LD4_patient_name");
        LD4_patient_name->setGeometry(QRect(40, 160, 231, 40));
        LD4_patient_age = new QLineEdit(surgerydata_1);
        LD4_patient_age->setObjectName("LD4_patient_age");
        LD4_patient_age->setGeometry(QRect(40, 260, 231, 40));
        LD4_surgery_name = new QLineEdit(surgerydata_1);
        LD4_surgery_name->setObjectName("LD4_surgery_name");
        LD4_surgery_name->setGeometry(QRect(400, 160, 231, 40));
        LD4_patient_ID = new QLineEdit(surgerydata_1);
        LD4_patient_ID->setObjectName("LD4_patient_ID");
        LD4_patient_ID->setGeometry(QRect(40, 60, 231, 40));
        label_6 = new QLabel(surgerydata_1);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 20, 141, 30));
        label_6->setStyleSheet(QString::fromUtf8("font-size:18px;"));
        LD4_surgeon_name = new QComboBox(surgerydata_1);
        LD4_surgeon_name->setObjectName("LD4_surgeon_name");
        LD4_surgeon_name->setGeometry(QRect(400, 60, 231, 40));
        LD4_surgeon_name->setEditable(true);
        LD4_surgeon_name->setIconSize(QSize(16, 16));
        bt_patient_id = new keyboard_bt(surgerydata_1);
        bt_patient_id->setObjectName("bt_patient_id");
        bt_patient_id->setGeometry(QRect(280, 65, 30, 30));
        bt_patient_name = new keyboard_bt(surgerydata_1);
        bt_patient_name->setObjectName("bt_patient_name");
        bt_patient_name->setGeometry(QRect(280, 166, 30, 30));
        bt_patient_age = new keyboard_bt(surgerydata_1);
        bt_patient_age->setObjectName("bt_patient_age");
        bt_patient_age->setGeometry(QRect(280, 265, 30, 30));
        bt_Surgery_name = new keyboard_bt(surgerydata_1);
        bt_Surgery_name->setObjectName("bt_Surgery_name");
        bt_Surgery_name->setGeometry(QRect(640, 165, 30, 30));
        bt_Surgeon_name = new keyboard_bt(surgerydata_1);
        bt_Surgeon_name->setObjectName("bt_Surgeon_name");
        bt_Surgeon_name->setGeometry(QRect(640, 65, 30, 30));
        B4_skip = new QPushButton(Surgery_data);
        B4_skip->setObjectName("B4_skip");
        B4_skip->setGeometry(QRect(590, 410, 80, 50));
        B4_skip->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B4_save = new QPushButton(Surgery_data);
        B4_save->setObjectName("B4_save");
        B4_save->setGeometry(QRect(700, 410, 80, 50));
        B4_save->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;\n"
"background-color:rgb(255, 97, 34);\n"
""));
        L4_tital = new QLabel(Surgery_data);
        L4_tital->setObjectName("L4_tital");
        L4_tital->setGeometry(QRect(270, 10, 260, 40));
        L4_tital->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        L4_tital->setAlignment(Qt::AlignmentFlag::AlignCenter);
        B4_back_to_home = new QPushButton(Surgery_data);
        B4_back_to_home->setObjectName("B4_back_to_home");
        B4_back_to_home->setGeometry(QRect(20, 10, 51, 40));
        QFont font;
        font.setPointSize(22);
        font.setBold(false);
        B4_back_to_home->setFont(font);
        B4_back_to_home->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B4_back_to_home->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        B4_skip->raise();
        surgerydata_1->raise();
        B4_save->raise();
        L4_tital->raise();
        B4_back_to_home->raise();

        retranslateUi(Surgery_data);

        QMetaObject::connectSlotsByName(Surgery_data);
    } // setupUi

    void retranslateUi(QWidget *Surgery_data)
    {
        Surgery_data->setWindowTitle(QCoreApplication::translate("Surgery_data", "Form", nullptr));
        label->setText(QCoreApplication::translate("Surgery_data", "Surgeon Name", nullptr));
        label_2->setText(QCoreApplication::translate("Surgery_data", "Patient Name", nullptr));
        label_3->setText(QCoreApplication::translate("Surgery_data", "Patient Age", nullptr));
        label_4->setText(QCoreApplication::translate("Surgery_data", "Surgery Name", nullptr));
        label_5->setText(QCoreApplication::translate("Surgery_data", "Gender", nullptr));
        B4_male->setText(QCoreApplication::translate("Surgery_data", "Male", nullptr));
        B4_female->setText(QCoreApplication::translate("Surgery_data", "Female", nullptr));
        label_6->setText(QCoreApplication::translate("Surgery_data", "Patient ID", nullptr));
        bt_patient_id->setText(QString());
        bt_patient_name->setText(QString());
        bt_patient_age->setText(QString());
        bt_Surgery_name->setText(QString());
        bt_Surgeon_name->setText(QString());
        B4_skip->setText(QCoreApplication::translate("Surgery_data", "Skip", nullptr));
        B4_save->setText(QCoreApplication::translate("Surgery_data", "Save", nullptr));
        L4_tital->setText(QCoreApplication::translate("Surgery_data", "Enter Surgery Data", nullptr));
        B4_back_to_home->setText(QCoreApplication::translate("Surgery_data", "\360\237\241\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Surgery_data: public Ui_Surgery_data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURGERY_DATA_H
