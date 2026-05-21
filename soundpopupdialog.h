#ifndef SOUNDPOPUPDIALOG_H
#define SOUNDPOPUPDIALOG_H

#include <QDialog>
#include <QTimer>

class QSlider;
class QLabel;

class SoundPopupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SoundPopupDialog(QWidget *parent = nullptr);

private slots:
    void onSliderValueChanged(int value);
    void onSlider2ValueChanged(int value);

private:  
    QLabel *label;
    QSlider *slider;

    QLabel *label2;
    QSlider *slider2;


};

#endif // SOUNDPOPUPDIALOG_H
