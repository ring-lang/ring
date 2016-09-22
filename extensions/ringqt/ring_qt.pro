#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T17:41:04
#
#-------------------------------------------------

QT       += sql core gui network webkitwidgets multimedia multimediawidgets testlib printsupport widgets

TARGET = ringqt
TEMPLATE = lib

DEFINES -= UNICODE

SOURCES +=   \
    gpushbutton.cpp \
    gaction.cpp \
    glineedit.cpp \
    gtextedit.cpp \
    glistwidget.cpp \
    gtreeview.cpp \
    gtreewidget.cpp \
    gcombobox.cpp \
    gtabwidget.cpp \
    gtablewidget.cpp \
    gprogressbar.cpp \
    gspinbox.cpp \
    gslider.cpp \
    gdial.cpp \
    gwebview.cpp \
    gcheckbox.cpp \
    gradiobutton.cpp \
    gbuttongroup.cpp \
    gvideowidget.cpp \
    gtimer.cpp \
    gtcpserver.cpp \
    giodevice.cpp \
    gabstractsocket.cpp \
    gtcpsocket.cpp \
    gallevents.cpp \
    gnetworkaccessmanager.cpp \
    highlighter.cpp \
    gthread.cpp \
    ring_qt.cpp

HEADERS  += \
    gpushbutton.h \
    gaction.h \
    glineedit.h \
    gtextedit.h \
    glistwidget.h \
    gtreeview.h \
    gtreewidget.h \
    gcombobox.h \
    gtabwidget.h \
    gtablewidget.h \
    gprogressbar.h \
    gspinbox.h \
    gslider.h \
    gdial.h \
    gwebview.h \
    gcheckbox.h \
    gradiobutton.h \
    gbuttongroup.h \
    gvideowidget.h \
    gtimer.h \
    gtcpserver.h \ 
    giodevice.h \
    gabstractsocket.h \
    gtcpsocket.h \
    gallevents.h \
    gnetworkaccessmanager.h \
    highlighter.h \
    gthread.h

INCLUDEPATH += ../../include

win32 {
	LIBS +=  ../../lib/ring.lib
}

macx {
	LIBS +=  ../../lib/libring.dylib
}

unix:!macx {
  	LIBS +=  /usr/lib/libring.so
}

CONFIG += warn_off
CONFIG += release

QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01

DEPLOYMENT_PLUGIN += qsqlite
