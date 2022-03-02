#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->ui->wrong_password->hide();
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

    }
    else
    {
        this->ui->wrong_password->show();
    }
}


void Login::on_exit_button_clicked()
{
    this->ui->wrong_password->hide();
    emit returnMainWindow();
}

