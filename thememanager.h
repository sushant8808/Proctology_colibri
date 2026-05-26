#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QObject>
#include <QPalette>
#include <QApplication>


class ThemeManager : public QObject
{
    Q_OBJECT

public:
    explicit ThemeManager(QObject *parent = nullptr);

    static void applyDarkTheme();
    static void applyLightTheme();
    static void Dark_theme();
    static void Light_theme();

};

#endif // THEMEMANAGER_H
