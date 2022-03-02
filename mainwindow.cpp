#include "mainwindow.h"
#include "ui_mainwindow.h"

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
