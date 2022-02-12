#include "reportinfo.h"
#include "ui_reportinfo.h"
#include <sstream>

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

void ReportInfo::on_LogOutButton_clicked()
{
    emit logOutClicked();
}


void ReportInfo::on_testButton_clicked()
{
    std::string test = "o\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                       "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nnice";
    std::stringstream sSDisplay;
    std::string out;
    sSDisplay.clear();
    sSDisplay.str(test);
    out = sSDisplay.str();
    QString qstr = QString::fromStdString(out);

    ui->ReportDisplay->setText(qstr);
}


void ReportInfo::on_testItemButton_clicked()
{
    //input fetch
    std::string Input;

    //unnecessary
    QString input =ui->ItemSearchInput->toPlainText();

    Input = (ui->ItemSearchInput->toPlainText()).toStdString();
    //also seems to be unnecessary
    //QString::fromUtf8(Input.c_str());
//    std::stringstream ss;
//    ss.str("");
//    ss << input.toStdString();
//    ss >> Input;

    //item search
    std::string test = inv.pull(Input,fullfile);
    //item process
    std::stringstream sSDisplay;
    std::string out;
    sSDisplay.clear();
    sSDisplay.str(test);
    out = sSDisplay.str();
    QString qstr = QString::fromStdString(test);

    ui->ReportDisplay->setText(qstr);
\
}


void ReportInfo::on_testDayButton_clicked()
{
    int a = ui->DayBox->value();
    stringstream ss;
    ss.clear();
    ss<<a;
    std::string str = ss.str();
    std::string filename = file + str +filetype;
    std::string out = inv.print(inv.add(filename));
//    std::stringstream sSDisplay;
//    std::string out;
//    sSDisplay.clear();
//    sSDisplay.str(test);
//    out = sSDisplay.str();
    QString qstr = QString::fromStdString(out);

    ui->ReportDisplay->setText(qstr);
}

