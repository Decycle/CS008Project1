QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminmenu.cpp \
    date.cpp \
    editinfo.cpp \
    employeemenu.cpp \
    filemanager.cpp \
    infointerface.cpp \
    inventory.cpp \
    iterator.cpp \
    list.cpp \
    logininvalid.cpp \
    main.cpp \
    mainwindow.cpp \
    member.cpp \
    node.cpp \
    purchase.cpp \
    reportinfo.cpp

HEADERS += \
    adminmenu.h \
    date.h \
    editinfo.h \
    employeemenu.h \
    filemanager.h \
    infointerface.h \
    inventory.h \
    iterator.h \
    list.h \
    logininvalid.h \
    mainwindow.h \
    member.h \
    node.h \
    purchase.h \
    reportinfo.h

FORMS += \
    adminmenu.ui \
    editinfo.ui \
    employeemenu.ui \
    logininvalid.ui \
    mainwindow.ui \
    reportinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    day1.txt \
    day2.txt \
    day3.txt \
    day4.txt \
    day5.txt \
    warehouse shoppers.txt
