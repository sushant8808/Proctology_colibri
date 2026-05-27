#include "error_popup.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QScreen>
#include "global.h"

error_popup::error_popup(QWidget *parent)
    : QWidget(parent),
      canAcknowledge(false)
{
    //    // Full screen overlay
    //    setWindowFlags(Qt::FramelessWindowHint |
    //                   Qt::WindowStaysOnTopHint);

    setWindowFlags(Qt::Popup);


    setAttribute(Qt::WA_TintedBackground);

    if (parent)
        setGeometry(parent->rect());
    else
        setGeometry(QApplication::primaryScreen()->geometry());

    // Dimmed background
    setStyleSheet("background-color: rgba(0, 0, 0, 225);");

    // ===== Center Box =====
    centerBox = new QWidget(this);
    centerBox->setFixedSize(650, 350);
    centerBox->setStyleSheet(
                "background-color: #1E1F23;"
        "border-radius: 14px;"
        "color: white;"
        );

    centerBox->move(width()/2 - centerBox->width()/2,
                    height()/2 - centerBox->height()/2);

    QVBoxLayout *mainLayout = new QVBoxLayout(centerBox);
    mainLayout->setSpacing(18);
    mainLayout->setContentsMargins(40, 30, 40, 30);

    // ===== Severity Top Bar =====
    severityBar = new QWidget(centerBox);
    severityBar->setFixedHeight(8);
    severityBar->setStyleSheet(
                "border-top-left-radius:14px;"
        "border-top-right-radius:14px;"
        );

    mainLayout->addWidget(severityBar);

    // ===== Status Label =====
    statusLabel = new QLabel("STATUS", centerBox);
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setStyleSheet(
                "font-size: 14px;"
        "font-weight: bold;"
        "letter-spacing: 1px;"
        );

    mainLayout->addWidget(statusLabel);

    // ===== Title =====
    titleLabel = new QLabel("TITLE", centerBox);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet(
                "font-size: 32px;"
        "font-weight: 600;"
        "letter-spacing: 1px;"
        );

    mainLayout->addWidget(titleLabel);

    // ===== Message =====
    messageLabel = new QLabel("Message text", centerBox);
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->setWordWrap(true);
    messageLabel->setStyleSheet(
                "font-size: 22px;"
        "color: #D0D0D0;"
        );

    mainLayout->addWidget(messageLabel);
    mainLayout->addStretch();

    // ===== Acknowledge Button =====

    ackButton = new QPushButton("OK", centerBox);
    yesButton = new QPushButton("YES", centerBox);
    noButton  = new QPushButton("NO", centerBox);

    ackButton->setFixedHeight(50);
    yesButton->setFixedHeight(50);
    noButton->setFixedHeight(50);


    ackButton->setStyleSheet(
                "QPushButton {"
            "background-color: #3A3A3A;"
            "color: white;"
            "border: 1px solid rgb(255, 97, 34);"
            "border-radius: 25px;"
            "font-size:20px;"
            "}"
            "QPushButton:pressed {"
            "background-color: #2A2A2A;"
            "}"
            );


    yesButton->setStyleSheet(
                "QPushButton {"
        "background-color: #3A3A3A;"
        "color: white;"
        "border: 1px solid rgb(255, 97, 34);"
        "border-radius: 25px;"
        "font-size:20px;"
        "}"
        "QPushButton:pressed {"
        "background-color: #2A2A2A;"
        "}"
        );
    noButton->setStyleSheet(
                "QPushButton {"
        "background-color: #3A3A3A;"
        "color: white;"
        "border: 1px solid rgb(255, 97, 34);"
        "border-radius: 25px;"
        "font-size:20px;"
        "}"
        "QPushButton:pressed {"
        "background-color: #2A2A2A;"
        "}"
        );

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(yesButton);
    buttonLayout->addWidget(noButton);
    buttonLayout->addWidget(ackButton);

    mainLayout->addLayout(buttonLayout);

    yesButton->hide();
    noButton->hide();

    connect(ackButton, &QPushButton::clicked, this, [=]() {
        if (canAcknowledge)
        {
            emit acknowledged();
            hide();
        }
    });

    connect(yesButton, &QPushButton::clicked, this, [=]() {
        emit yesClicked();
        hide();
    });

    connect(noButton, &QPushButton::clicked, this, [=]() {
        emit noClicked();
        hide();
    });

    hide();
}

QString error_popup::severityText(Severity s)
{
    switch (s)
    {
    case Critical: return "CRITICAL FAULT";
    case Warning:  return "WARNING";
    case Info:     return "SYSTEM INFORMATION";
    case Success:  return "OPERATION SUCCESSFUL";
    case Confirmation: return "Confirmation";
    default:       return "";
    }
}

QString error_popup::severityColor(Severity s)
{
    switch (s)
    {
    case Critical: return "#C62828";  // red
    case Warning:  return "#F9A825";  // amber
    case Info:     return "#1565C0";  // blue
    case Success:  return "#2E7D32";  // green
    case Confirmation: return "#F0E68C";
    default:       return "#3A3A3A";
    }
}

void error_popup::showMessage(const QString &title,
                              const QString &message,
                              Severity severity,
                              bool acknowledgeAllowed)
{
    canAcknowledge = acknowledgeAllowed;

    statusLabel->setText(severityText(severity));
    statusLabel->setStyleSheet(QString(
                                   "font-size:14px;"
                                   "font-weight:bold;"
                                   "letter-spacing:1px;"
                                   "color:%1;").arg(severityColor(severity)));

    severityBar->setStyleSheet(QString(
                                   "background-color:%1;"
                                   "border-top-left-radius:14px;"
                                   "border-top-right-radius:14px;")
                               .arg(severityColor(severity)));

    if(surgery_pause_bt)
        ackButton->setText("RESUME");
    else if(override_popup)
        ackButton->setText("Override");
    else
        ackButton->setText("OK");

    if(surgery_pause_bt || override_popup)
    {
        ackButton->setStyleSheet(
                    "QPushButton {"
            "background-color: rgb(255, 97, 34);"
            "color: white;"
            "max-width: 150px;"
            "border: 1px solid rgb(255, 97, 34);"
            "border-radius: 25px;"
            "font-size:20px;"
            "}"
            "QPushButton:pressed {"
            "background-color: #2A2A2A;"
            "}"
            );
    }

    else
    {
        ackButton->setStyleSheet(
                    "QPushButton {"
            "background-color: #3A3A3A;"
            "color: white;"
            "border: 1px solid rgb(255, 97, 34);"
            "border-radius: 25px;"
            "font-size:20px;"
            "}"
            "QPushButton:pressed {"
            "background-color: #2A2A2A;"
            "}"
            );
    }

    titleLabel->setText(title);
    messageLabel->setText(message);

    if (severity == Confirmation)
    {
        ackButton->hide();
        yesButton->show();
        noButton->show();
    }
    else
    {
        yesButton->hide();
        noButton->hide();
        ackButton->setVisible(acknowledgeAllowed);
    }

    show();
    raise();
}

void error_popup::hidePopup()
{
    if (!canAcknowledge)
        return;

    hide();
}

void error_popup::forceHide()
{
    // We explicitly bypass the 'canAcknowledge' check here
    // because this is called directly by your system code.
    QWidget::hide();
}
