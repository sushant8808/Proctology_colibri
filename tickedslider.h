#pragma once

#include <QSlider>

class TickedSlider : public QSlider
{
    Q_OBJECT
public:
    explicit TickedSlider(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};
