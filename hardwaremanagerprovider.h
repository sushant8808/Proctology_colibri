#ifndef HARDWAREMANAGERPROVIDER_H
#define HARDWAREMANAGERPROVIDER_H

#include <QObject>
#include "hardwaremanager.h"
#define TOUCH_BEEP() HardwareManagerProvider::instance()->beep(HardwareManager::TouchBeep);
#define WARNING_BEEP() HardwareManagerProvider::instance()->beep(HardwareManager::WarningBeep);
#define ERROR_BEEP() HardwareManagerProvider::instance()->beep(HardwareManager::ErrorBeep);
#define SUCCESS_BEEP() HardwareManagerProvider::instance()->beep(HardwareManager::SuccessBeep);
class HardwareManager;

/*
 * Lightweight access point to the application-wide HardwareManager.
 * No globals, proper lifetime, safe for embedded Qt apps.
 */
class HardwareManagerProvider
{
public:
    static HardwareManager *instance();
};

#endif // HARDWAREMANAGERPROVIDER_H
