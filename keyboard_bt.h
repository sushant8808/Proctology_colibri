#ifndef KEYBOARD_BT_H
#define KEYBOARD_BT_H

#include <QPushButton>

class keyboard_bt : public QPushButton
{
    Q_OBJECT
public:
    explicit keyboard_bt(QWidget *parent = nullptr);
};

#endif // KEYBOARD_BT_H
