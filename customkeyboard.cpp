#include "customkeyboard.h"

#include <QApplication>
#include <QScreen>

CustomKeyboard::CustomKeyboard(QWidget *parent)
    : QDialog(parent)
    , targetLineEdit(nullptr)
    , shiftEnabled(false)
    , capsEnabled(false)
{
    setWindowFlags(
        Qt::FramelessWindowHint |
        Qt::Dialog
        );

    setModal(true);

    setFixedSize(800, 320);

    setObjectName("CustomKeyboard");

    shiftEnabled = true;
    capsEnabled = false;

    createKeyboard();

    QRect screen = QGuiApplication::primaryScreen()->geometry();

    move(
        (screen.width() - width()) / 2,
        screen.height() - height() - 30
        );
}

void CustomKeyboard::setTarget(QLineEdit *target)
{
    targetLineEdit = target;

    if(target)
    {
        display->setText(target->text());
    }
}

QPushButton* CustomKeyboard::createButton(
    const QString &text,
    int width,
    int height)
{
    QPushButton *btn = new QPushButton(text);

    btn->setFixedSize(width, height);

    btn->setProperty("keyboardButton", true);

    return btn;
}

void CustomKeyboard::createKeyboard()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    mainLayout->setSpacing(5);
    mainLayout->setContentsMargins(8,8,8,8);

    display = new QLineEdit;
    display->setReadOnly(true);

    display->setObjectName("KeyboardDisplay");

    mainLayout->addWidget(display);

    // ================= ROW 1 =================

    QHBoxLayout *row1 = new QHBoxLayout;

    QString numbers = "1234567890";

    for(QChar c : numbers)
    {
        QPushButton *btn = createButton(QString(c), 60, 40);

        connect(btn,
                &QPushButton::clicked,
                this,
                &CustomKeyboard::handleKeyPress);

        row1->addWidget(btn);
    }

    QPushButton *backBtn = createButton("⌫", 90, 40);

    backBtn->setProperty("keyboardSpecial", true);

    connect(backBtn,
            &QPushButton::clicked,
            this,
            &CustomKeyboard::onBackspace);

    row1->addWidget(backBtn);

    mainLayout->addLayout(row1);

    // ================= ROW 2 =================

    QHBoxLayout *row2 = new QHBoxLayout;

    QString row2Keys = "QWERTYUIOP";

    for(QChar c : row2Keys)
    {
        QPushButton *btn = createButton(QString(c), 60, 40);

        connect(btn,
                &QPushButton::clicked,
                this,
                &CustomKeyboard::handleKeyPress);

        row2->addWidget(btn);

        letterButtons.append(btn);
    }

    mainLayout->addLayout(row2);

    // ================= ROW 3 =================

    QHBoxLayout *row3 = new QHBoxLayout;

    QString row3Keys = "ASDFGHJKL";

    row3->addSpacing(35);

    for(QChar c : row3Keys)
    {
        QPushButton *btn = createButton(QString(c), 60, 40);

        connect(btn,
                &QPushButton::clicked,
                this,
                &CustomKeyboard::handleKeyPress);

        row3->addWidget(btn);

        letterButtons.append(btn);
    }

    row3->addSpacing(35);

    mainLayout->addLayout(row3);

    // ================= ROW 4 =================

    QHBoxLayout *row4 = new QHBoxLayout;

    shiftButton = createButton("🡅 Shift", 90, 40);

    shiftButton->setProperty("keyboardSpecial", true);

    shiftButton->setCheckable(true);

    connect(shiftButton,
            &QPushButton::clicked,
            this,
            &CustomKeyboard::onShift);

    row4->addWidget(shiftButton);

    QString row4Keys = "ZXCVBNM";

    for(QChar c : row4Keys)
    {
        QPushButton *btn = createButton(QString(c), 60, 40);

        connect(btn,
                &QPushButton::clicked,
                this,
                &CustomKeyboard::handleKeyPress);

        row4->addWidget(btn);

        letterButtons.append(btn);
    }

    QPushButton *clearBtn = createButton("Clear", 90, 40);

    clearBtn->setProperty("keyboardSpecial", true);

    connect(clearBtn,
            &QPushButton::clicked,
            this,
            &CustomKeyboard::onClear);

    row4->addWidget(clearBtn);

    mainLayout->addLayout(row4);

    // ================= ROW 5 =================

    QHBoxLayout *row5 = new QHBoxLayout;

    capsButton = createButton("Caps", 90, 40);

    capsButton->setProperty("keyboardSpecial", true);

    capsButton->setCheckable(true);

    connect(capsButton,
            &QPushButton::clicked,
            this,
            &CustomKeyboard::onCaps);

    row5->addWidget(capsButton);

    QPushButton *spaceBtn = createButton("Space ⎵", 420, 40);

    spaceBtn->setProperty("keyboardSpace", true);

    connect(spaceBtn,
            &QPushButton::clicked,
            this,
            &CustomKeyboard::onSpace);

    row5->addWidget(spaceBtn);

    QPushButton *dotBtn = createButton(".", 60, 40);

    connect(dotBtn,
            &QPushButton::clicked,
            this,
            &CustomKeyboard::handleKeyPress);

    row5->addWidget(dotBtn);

    QPushButton *enterBtn = createButton("Enter", 120, 40);

    enterBtn->setProperty("keyboardEnter", true);

    connect(enterBtn,
            &QPushButton::clicked,
            this,
            &CustomKeyboard::onEnter);

    row5->addWidget(enterBtn);

    mainLayout->addLayout(row5);
}

void CustomKeyboard::handleKeyPress()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    if(!btn)
        return;

    display->insert(btn->text());

    // After one uppercase press,
    // return to lowercase automatically
    if(shiftEnabled)
    {
        shiftEnabled = false;

        shiftButton->setChecked(false);

        updateKeyCase();
    }
}

void CustomKeyboard::onBackspace()
{
    QString text = display->text();

    text.chop(1);

    display->setText(text);
}

void CustomKeyboard::onClear()
{
    display->clear();
}

void CustomKeyboard::onSpace()
{
    display->insert(" ");
}

void CustomKeyboard::onEnter()
{
    if(targetLineEdit)
    {
        targetLineEdit->setText(display->text());
    }

    accept();
}

void CustomKeyboard::onShift()
{
    shiftEnabled = !shiftEnabled;

    shiftButton->setChecked(shiftEnabled);

    updateKeyCase();
}

void CustomKeyboard::onCaps()
{
    capsEnabled = !capsEnabled;

    capsButton->setChecked(capsEnabled);

    updateKeyCase();
}

void CustomKeyboard::updateKeyCase()
{
    bool upper = shiftEnabled || capsEnabled;

    for(QPushButton *btn : letterButtons)
    {
        QString lower = btn->text().toLower();

        if(upper)
            btn->setText(lower.toUpper());
        else
            btn->setText(lower.toLower());
    }
}
