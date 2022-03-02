#ifndef LOGIN_H
#define LOGIN_H

#include "adminmenu.h"
#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_login_button_clicked();
    void on_exit_button_clicked();
    void show_login_window();

signals:
    void returnMainWindow();
private:
    Ui::Login *ui;
    AdminMenu *adminMenu;
};

#endif // LOGIN_H
