#include "protocolselect.h"
#include "ui_protocolselect.h"
#include "clickablelabel.h"
#include "databaseinitializer.h"
#include "databasemanager.h"
#include "global.h"
#include <QGridLayout>
#include <QScrollArea>
#include <QVBoxLayout>
#include "home.h"
#include "protocolitemwidget.h"
#include "mainwindow.h"
#include "pageindex.h"

bool customMode = false;
int selectedCustomId = -1;
QString selectedCustomName = "";

protocolselect::protocolselect(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::protocolselect)
    , home(home)   // store pointer
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    setupTabs();

}

protocolselect::~protocolselect()
{
    delete ui;
}

// Setup main tabs: Favourite, Preset, Custom
void protocolselect::setupTabs()
{
    // Preset sub-tabs mapping
    struct PresetTab {
        QString tableName;
        QWidget* tabWidget;
    };

    PresetTab presetTabs[] = {
        {"preset_protocol_ent", ui->tabENT},
        {"preset_protocol_gynaecology", ui->tabGynaecology},
        {"preset_protocol_neurology", ui->tabNeurology},
        {"preset_protocol_therapy", ui->tabTherapy},
        {"preset_protocol_urology", ui->tabUrology},
        {"preset_protocol_vascular", ui->tabVascular},
        {"preset_protocol_general", ui->tabGeneral}
    };

    // Load preset protocols
    for(auto &tab : presetTabs) {
        loadProtocols(tab.tableName, tab.tabWidget);
    }

    // Load Favourite and Custom
    loadProtocols("protocol_favourites", ui->tabFavourite);
    loadProtocols("protocol_custom", ui->tabCustom);
}


void protocolselect::loadProtocols(const QString &tableName, QWidget *tabWidget)
{
    if (tabWidget->layout())
    {
        QLayoutItem *item;
        while ((item = tabWidget->layout()->takeAt(0)) != nullptr)
        {
            delete item->widget();
            delete item;
        }
        delete tabWidget->layout();
    }

    QGridLayout *grid = new QGridLayout();

    int row = 0, col = 0;
    int total = 0;
    const int maxCols = 2;
    const int minItems = 8;

    QSqlQuery query(DatabaseManager::instance().db());

    if (tableName == "protocol_favourites")
        query.exec("SELECT id, name, source_table FROM protocol_favourites");
    else
        query.exec(QString("SELECT id, name, favourite FROM %1").arg(tableName));

    while (query.next())
    {
        int id = query.value("id").toInt();
        QString name = query.value("name").toString();

        QString sourceTable;
        bool favourite;

        if (tableName == "protocol_favourites")
        {
            sourceTable = query.value("source_table").toString();
            favourite = true;
        }
        else
        {
            sourceTable = tableName;
            favourite = query.value("favourite").toInt();
        }

        ProtocolItemWidget *item =
            new ProtocolItemWidget(id, 0, name, favourite);

        if (tableName == "protocol_custom" &&
            mode != NormalMode &&
            selectedCustomId == id)
        {
            item->setStyleSheet(
                "background-color: rgb(255,150,150);"
                "border-radius: 20px;"
                );
        }

        // ---------- CLICK ----------
        connect(item, &ProtocolItemWidget::clicked, this, [=]()
                {
                    DatabaseInitializer db;
                    db.fetchProtocol(sourceTable, id);

                    if(mode == DeleteMode && tableName == "protocol_custom")
                    {
                        qDebug()<< "delete";
                        // Selection mode
                        selectedCustomId = id;
                        selectedCustomName = name;

                        // Reload to update highlight
                        loadProtocols("protocol_custom", ui->tabCustom);

                    }else if(mode == ModifyMode && tableName == "protocol_custom")
                    {
                        qDebug()<< "modify";
                        // Selection mode
                        selectedCustomId = id;
                        selectedCustomName = name;

                        // Reload to update highlight
                        loadProtocols("protocol_custom", ui->tabCustom);

                    }else{

                        no_protocol_used++;
                        db.updateSingleColumn(sourceTable,
                                              "no_protocol_used",
                                              no_protocol_used,
                                              id);

                        emit protocolSelected(name);
                        MainWindow::instance->switchPage(PAGE_HOME);
                    }
                });

        // ---------- STAR ----------
        connect(item, &ProtocolItemWidget::favouriteToggled,
                this, [=](int id, bool fav)
                {
                    DatabaseInitializer db;

                    db.updateSingleColumn(sourceTable,
                                          "favourite",
                                          fav ? 1 : 0,
                                          id);

                    if (fav)
                    {
                        QSqlQuery q(DatabaseManager::instance().db());
                        q.prepare(
                            "INSERT OR IGNORE INTO protocol_favourites "
                            "(id, name, source_table) VALUES (?, ?, ?)"
                            );
                        q.addBindValue(id);
                        q.addBindValue(name);
                        q.addBindValue(sourceTable);
                        q.exec();
                    }
                    else
                    {
                        QSqlQuery q(DatabaseManager::instance().db());
                        q.prepare(
                            "DELETE FROM protocol_favourites "
                            "WHERE id = ? AND source_table = ?"
                            );
                        q.addBindValue(id);
                        q.addBindValue(sourceTable);
                        q.exec();
                    }

                    // Preset sub-tabs mapping
                    struct PresetTab {
                        QString tableName;
                        QWidget* tabWidget;
                    };

                    PresetTab presetTabs[] = {
                        {"preset_protocol_ent", ui->tabENT},
                        {"preset_protocol_gynaecology", ui->tabGynaecology},
                        {"preset_protocol_neurology", ui->tabNeurology},
                        {"preset_protocol_therapy", ui->tabTherapy},
                        {"preset_protocol_urology", ui->tabUrology},
                        {"preset_protocol_vascular", ui->tabVascular},
                        {"preset_protocol_general", ui->tabGeneral}
                    };

                    // Load preset protocols
                    for(auto &tab : presetTabs) {
                        loadProtocols(tab.tableName, tab.tabWidget);
                    }

                    loadProtocols("protocol_favourites", ui->tabFavourite);
                    loadProtocols("protocol_custom", ui->tabCustom);
                });

        grid->addWidget(item, row, col);
        col++; total++;

        if (col >= maxCols) { col = 0; row++; }
    }

    // ---------- DUMMY ITEMS ----------
    while (total < minItems)
    {
        ProtocolItemWidget *dummy =
            new ProtocolItemWidget(-1, 1, "-", false);
        dummy->setEnabled(false);

        if(dark)
        {
            dummy->setStyleSheet(
                "ProtocolItemWidget {"
                "background-color: rgb(220,200,200);"
                "border-radius: 20px;"
                "border: 2px dashed rgb(230,230,230);"
                "}"
                );
        }else
        {
            dummy->setStyleSheet(
                "ProtocolItemWidget {"
                "background-color: rgb(15,15,15);"
                "border-radius: 20px;"
                "border: 2px dashed rgb(25,25,25);"
                "}"
                );
        }



        grid->addWidget(dummy, row, col);
        col++; total++;
        if (col >= maxCols) { col = 0; row++; }
    }

    QWidget *container = new QWidget();
    container->setLayout(grid);

    QScrollArea *scroll = new QScrollArea();
    scroll->setWidgetResizable(true);
    scroll->setWidget(container);
    scroll->setFrameShape(QFrame::NoFrame);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QVBoxLayout *vbox = new QVBoxLayout(tabWidget);

    // ✅ If Custom Tab → Add buttons on top
    if (tableName == "protocol_custom")
    {
        QHBoxLayout *buttonLayout = new QHBoxLayout();

        QPushButton *btnNew = new QPushButton("New");
        QPushButton *btnModify = new QPushButton("Modify");
        QPushButton *btnDelete = new QPushButton("Delete");
        QPushButton *btnConfirm = new QPushButton("Confirm");

        btnNew->setProperty("type", "customAction");
        btnModify->setProperty("type", "customAction");
        btnDelete->setProperty("type", "customAction");
        btnConfirm->setProperty("type", "customAction");

        btnNew->setFixedHeight(40);
        btnModify->setFixedHeight(40);
        btnDelete->setFixedHeight(40);
        btnConfirm->setFixedHeight(40);

        buttonLayout->addWidget(btnNew);
        buttonLayout->addWidget(btnModify);
        buttonLayout->addWidget(btnDelete);
        buttonLayout->addWidget(btnConfirm);
        buttonLayout->addStretch();

        vbox->addLayout(buttonLayout);

        btnConfirm->hide();

        // ---------- BUTTON CONNECTIONS ----------

        connect(btnNew, &QPushButton::clicked, this, [=]() {
            qDebug() << "New clicked";
            new_protocol = true;
            modify_protocol = false;
            this->hide();
            switchTonewprotocol();
            // TODO: Open create protocol dialog
        });

        connect(btnModify, &QPushButton::clicked, this, [=]() {
            qDebug() << "Modify clicked";
            mode = ModifyMode;
            btnConfirm->show();
            // TODO: Modify selected protocol
        });

        connect(btnDelete, &QPushButton::clicked, this, [=]() {
            qDebug() << "Delete clicked";
            mode = DeleteMode;
            btnConfirm->show();
            // TODO: Delete selected protocol
        });
        connect(btnConfirm, &QPushButton::clicked, this, [=]() {
            qDebug() << "Confirm clicked";
            if(mode == DeleteMode)
            {
                DatabaseInitializer dbinit;

                dbinit.deletePresetProtocol(tableName,selectedCustomName);

                // Reload to update highlight
                loadProtocols("protocol_custom", ui->tabCustom);
            }
            else if(mode == ModifyMode)
            {
                custom_modify = 1;
                new_protocol = false;
                modify_protocol = true;
                switchTonewprotocol();
            }
            mode = NormalMode;
            btnConfirm->hide();
            // TODO: Confirm selected protocol
        });
    }

    // ✅ Add scroll area below buttons
    vbox->addWidget(scroll);

    tabWidget->setLayout(vbox);
}

void protocolselect::switchTonewprotocol()
{
    MainWindow::instance->switchPage(PAGE_NEWCUSTOMPROTOCOL);
}

// Update Home or globals (example)
void protocolselect::loadHomeFromGlobals()
{
    // Here you can update any Home UI or globals after protocol selection
    //qDebug() << "Loaded protocol into globals:" << protocolName;
    //qDebug() << "Power 980:" << power980 << "Power 1470:" << power1470;
}

void protocolselect::on_B3_back_to_home_clicked()
{
    MainWindow::instance->switchPage(PAGE_HOME);
}

void protocolselect::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}
void protocolselect::refreshPage()
{
    qDebug() << "Refreshing Protocol Select Page";

    // Reset selection state
    selectedCustomId = -1;
    selectedCustomName.clear();

    mode = NormalMode;

    // Reload all tabs
//    setupTabs();
    loadProtocols("protocol_custom", ui->tabCustom);

    qDebug() << "Protocol Select Refresh Complete";
}
