#include "brightnesspopupdialog.h"
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include "global.h"
#include "tickedslider.h"

BrightnessPopupDialog::BrightnessPopupDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowFlags(Qt::Popup);
    setFixedSize(600, 200);

    label = new QLabel("Screen Brightness", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 28px;");

    slider = new TickedSlider(this);
    slider->setRange(1, 5);
    slider->setTickInterval(1);

    connect(slider, &QSlider::valueChanged, this, &BrightnessPopupDialog::onSliderValueChanged);

    slider->setValue(brightnessIntensity);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addStretch();
    layout->addWidget(label);
    layout->addSpacing(20);
    layout->addWidget(slider);
    layout->addStretch();
    layout->setContentsMargins(20, 20, 20, 20);
    setLayout(layout);

    QTimer::singleShot(4000, this, &QDialog::accept);

}

void BrightnessPopupDialog::onSliderValueChanged(int value)
{
    brightnessIntensity = value;
    //qDebug()<<brightnessIntensity;
}
