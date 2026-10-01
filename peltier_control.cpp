#include "peltier_control.h"

#include <QDebug>
#include <math.h>

#define ADC_CH2             2
#define ADC_CH0             0

#define ADC_MAX             4095.0f
#define ADC_REF             3.3f

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

    pid.kp = 8.0f;
    pid.ki = 0.05f;
    pid.kd = 3.0f;

    pid.integral = 0;
    pid.previousError = 0;

    connect(&m_timer,
            &QTimer::timeout,
            this,
            &peltier_control::controlLoop);
}

void peltier_control::start()
{
    if (!m_timer.isActive())
    {
        qDebug() << "Peltier control started";
        m_timer.start(100);
    }
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
    /*
     * ADC calibration points:
     *
     * ADC = 2650 -> 10.0 °C
     * ADC = 2950 -> 35.0 °C
     */

    const float ADC_LOW  = 2650.0f;
    const float TEMP_LOW = 10.0f;

    const float ADC_HIGH  = 2950.0f;
    const float TEMP_HIGH = 40.0f;

    float temperature =
        TEMP_LOW +
        ((float)adcValue - ADC_LOW) *
        (TEMP_HIGH - TEMP_LOW) /
        (ADC_HIGH - ADC_LOW);

    return temperature;
}

void peltier_control::controlLoop()
{
    uint16_t adcRaw =
            (uint16_t)m_adc.readRaw(ADC_CH2);

    uint16_t adcRaw_0 = (uint16_t)m_adc1.readRaw(ADC_CH0);

//    qDebug()<<"adc 0 or sma value - "<<adcRaw_0;

    float currentTemp =
            adcToTemperature(adcRaw);

    g_diode_temp = currentTemp;

    // Cooling required only when temperature is above setpoint
    if(currentTemp <= m_setTemp)
    {
        pid.integral = 0;
        pid.previousError = 0;

        m_hw->setPwm(
                    m_hw->m_pwms['D'],
                    0,
                    PWM_PERIOD_NS);

//        qDebug()
//                << "ADC =" << adcRaw
//                << "Temp =" << currentTemp
//                << "Set =" << m_setTemp
//                << "PWM = 0 (Cooling OFF)";

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

//    qDebug()
//            << "ADC =" << adcRaw
//            << "Temp =" << currentTemp
//            << "Set =" << m_setTemp
//            << "PWM =" << output;
}
