#ifndef RUNTIMEMANAGER_H
#define RUNTIMEMANAGER_H

#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
#include "global.h"



class RuntimeManager : public QObject
{
    Q_OBJECT

public:
    explicit RuntimeManager(QObject *parent = nullptr);
    ~RuntimeManager();

    void start();

    void set1470Active(bool state);
    void set980Active(bool state);

    void setSurgeryActive(bool active);

private slots:
    void updateMinuteTimers();
    void handleAppAboutToQuit();

private:
    void update1470ToDatabase(qint64 seconds);
    void update980ToDatabase(qint64 seconds);

private:
    QTimer *minuteTimer;

    bool diode1470Active;
    bool diode980Active;

    double systemMinuteAccumulator = 0.0;
    bool surgeryActive = false;

    QElapsedTimer diode1470Elapsed;
    QElapsedTimer diode980Elapsed;
    QElapsedTimer systemElapsed;
};

#endif // RUNTIMEMANAGER_H
