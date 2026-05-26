#ifndef TICKEDSLIDER_H
#define TICKEDSLIDER_H

#include <QSlider>
#include <QMouseEvent>

class TickedSlider : public QSlider
{
    Q_OBJECT

public:
    TickedSlider(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override; // <-- Add this line
};

#endif // TICKEDSLIDER_H
