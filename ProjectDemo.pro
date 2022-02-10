QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminmenu.cpp \
    employeemenu.cpp \
    logininvalid.cpp \
    main.cpp \
    mainwindow.cpp \
    reportinfo.cpp

HEADERS += \
    adminmenu.h \
    employeemenu.h \
    logininvalid.h \
    mainwindow.h \
    reportinfo.h

FORMS += \
    adminmenu.ui \
    employeemenu.ui \
    logininvalid.ui \
    mainwindow.ui \
    reportinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    global.qrc

DISTFILES += \
    global.qss
