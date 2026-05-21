#ifndef BRIGHTNESSPOPUPDIALOG_H
#define BRIGHTNESSPOPUPDIALOG_H

#include <QDialog>
#include <QTimer>

class QSlider;
class QLabel;

class BrightnessPopupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BrightnessPopupDialog(QWidget *parent = nullptr);

private slots:
    void onSliderValueChanged(int value);

private:
    QSlider *slider;
    QLabel *label;
};

#endif // BRIGHTNESSPOPUPDIALOG_H
