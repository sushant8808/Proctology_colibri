#include "clickablelabel.h"
#include <QMouseEvent>

ClickableLabel::ClickableLabel(QWidget *parent)
    : QLabel(parent) {}

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent) {}   // ✅ added this

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}
