#ifndef READYFORSURGERY_H
#define READYFORSURGERY_H

#include <QWidget>
#include "global.h"
#include "home.h"
#include "circularoverlay.h"
#include "timerring.h"
#include "changevalue.h"
#include <QElapsedTimer>
#include <QTimer>
#include <QQueue>
#include <QString>
#include "error_popup.h"




namespace Ui {
class ReadyForSurgery;
}

class ReadyForSurgery : public QWidget
{
    Q_OBJECT

public:
    explicit ReadyForSurgery(QWidget *parent = nullptr, Home *home = nullptr);
    ~ReadyForSurgery();

protected:
    void showEvent(QShowEvent *event) override;

private:
    void refreshPage();

private slots:
    void updatePower980Label();

    void updatePower1470Label();

    void updateTimerSecLabel();

    void updateTimerStateLabel();

    void updatePulseLabels();

    void updateJouleLabel();

    void on_B5_aimingbeam_clicked();

    void on_B5_sound_clicked();

    void on_B5_brightness_clicked();

    void on_B5_to_standby_clicked();

    void on_B5_change_clicked();

    void on_B5_reset_clicked();

    void on_B5_pause_clicked();

    void end_surgery(void);

    void resetSurgerySession();

private:
    Ui::ReadyForSurgery *ui;
    Home *home;
    TimerRing *timerRing; // <-- member variable for timer ring

    CircularOverlay *aimingBeamOverlay = nullptr;
    CircularOverlay *soundOverlay = nullptr;
    CircularOverlay *brightnessOverlay = nullptr;

    QQueue<QString> audioQueue;

    error_popup *popup;

    int lastAnnouncedEnergy = 0;
    int lastAnnouncedSeconds = 0;
    bool isPlaying = false;

    void playNextAudio();



    QTimer *energyUpdateTimer = nullptr;

    void updateEnergy();

    int Fiber_disconnection_count = 0;

    QString start_date_time = "";

    QString formatPulseTime(int valueUs);
    QString getPulseUnit(int valueUs);

};

#endif // READYFORSURGERY_H
