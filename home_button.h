#ifndef HOME_BUTTON_H
#define HOME_BUTTON_H

#include <QPushButton>

class home_button : public QPushButton
{
    Q_OBJECT
public:
    explicit home_button(QWidget *parent = nullptr);
};

#endif // HOME_BUTTON_H
