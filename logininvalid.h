#ifndef LOGININVALID_H
#define LOGININVALID_H

#include <QWidget>

namespace Ui {
class LoginInvalid;
}

class LoginInvalid : public QWidget
{
    Q_OBJECT

public:
    explicit LoginInvalid(QWidget *parent = nullptr);
    ~LoginInvalid();

private slots:
    void on_okButton_clicked();

signals:
    void okClicked();

private:
    Ui::LoginInvalid *ui;
};

#endif // LOGININVALID_H
