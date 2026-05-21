/********************************************************************************
** Form generated from reading UI file 'customkeyboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMKEYBOARD_H
#define UI_CUSTOMKEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customkeyboard
{
public:

    void setupUi(QWidget *customkeyboard)
    {
        if (customkeyboard->objectName().isEmpty())
            customkeyboard->setObjectName("customkeyboard");
        customkeyboard->resize(800, 400);

        retranslateUi(customkeyboard);

        QMetaObject::connectSlotsByName(customkeyboard);
    } // setupUi

    void retranslateUi(QWidget *customkeyboard)
    {
        customkeyboard->setWindowTitle(QCoreApplication::translate("customkeyboard", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customkeyboard: public Ui_customkeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMKEYBOARD_H
