#ifndef REPORTINFO_H
#define REPORTINFO_H

#include <QWidget>

namespace Ui {
class ReportInfo;
}

class ReportInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ReportInfo(QWidget *parent = nullptr);
    ~ReportInfo();

private:
    Ui::ReportInfo *ui;
};

#endif // REPORTINFO_H
