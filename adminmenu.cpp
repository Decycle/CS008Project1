#include "adminmenu.h"
#include "ui_adminmenu.h"

AdminMenu::AdminMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminMenu)
{
    ui->setupUi(this);
}

AdminMenu::~AdminMenu()
{
    delete ui;
}

void AdminMenu::on_logOffButton_clicked()
{
    emit logOutClicked();
}


void AdminMenu::on_ViewReportButton_clicked()
{
    emit ViewReportClicked();
}

void AdminMenu::on_editIntoButton_clicked()
{
    emit EditInfoClicked();
}

