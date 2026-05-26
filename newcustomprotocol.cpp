#include "newcustomprotocol.h"
#include "ui_newcustomprotocol.h"
#include "global.h"
#include "databaseinitializer.h"
#include "databasemanager.h"
#include "mainwindow.h"
#include "pageindex.h"
#include "customkeyboard.h"
#include <cmath>


newcustomprotocol::newcustomprotocol(QWidget *parent, Home *home)
    : QWidget(parent)
    , ui(new Ui::newcustomprotocol)
    , home(home)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->Surgery_name->installEventFilter(this);

    // 980
    setupHoldButton(ui->B2_980add, timer_980add, [this]() { on_B2_980add_clicked(); });
    setupHoldButton(ui->B2_980sub, timer_980sub, [this]() { on_B2_980sub_clicked(); });

    // 1470
    setupHoldButton(ui->B2_1470add, timer_1470add, [this]() { on_B2_1470add_clicked(); });
    setupHoldButton(ui->B2_1470sub, timer_1470sub, [this]() { on_B2_1470sub_clicked(); });

    // On Time
    setupHoldButton(ui->B2_on_time_add, timer_onTimeAdd, [this]() { on_B2_on_time_add_clicked(); });
    setupHoldButton(ui->B2_on_time_sub, timer_onTimeSub, [this]() { on_B2_on_time_sub_clicked(); });

    // Off Time
    setupHoldButton(ui->B2_off_time_add, timer_offTimeAdd, [this]() { on_B2_off_time_add_clicked(); });
    setupHoldButton(ui->B2_off_time_sub, timer_offTimeSub, [this]() { on_B2_off_time_sub_clicked(); });

    setupHoldButton(ui->B2_timer_add, timer_onTimeAdd, [this]() { on_B2_timer_add_clicked(); });
    setupHoldButton(ui->B2_timer_sub, timer_onTimeSub, [this]() { on_B2_timer_sub_clicked(); });

    connect(ui->Surgery_name, &QLineEdit::textChanged,
            this, &newcustomprotocol::on_Surgery_name_textChanged);

}

newcustomprotocol::~newcustomprotocol()
{
    delete ui;
}

void newcustomprotocol::switchToHome()
{
    MainWindow::instance->switchPage(PAGE_HOME);
}

void newcustomprotocol::switchToSetting()
{
    MainWindow::instance->switchPage(PAGE_SETTING);
}

void newcustomprotocol::on_B2_980sub_clicked()
{
    double step;
    if (l_power980 <= 1.0)
        step = 0.1;
    else if (l_power980 <= 3.0)
        step = 0.2;
    else
        step = 0.5;

    l_power980 -= step;

    if (l_power980 < 0.0)
        l_power980 = 0.0;

    l_power980 = std::round(l_power980 * 10.0) / 10.0;

    updatePower980Label();
    updateJouleLabel();
}


void newcustomprotocol::on_B2_980add_clicked()
{
    double step;
    if (l_power980 < 1.0)
        step = 0.1;
    else if (l_power980 < 3.0)
        step = 0.2;
    else if (l_power980 < 15.0)
        step = 0.5;
    else
        step = 0.0;

    l_power980 += step;

    if (l_power980 > 15.0)
        l_power980 = 15.0;

    l_power980 = std::round(l_power980 * 10.0) / 10.0;

    updatePower980Label();
    updateJouleLabel();
}


void newcustomprotocol::on_B2_1470sub_clicked()
{
    double step;
    if (l_power1470 <= 1.0)
        step = 0.1;
    else if (l_power1470 <= 3.0)
        step = 0.2;
    else
        step = 0.5;

    l_power1470 -= step;

    if (l_power1470 < 0.0)
        l_power1470 = 0.0;

    l_power1470 = std::round(l_power1470 * 10.0) / 10.0;

    updatePower1470Label();
    updateJouleLabel();
}


void newcustomprotocol::on_B2_1470add_clicked()
{
    double step;
    if (l_power1470 < 1.0)
        step = 0.1;
    else if (l_power1470 < 3.0)
        step = 0.2;
    else if (l_power1470 < 15.0)
        step = 0.5;
    else
        step = 0.0;

    l_power1470 += step;

    if (l_power1470 > 15.0)
        l_power1470 = 15.0;

    l_power1470 = std::round(l_power1470 * 10.0) / 10.0;

    updatePower1470Label();
    updateJouleLabel();
}


void newcustomprotocol::on_B2_timer_off_clicked()
{
    update_B2_timer_off();
}

void newcustomprotocol::update_B2_timer_off()
{
    l_timerFlag = false;
    l_TimerSec = 0;

    ui->L2_timer_show->hide();

    ui->B2_timer_add->setEnabled(false);
    ui->B2_timer_sub->setEnabled(false);

    if(dark)
    {
        ui->B2_timer_sub->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/negative_dark_disabled.png);"
                "}");
        ui->B2_timer_add->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/positive_dark_disabled.png);"
                "}");
    }else
    {
        ui->B2_timer_sub->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/negative_light_disabled.png);"
                "}");
        ui->B2_timer_add->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/positive_light_disabled.png);"
                "}");
    }

    updateTimerLabel();
    updateJouleLabel();
}


void newcustomprotocol::on_B2_timer_on_clicked()
{
    update_B2_timer_on();
}

void newcustomprotocol::update_B2_timer_on()
{
    l_timerFlag = true;
    ui->L2_timer_show->show();
    ui->B2_timer_add->setEnabled(true);
    ui->B2_timer_sub->setEnabled(true);
    if(dark)
    {
        ui->B2_timer_sub->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/negative_dark_active.png);"
                "}");
        ui->B2_timer_add->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/positive_dark_active.png);"
                "}");
    }else
    {
        ui->B2_timer_sub->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/negative_light_active.png);"
                "}");
        ui->B2_timer_add->setStyleSheet("QPushButton {"
                "background-image:url(:/icons/positive_light_active.png);"
                "}");
    }
    updateTimerLabel();
}

void newcustomprotocol::on_B2_timer_sub_clicked()
{
    if (ui->B2_timer_on->isChecked()) {
        if (l_TimerSec > 1) l_TimerSec--;
        updateTimerLabel();
        updateJouleLabel();
    }
}


void newcustomprotocol::on_B2_timer_add_clicked()
{
    if (ui->B2_timer_on->isChecked()) {
        if (l_TimerSec < 120) l_TimerSec++;
        updateTimerLabel();
        updateJouleLabel();
    }
}


void newcustomprotocol::on_B2_timer_reset_clicked()
{
    l_timer_reset = 1;
    setTimerResetState(l_timer_reset);
}


void newcustomprotocol::on_B2_timer_noreset_clicked()
{
    l_timer_reset = 0;
    setTimerResetState(l_timer_reset);
}

void newcustomprotocol::setTimerResetState(bool reset)
{
    //qDebug() <<"timer_reset" <<static_cast<int>(reset);

    if (reset)
    {
        ui->B2_timer_reset->setStyleSheet(
            "color: rgb(255, 97, 34);"
            "border: 0px solid;"
            "border-top-left-radius: 15px;"
            "border-bottom-left-radius: 15px;"
            "font-size: 14pt;"
            );

        ui->B2_timer_noreset->setStyleSheet(
            "border: 0px solid;"
            "border-top-right-radius: 15px;"
            "border-bottom-right-radius: 15px;"
            "font-size: 14pt;"
            );
    }
    else
    {
        ui->B2_timer_noreset->setStyleSheet(
            "color: rgb(255, 97, 34);"
            "border: 0px solid;"
            "border-top-right-radius: 15px;"
            "border-bottom-right-radius: 15px;"
            "font-size: 14pt;"
            );

        ui->B2_timer_reset->setStyleSheet(
            "border: 0px solid;"
            "border-top-left-radius: 15px;"
            "border-bottom-left-radius: 15px;"
            "font-size: 14pt;"
            );
    }
}

void newcustomprotocol::on_B2_pulsemode_stateChanged(int arg1)
{
    bool enabled = (arg1 == Qt::Checked);

    l_pulseMode = enabled;

    ui->B2_on_time_add->setEnabled(enabled);
    ui->B2_on_time_sub->setEnabled(enabled);
    ui->B2_off_time_add->setEnabled(enabled);
    ui->B2_off_time_sub->setEnabled(enabled);

    ui->L2_on_pulse_show->setVisible(enabled);
    ui->L2_off_pulse_show->setVisible(enabled);

    updatePulseLabels(l_pulseMode);
}

void newcustomprotocol::on_B2_on_time_sub_clicked()
{
    l_pulseOnTime = decrementPulseValue(l_pulseOnTime);

    updatePulseLabels(l_pulseMode);
}


void newcustomprotocol::on_B2_on_time_add_clicked()
{
    l_pulseOnTime = incrementPulseValue(l_pulseOnTime);

    updatePulseLabels(l_pulseMode);
}

void newcustomprotocol::on_B2_off_time_sub_clicked()
{
    l_pulseOffTime = decrementPulseValue(l_pulseOffTime);

    updatePulseLabels(l_pulseMode);
}


void newcustomprotocol::on_B2_off_time_add_clicked()
{
    l_pulseOffTime = incrementPulseValue(l_pulseOffTime);

    updatePulseLabels(l_pulseMode);
}


void newcustomprotocol::on_B2_cancel_clicked()
{
    switchToHome();
}


void newcustomprotocol::on_B2_save_clicked()
{
    if (l_name.isEmpty())
        return;   // safety, button should already be disabled

    DatabaseInitializer dbinit;   // ✅ local instance

    int newId = dbinit.getNextAvailableId("protocol_custom");


    bool ok;

    if(custom_modify == 1)
    {
        ok = dbinit.updatePresetProtocol(
            "protocol_custom",
            l_name,
            l_power980,
            l_power1470,
            l_TimerSec,
            l_timer_reset,
            l_timerFlag,
            l_pulseOnTime,
            l_pulseOffTime,
            l_pulseMode,
            0);
    }else
    {
        ok = dbinit.insertPresetProtocol(
            "protocol_custom",
            newId,
            l_name,
            l_power980,
            l_power1470,
            l_TimerSec,
            l_timer_reset,
            l_timerFlag,
            l_pulseOnTime,
            l_pulseOffTime,
            l_pulseMode,
            0
            );
    }

    if (!ok) {
        //qDebug() << "Failed to save custom protocol";
    } else {
        //qDebug() << "Custom protocol saved successfully";
        custom_modify = 0;
        switchToHome();   // optional UX
    }
}

void newcustomprotocol::updatePower980Label()
{
    ui->L2_980_show->setText(QString::number(l_power980, 'f', 1));
}

void newcustomprotocol::updatePower1470Label()
{
    ui->L2_1470_show->setText(QString::number(l_power1470, 'f', 1));
}

void newcustomprotocol::updateTimerLabel()
{
    ui->L2_timer_show->setText(QString::number(l_TimerSec));
}

void newcustomprotocol::updateJouleLabel()
{
    currentJoule= l_TimerSec * (l_power980+l_power1470);
}

void newcustomprotocol::updatePulseLabels(bool enabled)
{
    if(dark)
    {
        if(enabled)
        {
            ui->B2_on_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_active.png);"
                    "}");
            ui->B2_on_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_active.png);"
                    "}");
            ui->B2_off_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_active.png);"
                    "}");
            ui->B2_off_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_active.png);"
                    "}");
        }else
        {
            ui->B2_on_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_disabled.png);"
                    "}");
            ui->B2_on_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_disabled.png);"
                    "}");
            ui->B2_off_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_dark_disabled.png);"
                    "}");
            ui->B2_off_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_dark_disabled.png);"
                    "}");
        }

    }else
    {
        if(enabled)
        {
            ui->B2_on_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_active.png);"
                    "}");
            ui->B2_on_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_active.png);"
                    "}");
            ui->B2_off_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_active.png);"
                    "}");
            ui->B2_off_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_active.png);"
                    "}");
        }else
        {
            ui->B2_on_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_disabled.png);"
                    "}");
            ui->B2_on_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_disabled.png);"
                    "}");
            ui->B2_off_time_sub->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/negative_light_disabled.png);"
                    "}");
            ui->B2_off_time_add->setStyleSheet("QPushButton {"
                    "background-image:url(:/icons/positive_light_disabled.png);"
                    "}");
        }
    }
    // ON time
    ui->L2_on_pulse_show->setText(
        formatPulseTime(l_pulseOnTime));

    ui->L2_on_pulse_unit->setText(
        getPulseUnit(l_pulseOnTime));

    // OFF time
    ui->L2_off_pulse_show->setText(
        formatPulseTime(l_pulseOffTime));

    ui->L2_off_pulse_unit->setText(
        getPulseUnit(l_pulseOffTime));
}

void newcustomprotocol::setupHoldButton(QPushButton *button, QTimer *&timer, const std::function<void()> &slotFunc)
{
    timer = new QTimer(this);
    timer->setInterval(500);
    connect(timer, &QTimer::timeout, slotFunc);
    connect(button, &QPushButton::pressed, timer, QOverload<>::of(&QTimer::start));
    connect(button, &QPushButton::released, timer, &QTimer::stop);
}

void newcustomprotocol::setSimplifiedMode() {
    ui->homeframe_5->hide();
    simpliAdvanMode = 0;
}

void newcustomprotocol::setAdvancedMode() {
    ui->homeframe_5->show();
    simpliAdvanMode = 1;
}


void newcustomprotocol::on_B3_back_to_setting_clicked()
{
    if(modify_protocol == true)
    {
        switchToHome();
    }else
    {
        switchToSetting();
    }
}


void newcustomprotocol::on_B2_back_to_home_clicked()
{
    switchToHome();
}

void newcustomprotocol::on_Surgery_name_textChanged(const QString &text)
{
    l_name = text.trimmed();

    if (l_name.isEmpty())
    {
        ui->B2_save->setEnabled(false);
        return;
    }

    if (isProtocolNameExists(l_name))
    {
        ui->B2_save->setEnabled(false);
        ui->Surgery_name->setStyleSheet("border: 2px solid red;");
    }
    else
    {
        ui->B2_save->setEnabled(true);
        ui->Surgery_name->setStyleSheet("");
    }
}

bool newcustomprotocol::isProtocolNameExists(const QString &name)
{
    QSqlQuery query(DatabaseManager::instance().db());

    if (custom_modify == 1)
    {
        // In modify mode, allow same name for same record
        query.prepare("SELECT COUNT(*) FROM protocol_custom WHERE name = ? AND id != ?");
        query.addBindValue(name);
        query.addBindValue(selectedCustomId);   // important!
    }
    else
    {
        // In new mode, block any duplicate
        query.prepare("SELECT COUNT(*) FROM protocol_custom WHERE name = ?");
        query.addBindValue(name);
    }

    if (!query.exec())
        return false;

    if (query.next())
        return query.value(0).toInt() > 0;

    return false;
}

int newcustomprotocol::getStepForValue(int valueUs)
{
    // 50us -> 950us
    if (valueUs < 1000)
        return 50;

    // 1ms -> 9ms
    if (valueUs < 10000)
        return 1000;

    // 10ms -> 40ms
    if (valueUs < 50000)
        return 10000;

    // 50ms -> 950ms
    if (valueUs < 1000000)
        return 50000;

    // 1s -> 12s
    return 500000;
}

int newcustomprotocol::incrementPulseValue(int valueUs)
{
    // ----- Boundary transitions -----

    // 950us -> 1ms
    if (valueUs == 950)
        return 1000;

    // 9ms -> 10ms
    if (valueUs == 9000)
        return 10000;

    // 40ms -> 50ms
    if (valueUs == 40000)
        return 50000;

    // 950ms -> 1s
    if (valueUs == 950000)
        return 1000000;

    // ----- Normal increment -----

    valueUs += getStepForValue(valueUs);

    if (valueUs > pulseMaxLimit)
        valueUs = pulseMaxLimit;

    return valueUs;
}

int newcustomprotocol::decrementPulseValue(int valueUs)
{
    // ----- Boundary transitions -----

    // 1ms -> 950us
    if (valueUs == 1000)
        return 950;

    // 10ms -> 9ms
    if (valueUs == 10000)
        return 9000;

    // 50ms -> 40ms
    if (valueUs == 50000)
        return 40000;

    // 1s -> 950ms
    if (valueUs == 1000000)
        return 950000;

    // ----- Normal decrement -----

    valueUs -= getStepForValue(valueUs);

    if (valueUs < pulseMinLimit)
        valueUs = pulseMinLimit;

    return valueUs;
}

QString newcustomprotocol::formatPulseTime(int valueUs)
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

QString newcustomprotocol::getPulseUnit(int valueUs)
{
    if (valueUs < 1000)
        return "μs";

    if (valueUs < 1000000)
        return "ms";

    return "s";
}

void newcustomprotocol::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    refreshPage();
}

void newcustomprotocol::refreshPage()
{
    qDebug() << "Refreshing Custom Protocol Page";

    // ---------------------------------
    // Mode (New / Modify)
    // ---------------------------------

    if(modify_protocol == true)
    {
        ui->new_protocol_label->hide();
        ui->modify_protocol_label->show();
        ui->B2_back_to_home->hide();

        l_name          = protocolName;
        l_power980      = power980;
        l_power1470     = power1470;
        l_TimerSec      = TimerSec;
        l_timerFlag     = timerFlag;
        l_timer_reset   = timer_reset;
        l_pulseMode     = pulseMode;
        l_pulseOnTime   = pulseOnTime;
        l_pulseOffTime  = pulseOffTime;

        ui->Surgery_name->setText(l_name);
    }

    if(new_protocol == true)
    {
        ui->new_protocol_label->show();
        ui->modify_protocol_label->hide();
        ui->B2_back_to_home->show();

        l_name          = "";
        l_power980      = 0;
        l_power1470     = 0;
        l_TimerSec      = 0;
        l_timerFlag     = 0;
        l_timer_reset   = 0;
        l_pulseMode     = 0;
        l_pulseOnTime   = 50;
        l_pulseOffTime  = 50;

        ui->Surgery_name->clear();
    }

    // ---------------------------------
    // Power
    // ---------------------------------

    updatePower980Label();

    updatePower1470Label();

    // ---------------------------------
    // Timer
    // ---------------------------------

    ui->B2_timer_on->setChecked(l_timerFlag);

    ui->B2_timer_off->setChecked(!l_timerFlag);

    ui->L2_timer_show->setVisible(l_timerFlag);

    ui->B2_timer_add->setEnabled(l_timerFlag);

    ui->B2_timer_sub->setEnabled(l_timerFlag);

    updateTimerLabel();

    // ---------------------------------
    // Pulse Mode
    // ---------------------------------

    ui->B2_pulsemode->setChecked(l_pulseMode);

    ui->B2_on_time_add->setEnabled(l_pulseMode);

    ui->B2_on_time_sub->setEnabled(l_pulseMode);

    ui->B2_off_time_add->setEnabled(l_pulseMode);

    ui->B2_off_time_sub->setEnabled(l_pulseMode);

    ui->L2_on_pulse_show->setVisible(l_pulseMode);

    ui->L2_off_pulse_show->setVisible(l_pulseMode);

    updatePulseLabels(l_pulseMode);

    // ---------------------------------
    // Joules
    // ---------------------------------

    updateJouleLabel();

    // ---------------------------------
    // Timer Reset
    // ---------------------------------

    setTimerResetState(l_timer_reset);

    // ---------------------------------
    // Mode
    // ---------------------------------

    if (simpliAdvanMode == 0)
    {
        setSimplifiedMode();
    }
    else
    {
        setAdvancedMode();
    }

    // ---------------------------------
    // Save Button Validation
    // ---------------------------------

    ui->B2_save->setEnabled(!l_name.trimmed().isEmpty());

    qDebug() << "Custom Protocol Refresh Complete";
}

// Add this function to newcustomprotocol.cpp

bool newcustomprotocol::eventFilter(QObject *watched, QEvent *event)
{
    // Capture user clicks/touches inside the widget area
    if (event->type() == QEvent::MouseButtonPress)
    {
        if (watched == ui->Surgery_name)
        {
            // Remove active focus from text container to avoid conflicting blink overlays
            ui->Surgery_name->clearFocus();

            // Open up the custom full keyboard setup mapping to the target
            CustomKeyboard keyboard(this, CustomKeyboard::FullLayout);
            keyboard.setTarget(ui->Surgery_name);
            keyboard.move(0, 160);
            keyboard.exec();

            return true; // Click event successfully captured and processed here
        }
    }

    // Forward any other core standard operations down to the parent QWidget instance
    return QWidget::eventFilter(watched, event);
}

