#ifndef PROTOCOLSELECT_H
#define PROTOCOLSELECT_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>
#include <QPushButton>

class Home;

// ---- Custom Mode ----
enum CustomMode {
    NormalMode,
    ModifyMode,
    DeleteMode
};

extern bool customMode;
extern int selectedCustomId;
extern QString selectedCustomName;

namespace Ui {
class protocolselect;
}

class protocolselect : public QWidget
{
    Q_OBJECT

public:
    explicit protocolselect(QWidget *parent = nullptr, Home *home = nullptr);
    ~protocolselect();

protected:
    void showEvent(QShowEvent *event) override;

private:
    Ui::protocolselect *ui;
    Home *home;

    CustomMode mode = NormalMode;

    void setupTabs();
    void loadProtocols(const QString &tableName, QWidget *tabWidget);
    void loadHomeFromGlobals();  // Update Home UI or global variables

    QPushButton *btnNew;
    QPushButton *btnModify;
    QPushButton *btnDelete;
    QPushButton *btnConfirm;

    void refreshPage();


signals:
    void protocolSelected(const QString &protocolName);

private slots:
    void on_B3_back_to_home_clicked();

    void switchTonewprotocol();


};

#endif // PROTOCOLSELECT_H
