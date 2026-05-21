#ifndef CUSTOMKEYBOARD_H
#define CUSTOMKEYBOARD_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

class CustomKeyboard : public QDialog
{
    Q_OBJECT

public:
    explicit CustomKeyboard(QWidget *parent = nullptr);

    void setTarget(QLineEdit *target);

private slots:
    void handleKeyPress();
    void onBackspace();
    void onClear();
    void onSpace();
    void onEnter();
    void onShift();
    void onCaps();

private:
    void createKeyboard();
    QPushButton* createButton(const QString &text,
                              int width = 70,
                              int height = 60);

    void updateKeyCase();

private:
    QLineEdit *display;
    QLineEdit *targetLineEdit;

    QList<QPushButton*> letterButtons;

    QPushButton *shiftButton;
    QPushButton *capsButton;

    bool shiftEnabled;
    bool capsEnabled;
};

#endif
