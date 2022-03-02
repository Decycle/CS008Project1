#ifndef LOGIN_H
#define LOGIN_H

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

signals:
    void returnMainWindow();
private:
    Ui::Login *ui;
};

#endif // LOGIN_H
