#ifndef MQS_AUDIO_H
#define MQS_AUDIO_H
#include <QProcess>
#include <QFile>
#include <QThread>
#include <QDebug>
#include <QObject>

class MQS_Audio : public QObject
{
    Q_OBJECT
public:
    MQS_Audio(QObject *parent = nullptr);

private:

    void startAplay();

public slots:
    void playWav(const QString &path);
    void setMqsVolume(u_int8_t vol);
};

#endif // MQS_AUDIO_H
