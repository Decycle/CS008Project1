#include "logininvalid.h"
#include "ui_logininvalid.h"

LoginInvalid::LoginInvalid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginInvalid)
{
    ui->setupUi(this);
}

LoginInvalid::~LoginInvalid()
{
    delete ui;
}

void LoginInvalid::on_okButton_clicked()
{
    emit okClicked();
}

