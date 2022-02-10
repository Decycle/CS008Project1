#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //add code for use below
    //index 1
    ui->stackedWidget->insertWidget(1,&LogInvalid);
    //index 2
    ui->stackedWidget->insertWidget(2,&AdmMenu);
    //index 3
    ui->stackedWidget->insertWidget(3,&EmpMenu);

    connect(&LogInvalid,SIGNAL(okClicked()), this, SLOT(moveLogin()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CloseButton_clicked()
{
    this->close();
}

void MainWindow::moveLogin()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_TestEmployeeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_LoginButton_clicked()
{
    QString username = ui->UsernameInput->toPlainText();
    QString password = ui->UsernameInput->toPlainText();

    if(username == "admin" && password == "admin")
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
}

