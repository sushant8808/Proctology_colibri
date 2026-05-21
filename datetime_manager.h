#ifndef DATETIME_MANAGER_H
#define DATETIME_MANAGER_H

#include <QObject>
#include <QDateTime>
#include <QTimer>

class DateTimeManager : public QObject
{
    Q_OBJECT

public:
    static DateTimeManager* instance();

    QDateTime currentDateTime() const;
    void setDateTime(const QDateTime &dt);

signals:
    void dateTimeChanged(const QDateTime &dt);

private slots:
    void updateTime();   // <-- new

private:
    explicit DateTimeManager(QObject *parent = nullptr);
    static DateTimeManager* m_instance;

    QDateTime m_dateTime;
    QTimer *m_timer;     // <-- new
};

#endif
