#ifndef ERROR_POPUP_H
#define ERROR_POPUP_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class error_popup : public QWidget
{
    Q_OBJECT

public:
    enum Severity
    {
        Critical,
        Warning,
        Info,
        Success,
        Validation
    };

    explicit error_popup(QWidget *parent = nullptr);

    void showMessage(const QString &title,
                     const QString &message,
                     Severity severity,
                     bool acknowledgeAllowed);

    void hidePopup();

private:
    QWidget *centerBox;
    QWidget *severityBar;

    QLabel *statusLabel;
    QLabel *titleLabel;
    QLabel *messageLabel;

    QPushButton *ackButton;
    QPushButton *yesButton;
    QPushButton *noButton;


    bool canAcknowledge;

    QString severityText(Severity s);
    QString severityColor(Severity s);

signals:
    void acknowledged();      // for OK type popups
    void yesClicked();        // for validation
    void noClicked();         // for validation
};

#endif // ERROR_POPUP_H
