#-------------------------------------------------
#
# Project created by QtCreator 2019-02-09T10:39:40
#
#-------------------------------------------------

QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = gwentCalc
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

win32:RC_ICONS += gwentcalc.ico

SOURCES += \
        main.cpp \
        deckeditorwindow.cpp \
    comboeditorwindow.cpp \
    utilities.cpp \
    settingswindow.cpp \
    gwentcard.cpp \
    gwentcardcombo.cpp \
    dialog.cpp \
    simthread.cpp \
    progressdialog.cpp \
    gwentscenario.cpp \
    gwentgame.cpp \
    gwentsimresults.cpp \
    chartwindow.cpp \
    analysiswindow.cpp \
    gwentconditional.cpp

HEADERS += \
        deckeditorwindow.h \
    comboeditorwindow.h \
    utilities.h \
    globals.h \
    settingswindow.h \
    gwentcard.h \
    gwentcardcombo.h \
    dialog.h \
    simthread.h \
    progressdialog.h \
    gwentscenario.h \
    gwentgame.h \
    gwentsimresults.h \
    chartwindow.h \
    analysiswindow.h \
    gwentconditional.h

FORMS += \
        deckeditorwindow.ui \
    comboeditorwindow.ui \
    settingswindow.ui \
    dialog.ui \
    progressdialog.ui \
    chartwindow.ui \
    analysiswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
