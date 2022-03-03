#include "adminmenu.h"
#include "ui_adminmenu.h"
#include "mainwindow.h"

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

void AdminMenu::on_exit_button_clicked()
{
    emit return_login_window();
}

void AdminMenu::on_load_purchase_file_button_clicked()
{
    QString filename = this->ui->file_name_input->text();
    MainWindow::ii.readDayFile(filename.toStdString());

}


void AdminMenu::on_load_member_file_button_clicked()
{
    QString filename = this->ui->file_name_input->text();
    MainWindow::ii.readMemberFile(filename.toStdString());
}

