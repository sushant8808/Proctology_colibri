#include "tickedslider.h"
#include <QPainter>
#include <QStyleOptionSlider>
#include <QStyle>

TickedSlider::TickedSlider(QWidget *parent)
    : QSlider(Qt::Horizontal, parent)
{
    setTickPosition(QSlider::NoTicks);
    setTickInterval(1);
    setRange(1, 5);
}

void TickedSlider::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(palette().text().color());

    painter.setPen(Qt::NoPen);

    QStyleOptionSlider opt;
    initStyleOption(&opt);

    int sliderMin =
        style()->pixelMetric(QStyle::PM_SliderLength) / 2;

    int sliderMax =
        width() - style()->pixelMetric(QStyle::PM_SliderLength) / 2;

    int range = maximum() - minimum();

    for (int i = minimum(); i <= maximum(); ++i) {
        double normVal = double(i - minimum()) / range;
        int x = sliderMin + int(normVal * (sliderMax - sliderMin)) - 2;
        int y = height() / 2;

        painter.drawEllipse(QPoint(x, y), 5, 5);
    }

    QSlider::paintEvent(event);
}
