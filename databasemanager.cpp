#include "databasemanager.h"
#include <QSqlError>
#include <QDebug>
#include "global.h"

DatabaseManager::DatabaseManager()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE", "SYSTEM_DB");
}


DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::connect(const QString& databasePath)
{
    if (m_database.isOpen())
        return true;

    m_database.setDatabaseName(databasePath);

    if (!m_database.open()) {
       //qDebug() << "SYSTEM DB open failed:" << m_database.lastError().text();
        return false;
    }

   //qDebug() << "✅ SYSTEM DB connected:" << databasePath;
    return true;
}


void DatabaseManager::close()
{
    if (m_database.isOpen()) {
        m_database.close();
    }
}

bool DatabaseManager::isConnected() const
{
    return m_database.isOpen();
}

QSqlDatabase& DatabaseManager::db()
{
    return m_database;
}
