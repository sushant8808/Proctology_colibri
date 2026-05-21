/********************************************************************************
** Form generated from reading UI file 'error_popup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_POPUP_H
#define UI_ERROR_POPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_error_popup
{
public:

    void setupUi(QWidget *error_popup)
    {
        if (error_popup->objectName().isEmpty())
            error_popup->setObjectName("error_popup");
        error_popup->resize(800, 480);

        retranslateUi(error_popup);

        QMetaObject::connectSlotsByName(error_popup);
    } // setupUi

    void retranslateUi(QWidget *error_popup)
    {
        error_popup->setWindowTitle(QCoreApplication::translate("error_popup", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class error_popup: public Ui_error_popup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_POPUP_H
