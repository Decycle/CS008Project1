#include "employeemenu.h"
#include "ui_employeemenu.h"

EmployeeMenu::EmployeeMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeMenu)
{
    ui->setupUi(this);
}

EmployeeMenu::~EmployeeMenu()
{
    delete ui;
}
