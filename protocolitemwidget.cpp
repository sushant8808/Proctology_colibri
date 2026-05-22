#include "protocolitemwidget.h"
#include <QMouseEvent>
#include "global.h"

ProtocolItemWidget::ProtocolItemWidget(int id,
                                       int its_dummy,
                                       const QString &name,
                                       bool favourite,
                                       QWidget *parent)
    : QWidget(parent),
      protocolId(id),
      isFavourite(favourite)
{
    setObjectName("protocolItem");

    // 🔥 THIS IS THE KEY LINE
    setAttribute(Qt::WA_StyledBackground, true);

    nameLabel = new QLabel(name);
    nameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    nameLabel->setWordWrap(true);

    if(its_dummy == 0)
    {
        starLabel = new QLabel();
        starLabel->setFixedSize(30, 30);
        starLabel->setCursor(Qt::PointingHandCursor);
        starLabel->setAlignment(Qt::AlignCenter);

        updateStar();
    }



    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *contentLayout = new QHBoxLayout();
    contentLayout->addWidget(nameLabel);
    contentLayout->addStretch();
    if(its_dummy == 0)
        contentLayout->addWidget(starLabel);

    mainLayout->addStretch();
    mainLayout->addLayout(contentLayout);
    mainLayout->addStretch();

    mainLayout->setContentsMargins(18, 12, 18, 12);
    mainLayout->setSpacing(6);

    // setMinimumHeight(80);
    setMinimumSize(300, 60);
    setMaximumHeight(90);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    if (dark == 0)
    {
        setStyleSheet(
                    "ProtocolItemWidget {"
            "background-color: rgb(60,60,60);"
            "border-radius: 20px;"
            "border: 2px solid black;"
            "color: white;"
            "}"
            );
    }
    else
    {
        setStyleSheet(
                    "ProtocolItemWidget {"
            "background-color: rgb(220,220,220);"
            "border-radius: 20px;"
            "border: 2px solid white;"
            "color: black;"
            "}"
            );
    }
}

void ProtocolItemWidget::mousePressEvent(QMouseEvent *event)
{
    if (starLabel->geometry().contains(event->pos()))
    {
        isFavourite = !isFavourite;
        updateStar();
        emit favouriteToggled(protocolId, isFavourite);
        event->accept();
        return;
    }

    emit clicked();
    event->accept();
}

void ProtocolItemWidget::updateStar()
{
    if(dark == 0)
    {
        if (isFavourite)
            starLabel->setPixmap(QPixmap(":/icons/star_filled_dark.png"));
        else
            starLabel->setPixmap(QPixmap(":/icons/star_outline_dark.png"));
    }else
    {
        if (isFavourite)
            starLabel->setPixmap(QPixmap(":/icons/star_filled_light.png"));
        else
            starLabel->setPixmap(QPixmap(":/icons/star_outline_light.png"));
    }

}


