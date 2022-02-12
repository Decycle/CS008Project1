#ifndef EDITINFO_H
#define EDITINFO_H

#include <QWidget>

namespace Ui {
class EditInfo;
}

class EditInfo : public QWidget
{
    Q_OBJECT

public:
    explicit EditInfo(QWidget *parent = nullptr);
    ~EditInfo();
signals:
    void logOutClicked();
private slots:
    void on_pushButton_clicked();

private:
    Ui::EditInfo *ui;
};

#endif // EDITINFO_H
