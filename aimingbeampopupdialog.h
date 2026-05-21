#ifndef AIMINGBEAMPOPUPDIALOG_H
#define AIMINGBEAMPOPUPDIALOG_H

#include <QDialog>
#include <QTimer>

class QSlider;
class QLabel;

class AimingBeamPopupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AimingBeamPopupDialog(QWidget *parent = nullptr);

private slots:
    void onSliderValueChanged(int value);

private:
    QSlider *slider;
    QLabel *label;
};

#endif // AIMINGBEAMPOPUPDIALOG_H
