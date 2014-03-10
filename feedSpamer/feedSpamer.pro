QT += core gui network xml

TEMPLATE = app

TARGET = feedSpamer

DESTDIR = ../bin

HEADERS += ./src/mainwindow.h \
	./src/addcampaigndialog.h \
	./src/campaignconfig.h \
	./src/defines.h \
	./src/listitem.h \
	./src/listitemdelegate.h \
	./src/listitemmodel.h \
	./src/listitemwidget.h

SOURCES += ./src/main.cpp \
    ./src/mainwindow.cpp \
    ./src/addcampaigndialog.cpp \
    ./src/campaignconfig.cpp \
    ./src/listitem.cpp \
    ./src/listitemdelegate.cpp \
    ./src/listitemmodel.cpp \
    ./src/listitemwidget.cpp

FORMS += ./ui/mainwindow.ui \
	./ui/addcampaigndialog.ui

RESOURCES += ./res/mainwindow.qrc

TRANSLATIONS += ./ts/feedspamer_ru.ts