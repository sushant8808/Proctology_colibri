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

    int sliderMin = style()->pixelMetric(QStyle::PM_SliderLength) / 2;
    int sliderMax = width() - style()->pixelMetric(QStyle::PM_SliderLength) / 2;
    int range = maximum() - minimum();

    for (int i = minimum(); i <= maximum(); ++i) {
        double normVal = double(i - minimum()) / range;
        int x = sliderMin + int(normVal * (sliderMax - sliderMin)) - 2;
        int y = height() / 2;

        painter.drawEllipse(QPoint(x, y), 5, 5);
    }

    QSlider::paintEvent(event);
}

// Add this function to handle the touchscreen taps perfectly
void TickedSlider::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // Get the internal slider metrics just like in paintEvent
        int sliderMin = style()->pixelMetric(QStyle::PM_SliderLength) / 2;
        int sliderMax = width() - style()->pixelMetric(QStyle::PM_SliderLength) / 2;

        int clickX = event->x();

        // Constrain click coordinates to the actual slider track bounds
        if (clickX < sliderMin) clickX = sliderMin;
        if (clickX > sliderMax) clickX = sliderMax;

        // Calculate the ratio of where the click happened along the track
        double ratio = double(clickX - sliderMin) / double(sliderMax - sliderMin);

        // Convert that ratio to your range (1 to 5)
        int range = maximum() - minimum();
        int newValue = minimum() + qRound(ratio * range);

        // Account for layout inversion (e.g. Right-to-Left languages)
        if (this->invertedAppearance()) {
            newValue = maximum() - (newValue - minimum());
        }

        this->setValue(newValue);

        // Accept the event so it doesn't propagate further
        event->accept();
    }

    // Call the base class implementation so standard dragging/sliding mechanics still work
    QSlider::mousePressEvent(event);
}
