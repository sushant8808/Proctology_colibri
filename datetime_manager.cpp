#include "datetime_manager.h"

DateTimeManager* DateTimeManager::m_instance = nullptr;

DateTimeManager::DateTimeManager(QObject *parent)
    : QObject(parent)
{
    m_dateTime = QDateTime::currentDateTime();

    m_timer = new QTimer(this);

    connect(m_timer, &QTimer::timeout,
            this, &DateTimeManager::updateTime);

    m_timer->start(1000);   // tick every 1 second
}

DateTimeManager* DateTimeManager::instance()
{
    if (!m_instance)
        m_instance = new DateTimeManager();

    return m_instance;
}

QDateTime DateTimeManager::currentDateTime() const
{
    return m_dateTime;
}

void DateTimeManager::setDateTime(const QDateTime &dt)
{
    m_dateTime = dt;
    emit dateTimeChanged(m_dateTime);
}

void DateTimeManager::updateTime()
{
    m_dateTime = m_dateTime.addSecs(1);
    emit dateTimeChanged(m_dateTime);
}
