/********************************************************************************
** Form generated from reading UI file 'surgery_data.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURGERY_DATA_H
#define UI_SURGERY_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Surgery_data
{
public:
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Surgery_data)
    {
        if (Surgery_data->objectName().isEmpty())
            Surgery_data->setObjectName("Surgery_data");
        Surgery_data->resize(800, 480);
        lineEdit = new QLineEdit(Surgery_data);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 100, 113, 24));
        textEdit = new QTextEdit(Surgery_data);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(80, 150, 104, 70));
        label = new QLabel(Surgery_data);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 100, 49, 16));
        label_2 = new QLabel(Surgery_data);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 160, 49, 16));

        retranslateUi(Surgery_data);

        QMetaObject::connectSlotsByName(Surgery_data);
    } // setupUi

    void retranslateUi(QWidget *Surgery_data)
    {
        Surgery_data->setWindowTitle(QCoreApplication::translate("Surgery_data", "Form", nullptr));
        label->setText(QCoreApplication::translate("Surgery_data", "LineEdit", nullptr));
        label_2->setText(QCoreApplication::translate("Surgery_data", "TextEdit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Surgery_data: public Ui_Surgery_data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURGERY_DATA_H
