#include "userdatabasemanager.h"
#include <QSqlError>
#include <QDebug>

UserDatabaseManager::UserDatabaseManager()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE", "USER_DB");
}

UserDatabaseManager::~UserDatabaseManager()
{
    close();
}

UserDatabaseManager& UserDatabaseManager::instance()
{
    static UserDatabaseManager instance;
    return instance;
}

bool UserDatabaseManager::connect(const QString& databasePath)
{
    if (m_database.isOpen())
        return true;

    m_database.setDatabaseName(databasePath);

    if (!m_database.open()) {
       //qDebug() << "USER DB open failed:" << m_database.lastError().text();
        return false;
    }

   //qDebug() << "✅ USER DB connected:" << databasePath;
    return true;
}

void UserDatabaseManager::close()
{
    if (m_database.isOpen())
        m_database.close();
}

bool UserDatabaseManager::isConnected() const
{
    return m_database.isOpen();
}

QSqlDatabase& UserDatabaseManager::db()
{
    return m_database;
}
