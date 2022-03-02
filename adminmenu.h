#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QWidget>

namespace Ui {
class AdminMenu;
}

class AdminMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = nullptr);
    ~AdminMenu();

private slots:
    void on_exit_button_clicked();

signals:
    void return_login_window();

private:
    Ui::AdminMenu *ui;
};

#endif // ADMINMENU_H
