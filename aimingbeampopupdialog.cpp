#include "aimingbeampopupdialog.h"
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include "global.h"
#include "tickedslider.h"
#include "pageindex.h"
#include "hardwaremanagerprovider.h"

AimingBeamPopupDialog::AimingBeamPopupDialog(QWidget *parent)
    : QDialog(parent)
{

    setWindowFlags(Qt::Popup);
    setFixedSize(600, 200);

    label = new QLabel("Aiming Beam Intensity", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 26px;");

    slider = new TickedSlider(this);
    slider->setRange(1, 5);
    slider->setTickInterval(1);

    connect(slider, &QSlider::valueChanged, this, &AimingBeamPopupDialog::onSliderValueChanged);

    slider->setValue(aimingbeamIntensity);

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

void AimingBeamPopupDialog::onSliderValueChanged(int value)
{
    aimingbeamIntensity = value;
    HardwareManagerProvider::instance()->demoAimingBeam(value, g_stackIndex != PAGE_READYFORSURGERY);
    //qDebug()<<aimingbeamIntensity;
}
