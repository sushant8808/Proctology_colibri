#include "rental_info.h"
#include "ui_rental_info.h"
#include "runtime_manager.h"
#include "service_engineer_area.h"
#include "mainwindow.h"
#include "pageindex.h"

rental_info::rental_info(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::rental_info)
    , home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

}

rental_info::~rental_info()
{
    delete ui;
}
void rental_info::switchToServiceEngArea()
{
    MainWindow::instance->switchPage(PAGE_SERVICEENGINEER);
}

void rental_info::on_B3_back_to_setting_clicked()
{
    switchToServiceEngArea();
}

void rental_info::switchToHome()
{
    MainWindow::instance->switchPage(PAGE_HOME);
}


void rental_info::on_back_to_home_clicked()
{
    switchToHome();
}
