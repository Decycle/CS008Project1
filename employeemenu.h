#ifndef EMPLOYEEMENU_H
#define EMPLOYEEMENU_H

#include <QWidget>

namespace Ui {
class EmployeeMenu;
}

class EmployeeMenu : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeeMenu(QWidget *parent = nullptr);
    ~EmployeeMenu();
signals:
    void logOutClicked();
    void ViewReportClicked();

private slots:
    void on_LogOutButton_clicked();

    void on_ViewReportButton_clicked();

private:
    Ui::EmployeeMenu *ui;
};

#endif // EMPLOYEEMENU_H
