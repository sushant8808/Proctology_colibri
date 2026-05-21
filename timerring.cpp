#include "timerring.h"
#include "global.h"
#include <QPainter>
#include <QPen>
#include <QFont>
#include <QtMath>

TimerRing::TimerRing(QWidget *parent)
    : QWidget(parent)
{
    connect(&updateTimer, &QTimer::timeout, this, [=]() {

        if (timerFlag == 1) {
            // ===== MEDICAL-GRADE COUNTDOWN (ABSOLUTE TIME) =====
            float elapsedSec = countdownTimer.elapsed() / 1000.0f;
            currentValue = countdownStartValue - elapsedSec;

            if (currentValue <= 0.0f) {
                currentValue = 0.0f;
                updateTimer.stop();
            }
        } else {
            // Only update UI display — do not affect energy calculation
            float displayElapsed = accumulatedElapsed +
                                   (elapsedTimer.isValid() ? elapsedTimer.elapsed() / 1000.0f : 0.0f);
            elapsedValue = displayElapsed; // for UI
        }


        update();   // UI refresh only
    });
}

void TimerRing::setTargetValue(float value)
{
    targetValue  = value;
    currentValue = targetValue;
    elapsedValue = 0.0f;
    accumulatedElapsed = 0.0f;
    update();
}

void TimerRing::startTimerAnimation()
{
    if (timerFlag == 1) {
        // Countdown start reference
        countdownStartValue = currentValue;
        countdownTimer.restart();
    } else {
        if (timer_reset == 1) {
            accumulatedElapsed = 0.0f;
            elapsedValue = 0.0f;
        }
        elapsedTimer.restart();
    }

    updateTimer.start(50);   // repaint only — timing is independent
}

void TimerRing::stopTimerAnimation()
{
    if (timerFlag == 0) {
        accumulatedElapsed = elapsedValue;
    }
    updateTimer.stop();
}

void TimerRing::resetTimer()
{
    if (timerFlag == 1) {
        currentValue = targetValue;
    } else {
        accumulatedElapsed = 0.0f;
        elapsedValue = 0.0f;
    }
    update();
}

float TimerRing::getCurrentValue() const
{
    return currentValue;
}

float TimerRing::getElapsedValue() const
{
    return elapsedValue;
}

void TimerRing::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int side = qMin(width(), height());
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 100.0, side / 100.0);

    // ===== Background Ring =====
    QPen bgPen(QColor(60, 60, 60), 8);
    painter.setPen(bgPen);
    painter.drawEllipse(QPoint(0, 0), 45, 45);

    // ===== Progress Ring =====
    QPen pen(QColor(255, 215, 0), 8);
    painter.setPen(pen);

    int angleSpan = 0;

    if (timerFlag == 1 && targetValue > 0.0f) {
        angleSpan = static_cast<int>(
            (currentValue / targetValue) * 360.0f * 16
            );
    } else {
        float rotationDuration = 10.0f;
        angleSpan = static_cast<int>(
            fmod(elapsedValue * (360.0f / rotationDuration), 360.0f) * 16
            );
    }

    painter.drawArc(-45, -45, 90, 90, 90 * 16, -angleSpan);

    // ===== Center Text =====
    QPen ctPen(QColor(50, 155, 255), 8);
    painter.setPen(ctPen);
    painter.setFont(QFont("Roboto", 20, QFont::Bold));

    QString text = (timerFlag == 1)
                       ? QString::number(currentValue, 'f', 1)
                       : QString::number(elapsedValue, 'f', 1);

    painter.drawText(QRect(-40, -20, 80, 40),
                     Qt::AlignCenter, text);
}

float TimerRing::getElapsedIncremental(bool freeze)
{
    if (timerFlag == 0) { // elapsed mode
        float val = accumulatedElapsed + (elapsedTimer.isValid() ? elapsedTimer.elapsed() / 1000.0f : 0.0f);
        if (freeze) {
            accumulatedElapsed = val; // lock it for next press
            elapsedTimer.invalidate(); // stop current elapsed count
        }
        return val;
    }
    return 0.0f; // countdown mode doesn't use this
}

