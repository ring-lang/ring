#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T17:41:04
#
#-------------------------------------------------

QT       += sql core gui network webkitwidgets multimedia multimediawidgets testlib printsupport widgets serialport bluetooth

TARGET = ringqt
TEMPLATE = lib

DEFINES -= UNICODE

SOURCES +=   \
    gpushbutton.cpp \
    ring_qt.cpp

HEADERS  += \
    gpushbutton.h 

INCLUDEPATH += ../../../include

win32 {
	LIBS +=  ../../../lib/ring.lib
	QT   += axcontainer
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

DEPLOYMENT_PLUGIN += qsqlite qsqlmysql qsqlodbc qsqppsql
