#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    //add code for use below
    //index 1
    ui->stackedWidget->insertWidget(1,&LogInvalid);
    //index 2
    ui->stackedWidget->insertWidget(2,&AdmMenu);
    //index 3
    ui->stackedWidget->insertWidget(3,&EmpMenu);
    //index 4
    ui->stackedWidget->insertWidget(4,&RepMenu);
    //index 5
    ui->stackedWidget->insertWidget(5,&EditMenu);
    //invalid login to login
    connect(&LogInvalid,SIGNAL(okClicked()), this, SLOT(moveHome()));
    //admin menu logging out to login
    connect(&AdmMenu,SIGNAL(logOutClicked()), this, SLOT(moveHome()));
    //employee menu logging out to login
    connect(&EmpMenu,SIGNAL(logOutClicked()), this, SLOT(moveHome()));
    //report info logging out to login
    connect(&RepMenu,SIGNAL(logOutClicked()), this, SLOT(moveHome()));
    //edit info logging out to login
    connect(&EditMenu,SIGNAL(logOutClicked()), this, SLOT(moveHome()));
    //admin menu to view report
    connect(&AdmMenu,SIGNAL(ViewReportClicked()), this, SLOT(moveReport()));
    //employee menu to view report
    connect(&EmpMenu,SIGNAL(ViewReportClicked()), this, SLOT(moveReport()));
    //admin menu to edit info
    connect(&AdmMenu,SIGNAL(EditInfoClicked()), this, SLOT(moveEdit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_TestInvalidButton_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_CloseButton_clicked()
{
    this->close();
}

void MainWindow::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::moveReport()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::moveEdit()
{
    ui->stackedWidget->setCurrentIndex(5);
}



void MainWindow::on_TestAdminButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_TestEmployeeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_SubmitButton_clicked()
{
    std::string userInput;
    std::string passInput;
    userInput =ui->UsernameInput->toPlainText().toStdString();
    passInput =ui->PasswordInput->toPlainText().toStdString();
    //no longer need
//    QString user =ui->UsernameInput->toPlainText();
//    QString pass =ui->PasswordInput->toPlainText();
//    std::stringstream ss;
//    ss.str("");
//    ss << user.toStdString();
//    ss >> userInput;
//    std::cout << userInput<<std::endl;
//    ss.clear();
//    ss.str("");
//    ss << pass.toStdString();
//    ss >> passInput;
//    std::cout << passInput<<std::endl;

    if (userInput == "admin" && passInput == "admin"){
        ui->stackedWidget->setCurrentIndex(2);
    }
    else{
        ui->stackedWidget->setCurrentIndex(1);
    }
    ui->UsernameInput->clear();
    ui->PasswordInput->clear();
}

