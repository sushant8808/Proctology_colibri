#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>

class DatabaseManager
{
public:
    static DatabaseManager& instance();

    bool connect(const QString& databasePath);
    void close();
    bool isConnected() const;
    QSqlDatabase& db();

private:
    DatabaseManager();
    QSqlDatabase m_database;
};

#endif // DATABASEMANAGER_H
