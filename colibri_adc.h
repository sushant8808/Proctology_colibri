#ifndef COLIBRI_ADC_H
#define COLIBRI_ADC_H
#include <QFile>
#include <QDebug>
#include <QObject>

class Colibri_ADC : public QObject
{
    Q_OBJECT
public:
    explicit Colibri_ADC(QObject *parent = nullptr);
    static int readRaw(int channel);
    static float readVoltage(int channel);

signals:

};

#endif // COLIBRI_ADC_H
