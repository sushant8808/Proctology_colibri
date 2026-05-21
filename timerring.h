#ifndef TIMER_RING_H
#define TIMER_RING_H

#include <QWidget>
#include <QTimer>
#include <QElapsedTimer>

class TimerRing : public QWidget
{
    Q_OBJECT
public:
    explicit TimerRing(QWidget *parent = nullptr);

    void setTargetValue(float value);
    void startTimerAnimation();
    void stopTimerAnimation();
    void resetTimer();

    float getCurrentValue() const;
    float getElapsedValue() const;

    // Returns total elapsed time, optionally freezing accumulatedElapsed
    float getElapsedIncremental(bool freeze = false);


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QTimer updateTimer;

    // Countdown
    float targetValue = 10.0f;
    float currentValue = 0.0f;
    float countdownStartValue = 0.0f;
    QElapsedTimer countdownTimer;

    // Elapsed
    float elapsedValue = 0.0f;
    float accumulatedElapsed = 0.0f;
    QElapsedTimer elapsedTimer;
};

#endif // TIMER_RING_H
