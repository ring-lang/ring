#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T17:41:04
#
#-------------------------------------------------

QT       += sql core gui network multimedia multimediawidgets testlib printsupport widgets serialport bluetooth opengl webenginewidgets

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
    gnetworkaccessmanager.cpp \
    highlighter.cpp \
    codeeditor.cpp \
    gthread.cpp \
    gplaintextedit.cpp \
    gheaderview.cpp \
    gprocess.cpp \
    gtoolbutton.cpp \
    gserialport.cpp \
    gbluetoothdevicediscoveryagent.cpp \
    gbluetoothlocaldevice.cpp \
    gbluetoothserver.cpp \
    gbluetoothservicediscoveryagent.cpp \
    gbluetoothsocket.cpp \
    gbluetoothtransfermanager.cpp \
    gbluetoothtransferreply.cpp \
    gwindow.cpp \
    gguiapplication.cpp \
    gtextbrowser.cpp \
    gdockwidget.cpp \
    gstackedwidget.cpp \
    gcalendarwidget.cpp \
    gtabbar.cpp \
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
    gallevents.h \
    gnetworkaccessmanager.h \
    highlighter.h \
    codeeditor.h \
    gthread.h \
    gplaintextedit.h \
    gprocess.h  \
    gtoolbutton.h \
    gheaderview.h \
    gserialport.h \
    gbluetoothdevicediscoveryagent.h \
    gbluetoothlocaldevice.h \
    gbluetoothservicediscoveryagent.h \
    gbluetoothsocket.h \
    gbluetoothtransfermanager.h \
    gbluetoothtransferreply.h \
    gbluetoothserver.h \
    gguiapplication.h \
    gtextbrowser.h \
    gwindow.h \
    gstackedwidget.h \
    gcalendarwidget.h \
    gdockwidget.h \
    gtabbar.h 
    

INCLUDEPATH += ../../include

win32 {
	LIBS +=  ../../lib/ring.lib
	QT   += axcontainer quick quickwidgets qml
	SOURCES += openglwidget.cpp gquickwidget.cpp 
	HEADERS += openglwidget.h gquickwidget.h 
}

macx {
	LIBS +=  ../../lib/libring.dylib
	QT   += quick quickwidgets qml
	SOURCES += gquickwidget.cpp 
	HEADERS += gquickwidget.h 
}

unix:!macx {
  	LIBS +=  /usr/lib/libring.so
}

CONFIG += warn_off
CONFIG += release

QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01

DEPLOYMENT_PLUGIN += qsqlite qsqlmysql qsqlodbc qsqppsql
