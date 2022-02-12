#include "editinfo.h"
#include "ui_editinfo.h"

EditInfo::EditInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditInfo)
{
    ui->setupUi(this);
}

EditInfo::~EditInfo()
{
    delete ui;
}

void EditInfo::on_pushButton_clicked()
{
    emit logOutClicked();
}

