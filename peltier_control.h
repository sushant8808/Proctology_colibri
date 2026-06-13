#ifndef PELTIER_CONTROL_H
#define PELTIER_CONTROL_H

#include <QObject>
#include <QTimer>

#include "hardwaremanager.h"
#include "hardwaremanagerprovider.h"
#include "colibri_adc.h"

class peltier_control : public QObject
{
    Q_OBJECT

public:
    explicit peltier_control(QObject *parent = nullptr);

    void start();
    void stop();

    void setTemperature(float temp);

private slots:
    void controlLoop();

private:
    float adcToTemperature(uint16_t adcValue);

    struct PID_t
    {
        float kp;
        float ki;
        float kd;

        float integral;
        float previousError;
    };

    PID_t pid;

    QTimer m_timer;

    HardwareManager *m_hw;

    float m_setTemp;

    Colibri_ADC m_adc;
};

#endif
