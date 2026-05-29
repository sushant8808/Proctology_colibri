#include "mqs_audio.h"

static QProcess *aplay = nullptr;
static QProcess *amixer = nullptr;

MQS_Audio::MQS_Audio(QObject *parent) : QObject(parent)
{
//    startAplay();
}

void MQS_Audio::startAplay()
{
    if (aplay) return;

    aplay = new QProcess();

    QStringList args;
//    args << "-f" << "S16_LE"
//         << "-r" << "44100"
//         << "-c" << "1"
//         << "-q"
//         << "-";
    args << "-f" << "S16_LE"
         << "-r" << "44100"
         << "-c" << "1"
         << "-q"
         << "-" << "softvol";

    aplay->start("aplay", args);

    if (!aplay->waitForStarted()) {
        qFatal("Failed to start aplay");
    }
}

void MQS_Audio::playWav(const QString &path)
{
//    QFile f(path);
//    if (!f.open(QIODevice::ReadOnly)) {
//        qDebug() << "Cannot open file";
//        return;
//    }

//    QByteArray data = f.readAll();

//    // assume PCM WAV
//    QByteArray pcm = data.mid(44);

//    // IMPORTANT: write in one shot (no loops, no blocking wait)
//    aplay->write(pcm);
    QString program = "aplay";

    QStringList arguments;
    arguments << "-D" << "softvol" << path;

    QProcess *process = new QProcess();

    process->startDetached(program, arguments);


    // Optional: wait until started
    if (!process->waitForStarted()) {
        qDebug() << "Failed to start aplay";
        return;
    }
}

void MQS_Audio::setMqsVolume(u_int8_t vol)
{
    QString program = "amixer";

        QStringList arguments;
        arguments << "sset"
                  << "SoftMaster"
                  << QString("%1%").arg(vol);

        QProcess process;

        process.start(program, arguments);

        if (!process.waitForFinished()) {
            qDebug() << "Failed to set volume";
            return;
        }

        qDebug() << process.readAllStandardOutput();
}
