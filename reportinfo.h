#ifndef REPORTINFO_H
#define REPORTINFO_H

#include <QWidget>
#include "inventory.h"
namespace Ui {
class ReportInfo;
}

class ReportInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ReportInfo(QWidget *parent = nullptr);
    ~ReportInfo();

private slots:
    void on_LogOutButton_clicked();

    void on_testButton_clicked();

    void on_testItemButton_clicked();

    void on_testDayButton_clicked();

signals:
    void logOutClicked();

private:
    Ui::ReportInfo *ui;
    Inventory inv;
    std::string file = "C:\\Users\\Sean Leung\\Dropbox\\CS3A (C++) Juan Leon"
                  "\\labs\\ProjectDemo\\day";
    std::string filetype = ".txt";

    std::string fullfile = "C:\\Users\\Sean Leung\\Dropbox\\CS3A (C++) Juan Leon"
                  "\\labs\\ProjectDemo\\day1.txt";
};


#endif // REPORTINFO_H
