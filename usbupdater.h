// usbupdater.h - goes into the PRIMARY application (not the updater project).
// Detects an update binary on a USB drive and launches hikarixUpdaterGUI.
//
// Add this file to HEADERS in the primary app's .pro (it needs moc), then e.g.:
//
//   auto *usb = new UsbUpdater(this);
//   ui->updateButton->setEnabled(usb->updateAvailable());
//   connect(usb, &UsbUpdater::updateAvailableChanged, this,
//           [=] { ui->updateButton->setEnabled(usb->updateAvailable()); });
//   connect(ui->updateButton, &QPushButton::clicked, usb, &UsbUpdater::startUpdate);

#pragma once

#include <QDebug>
#include <QFile>
#include <QObject>
#include <QProcess>
#include <QStorageInfo>
#include <QStringList>
#include <QTimer>

// File name of the new binary in the root folder of the USB stick.
static const char kUsbBinaryName[] = "laser_ui_2";
// Where hikarixUpdaterGUI is installed (target.path in hikarixUpdaterGUI.pro).
static const char kUpdaterPath[]   = "/usr/bin/hikarixUpdaterGUI";

class UsbUpdater : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool updateAvailable READ updateAvailable NOTIFY updateAvailableChanged)

public:
    explicit UsbUpdater(QObject *parent = nullptr) : QObject(parent)
    {
        connect(&m_timer, &QTimer::timeout, this, &UsbUpdater::scan);
        m_timer.start(2000);   // poll mounted volumes every 2 s
        scan();
    }

    bool updateAvailable() const { return !m_newBinary.isEmpty(); }

public slots:
    // Hook this to the "Update" button (clicked signal, or call from QML).
    bool startUpdate()
    {
        scan();
        if (m_newBinary.isEmpty())
            return false;

        // systemd-run puts the updater in its own transient unit/cgroup, so it is
        // NOT killed when wayland-app-launch.service (and this app) is stopped.
        // A transient unit starts with a clean environment, so pass on what the
        // updater needs to connect to the same Wayland compositor as this app.
        QStringList args;
        args << "--unit=hikarix-updater"
             << "--collect"             // drop the unit afterwards, even if it failed
             << "--no-block"
             << "--setenv=XDG_RUNTIME_DIR=" + qEnvironmentVariable("XDG_RUNTIME_DIR", "/run/user/0")
             << "--setenv=WAYLAND_DISPLAY=" + qEnvironmentVariable("WAYLAND_DISPLAY", "wayland-0")
             << "--setenv=QT_QPA_PLATFORM=" + qEnvironmentVariable("QT_QPA_PLATFORM", "wayland")
             << QString::fromLatin1(kUpdaterPath)
             << m_newBinary;
        const bool ok = QProcess::startDetached("systemd-run", args);
        if (!ok)
            qWarning() << "Failed to launch updater";
        return ok;
    }

signals:
    void updateAvailableChanged();

private slots:
    void scan()
    {
        QString found;
        const auto volumes = QStorageInfo::mountedVolumes();
        for (const QStorageInfo &vol : volumes) {
            const QString root = vol.rootPath();
            // Toradex BSP automounts USB sticks under /run/media/<dev>
            if (!vol.isValid() || !vol.isReady())
                continue;
            if (!root.startsWith("/run/media/") && !root.startsWith("/media/"))
                continue;
            const QString candidate = root + "/" + QString::fromLatin1(kUsbBinaryName);
            if (QFile::exists(candidate)) {
                found = candidate;
                break;
            }
        }
        if (found != m_newBinary) {
            m_newBinary = found;
            emit updateAvailableChanged();
        }
    }

private:
    QString m_newBinary;
    QTimer  m_timer;
};
