#-------------------------------------------------
#
# Project created by QtCreator 2015-06-14T18:20:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Keep_Life_QT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    human.cpp \
    position.cpp \
    food.cpp \
    simulation.cpp \
    display_window.cpp \
    state.cpp \
    group.cpp \
    item.cpp \
    building.cpp \
    strategies/woodcutter.cpp

HEADERS  += mainwindow.h \
    human.h \
    position.h \
    food.h \
    simulation.h \
    display_window.h \
    state.h \
    group.h \
    item.h \
    building.h \
    strategies/jobs.h \
    strategies/woodcutter.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../lib/release/ -lsfml-graphics
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../lib/debug/ -lsfml-graphics
else:unix: LIBS += -L$$PWD/../../../../../lib/ -lsfml-graphics

INCLUDEPATH += $$PWD/../../../../../
DEPENDPATH += $$PWD/../../../../../

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../lib/release/ -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../lib/debug/ -lsfml-system
else:unix: LIBS += -L$$PWD/../../../../../lib/ -lsfml-system

INCLUDEPATH += $$PWD/../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../usr/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/release/ -lsfml-window
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/debug/ -lsfml-window
else:unix: LIBS += -L$$PWD/../../../../../usr/lib/ -lsfml-window

INCLUDEPATH += $$PWD/../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../usr/include
