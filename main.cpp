#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile stylesheet(":/ui/global.qss");
    stylesheet.open(QIODevice::ReadOnly);
    QString stylesheetString = QLatin1String(stylesheet.readAll());

    a.setStyleSheet(stylesheetString);

    MainWindow w;
    w.show();
    return a.exec();
}
