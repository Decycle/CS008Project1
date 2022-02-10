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

private:
    Ui::EmployeeMenu *ui;
};

#endif // EMPLOYEEMENU_H
