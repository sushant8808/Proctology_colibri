#ifndef USERDATABASEMANAGER_H
#define USERDATABASEMANAGER_H

#include <QSqlDatabase>

class UserDatabaseManager
{
public:
    static UserDatabaseManager& instance();

    bool connect(const QString& databasePath);
    void close();
    bool isConnected() const;

    QSqlDatabase& db();

private:
    UserDatabaseManager();
    ~UserDatabaseManager();

    QSqlDatabase m_database;
};

#endif
