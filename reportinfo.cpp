#include "reportinfo.h"
#include "ui_reportinfo.h"

ReportInfo::ReportInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportInfo)
{
    ui->setupUi(this);
}

ReportInfo::~ReportInfo()
{
    delete ui;
}
