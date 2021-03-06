QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminmenu.cpp \
    date.cpp \
    filemanager.cpp \
    infointerface.cpp \
    linkedlist.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    member.cpp \
    purchase.cpp

HEADERS += \
    adminmenu.h \
    date.h \
    filemanager.h \
    infointerface.h \
    linkedlist.h \
    listempty.h \
    login.h \
    mainwindow.h \
    member.h \
    purchase.h

FORMS += \
    adminmenu.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    global.qss
