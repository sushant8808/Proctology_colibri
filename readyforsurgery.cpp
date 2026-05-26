#include "readyforsurgery.h"
#include "ui_readyforsurgery.h"
#include "soundpopupdialog.h"
#include "brightnesspopupdialog.h"
#include "aimingbeampopupdialog.h"
#include "databaseinitializer.h"
#include "userdatabaseinitializer.h"
#include "userdatabasemanager.h"
#include "surgerycontext.h"
#include <QSqlError>
#include "runtime_manager.h"
#include "datetime_manager.h"
//#include <QMediaPlayer>
//#include <QMediaContent>  // Added for Qt5 media loading
#include <QQueue>
#include "databasemanager.h"
#include "mainwindow.h"
#include "pageindex.h"
#include <cmath>

// Cleaned up unused Qt6 global audio objects
//QMediaPlayer *player = nullptr;


ReadyForSurgery::ReadyForSurgery(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::ReadyForSurgery)
    , home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    g_runtimeManager->setSurgeryActive(true);

    auto setupOverlay = [](QPushButton* button, CircularOverlay*& overlay) {
        overlay = new CircularOverlay(button->parentWidget());
        overlay->setGeometry(button->geometry());
        overlay->raise();
        overlay->show();
    };

    setupOverlay(ui->B5_sound, soundOverlay);
    setupOverlay(ui->B5_aimingbeam, aimingBeamOverlay);
    setupOverlay(ui->B5_brightness, brightnessOverlay);

    start_date_time = DateTimeManager::instance()
                          ->currentDateTime()
                          .toString("dd-MM-yy HH:mm:ss");


    timerRing = new TimerRing(ui->F5_timer);
    timerRing->setGeometry(0, 0, ui->F5_timer->width(), ui->F5_timer->height());
    timerRing->show();

    energyUpdateTimer = new QTimer(this);
    energyUpdateTimer->setInterval(1); // update every 100 ms

    connect(energyUpdateTimer, &QTimer::timeout, this, &ReadyForSurgery::updateEnergy);


    connect(ui->pushButton, &QPushButton::pressed, this, [=]() {
        if(surgery_pause == 1)
        {
            popup->hidePopup();
            surgery_pause = 0;
        }
        else{
            if(power1470)
                g_runtimeManager->set1470Active(true);
            if(power980)
                g_runtimeManager->set980Active(true);

            timerRing->startTimerAnimation();
            energyUpdateTimer->start();

            if (timer_reset == 1)
            {
                energyAtPress = new2_totalEnergyDelivered;
            }
            else
            {
                energyAtPress = new_totalEnergyDelivered;
            }

            ui->pushButton->setText("Laser\nON");
            ui->pushButton->setStyleSheet(
                "background-color: red; color: white; font: 12pt \"Roboto\";");

            qDebug()<<"1470 DAC: "<<dacAValue<<"980 DAC: "<<dacBValue;
        }
    });



    connect(ui->pushButton, &QPushButton::released, this, [=]() {
        g_runtimeManager->set980Active(false);
        g_runtimeManager->set1470Active(false);

        timerRing->stopTimerAnimation();
        energyUpdateTimer->stop();

        if (timer_reset == 1) {
            timerRing->resetTimer();
            energyDelivered = new_totalEnergyDelivered + new2_totalEnergyDelivered - totalEnergyDelivered;
            new2_totalEnergyDelivered = new_totalEnergyDelivered + new2_totalEnergyDelivered;
        } else {
            if (timerRing->getCurrentValue() <= 0.0f )
            {
                if(timerFlag == 1)
                {
                    new2_totalEnergyDelivered += new_totalEnergyDelivered;
                    timerRing->resetTimer();
                }
            }
            energyDelivered = new_totalEnergyDelivered + new2_totalEnergyDelivered - totalEnergyDelivered;
        }

        ui->pushButton->setText("Laser\nOFF");
        ui->pushButton->setStyleSheet("background-color: gray; color: black; font: 12pt \"Roboto\";");

        updateEnergy();

        energyAtRelease = new_totalEnergyDelivered + new2_totalEnergyDelivered;

        if((timerFlag == 0) && (timer_reset == 0))
        {
            qDebug() << "| energyAtPress1:" << energyAtPress
                     << "| energyAtRelease:" << energyAtRelease
                     << "| last_energyPerPedal:" << last_energyPerPedal;
            energyPerPedal = energyAtRelease - last_energyPerPedal;
            last_energyPerPedal = energyAtRelease;
        }else if((timerFlag == 1) && (timer_reset == 0))
        {
            qDebug() << "| energyAtPress2:" << energyAtPress
                     << "| energyAtRelease:" << energyAtRelease
                     << "| last_energyPerPedal:" << last_energyPerPedal;
            energyPerPedal = energyAtRelease - last_energyPerPedal;
            last_energyPerPedal = energyAtRelease;
        }
        else
        {
            qDebug() << "| energyAtPress3:" << energyAtPress
                     << "| energyAtRelease:" << energyAtRelease
                     << "| last_energyPerPedal:" << last_energyPerPedal;
            energyPerPedal = energyAtRelease - energyAtPress;
        }

        if (energyPerPedal < 0)
            energyPerPedal = 0;

        qDebug() << "| Name:" << protocolName
                 << "| 980_power:" << power980
                 << "| 1470_power:" << power1470
                 << "| 650_power level:" << aimingbeamIntensity
                 << "| Max timer per pedal:" << TimerSec
                 << "| Timer Reset:" << timer_reset
                 << "| Timer Flag:" << timerFlag
                 << "| Pulse ON(ms):" << pulseOnTime
                 << "| Pulse OFF(ms):" << pulseOffTime
                 << "| Pulse Mode:" << pulseMode
                 << "| Total Energy:" << new_totalEnergyDelivered + new2_totalEnergyDelivered
                 << "| per pedal energy deliverd:" << energyPerPedal;

        for(int i = 0; i<8;i++)
            qDebug()<< " | Stored energy value:" << storedEnergy[i];

        // ===== Store in SQLite =====
        QSqlQuery query(UserDatabaseManager::instance().db());
        query.prepare(R"(
        INSERT INTO surgery_log_by_id (
            surgery_id,
            protocol_name,
            power_980,
            power_1470,
            power_650,
            max_pedal_timer_sec,
            timer_reset,
            timer_flag,
            pulse_on_time_ms,
            pulse_off_time_ms,
            pulse_mode,
            energy_per_pedal,
            total_energy,
            stored_energy_1,
            stored_energy_2,
            stored_energy_3,
            stored_energy_4,
            stored_energy_5,
            stored_energy_6,
            stored_energy_7,
            stored_energy_8
        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
    )");

        query.addBindValue(g_surgeryId);
        query.addBindValue(protocolName);
        query.addBindValue(power980);
        query.addBindValue(power1470);
        query.addBindValue(aimingbeamIntensity);
        query.addBindValue(TimerSec);
        query.addBindValue(timer_reset);
        query.addBindValue(timerFlag);
        query.addBindValue(pulseOnTime);
        query.addBindValue(pulseOffTime);
        query.addBindValue(pulseMode);
        query.addBindValue(energyPerPedal);
        query.addBindValue(new_totalEnergyDelivered + new2_totalEnergyDelivered);
        query.addBindValue(storedEnergy[0]);
        query.addBindValue(storedEnergy[1]);
        query.addBindValue(storedEnergy[2]);
        query.addBindValue(storedEnergy[3]);
        query.addBindValue(storedEnergy[4]);
        query.addBindValue(storedEnergy[5]);
        query.addBindValue(storedEnergy[6]);
        query.addBindValue(storedEnergy[7]);

        if (!query.exec()) {
            qDebug() << "Failed to insert surgery log:" << query.lastError().text();
        }
    });

    // ===== Qt5 Audio Engine Initialization =====
//    player = new QMediaPlayer(this);

    // Qt5 handles volumes using integers from 0 to 100.
    // Scales intensity slider (1 to 5) smoothly up to a max volume of 100.
//    int qt5Volume = static_cast<int>((soundIntensity / 5.0) * 100);
//    player->setVolume(qt5Volume);

//    connect(player, &QMediaPlayer::mediaStatusChanged, this,
//            [=](QMediaPlayer::MediaStatus status)
//            {
//                if (status == QMediaPlayer::EndOfMedia)
//                {
//                    playNextAudio();
//                }
//            });

    popup = new error_popup(this);

    connect(popup, &error_popup::yesClicked, this, [this]() {
        end_surgery();
        qDebug() << "Yes";
    });

    connect(popup, &error_popup::noClicked, this, [this]() {
        qDebug() << "No";
    });

    connect(popup, &error_popup::acknowledged,
            this,[this](){
        if(surgery_pause)
            surgery_pause = 0;

        surgery_pause_bt = 0;
        qDebug() << "ok";
    });
}

ReadyForSurgery::~ReadyForSurgery()
{
    delete ui;
}

void ReadyForSurgery::updatePower980Label()
{
    ui->L5_980nm->setText(QString::number(power980, 'f', 1));
}

void ReadyForSurgery::updatePower1470Label()
{
    ui->L5_1470nm->setText(QString::number(power1470, 'f', 1));
}

void ReadyForSurgery::updateTimerSecLabel()
{
    ui->L5_timer_sec->setText(QString::number(TimerSec));
}

void ReadyForSurgery::updateTimerStateLabel()
{
    if(timer_reset == 0)
        ui->L5_timer_state->setText("NoReset");

    if(timer_reset == 1)
        ui->L5_timer_state->setText("Reset");
}

void ReadyForSurgery::updatePulseLabels()
{
    if(pulseMode == 0)
    {
        ui->L5_pulse_on->setText("--");
        ui->L2_on_pulse_unit->setText("");
        ui->L5_pulse_off->setText("--");
        ui->L2_off_pulse_unit->setText("");
    }
    else
    {
        ui->L5_pulse_on->show();
        ui->L5_pulse_off->show();

        ui->L5_pulse_on->setText(formatPulseTime(pulseOnTime));
        ui->L2_on_pulse_unit->setText(getPulseUnit(pulseOnTime));

        ui->L5_pulse_off->setText(formatPulseTime(pulseOffTime));
        ui->L2_off_pulse_unit->setText(getPulseUnit(pulseOffTime));
    }
}

QString ReadyForSurgery::formatPulseTime(int valueUs)
{
    if (valueUs < 1000)
    {
        return QString::number(valueUs);
    }

    if (valueUs < 1000000)
    {
        double ms = valueUs / 1000.0;
        if (ms == static_cast<int>(ms))
        {
            return QString::number(static_cast<int>(ms));
        }
        return QString::number(ms, 'f', 1);
    }

    double sec = valueUs / 1000000.0;
    if (sec == static_cast<int>(sec))
    {
        return QString::number(static_cast<int>(sec));
    }
    return QString::number(sec, 'f', 1);
}

QString ReadyForSurgery::getPulseUnit(int valueUs)
{
    if (valueUs < 1000)
        return "μs";

    if (valueUs < 1000000)
        return "ms";

    return "s";
}

void ReadyForSurgery::updateJouleLabel()
{
    currentJoule = TimerSec * (power980 + power1470);
    ui->L5_energy->setText(QString::number(currentJoule));
}

void ReadyForSurgery::on_B5_aimingbeam_clicked()
{
    DatabaseInitializer dbinit;

    QWidget *overlay = new QWidget(this);
    overlay->resize(this->size());
    overlay->setStyleSheet("background-color: rgba(0, 0, 0, 150);");
    overlay->show();

    AimingBeamPopupDialog dialog(this);

    QRect rect = this->geometry();
    int centerX = rect.x() + rect.width() / 2;
    int centerY = rect.y() + rect.height() / 2;

    int popupX = centerX - dialog.width() / 2;
    int popupY = centerY - dialog.height() / 2;

    dialog.move(popupX, popupY);
    dialog.exec();

    aimingBeamOverlay->setProgress(aimingbeamIntensity);

    overlay->hide();
    overlay->deleteLater();

    dbinit.updateSingleColumn("device_setting","aiming_beam_intensity",aimingbeamIntensity,1);
}


void ReadyForSurgery::on_B5_sound_clicked()
{
    DatabaseInitializer dbinit;

    QWidget *overlay = new QWidget(this);
    overlay->resize(this->size());
    overlay->setStyleSheet("background-color: rgba(0, 0, 0, 150);");
    overlay->show();

    SoundPopupDialog dialog(this);

    QRect rect = this->geometry();
    int centerX = rect.x() + rect.width() / 2;
    int centerY = rect.y() + rect.height() / 2;

    int popupX = centerX - dialog.width() / 2;
    int popupY = centerY - dialog.height() / 2;

    dialog.move(popupX, popupY);
    dialog.exec();

    overlay->hide();
    overlay->deleteLater();

    soundOverlay->setProgress(soundIntensity);

    dbinit.updateSingleColumn("device_setting", "sound_intensity", soundIntensity, 1);
    dbinit.updateSingleColumn("device_setting", "beep_intensity", beepIntensity, 1);
}


void ReadyForSurgery::on_B5_brightness_clicked()
{
    DatabaseInitializer dbinit;

    QWidget *overlay = new QWidget(this);
    overlay->resize(this->size());
    overlay->setStyleSheet("background-color: rgba(0, 0, 0, 150);");
    overlay->show();

    BrightnessPopupDialog dialog(this);

    QRect rect = this->geometry();
    int centerX = rect.x() + rect.width() / 2;
    int centerY = rect.y() + rect.height() / 2;

    int popupX = centerX - dialog.width() / 2;
    int popupY = centerY - dialog.height() / 2;

    dialog.move(popupX, popupY);
    dialog.exec();

    overlay->hide();
    overlay->deleteLater();

    brightnessOverlay->setProgress(brightnessIntensity);

    dbinit.updateSingleColumn("device_setting","screen_brightness",brightnessIntensity,1);
}


void ReadyForSurgery::on_B5_to_standby_clicked()
{
    popup->showMessage(
        "END SURGERY",
        "Are you sure you want to end the surgery?\n"
        "",
        error_popup::Confirmation,
        true
        );
}

void ReadyForSurgery::on_B5_change_clicked()
{
    QWidget *overlay = new QWidget(this);
    overlay->setGeometry(0, 0, width(), height());
    overlay->setStyleSheet("background-color: rgba(0, 0, 0, 150);");
    overlay->setAttribute(Qt::WA_TransparentForMouseEvents, false);
    overlay->show();

    QDialog popup(this);
    popup.setModal(true);
    popup.setFixedSize(784, 337);
    popup.setWindowFlags(Qt::Popup);

    changevalue *cv = new changevalue(&popup);
    QVBoxLayout *layout = new QVBoxLayout(&popup);
    layout->addWidget(cv);
    popup.setLayout(layout);

    int popupX = (this->width() - popup.width()) / 2;
    int popupY = (this->height() - popup.height()) / 2;
    popup.move(this->mapToGlobal(QPoint(popupX, popupY)));

    popup.exec();

    overlay->deleteLater();
    updatePower980Label();
    updatePower1470Label();
    updateTimerSecLabel();
    updateTimerStateLabel();
    updatePulseLabels();
    updateJouleLabel();
    timerRing->setTargetValue(TimerSec);

    DatabaseInitializer dbinit;
    dbinit.fetchDACByPower(power980,980);
    dbinit.fetchDACByPower(power1470,1470);
}


void ReadyForSurgery::on_B5_reset_clicked()
{
    if (storedCount < 8) {
        storedEnergy[storedCount] = energyDelivered;

        QString valueStr = QString::number(energyDelivered, 'f', 0);
        switch (storedCount) {
        case 0: ui->L5_store_1->setText(valueStr); break;
        case 1: ui->L5_store_2->setText(valueStr); break;
        case 2: ui->L5_store_3->setText(valueStr); break;
        case 3: ui->L5_store_4->setText(valueStr); break;
        case 4: ui->L5_store_5->setText(valueStr); break;
        case 5: ui->L5_store_6->setText(valueStr); break;
        case 6: ui->L5_store_7->setText(valueStr); break;
        case 7: ui->L5_store_8->setText(valueStr); break;
        }

        totalEnergyDelivered += energyDelivered;
        storedCount++;
    }

    energyDelivered = 0;
    ui->L5_energy_deliverd->setText(QString::number(energyDelivered, 'f', 0));
}

void ReadyForSurgery::updateEnergy()
{
    if (timerFlag == 1 && timerRing->getCurrentValue() <= 0.0f)
    {
        qDebug() << "⛔ Timer reached zero → Auto stopping laser";

        g_runtimeManager->set980Active(false);
        g_runtimeManager->set1470Active(false);

        energyUpdateTimer->stop();
        timerRing->stopTimerAnimation();

        if (timer_reset == 1)
        {
            timerRing->resetTimer();
        }

        ui->pushButton->setText("Laser OFF");
        ui->pushButton->setStyleSheet(
            "background-color: gray; color: black; font: 12pt \"Roboto\";");

        return;
    }

    if (timerFlag == 1) {
        liveTime = TimerSec - timerRing->getCurrentValue();
        if (liveTime < 0) liveTime = 0;
    } else {
        liveTime = timerRing->getElapsedValue();
    }

    if (liveTime > MAX_ALLOWED_TIME) liveTime = MAX_ALLOWED_TIME;

    if(pulseMode)
    {
        avgPower = (static_cast<double>(pulseOnTime) / (pulseOnTime + pulseOffTime)) * (power980 + power1470);
    }else
    {
        avgPower = (power980 + power1470);
    }

    new_totalEnergyDelivered = liveTime * avgPower;

    ui->L5_energy_deliverd->setText(QString::number(
        new_totalEnergyDelivered + new2_totalEnergyDelivered - totalEnergyDelivered, 'f', 0));

    ui->L5_total_energy->setText(QString::number(
        new_totalEnergyDelivered + new2_totalEnergyDelivered, 'f', 0));

    double totalEnergy = new_totalEnergyDelivered + new2_totalEnergyDelivered;
    int currentLevel = static_cast<int>(totalEnergy);

    if (alarmJoules > 0)
    {
        int currentMultiple = currentLevel / alarmJoules;
        int lastMultiple    = lastAnnouncedEnergy / alarmJoules;

        if (currentMultiple > lastMultiple)
        {
            int announcedValue = currentMultiple * alarmJoules;
            audioQueue.clear();

            QString filePath = QString("qrc:/audio/Audio/%1.mp3")
                                   .arg(announcedValue, 4, 10, QChar('0'));
            audioQueue.enqueue(filePath);

            if (!isPlaying)
                playNextAudio();

            lastAnnouncedEnergy = announcedValue;
        }
    }else if (alarmSeconds > 0)
    {
        double diode1470Sec = g_diode1470Ms_persurgery / 1000.0;
        double diode980Sec  = g_diode980Ms_persurgery / 1000.0;
        double currentSec = qMax(diode1470Sec, diode980Sec);

        int currentMultiple = static_cast<int>(currentSec) / alarmSeconds;
        int lastMultiple    = lastAnnouncedSeconds / alarmSeconds;

        if (currentMultiple > lastMultiple)
        {
            audioQueue.clear();
            audioQueue.enqueue("qrc:/audio/Audio/0001.mp3");

            if (!isPlaying)
                playNextAudio();

            lastAnnouncedSeconds = currentMultiple * alarmSeconds;
        }
    }
}

// Fixed for Qt5 QMediaPlayer Engine
void ReadyForSurgery::playNextAudio()
{
//    if (audioQueue.isEmpty()) {
//        isPlaying = false;
//        return;
//    }

//    isPlaying = true;
//    QString filePath = audioQueue.dequeue();

//    player->stop();

//    // Qt5 Alternative: Media is defined as a container object via QMediaContent
//    player->setMedia(QMediaContent(QUrl(filePath)));
//    player->setPlaybackRate(1);
//    player->play();
}


void ReadyForSurgery::on_B5_pause_clicked()
{
    surgery_pause_bt = 1;

    popup->showMessage(
        "SURGERY PAUSED",
        "Press RESUME to continue the surgery. \n"
        "OR\n"
        "Press foot peddel to resume.",
        error_popup::Info,
        true
        );

    surgery_pause = 1;

//    if(surgery_pause == 0)
//    {
//        surgery_pause = 1;
//        ui->B5_pause->setText("Resume Surgery");
//    }else
//    {
//        surgery_pause = 0;
//        ui->B5_pause->setText("Pause Surgery");
//    }
}

void ReadyForSurgery::end_surgery(void)
{
    qDebug() << "Surgery end";

    int surgery_min = (g_surgery_ms/1000);
    int diode_avg_ms = 0;
    int totalMs = 0;
    int activeDiodes = 0;

    if(g_diode1470Ms_persurgery > 0)
    {
        totalMs += g_diode1470Ms_persurgery;
        activeDiodes++;
    }

    if(g_diode980Ms_persurgery > 0)
    {
        totalMs += g_diode980Ms_persurgery;
        activeDiodes++;
    }

    if(activeDiodes > 0)
    {
        diode_avg_ms = totalMs / (activeDiodes * 1000);
    }

    int summ_total_energy = new_totalEnergyDelivered + new2_totalEnergyDelivered;
    double summ_avgPower = 0;

    if(pulseMode)
    {
        summ_avgPower = (static_cast<double>(pulseOnTime) / (pulseOnTime + pulseOffTime)) * (power980 + power1470);
        summ_avgPower = std::round(summ_avgPower * 10.0) / 10.0;
    }else
    {
        summ_avgPower = (power980 + power1470);
    }

    UserDatabaseInitializer userInit;
    userInit.insertSurgerySummary(
        g_surgeryId,
        protocolName,
        start_date_time,
        surgery_min,
        diode_avg_ms,
        summ_total_energy,
        summ_avgPower,
        Fiber_disconnection_count);

    QSqlQuery query(DatabaseManager::instance().db());
    query.exec(
        "UPDATE system_timer SET "
        "total_no_surgery_done = total_no_surgery_done + 1, "
        "usage_no_surgery_done = usage_no_surgery_done + 1 "
        "WHERE id = 1"
        );

    g_runtimeManager->setSurgeryActive(false);
    resetSurgerySession();
    MainWindow::instance->switchPage(PAGE_HOME);
}

void ReadyForSurgery::resetSurgerySession()
{
    new_totalEnergyDelivered = 0;
    new2_totalEnergyDelivered = 0;
    totalEnergyDelivered = 0;
    energyDelivered = 0;
    energyAtPress = 0;
    energyAtRelease = 0;
    energyPerPedal = 0;
    last_energyPerPedal = 0;
    liveTime = 0;
    avgPower = 0;
    lastAnnouncedEnergy = 0;
    storedCount = 0;

    for (int i = 0; i < 8; i++)
    {
        storedEnergy[i] = 0;
    }

    ui->L5_store_1->setText("0");
    ui->L5_store_2->setText("0");
    ui->L5_store_3->setText("0");
    ui->L5_store_4->setText("0");
    ui->L5_store_5->setText("0");
    ui->L5_store_6->setText("0");
    ui->L5_store_7->setText("0");
    ui->L5_store_8->setText("0");

    ui->L5_energy_deliverd->setText("0");
    ui->L5_total_energy->setText("0");

    audioQueue.clear();
    isPlaying = false;

//    if (player)
//        player->stop();

    surgery_pause = 0;
    ui->B5_pause->setText("Pause Surgery");

    energyUpdateTimer->stop();
    timerRing->stopTimerAnimation();
    timerRing->resetTimer();

    g_runtimeManager->set980Active(false);
    g_runtimeManager->set1470Active(false);
    g_runtimeManager->setSurgeryActive(false);

    g_surgery_ms = 0;
    g_diode1470Ms_persurgery = 0;
    g_diode980Ms_persurgery = 0;
    Fiber_disconnection_count = 0;
}

void ReadyForSurgery::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    refreshPage();
}

void ReadyForSurgery::refreshPage()
{
    updatePower980Label();
    updatePower1470Label();
    updateTimerSecLabel();
    updateTimerStateLabel();
    updatePulseLabels();
    updateJouleLabel();

    ui->L5_ready->setText(protocolName);

    if(soundOverlay)
        soundOverlay->setProgress(soundIntensity);

    if(brightnessOverlay)
        brightnessOverlay->setProgress(brightnessIntensity);

    if(aimingBeamOverlay)
        aimingBeamOverlay->setProgress(aimingbeamIntensity);

    start_date_time = DateTimeManager::instance()
                          ->currentDateTime()
                          .toString("dd-MM-yy HH:mm:ss");

    if(timerRing)
    {
        timerRing->stopTimerAnimation();
        timerRing->resetTimer();
        timerRing->setTargetValue(TimerSec);
    }

    DatabaseInitializer dbinit;
    dbinit.fetchDACByPower(power980,980);
    dbinit.fetchDACByPower(power1470,1470);

    ui->pushButton->setText("Laser\nOFF");
    ui->pushButton->setStyleSheet(
        "background-color: gray; "
        "color: black; "
        "font: 12pt \"Roboto\";");

    surgery_pause = 0;
    ui->B5_pause->setText("Pause Surgery");

    g_runtimeManager->setSurgeryActive(true);
    g_runtimeManager->set980Active(false);
    g_runtimeManager->set1470Active(false);

    if(energyUpdateTimer)
        energyUpdateTimer->stop();

//    bool timerEnabled = (timerFlag == 1);
//    ui->L5_timer_sec->setVisible(timerEnabled);
//    ui->label_5->setVisible(timerEnabled);
//    ui->label_6->setVisible(timerEnabled);
//    ui->label_8->setVisible(timerEnabled);
//    ui->L5_timer_state->setVisible(timerEnabled);
//    ui->label_10->setVisible(timerEnabled);
//    ui->label_11->setVisible(timerEnabled);
//    ui->L5_energy->setVisible(timerEnabled);
}
