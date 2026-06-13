#include "clickablelabel.h"
#include <QMouseEvent>
#include "hardwaremanagerprovider.h"

ClickableLabel::ClickableLabel(QWidget *parent)
    : QLabel(parent) {}

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent) {}   // ✅ added this

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    TOUCH_BEEP();
    emit clicked();
}
