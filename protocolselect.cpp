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
    , home(home)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    // -------------------------------------------------------------
    // INITIALIZE BUTTONS ONCE
    // -------------------------------------------------------------
    btnNew = new QPushButton("New", this);
    btnModify = new QPushButton("Modify", this);
    btnDelete = new QPushButton("Delete", this);
    btnConfirm = new QPushButton("Confirm", this);

    btnNew->setProperty("type", "customAction");
    btnModify->setProperty("type", "customAction");
    btnDelete->setProperty("type", "customAction");
    btnConfirm->setProperty("type", "customAction");

    btnNew->setFixedHeight(40);
    btnModify->setFixedHeight(40);
    btnDelete->setFixedHeight(40);
    btnConfirm->setFixedHeight(40);

    btnConfirm->hide(); // Hidden by default

    // -------------------------------------------------------------
    // PERMANENT CONNECTIONS
    // -------------------------------------------------------------
    connect(btnNew, &QPushButton::clicked, this, [=]() {
        qDebug() << "New clicked";
        new_protocol = true;
        modify_protocol = false;
        this->hide();
        switchTonewprotocol();
    });

    connect(btnModify, &QPushButton::clicked, this, [=]() {
        qDebug() << "Modify clicked";
        mode = ModifyMode;
        btnConfirm->show();
    });

    connect(btnDelete, &QPushButton::clicked, this, [=]() {
        qDebug() << "Delete clicked";
        mode = DeleteMode;
        btnConfirm->show();
    });

    connect(btnConfirm, &QPushButton::clicked, this, [=]() {
        qDebug() << "Confirm clicked";
        if(mode == DeleteMode)
        {
            DatabaseInitializer dbinit;
            dbinit.deletePresetProtocol("protocol_custom", selectedCustomName);

            // Safely refresh UI using singleShot to prevent crash
            QTimer::singleShot(0, this, [=](){ loadProtocols("protocol_custom", ui->tabCustom); });
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
    });

    // Run your initial tab setup
    setupTabs();

    last_theme_status = dark;
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
            if (item->widget()) {
                // Only delete widgets that are NOT our persistent buttons
                if (item->widget() != btnNew && item->widget() != btnModify &&
                        item->widget() != btnDelete && item->widget() != btnConfirm)
                {
                    delete item->widget();
                } else {
                    // Remove the button from the current layout parent visually
                    // without deleting its pointer from memory
                    item->widget()->setParent(nullptr);
                }
            }
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

            if (dark == 0)
            {
                item->setStyleSheet(
                            "ProtocolItemWidget {"
                    "background-color: rgb(60,60,60);"
                    "border-radius: 20px;"
                    "border: 3px solid rgb(255,97,34);"
                    "color: white;"
                    "}"
                    );
            }
            else
            {
                item->setStyleSheet(
                            "ProtocolItemWidget {"
                    "background-color: rgb(220,220,220);"
                    "border-radius: 20px;"
                    "border: 3px solid rgb(255,97,34);"
                    "color: black;"
                    "}"
                    );
            }
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

        if(dark == 0)
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

        // Re-add your persistent buttons
        buttonLayout->addWidget(btnNew);
        buttonLayout->addWidget(btnModify);
        buttonLayout->addWidget(btnDelete);
        buttonLayout->addWidget(btnConfirm);
        buttonLayout->addStretch();

        vbox->addLayout(buttonLayout);

        // Adjust visibility state matching current runtime mode
        if (mode == NormalMode) {
            btnConfirm->hide();
        } else {
            btnConfirm->show();
        }
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

    if(last_theme_status != dark)
        setupTabs();
    else
        loadProtocols("protocol_custom", ui->tabCustom);

    // Reload all tabs
    //    setupTabs();
    //    loadProtocols("protocol_custom", ui->tabCustom);


    qDebug() << "Protocol Select Refresh Complete";
}
