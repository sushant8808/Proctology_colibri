#include "customkeyboard.h"

#include <QApplication>
#include <QScreen>

CustomKeyboard::CustomKeyboard(QWidget *parent, KeyboardMode mode)
    : QDialog(parent)
    , targetLineEdit(nullptr)
    , shiftEnabled(false)
    , capsEnabled(false)
    , currentMode(mode)
{

    setWindowFlags(Qt::Popup);

    setModal(true);

    if (currentMode == NumericOnly) {
        setFixedSize(320, 420); // Square numeric grid profile
    } else {
        setFixedSize(800, 320); // Wide landscape full key layout
    }

    setObjectName("CustomKeyboard");

    shiftEnabled = (currentMode == FullLayout);
    capsEnabled = false;

    createKeyboard();

    QRect screen = QGuiApplication::primaryScreen()->geometry();

    move(
                (screen.width() - width()) / 2,
                screen.height() - height() - 30
                );
}

void CustomKeyboard::setKeyboardMode(KeyboardMode mode)
{
    currentMode = mode;
    // Adjust size sizing context dynamically if altered runtime
    if (currentMode == NumericOnly) setFixedSize(320, 420);
    else setFixedSize(800, 320);
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

    if (currentMode == NumericOnly)
    {
        QGridLayout *numGrid = new QGridLayout();
        numGrid->setSpacing(5);

        // Standard ATM/Phone matrix layout configuration string
        QStringList keys = {
            "1", "2", "3",
            "4", "5", "6",
            "7", "8", "9",
            "⌫", "0", "Clear"
        };

        int index = 0;
        for(int row = 0; row < 4; ++row) {
            for(int col = 0; col < 3; ++col) {
                QString keyText = keys[index++];
                QPushButton *btn = createButton(keyText, 90, 60); // Taller key sizing

                if (keyText == "⌫") {
                    btn->setProperty("keyboardSpecial", true);
                    connect(btn, &QPushButton::clicked, this, &CustomKeyboard::onBackspace);
                } else if (keyText == "Clear") {
                    btn->setProperty("keyboardSpecial", true);
                    connect(btn, &QPushButton::clicked, this, &CustomKeyboard::onClear);
                } else {
                    connect(btn, &QPushButton::clicked, this, &CustomKeyboard::handleKeyPress);
                }
                numGrid->addWidget(btn, row, col);
            }
        }
        mainLayout->addLayout(numGrid);

        // Bottom horizontal execution strip
        QHBoxLayout *bottomRow = new QHBoxLayout();


        QPushButton *enterBtn = createButton("Enter", 195, 50);
        enterBtn->setProperty("keyboardEnter", true);
        connect(enterBtn, &QPushButton::clicked, this, &CustomKeyboard::onEnter);

        bottomRow->addWidget(enterBtn);
        mainLayout->addLayout(bottomRow);
    }

    else
    {

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

        if (shiftButton) {
            shiftButton->setChecked(false);
        }
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

    if (shiftButton) {
        shiftButton->setChecked(shiftEnabled);
    }

    updateKeyCase();
}

void CustomKeyboard::onCaps()
{
    capsEnabled = !capsEnabled;

    if (capsButton) {
        capsButton->setChecked(capsEnabled);
    }

    updateKeyCase();
}

void CustomKeyboard::updateKeyCase()
{

    if (currentMode == NumericOnly)
        return;

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

