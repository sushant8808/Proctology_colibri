#include "hardwaremanagerprovider.h"
#include "hardwaremanager.h"

#include <QApplication>
#include <QVariant>
#include <QDebug>


static const char *HW_PROPERTY = "hardware_manager";

HardwareManager *HardwareManagerProvider::instance()
{
    if (!qApp) {
        qCritical() << "QApplication not initialized";
        return nullptr;
    }

    QVariant v = qApp->property(HW_PROPERTY);
    if (!v.isValid()) {
        qCritical() << "HardwareManager not set in QApplication";
        return nullptr;
    }

    auto *hw = qobject_cast<HardwareManager *>(v.value<QObject*>());
    if (!hw) {
        qCritical() << "Invalid HardwareManager object";
    }

    return hw;
}
