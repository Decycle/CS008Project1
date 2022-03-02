#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->ui->wrong_password->hide();

    adminMenu = new AdminMenu();

    connect(adminMenu, SIGNAL(return_login_window()), this, SLOT(show_login_window()));
}

Login::~Login()
{
    delete ui;
}


void Login::on_login_button_clicked()
{
    QString username = this->ui->username_input->text();
    QString password = this->ui->password_input->text();

    if(username == "admin" && password == "admin")
    {
        adminMenu->show();
        this->hide();
    }
    else
    {
        this->ui->wrong_password->show();
    }
}

void Login::show_login_window()
{
    adminMenu->hide();
    this->show();
}


void Login::on_exit_button_clicked()
{
    this->ui->wrong_password->hide();
    emit returnMainWindow();
}

