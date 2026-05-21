#include "userdatabaseinitializer.h"
#include "userdatabasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool UserDatabaseInitializer::initialize()
{
    return createTables();
}

bool UserDatabaseInitializer::createTables()
{
    QSqlQuery query(UserDatabaseManager::instance().db());

    // 1️⃣ Surgery log table
    QString createSurgeryLogTable = R"(
        CREATE TABLE IF NOT EXISTS surgery_log_by_id (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            surgery_id INTEGER NOT NULL,
            protocol_name TEXT NOT NULL,
            power_980 REAL NOT NULL,
            power_1470 REAL NOT NULL,
            power_650 INTEGER NOT NULL,
            max_pedal_timer_sec REAL NOT NULL,
            timer_reset INTEGER NOT NULL CHECK(timer_reset IN (0,1)),
            timer_flag  INTEGER NOT NULL CHECK(timer_flag IN (0,1)),
            pulse_on_time_ms REAL NOT NULL,
            pulse_off_time_ms REAL NOT NULL,
            pulse_mode INTEGER NOT NULL,
            energy_per_pedal REAL NOT NULL,
            total_energy REAL NOT NULL,
            stored_energy_1 REAL NOT NULL,
            stored_energy_2 REAL NOT NULL,
            stored_energy_3 REAL NOT NULL,
            stored_energy_4 REAL NOT NULL,
            stored_energy_5 REAL NOT NULL,
            stored_energy_6 REAL NOT NULL,
            stored_energy_7 REAL NOT NULL,
            stored_energy_8 REAL NOT NULL,
            created_at DATETIME DEFAULT (datetime('now','localtime'))
        );
    )";

    if (!query.exec(createSurgeryLogTable)) {
        qDebug() << "Failed to create surgery_log_by_id:" << query.lastError().text();
        return false;
    }

    // 2️⃣ Surgery details table
    QString createSurgeryDetailsTable = R"(
        CREATE TABLE IF NOT EXISTS surgery_details (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            surgery_id INTEGER NOT NULL UNIQUE,
            surgeon_name TEXT NOT NULL,
            patient_id TEXT NOT NULL,
            patient_name TEXT NOT NULL,
            patient_age INTEGER,
            gender TEXT CHECK (gender IN ('Male', 'Female', 'Other', 'Skip')),
            surgery_name TEXT NOT NULL,
            created_at DATETIME DEFAULT (datetime('now','localtime'))
        );
    )";

    if (!query.exec(createSurgeryDetailsTable)) {
        qDebug() << "Failed to create surgery_details:" << query.lastError().text();
        return false;
    }

    // 3️⃣ Surgery summary table
    QString createSurgerySummaryTable = R"(
    CREATE TABLE IF NOT EXISTS surgery_summary (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        surgery_id INTEGER NOT NULL UNIQUE,
        protocol_name TEXT NOT NULL,
        surgery_start_time DATETIME NOT NULL,
        surgery_duration_sec REAL NOT NULL,
        laser_activation_duration_sec REAL NOT NULL,
        total_energy_delivered REAL NOT NULL,
        effective_power REAL NOT NULL,
        fiber_disconnection_count INTEGER NOT NULL,
        created_at DATETIME DEFAULT (datetime('now','localtime'))
    );
)";

    if (!query.exec(createSurgerySummaryTable)) {
        qDebug() << "Failed to create surgery_summary:" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ USER DB tables created";
    return true;
}

bool UserDatabaseInitializer::deleteAllUserData()
{
    QSqlQuery query(UserDatabaseManager::instance().db());

    if (!query.exec("BEGIN TRANSACTION;")) {
        qDebug() << "Transaction begin failed:" << query.lastError().text();
        return false;
    }

    // Delete surgery logs
    if (!query.exec("DELETE FROM surgery_log_by_id;")) {
        qDebug() << "Failed to delete surgery_log_by_id:"
                 << query.lastError().text();
        query.exec("ROLLBACK;");
        return false;
    }

    // Delete surgery details
    if (!query.exec("DELETE FROM surgery_details;")) {
        qDebug() << "Failed to delete surgery_details:"
                 << query.lastError().text();
        query.exec("ROLLBACK;");
        return false;
    }

    // Reset AUTOINCREMENT counters (important)
    if (!query.exec("DELETE FROM sqlite_sequence WHERE name='surgery_log_by_id';"))
        qDebug() << "Failed to reset sequence log table";

    if (!query.exec("DELETE FROM sqlite_sequence WHERE name='surgery_details';"))
        qDebug() << "Failed to reset sequence details table";

    if (!query.exec("COMMIT;")) {
        qDebug() << "Transaction commit failed:" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ All user data deleted successfully";
    return true;
}

bool UserDatabaseInitializer::deleteAllSurgerySummary()
{
    QSqlQuery query(UserDatabaseManager::instance().db());

    if (!query.exec("BEGIN TRANSACTION;")) {
        qDebug() << "Transaction begin failed:"
                 << query.lastError().text();
        return false;
    }

    // Delete all surgery summary records
    if (!query.exec("DELETE FROM surgery_summary;")) {
        qDebug() << "Failed to delete surgery_summary:"
                 << query.lastError().text();

        query.exec("ROLLBACK;");
        return false;
    }

    // Reset AUTOINCREMENT counter
    if (!query.exec(
            "DELETE FROM sqlite_sequence "
            "WHERE name='surgery_summary';"))
    {
        qDebug() << "Failed to reset sequence summary table";
    }

    if (!query.exec("COMMIT;")) {
        qDebug() << "Transaction commit failed:"
                 << query.lastError().text();
        return false;
    }

    qDebug() << "✅ All surgery summary deleted successfully";

    return true;
}

bool UserDatabaseInitializer::insertSurgerySummary(
    qint64 surgery_id,
    const QString &protocol_name,
    const QString &start_time,
    double surgery_duration,
    double laser_duration,
    double total_energy,
    double effective_power,
    int fiber_disconnect_count)
{
    QSqlQuery query(UserDatabaseManager::instance().db());

    query.prepare(R"(
        INSERT INTO surgery_summary (
            surgery_id,
            protocol_name,
            surgery_start_time,
            surgery_duration_sec,
            laser_activation_duration_sec,
            total_energy_delivered,
            effective_power,
            fiber_disconnection_count
        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?)
    )");

    query.addBindValue(surgery_id);
    query.addBindValue(protocol_name);
    query.addBindValue(start_time);
    query.addBindValue(surgery_duration);
    query.addBindValue(laser_duration);
    query.addBindValue(total_energy);
    query.addBindValue(effective_power);
    query.addBindValue(fiber_disconnect_count);

    if (!query.exec()) {
        qDebug() << "Insert surgery_summary failed:" << query.lastError().text();
        return false;
    }

    return true;
}

QVariantMap UserDatabaseInitializer::getSurgerySummary(int surgery_id)
{
    QSqlQuery query(UserDatabaseManager::instance().db());
    QVariantMap data;

    query.prepare("SELECT * FROM surgery_summary WHERE surgery_id = ?");
    query.addBindValue(surgery_id);

    if (!query.exec()) {
        qDebug() << "Fetch surgery_summary failed:" << query.lastError().text();
        return data;
    }

    if (query.next()) {
        data["surgery_id"] = query.value("surgery_id");
        data["protocol_name"] = query.value("protocol_name");
        data["start_time"] = query.value("surgery_start_time");
        data["surgery_duration"] = query.value("surgery_duration_sec");
        data["laser_duration"] = query.value("laser_activation_duration_sec");
        data["total_energy"] = query.value("total_energy_delivered");
        data["effective_power"] = query.value("effective_power");
        data["fiber_disconnect"] = query.value("fiber_disconnection_count");
    }

    return data;
}

bool UserDatabaseInitializer::deleteSurgerySummary(int surgery_id)
{
    QSqlQuery query(UserDatabaseManager::instance().db());

    query.prepare("DELETE FROM surgery_summary WHERE surgery_id = ?");
    query.addBindValue(surgery_id);

    if (!query.exec()) {
        qDebug() << "Delete surgery_summary failed:" << query.lastError().text();
        return false;
    }

    return true;
}

