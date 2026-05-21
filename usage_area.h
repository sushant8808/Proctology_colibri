#ifndef USAGE_AREA_H
#define USAGE_AREA_H

#include <QWidget>
#include "home.h"
#include "error_popup.h"

namespace Ui {
class usage_area;
}

class usage_area : public QWidget
{
    Q_OBJECT

public:
    explicit usage_area(QWidget *parent = nullptr, Home *home = nullptr);
    ~usage_area();

protected:
    void showEvent(QShowEvent *event) override;

private:
    void refreshPage();

private slots:
    void on_B3_back_to_setting_clicked();

    void loadSurgerySummaryPage(int page);

    void on_prevButton_clicked();

    void on_nextButton_clicked();

    void deleteSelectedRows();

    void deleteCurrentPage();

    void on_B3_clear_data_clicked();

    void clear_data_form_userdb();

private:
    Ui::usage_area *ui;
    Home *home;

    int currentPage = 0;
    const int pageSize = 6;

    error_popup *popup;
};

#endif // USAGE_AREA_H
