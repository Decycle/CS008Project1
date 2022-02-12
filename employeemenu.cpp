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



void EmployeeMenu::on_LogOutButton_clicked()
{
    emit logOutClicked();
}


void EmployeeMenu::on_ViewReportButton_clicked()
{
    emit ViewReportClicked();
}

