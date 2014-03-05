QT += core gui network xml

TEMPLATE = app

TARGET = feedSpamer

HEADERS += ./mainwindow.h

SOURCES += ./main.cpp \
    ./mainwindow.cpp

FORMS += ./mainwindow.ui

RESOURCES += mainwindow.qrc
