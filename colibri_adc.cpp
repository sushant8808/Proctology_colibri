#include "colibri_adc.h"

Colibri_ADC::Colibri_ADC(QObject *parent) : QObject(parent)
{

}

int Colibri_ADC::readRaw(int channel)
{
    // Validate channel
            if (channel < 0 || channel > 9) {
                qDebug() << "Invalid ADC channel";
                return -1;
            }

            QString path =
                QString("/sys/bus/iio/devices/iio:device0/in_voltage%1_raw")
                .arg(channel);

            QFile file(path);

            if (!file.open(QIODevice::ReadOnly)) {
                qDebug() << "Cannot open:" << path;
                return -1;
            }

            QByteArray data = file.readAll();

            file.close();

            bool ok;

            int value = data.trimmed().toInt(&ok);

            if (!ok) {
                qDebug() << "ADC conversion failed";
                return -1;
            }

            return value;
}

float Colibri_ADC::readVoltage(int channel)
{
    int raw = readRaw(channel);

            if (raw < 0)
                return -1.0f;

            // 12-bit ADC, 3.3V reference
            return (raw * 3.3f) / 4095.0f;
}

