#include "circularoverlay.h"
#include <QPainter>
#include <QPen>
#include <QtMath>

CircularOverlay::CircularOverlay(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);
}

void CircularOverlay::setProgress(int step)
{
    progressStep = qBound(0, step, 5);
    update();
}

void CircularOverlay::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QRectF rect = this->rect().adjusted(3, 3, -3, -3);
    QPen pen(Qt::white, 4);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);

    pen.setColor(Qt::gray);
    painter.setPen(pen);
    painter.drawEllipse(rect);

    if (progressStep > 0) {
        pen.setColor(QColor(0, 255, 0));
        painter.setPen(pen);

        qreal spanAngle = 360.0 / 5.0 * progressStep;
        painter.drawArc(rect, 90 * 16, -spanAngle * 16);
    }
}
