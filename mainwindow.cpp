#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "infointerface.h"

#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Superware House");
    login = new Login();
    login->setWindowTitle("Login");

    connect(login, SIGNAL(returnMainWindow()), this, SLOT(show_main_window()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

InfoInterface MainWindow::ii;

void MainWindow::on_adminLoginButton_clicked()
{
   login->show();
   this->hide();
}

void MainWindow::show_main_window()
{
    this->show();
    login->hide();
}

void MainWindow::on_dailySalesReportButton_clicked()
{

    this->ui->outputConsole->setText(QString::fromStdString(ii.getFullReport()));
}

