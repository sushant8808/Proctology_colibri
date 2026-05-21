#ifndef CIRCULAROVERLAY_H
#define CIRCULAROVERLAY_H

#include <QWidget>

class CircularOverlay : public QWidget
{
    Q_OBJECT

public:
    explicit CircularOverlay(QWidget *parent = nullptr);
    void setProgress(int step); // 1 to 5

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int progressStep = 0; // 0 to 5
};

#endif // CIRCULAROVERLAY_H
