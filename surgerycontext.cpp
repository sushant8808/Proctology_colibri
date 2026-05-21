#include "surgerycontext.h"
#include <QDateTime>

qint64 g_surgeryId = 0;

void startNewSurgery()
{
    g_surgeryId = QDateTime::currentMSecsSinceEpoch();
}
