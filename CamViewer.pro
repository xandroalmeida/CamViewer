#-------------------------------------------------
#
# Project created by QtCreator 2011-12-28T14:15:27
#
#-------------------------------------------------

QT       += core gui

TARGET = CamViewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camconfig.cpp \
    camconfigdlg.cpp \
    settingsdlg.cpp \
    camconfigdao.cpp \
    repositoryfactory.cpp \
    camviewframe.cpp \
    abstractbasedao.cpp

HEADERS  += mainwindow.h \
    camconfig.h \
    camconfigdlg.h \
    settingsdlg.h \
    repositoryfactory.h \
    camconfigdao.h \
    camviewframe.h \
    abstractbasedao.h

FORMS    += mainwindow.ui \
    camconfigdlg.ui \
    settingsdlg.ui \
    camviewframe.ui

RESOURCES += \
    icons.qrc
