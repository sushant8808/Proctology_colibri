#include "runtime_manager.h"
#include "databasemanager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCoreApplication>

RuntimeManager::RuntimeManager(QObject *parent)
    : QObject(parent),
    diode1470Active(false),
    diode980Active(false)
{
    minuteTimer = new QTimer(this);
    minuteTimer->setInterval(1000);

    connect(minuteTimer, &QTimer::timeout,
            this, &RuntimeManager::updateMinuteTimers);

    // Ensure diode time is saved if app closes while ON
    connect(qApp, &QCoreApplication::aboutToQuit,
            this, &RuntimeManager::handleAppAboutToQuit);
}

RuntimeManager::~RuntimeManager()
{
}

void RuntimeManager::start()
{
    systemElapsed.start();
    if (!minuteTimer->isActive())
    {
        systemElapsed.start();
        minuteTimer->start();
    }
}

void RuntimeManager::setSurgeryActive(bool active)
{
    surgeryActive = active;

    // Optional: reset surgery timer when starting fresh surgery
    if (active)
    {
        g_surgery_ms = 0;
        g_diode1470Ms_persurgery = 0;
        g_diode980Ms_persurgery = 0;
    }
}

//////////////////////////////////////////////////////////////////
// SYSTEM + RENTAL TIMER (Every 1 minute)
//////////////////////////////////////////////////////////////////

void RuntimeManager::updateMinuteTimers()
{

    if (!systemElapsed.isValid())
        systemElapsed.start();

    qint64 elapsed_ms = systemElapsed.elapsed();
    systemElapsed.restart();

    if (elapsed_ms < 200)
        return;

    double elapsed_minutes = elapsed_ms / 60000.0;

    // ✅ accumulate
    systemMinuteAccumulator += elapsed_minutes;

    // ✅ update DB only when >= 1 minute
    if (systemMinuteAccumulator >= 1.0)
    {
        int minutesToAdd = static_cast<int>(systemMinuteAccumulator);

        QSqlQuery query(DatabaseManager::instance().db());

        query.prepare(
            "UPDATE system_timer "
            "SET total_system_minutes = total_system_minutes + ? "
            "WHERE id = 1");

        query.addBindValue(minutesToAdd);

        if (!query.exec())
        {
            qDebug() << "System timer update failed:"
                     << query.lastError().text();
        }

        systemMinuteAccumulator -= minutesToAdd;
    }

    // Update your global variable also properly
    if (surgeryActive)
    {
        g_surgery_ms += elapsed_ms;
    }
}

//////////////////////////////////////////////////////////////////
// 1470 DIODE CONTROL
//////////////////////////////////////////////////////////////////

void RuntimeManager::set1470Active(bool state)
{
    if (state && !diode1470Active)
    {
        // Turned ON
        diode1470Active = true;
        diode1470Elapsed.start();
    }
    else if (!state && diode1470Active)
    {
        // Turned OFF
        diode1470Active = false;

        qint64 ms = diode1470Elapsed.elapsed();
        update1470ToDatabase(ms);
    }
}

void RuntimeManager::update1470ToDatabase(qint64 ms)
{
    if (ms <= 0)
        return;

    // Update global rental variable
    g_diode1470Ms_persurgery += ms;

    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare(
        "UPDATE system_timer "
        "SET diode_1470_ms = diode_1470_ms + ? "
        "WHERE id = 1");

    query.addBindValue(ms);

    if (!query.exec())
    {
        qDebug() << "1470 timer update failed:"
                 << query.lastError().text();
    }
}

//////////////////////////////////////////////////////////////////
// 980 DIODE CONTROL
//////////////////////////////////////////////////////////////////

void RuntimeManager::set980Active(bool state)
{
    if (state && !diode980Active)
    {
        diode980Active = true;
        diode980Elapsed.start();
    }
    else if (!state && diode980Active)
    {
        diode980Active = false;

        qint64 ms = diode980Elapsed.elapsed();
        update980ToDatabase(ms);
    }
}

void RuntimeManager::update980ToDatabase(qint64 ms)
{
    if (ms <= 0)
        return;

    // Update global rental variable
    g_diode980Ms_persurgery += ms;

    QSqlQuery query(DatabaseManager::instance().db());

    query.prepare(
        "UPDATE system_timer "
        "SET diode_980_ms = diode_980_ms + ? "
        "WHERE id = 1");

    query.addBindValue(ms);

    if (!query.exec())
    {
        qDebug() << "980 timer update failed:"
                 << query.lastError().text();
    }
}

//////////////////////////////////////////////////////////////////
// 5️⃣ SAFETY: SAVE DIODE TIME IF APP CLOSES WHILE ON
//////////////////////////////////////////////////////////////////

void RuntimeManager::handleAppAboutToQuit()
{
    // ✅ capture last elapsed chunk
    qint64 elapsed_ms = systemElapsed.elapsed();

    if (elapsed_ms > 0)
    {
        systemMinuteAccumulator += (elapsed_ms / 60000.0);
    }

    // ✅ flush accumulator
    if (systemMinuteAccumulator > 0)
    {
        QSqlQuery query(DatabaseManager::instance().db());

        query.prepare(
            "UPDATE system_timer "
            "SET total_system_minutes = total_system_minutes + ? "
            "WHERE id = 1");

        query.addBindValue(systemMinuteAccumulator);

        if (!query.exec())
        {
            qDebug() << "Final system time update failed:"
                     << query.lastError().text();
        }

        systemMinuteAccumulator = 0;
    }

    // ✅ save diode times
    if (diode1470Active)
    {
        qint64 ms = diode1470Elapsed.elapsed();
        update1470ToDatabase(ms);
    }

    if (diode980Active)
    {
        qint64 ms = diode980Elapsed.elapsed();
        update980ToDatabase(ms);
    }
}



