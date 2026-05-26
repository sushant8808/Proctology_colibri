#ifndef SET_DATE_TIME_H
#define SET_DATE_TIME_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <functional>

namespace Ui {
class Set_date_time;
}

class Home;

class Set_date_time : public QWidget
{
    Q_OBJECT

public:
    explicit Set_date_time(QWidget *parent = nullptr, Home *home = nullptr);
    ~Set_date_time();

private slots:
    void on_back_to_home_clicked();
    void on_back_to_service_engineer_area_clicked();

protected:
    void showEvent(QShowEvent *event) override;

private:
    void switchToHome();
    void switchToServiceEngArea();
    void refreshPage();
    void updateUIDisplays();
    void setupHoldButton(QPushButton *button, QTimer *&timer, const std::function<void()> &slotFunc);

    Ui::Set_date_time *ui;
    Home *home;

    // Tracking variables
    int m_year;
    int m_month;
    int m_day;
    int m_hour;
    int m_minute;

    // ✅ Dynamic Label Component Tracking Targets
    QLabel *m_lblYear = nullptr;
    QLabel *m_lblMonth = nullptr;
    QLabel *m_lblDay = nullptr;
    QLabel *m_lblHour = nullptr;
    QLabel *m_lblMin = nullptr;

    // Scroll Timers
    QTimer *t_yrAdd = nullptr; QTimer *t_yrSub = nullptr;
    QTimer *t_moAdd = nullptr; QTimer *t_moSub = nullptr;
    QTimer *t_daAdd = nullptr; QTimer *t_daSub = nullptr;
    QTimer *t_hrAdd = nullptr; QTimer *t_hrSub = nullptr;
    QTimer *t_miAdd = nullptr; QTimer *t_miSub = nullptr;
};

#endif // SET_DATE_TIME_H
