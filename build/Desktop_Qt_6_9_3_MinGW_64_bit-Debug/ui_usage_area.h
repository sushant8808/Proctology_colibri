/********************************************************************************
** Form generated from reading UI file 'usage_area.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USAGE_AREA_H
#define UI_USAGE_AREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usage_area
{
public:
    QFrame *settingframe_1;
    QFrame *settingframe_2;
    QLabel *label_10;
    QLabel *usage_no_surgery;
    QFrame *settingframe_3;
    QTableWidget *usage_table;
    QPushButton *nextButton;
    QPushButton *prevButton;
    QPushButton *deleteButton;
    QPushButton *pageDeleteButton;
    QPushButton *B3_clear_data;
    QPushButton *B3_back_to_setting;
    QLabel *label_9;

    void setupUi(QWidget *usage_area)
    {
        if (usage_area->objectName().isEmpty())
            usage_area->setObjectName("usage_area");
        usage_area->resize(800, 480);
        settingframe_1 = new QFrame(usage_area);
        settingframe_1->setObjectName("settingframe_1");
        settingframe_1->setGeometry(QRect(20, 60, 760, 400));
        settingframe_1->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_1->setFrameShadow(QFrame::Shadow::Raised);
        settingframe_2 = new QFrame(settingframe_1);
        settingframe_2->setObjectName("settingframe_2");
        settingframe_2->setGeometry(QRect(5, 5, 750, 60));
        settingframe_2->setStyleSheet(QString::fromUtf8(""));
        settingframe_2->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_2->setFrameShadow(QFrame::Shadow::Raised);
        label_10 = new QLabel(settingframe_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 15, 311, 30));
        label_10->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        label_10->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);
        usage_no_surgery = new QLabel(settingframe_2);
        usage_no_surgery->setObjectName("usage_no_surgery");
        usage_no_surgery->setGeometry(QRect(290, 15, 101, 31));
        usage_no_surgery->setStyleSheet(QString::fromUtf8("font-size: 18pt;"));
        usage_no_surgery->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);
        settingframe_3 = new QFrame(settingframe_1);
        settingframe_3->setObjectName("settingframe_3");
        settingframe_3->setGeometry(QRect(5, 70, 750, 325));
        settingframe_3->setStyleSheet(QString::fromUtf8(""));
        settingframe_3->setFrameShape(QFrame::Shape::StyledPanel);
        settingframe_3->setFrameShadow(QFrame::Shadow::Raised);
        usage_table = new QTableWidget(settingframe_3);
        usage_table->setObjectName("usage_table");
        usage_table->setGeometry(QRect(10, 10, 730, 231));
        nextButton = new QPushButton(settingframe_3);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(694, 240, 51, 31));
        prevButton = new QPushButton(settingframe_3);
        prevButton->setObjectName("prevButton");
        prevButton->setGeometry(QRect(5, 240, 51, 31));
        deleteButton = new QPushButton(settingframe_3);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(75, 265, 150, 50));
        deleteButton->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        pageDeleteButton = new QPushButton(settingframe_3);
        pageDeleteButton->setObjectName("pageDeleteButton");
        pageDeleteButton->setGeometry(QRect(300, 265, 150, 50));
        pageDeleteButton->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B3_clear_data = new QPushButton(settingframe_3);
        B3_clear_data->setObjectName("B3_clear_data");
        B3_clear_data->setGeometry(QRect(525, 265, 150, 50));
        B3_clear_data->setStyleSheet(QString::fromUtf8("font-size: 14pt;\n"
"border: 1px solid rgb(255, 97, 34);\n"
"border-radius: 25px;"));
        B3_back_to_setting = new QPushButton(usage_area);
        B3_back_to_setting->setObjectName("B3_back_to_setting");
        B3_back_to_setting->setGeometry(QRect(20, 10, 51, 40));
        QFont font;
        font.setPointSize(22);
        font.setBold(false);
        B3_back_to_setting->setFont(font);
        B3_back_to_setting->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        B3_back_to_setting->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_9 = new QLabel(usage_area);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(310, 10, 191, 40));
        label_9->setStyleSheet(QString::fromUtf8("font-size: 22pt;"));
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(usage_area);

        QMetaObject::connectSlotsByName(usage_area);
    } // setupUi

    void retranslateUi(QWidget *usage_area)
    {
        usage_area->setWindowTitle(QCoreApplication::translate("usage_area", "Form", nullptr));
        label_10->setText(QCoreApplication::translate("usage_area", "No. of Surgery Done - ", nullptr));
        usage_no_surgery->setText(QCoreApplication::translate("usage_area", "000", nullptr));
        nextButton->setText(QCoreApplication::translate("usage_area", ">", nullptr));
        prevButton->setText(QCoreApplication::translate("usage_area", "<", nullptr));
        deleteButton->setText(QCoreApplication::translate("usage_area", "Multi delete", nullptr));
        pageDeleteButton->setText(QCoreApplication::translate("usage_area", "Page delete", nullptr));
        B3_clear_data->setText(QCoreApplication::translate("usage_area", "Clear data", nullptr));
        B3_back_to_setting->setText(QCoreApplication::translate("usage_area", "\360\237\241\220", nullptr));
        label_9->setText(QCoreApplication::translate("usage_area", "Usage Area", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usage_area: public Ui_usage_area {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USAGE_AREA_H
