#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "infointerface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static InfoInterface ii;

private slots:
    void show_main_window();

    void on_adminLoginButton_clicked();
    void on_dailySalesReportButton_clicked();

private:
    Ui::MainWindow *ui;
    Login *login;
};
#endif // MAINWINDOW_H
