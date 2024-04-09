QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    base/basefragment.cpp \
    base/basescreensfactory.cpp \
    base/navigator.cpp \
    main.cpp \
    mainwindow.cpp \
    models/basemodel.cpp \
    models/projectmodel.cpp \
    screensfactory.cpp \
    ui/auth/loginfragment.cpp \
    ui/auth/loginfragment_old.cpp \
    ui/mainfragment.cpp \
    ui/project/projectfragment.cpp \
    ui/secondwindow.cpp \
    ui/view/projectwidget.cpp

HEADERS += \
    base/basefragment.h \
    base/basescreensfactory.h \
    base/navigator.h \
    mainwindow.h \
    models/basemodel.h \
    models/projectmodel.h \
    screensfactory.h \
    ui/auth/loginfragment.h \
    ui/auth/loginfragment_old.h \
    ui/mainfragment.h \
    ui/project/projectfragment.h \
    ui/secondwindow.h \
    ui/view/projectwidget.h

FORMS += \
    mainwindow.ui \
    ui/auth/loginfragment.ui \
    ui/mainfragment.ui \
    ui/project/projectfragment.ui \
    ui/secondwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
