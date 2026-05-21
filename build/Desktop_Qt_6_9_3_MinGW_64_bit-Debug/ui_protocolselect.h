/********************************************************************************
** Form generated from reading UI file 'protocolselect.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTOCOLSELECT_H
#define UI_PROTOCOLSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_protocolselect
{
public:
    QFrame *tabframe;
    QTabWidget *Main_Tab;
    QWidget *tabFavourite;
    QWidget *tabPreset;
    QTabWidget *Sub_Tab;
    QWidget *tabGeneral;
    QWidget *tabENT;
    QWidget *tabGynaecology;
    QWidget *tabNeurology;
    QWidget *tabTherapy;
    QWidget *tabUrology;
    QWidget *tabVascular;
    QWidget *tabCustom;
    QPushButton *B3_back_to_home;
    QLabel *select_protocol_level;

    void setupUi(QWidget *protocolselect)
    {
        if (protocolselect->objectName().isEmpty())
            protocolselect->setObjectName("protocolselect");
        protocolselect->resize(800, 480);
        tabframe = new QFrame(protocolselect);
        tabframe->setObjectName("tabframe");
        tabframe->setGeometry(QRect(20, 60, 760, 400));
        tabframe->setStyleSheet(QString::fromUtf8(""));
        tabframe->setFrameShape(QFrame::Shape::StyledPanel);
        tabframe->setFrameShadow(QFrame::Shadow::Raised);
        Main_Tab = new QTabWidget(tabframe);
        Main_Tab->setObjectName("Main_Tab");
        Main_Tab->setGeometry(QRect(0, 0, 760, 400));
        Main_Tab->setStyleSheet(QString::fromUtf8(""));
        tabFavourite = new QWidget();
        tabFavourite->setObjectName("tabFavourite");
        Main_Tab->addTab(tabFavourite, QString());
        tabPreset = new QWidget();
        tabPreset->setObjectName("tabPreset");
        Sub_Tab = new QTabWidget(tabPreset);
        Sub_Tab->setObjectName("Sub_Tab");
        Sub_Tab->setGeometry(QRect(0, 0, 756, 350));
        tabGeneral = new QWidget();
        tabGeneral->setObjectName("tabGeneral");
        Sub_Tab->addTab(tabGeneral, QString());
        tabENT = new QWidget();
        tabENT->setObjectName("tabENT");
        Sub_Tab->addTab(tabENT, QString());
        tabGynaecology = new QWidget();
        tabGynaecology->setObjectName("tabGynaecology");
        Sub_Tab->addTab(tabGynaecology, QString());
        tabNeurology = new QWidget();
        tabNeurology->setObjectName("tabNeurology");
        Sub_Tab->addTab(tabNeurology, QString());
        tabTherapy = new QWidget();
        tabTherapy->setObjectName("tabTherapy");
        Sub_Tab->addTab(tabTherapy, QString());
        tabUrology = new QWidget();
        tabUrology->setObjectName("tabUrology");
        Sub_Tab->addTab(tabUrology, QString());
        tabVascular = new QWidget();
        tabVascular->setObjectName("tabVascular");
        Sub_Tab->addTab(tabVascular, QString());
        Main_Tab->addTab(tabPreset, QString());
        tabCustom = new QWidget();
        tabCustom->setObjectName("tabCustom");
        Main_Tab->addTab(tabCustom, QString());
        B3_back_to_home = new QPushButton(protocolselect);
        B3_back_to_home->setObjectName("B3_back_to_home");
        B3_back_to_home->setGeometry(QRect(20, 10, 51, 40));
        QFont font;
        font.setPointSize(22);
        font.setBold(false);
        B3_back_to_home->setFont(font);
        B3_back_to_home->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B3_back_to_home->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        select_protocol_level = new QLabel(protocolselect);
        select_protocol_level->setObjectName("select_protocol_level");
        select_protocol_level->setGeometry(QRect(210, 10, 380, 40));
        select_protocol_level->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        select_protocol_level->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(protocolselect);

        Main_Tab->setCurrentIndex(2);
        Sub_Tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(protocolselect);
    } // setupUi

    void retranslateUi(QWidget *protocolselect)
    {
        protocolselect->setWindowTitle(QCoreApplication::translate("protocolselect", "Form", nullptr));
        Main_Tab->setTabText(Main_Tab->indexOf(tabFavourite), QCoreApplication::translate("protocolselect", "Favourite", nullptr));
        Sub_Tab->setTabText(Sub_Tab->indexOf(tabGeneral), QCoreApplication::translate("protocolselect", "General", nullptr));
        Sub_Tab->setTabText(Sub_Tab->indexOf(tabENT), QCoreApplication::translate("protocolselect", "ENT", nullptr));
        Sub_Tab->setTabText(Sub_Tab->indexOf(tabGynaecology), QCoreApplication::translate("protocolselect", "Gynaecology", nullptr));
        Sub_Tab->setTabText(Sub_Tab->indexOf(tabNeurology), QCoreApplication::translate("protocolselect", "Neurology", nullptr));
        Sub_Tab->setTabText(Sub_Tab->indexOf(tabTherapy), QCoreApplication::translate("protocolselect", "Therapy", nullptr));
        Sub_Tab->setTabText(Sub_Tab->indexOf(tabUrology), QCoreApplication::translate("protocolselect", "Urology", nullptr));
        Sub_Tab->setTabText(Sub_Tab->indexOf(tabVascular), QCoreApplication::translate("protocolselect", "Vascular", nullptr));
        Main_Tab->setTabText(Main_Tab->indexOf(tabPreset), QCoreApplication::translate("protocolselect", "Preset", nullptr));
        Main_Tab->setTabText(Main_Tab->indexOf(tabCustom), QCoreApplication::translate("protocolselect", "Custom", nullptr));
        B3_back_to_home->setText(QCoreApplication::translate("protocolselect", "\360\237\241\220", nullptr));
        select_protocol_level->setText(QCoreApplication::translate("protocolselect", "Select Protocol", nullptr));
    } // retranslateUi

};

namespace Ui {
    class protocolselect: public Ui_protocolselect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOCOLSELECT_H
