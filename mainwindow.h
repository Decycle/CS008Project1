#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logininvalid.h"
#include "employeemenu.h"
#include "adminmenu.h"
#include "reportinfo.h"
#include "editinfo.h"

#include "inventory.h"
/*
 * For Reference the mainwindow is the login page
 *
 *
 *
 *
 */
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_TestInvalidButton_clicked();

    void on_CloseButton_clicked();

    void moveHome();

    void moveReport();

    void moveEdit();

    void on_TestAdminButton_clicked();

    void on_TestEmployeeButton_clicked();

    void on_SubmitButton_clicked();

private:
    Ui::MainWindow *ui;
    LoginInvalid LogInvalid;
    AdminMenu AdmMenu;
    EmployeeMenu EmpMenu;
    ReportInfo RepMenu;
    EditInfo EditMenu;
    Inventory inv;

};
#endif // MAINWINDOW_H
