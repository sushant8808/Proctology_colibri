#include "peltier_control.h"

#include <QDebug>
#include <math.h>

#define ADC_CH2             2

#define ADC_MAX             4095.0f
#define ADC_REF             1.8f

#define NTC_R0              10000.0f
#define NTC_BETA            3950.0f
#define NTC_T0              298.15f

#define SERIES_RESISTOR     10000.0f

#define PWM_PERIOD_NS       1000000

peltier_control::peltier_control(QObject *parent)
    : QObject(parent)
{
    m_hw = HardwareManagerProvider::instance();

    m_setTemp = 23.0f;

    pid.kp = 5.0f;
    pid.ki = 0.00f;
    pid.kd = 2.0f;

    pid.integral = 0;
    pid.previousError = 0;

    connect(&m_timer,
            &QTimer::timeout,
            this,
            &peltier_control::controlLoop);
}

void peltier_control::start()
{
    m_timer.start(100);     // 100ms
}

void peltier_control::stop()
{
    m_timer.stop();
}

void peltier_control::setTemperature(float temp)
{
    m_setTemp = temp;
}

float peltier_control::adcToTemperature(uint16_t adcValue)
{
    float voltage =
            ((float)adcValue * ADC_REF) / ADC_MAX;

    if(voltage < 0.01f)
        voltage = 0.01f;

    if(voltage > 3.29f)
        voltage = 3.29f;

    float resistance =
            (SERIES_RESISTOR * voltage) /
            (ADC_REF - voltage);

    float tempK =
            1.0f /
            (
                (1.0f / NTC_T0)
                +
                (1.0f / NTC_BETA)
                *
                log(resistance / NTC_R0)
            );

    return tempK - 273.15f;
}

void peltier_control::controlLoop()
{
    uint16_t adcRaw =
            (uint16_t)m_adc.readRaw(ADC_CH2);

    float currentTemp =
            adcToTemperature(adcRaw);

    // Cooling required only when temperature is above setpoint
    if(currentTemp <= m_setTemp)
    {
        pid.integral = 0;
        pid.previousError = 0;

        m_hw->setPwm(
                    m_hw->m_pwms['D'],
                    0,
                    PWM_PERIOD_NS);

        qDebug()
                << "ADC =" << adcRaw
                << "Temp =" << currentTemp
                << "Set =" << m_setTemp
                << "PWM = 0 (Cooling OFF)";

        return;
    }

    float error = currentTemp - m_setTemp;

    float dt = 0.1f;

    pid.integral += error * dt;

    float derivative =
            (error - pid.previousError) / dt;

    float output =
            (pid.kp * error)
            +
            (pid.ki * pid.integral)
            +
            (pid.kd * derivative);

    pid.previousError = error;

    if(output < 0)
        output = 0;

    if(output > 100)
        output = 100;

    int dutyNs =
            (int)((output / 100.0f)
                  * PWM_PERIOD_NS);

    m_hw->setPwm(
                m_hw->m_pwms['D'],
                dutyNs,
                PWM_PERIOD_NS);

    qDebug()
            << "ADC =" << adcRaw
            << "Temp =" << currentTemp
            << "Set =" << m_setTemp
            << "PWM =" << output;
}
