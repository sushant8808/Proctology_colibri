#ifndef PULSEMODE_H
#define PULSEMODE_H

#include <QWidget>
#include "home.h"

namespace Ui {
class PulseMode;
}

class PulseMode : public QWidget
{
    Q_OBJECT

public:
    explicit PulseMode(QWidget *parent = nullptr, Home *home = nullptr);
    ~PulseMode();

protected:
    void showEvent(QShowEvent *event) override;

private:
    void refreshPage();

private slots:

    void on_B3_back_to_setting_clicked();

    void on_dec_low_value_clicked();

    void on_inc_low_value_clicked();

    void on_dec_high_value_clicked();

    void on_inc_high_value_clicked();

private:
    Ui::PulseMode *ui;
    Home *home;

    QString formatPulseTime(int valueUs);
    QString getPulseUnit(int valueUs);
    void updateRangeLabels();



};

#endif // PULSEMODE_H
