#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T17:41:04
#
#-------------------------------------------------

QT       += core gui network  webenginewidgets multimedia multimediawidgets testlib printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    gwebengineview.cpp \
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
    gwebengineview.h \
    gcheckbox.h \
    gradiobutton.h \
    gbuttongroup.h \
    gvideowidget.h \
    gtimer.h \
    gtcpserver.h \ 
    giodevice.h \
    gabstractsocket.h \
    gtcpsocket.h \
    gallevents.h 

INCLUDEPATH += ../../include

FORMS    +=

CONFIG += mobility
MOBILITY = 

OTHER_FILES +=

win32 {
	LIBS +=  ../../lib/ring.lib
}

macx {
	LIBS +=  ../../lib/libring.dylib
}

unix:!macx {
	LIBS +=  $$PWD/libring.so
}

CONFIG += warn_off
QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01


