#ifndef PROTOCOLITEMWIDGET_H
#define PROTOCOLITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ProtocolItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProtocolItemWidget(int id,
                                const QString &name,
                                bool favourite,
                                QWidget *parent = nullptr);

signals:
    void clicked();
    void favouriteToggled(int id, bool fav);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    void updateStar();

    int protocolId;
    bool isFavourite;

    QLabel *nameLabel;
    QLabel *starLabel;
};

#endif
