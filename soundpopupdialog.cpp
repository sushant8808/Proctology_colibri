#include "soundpopupdialog.h"
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include "global.h"
#include "tickedslider.h"

SoundPopupDialog::SoundPopupDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowFlags(Qt::Popup);
    setFixedSize(600, 300); // increased height for second slider

    // ---- First Slider (Volume) ----
    label = new QLabel("Speaker Volume", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 28px;");

    slider = new TickedSlider(this);
    slider->setRange(1, 5);
    slider->setTickInterval(1);
    slider->setValue(soundIntensity);

    connect(slider, &QSlider::valueChanged,
            this, &SoundPopupDialog::onSliderValueChanged);

    // ---- Second Slider (e.g., Tone / Beep Level) ----
    label2 = new QLabel("Buzzer volume", this);
    label2->setAlignment(Qt::AlignCenter);
    label2->setStyleSheet("font-size: 28px;");

    slider2 = new TickedSlider(this);
    slider2->setRange(1, 5);
    slider2->setTickInterval(1);
    slider2->setValue(beepIntensity);   // create this variable in global.h

    connect(slider2, &QSlider::valueChanged,
            this, &SoundPopupDialog::onSlider2ValueChanged);

    // ---- Layout ----
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addStretch();

    layout->addWidget(label);
    layout->addSpacing(10);
    layout->addWidget(slider);

    layout->addSpacing(40);

    layout->addWidget(label2);
    layout->addSpacing(10);
    layout->addWidget(slider2);

    layout->addStretch();
    layout->setContentsMargins(20, 20, 20, 20);

    setLayout(layout);

    QTimer::singleShot(4000, this, &QDialog::accept);
}

// ---- First Slider Handler ----
void SoundPopupDialog::onSliderValueChanged(int value)
{
    soundIntensity = value;
}

// ---- Second Slider Handler ----
void SoundPopupDialog::onSlider2ValueChanged(int value)
{
    beepIntensity = value;
}
