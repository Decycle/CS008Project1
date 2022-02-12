#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QWidget>

namespace Ui {
class AdminMenu;
}

class AdminMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = nullptr);
    ~AdminMenu();
signals:
    void logOutClicked();
    void ViewReportClicked();
    void EditInfoClicked();
private slots:

    void on_logOffButton_clicked();

    void on_ViewReportButton_clicked();


    void on_editIntoButton_clicked();

private:
    Ui::AdminMenu *ui;
};

#endif // ADMINMENU_H
