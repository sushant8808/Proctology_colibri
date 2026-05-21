#ifndef PROTOCOLSELECT_H
#define PROTOCOLSELECT_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>

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
    void refreshPage();

private:
    Ui::protocolselect *ui;
    Home *home;

    CustomMode mode = NormalMode;

    void setupTabs();
    void loadProtocols(const QString &tableName, QWidget *tabWidget);
    void loadHomeFromGlobals();  // Update Home UI or global variables


signals:
    void protocolSelected(const QString &protocolName);

private slots:
    void on_B3_back_to_home_clicked();

    void switchTonewprotocol();


};

#endif // PROTOCOLSELECT_H
