#include "usage_area.h"
#include "ui_usage_area.h"
#include "datetime_manager.h"
#include "setting.h"
#include "runtime_manager.h"
#include "databaseinitializer.h"
#include "userdatabasemanager.h"
#include <QSqlError>
#include <QMessageBox>
#include "userdatabaseinitializer.h"
#include <QCheckBox>
#include <QHBoxLayout>
#include "mainwindow.h"
#include "pageindex.h"

usage_area::usage_area(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::usage_area)
    , home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    // ================= TABLE SETUP =================
    ui->usage_table->setColumnCount(9);

    ui->usage_table->setHorizontalHeaderLabels({
        "Select",
        "ID",
        "Protocol",
        "Start\nTime",
        "Surgery\nDuration(s)",
        "Laser\nDuration(s)",
        "Total\nEnergy(J)",
        "Effective\nPower(W)",
        "Fiber\nReconnect"
    });


    QHeaderView *header = ui->usage_table->horizontalHeader();

    // Checkbox column
    header->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->usage_table->setColumnWidth(0, 45);

    // Hidden ID column
    header->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->usage_table->setColumnWidth(1, 1);

    // Protocol column → stretch remaining space
    header->setSectionResizeMode(2, QHeaderView::Stretch);

    // Start time
    header->setSectionResizeMode(3, QHeaderView::ResizeToContents);

    // Numeric columns
    header->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(7, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(8, QHeaderView::ResizeToContents);

    // Header alignment
    header->setDefaultAlignment(Qt::AlignCenter);

    // Better spacing
    header->setMinimumSectionSize(70);

    // Hide ID column
    ui->usage_table->setColumnHidden(1, true);


    // ================= CLEAN UI =================
    ui->usage_table->setAlternatingRowColors(true);
    // ui->usage_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->usage_table->setSelectionMode(QAbstractItemView::NoSelection);
    // ui->usage_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->usage_table->setFocusPolicy(Qt::NoFocus);
    ui->usage_table->setMouseTracking(false);
    ui->usage_table->setShowGrid(false);
    ui->usage_table->verticalHeader()->setVisible(false);

    // ✅ Row height
    ui->usage_table->verticalHeader()->setDefaultSectionSize(31);

    // Optional: text handling
    ui->usage_table->setWordWrap(false);
    ui->usage_table->setTextElideMode(Qt::ElideRight);

    // ================= LOAD DATA =================
    currentPage = 0;
    loadSurgerySummaryPage(currentPage);

    connect(ui->deleteButton, &QPushButton::clicked,
            this, &usage_area::deleteSelectedRows);

    connect(ui->pageDeleteButton, &QPushButton::clicked,
            this, &usage_area::deleteCurrentPage);


    popup = new error_popup(this);

    connect(popup, &error_popup::yesClicked,
            this, [this]() {
                clear_data_form_userdb();
                qDebug() << "Yes";
            });

    connect(popup, &error_popup::noClicked,
            this, [this]() {
                clear_data = 0;
                qDebug() << "No";
            });


    connect(popup, &error_popup::acknowledged,
            this,[](){
                qDebug() << "ok";
            });

}

usage_area::~usage_area()
{
    delete ui;
}

void usage_area::on_B3_back_to_setting_clicked()
{
    MainWindow::instance->switchPage(PAGE_SETTING);
}

void usage_area::loadSurgerySummaryPage(int page)
{
    QSqlQuery query(UserDatabaseManager::instance().db());

    int offset = page * pageSize;

    query.prepare(R"(
        SELECT
            id,
            protocol_name,
            surgery_start_time,
            surgery_duration_sec,
            laser_activation_duration_sec,
            total_energy_delivered,
            effective_power,
            fiber_disconnection_count
        FROM surgery_summary
        ORDER BY id DESC
        LIMIT :limit OFFSET :offset
    )");

    query.bindValue(":limit", pageSize);
    query.bindValue(":offset", offset);

    if (!query.exec())
    {
        qDebug() << "Fetch surgery_summary failed:" << query.lastError().text();
        return;
    }

    ui->usage_table->setRowCount(0);

    int row = 0;

    while (query.next())
    {
        ui->usage_table->insertRow(row);

        // Create items
        QTableWidgetItem *idItem = new QTableWidgetItem(query.value("id").toString());
        QTableWidgetItem *protocol = new QTableWidgetItem(query.value("protocol_name").toString());
        QTableWidgetItem *startTime = new QTableWidgetItem(query.value("surgery_start_time").toString());
        QTableWidgetItem *surgDur = new QTableWidgetItem(query.value("surgery_duration_sec").toString());
        QTableWidgetItem *laserDur = new QTableWidgetItem(query.value("laser_activation_duration_sec").toString());
        QTableWidgetItem *energy = new QTableWidgetItem(query.value("total_energy_delivered").toString());
        QTableWidgetItem *power = new QTableWidgetItem(query.value("effective_power").toString());
        QTableWidgetItem *fiber = new QTableWidgetItem(query.value("fiber_disconnection_count").toString());

        // ✅ Center numeric columns
        surgDur->setTextAlignment(Qt::AlignCenter);
        laserDur->setTextAlignment(Qt::AlignCenter);
        energy->setTextAlignment(Qt::AlignCenter);
        power->setTextAlignment(Qt::AlignCenter);
        fiber->setTextAlignment(Qt::AlignCenter);

        // QTableWidgetItem *checkItem = new QTableWidgetItem();

        // checkItem->setCheckState(Qt::Unchecked);
        // checkItem->setTextAlignment(Qt::AlignCenter);

        QCheckBox *checkBox = new QCheckBox();

        QWidget *checkWidget = new QWidget();

        QHBoxLayout *layout = new QHBoxLayout(checkWidget);

        layout->addWidget(checkBox);

        layout->setAlignment(Qt::AlignCenter);

        layout->setContentsMargins(0, 0, 0, 0);

        checkWidget->setLayout(layout);

        ui->usage_table->setCellWidget(row, 0, checkWidget);


        // Set items
        // ui->usage_table->setItem(row, 0, checkItem);
        ui->usage_table->setItem(row, 1, idItem);
        ui->usage_table->setItem(row, 2, protocol);
        ui->usage_table->setItem(row, 3, startTime);
        ui->usage_table->setItem(row, 4, surgDur);
        ui->usage_table->setItem(row, 5, laserDur);
        ui->usage_table->setItem(row, 6, energy);
        ui->usage_table->setItem(row, 7, power);
        ui->usage_table->setItem(row, 8, fiber);

        row++;
    }

    // ================= PAGINATION =================

    // Next button
    ui->nextButton->setEnabled(row == pageSize);

    // Previous button
    ui->prevButton->setEnabled(currentPage > 0);

    qDebug() << "Loaded page:" << page;
}



void usage_area::on_prevButton_clicked()
{
    if (currentPage > 0)
    {
        currentPage--;
        loadSurgerySummaryPage(currentPage);
    }
}


void usage_area::on_nextButton_clicked()
{
    currentPage++;
    loadSurgerySummaryPage(currentPage);
}

void usage_area::deleteSelectedRows()
{
    QSqlQuery query(UserDatabaseManager::instance().db());
    query.exec("BEGIN TRANSACTION");

    int rows = ui->usage_table->rowCount();

    for (int i = 0; i < rows; i++)
    {
        QWidget *widget = ui->usage_table->cellWidget(i, 0);

        QCheckBox *checkBox = widget->findChild<QCheckBox *>();

        if (checkBox && checkBox->isChecked())
        {
            int id = ui->usage_table->item(i, 1)->text().toInt();

            query.prepare("DELETE FROM surgery_summary WHERE id = ?");
            query.addBindValue(id);

            if (!query.exec())
            {
                qDebug() << "Delete failed:" << query.lastError().text();
            }
        }
    }

    query.exec("COMMIT");

    loadSurgerySummaryPage(currentPage);
}

void usage_area::deleteCurrentPage()
{
    QSqlQuery query(UserDatabaseManager::instance().db());

    query.exec("BEGIN TRANSACTION");

    int rows = ui->usage_table->rowCount();

    for (int i = 0; i < rows; i++)
    {
        int id = ui->usage_table->item(i, 1)->text().toInt();

        query.prepare("DELETE FROM surgery_summary WHERE id = ?");
        query.addBindValue(id);

        if (!query.exec())
        {
            qDebug() << "Delete failed:" << query.lastError().text();
        }
    }

    query.exec("COMMIT");

    loadSurgerySummaryPage(currentPage);
}

void usage_area::on_B3_clear_data_clicked()
{
    popup->showMessage(
        "CLEAR USER DATA",
        "Are you sure you want to clear all user data?\n"
        "Data export recommended.",
        error_popup::Validation,
        true
        );

    clear_data = 1;
}

void usage_area::clear_data_form_userdb()
{
    if(clear_data == 1)
    {
        UserDatabaseInitializer user_db;
        user_db.deleteAllSurgerySummary();
        clear_data = 0;
    }
    loadSurgerySummaryPage(currentPage);
}

void usage_area::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}

void usage_area::refreshPage()
{
    // ===== Refresh usage count =====

    DatabaseInitializer dbInit;

    dbInit.fetchSystemTimer(1);

    ui->usage_no_surgery->setText(
        QString::number(g_usageNoSurgeryDone));

    // ===== Reload current page =====

    loadSurgerySummaryPage(currentPage);

    // ===== Safety check =====
    // If current page becomes empty after deletions

    if (ui->usage_table->rowCount() == 0 && currentPage > 0)
    {
        currentPage--;

        loadSurgerySummaryPage(currentPage);
    }

    // ===== Clear all checkbox selections =====

    for (int i = 0; i < ui->usage_table->rowCount(); i++)
    {
        QWidget *widget = ui->usage_table->cellWidget(i, 0);

        if (!widget)
            continue;

        QCheckBox *checkBox =
            widget->findChild<QCheckBox *>();

        if (checkBox)
        {
            checkBox->setChecked(false);
        }
    }

    // ===== Reset clear-data flag =====

    clear_data = 0;
}


// void Setting::on_B3_popup_clicked()
// {
//     // popup->showMessage(
//     //     "OVERHEAT CONDITION",
//     //     "System temperature exceeds safe operating limit.\n"
//     //     "Laser emission disabled.",
//     //     error_popup::Critical,
//     //     false   // cannot acknowledge
//     //     );

//     popup->showMessage(
//         "MEMORY CAPACITY WARNING",
//         "Internal storage nearing maximum capacity.\n"
//         "Data export recommended.",
//         error_popup::Warning,
//         true
//         );

//     // popup->showMessage(
//     //     "EXPORT COMPLETED",
//     //     "Surgical log successfully exported.",
//     //     error_popup::Success,
//     //     true
//     //     );
// }
