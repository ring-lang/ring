#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T17:41:04
#
#-------------------------------------------------

QT       += sql core gui network webkitwidgets multimedia multimediawidgets testlib printsupport widgets serialport bluetooth opengl positioning

TARGET = ringqt
TEMPLATE = lib

DEFINES -= UNICODE

SOURCES +=   \
    cpp/src/gpushbutton.cpp \
    cpp/src/gaction.cpp \
    cpp/src/glineedit.cpp \
    cpp/src/gtextedit.cpp \
    cpp/src/glistwidget.cpp \
    cpp/src/gtreeview.cpp \
    cpp/src/gtreewidget.cpp \
    cpp/src/gcombobox.cpp \
    cpp/src/gtabwidget.cpp \
    cpp/src/gtablewidget.cpp \
    cpp/src/gprogressbar.cpp \
    cpp/src/gspinbox.cpp \
    cpp/src/gslider.cpp \
    cpp/src/gdial.cpp \
    cpp/src/gwebview.cpp \
    cpp/src/gcheckbox.cpp \
    cpp/src/gradiobutton.cpp \
    cpp/src/gbuttongroup.cpp \
    cpp/src/gvideowidget.cpp \
    cpp/src/gtimer.cpp \
    cpp/src/gtcpserver.cpp \
    cpp/src/giodevice.cpp \
    cpp/src/gabstractsocket.cpp \
    cpp/src/gtcpsocket.cpp \
    cpp/src/gallevents.cpp \
    cpp/src/gnetworkaccessmanager.cpp \
    cpp/src/highlighter.cpp \
    cpp/src/codeeditor.cpp \
    cpp/src/gthread.cpp \
    cpp/src/gplaintextedit.cpp \
    cpp/src/gheaderview.cpp \
    cpp/src/gprocess.cpp \
    cpp/src/gtoolbutton.cpp \
    cpp/src/gserialport.cpp \
    cpp/src/gbluetoothdevicediscoveryagent.cpp \
    cpp/src/gbluetoothlocaldevice.cpp \
    cpp/src/gbluetoothserver.cpp \
    cpp/src/gbluetoothservicediscoveryagent.cpp \
    cpp/src/gbluetoothsocket.cpp \
    cpp/src/gbluetoothtransfermanager.cpp \
    cpp/src/gbluetoothtransferreply.cpp \
    cpp/src/gwindow.cpp \
    cpp/src/gguiapplication.cpp \
    cpp/src/gtextbrowser.cpp \
    cpp/src/gdockwidget.cpp \
    cpp/src/gstackedwidget.cpp \
    cpp/src/gcalendarwidget.cpp \
    cpp/src/gtabbar.cpp \
    cpp/src/gdrag.cpp \
    cpp/src/ggeopositioninfosource.cpp \
    cpp/src/gprintpreviewwidget.cpp \
    cpp/src/gprintpreviewdialog.cpp \
    cpp/src/gprintdialog.cpp \
    cpp/src/gmovie.cpp \
    cpp/src/gcolordialog.cpp \
    cpp/src/gfontdialog.cpp \
    cpp/src/gfiledialog.cpp \
    cpp/src/mscompleter.cpp \
    cpp/src/ring_qt.cpp

HEADERS  += \
    cpp/include/gpushbutton.h \
    cpp/include/gaction.h \
    cpp/include/glineedit.h \
    cpp/include/gtextedit.h \
    cpp/include/glistwidget.h \
    cpp/include/gtreeview.h \
    cpp/include/gtreewidget.h \
    cpp/include/gcombobox.h \
    cpp/include/gtabwidget.h \
    cpp/include/gtablewidget.h \
    cpp/include/gprogressbar.h \
    cpp/include/gspinbox.h \
    cpp/include/gslider.h \
    cpp/include/gdial.h \
    cpp/include/gwebview.h \
    cpp/include/gcheckbox.h \
    cpp/include/gradiobutton.h \
    cpp/include/gbuttongroup.h \
    cpp/include/gvideowidget.h \
    cpp/include/gtimer.h \
    cpp/include/gtcpserver.h \ 
    cpp/include/giodevice.h \
    cpp/include/gabstractsocket.h \
    cpp/include/gtcpsocket.h \
    cpp/include/gallevents.h \
    cpp/include/gnetworkaccessmanager.h \
    cpp/include/highlighter.h \
    cpp/include/codeeditor.h \
    cpp/include/gthread.h \
    cpp/include/gplaintextedit.h \
    cpp/include/gprocess.h  \
    cpp/include/gtoolbutton.h \
    cpp/include/gheaderview.h \
    cpp/include/gserialport.h \
    cpp/include/gbluetoothdevicediscoveryagent.h \
    cpp/include/gbluetoothlocaldevice.h \
    cpp/include/gbluetoothservicediscoveryagent.h \
    cpp/include/gbluetoothsocket.h \
    cpp/include/gbluetoothtransfermanager.h \
    cpp/include/gbluetoothtransferreply.h \
    cpp/include/gbluetoothserver.h \
    cpp/include/gguiapplication.h \
    cpp/include/gtextbrowser.h \
    cpp/include/gwindow.h \
    cpp/include/gstackedwidget.h \
    cpp/include/gcalendarwidget.h \
    cpp/include/gdockwidget.h \
    cpp/include/gtabbar.h \
    cpp/include/gdrag.h \
    cpp/include/ggeopositioninfosource.h \
    cpp/include/gprintpreviewwidget.h \
    cpp/include/gprintpreviewdialog.h \
    cpp/include/gprintdialog.h \
    cpp/include/gmovie.h \
    cpp/include/gcolordialog.h \
    cpp/include/gfontdialog.h \
    cpp/include/gfiledialog.h \
    cpp/include/mscompleter.h 

    

INCLUDEPATH += ../../language/include
INCLUDEPATH += cpp/include

win32 {
	LIBS +=  ../../lib/ring.lib
	QT   += axcontainer quick quickwidgets qml
	SOURCES += cpp/src/openglwidget.cpp cpp/src/gquickwidget.cpp 
	HEADERS += cpp/include/openglwidget.h cpp/include/gquickwidget.h 
}

macx {
	LIBS +=  ../../lib/libring.dylib
	QT   += quick quickwidgets qml
	SOURCES += cpp/src/openglwidget.cpp cpp/src/gquickwidget.cpp 
	HEADERS += cpp/include/openglwidget.h cpp/include/gquickwidget.h 
}

unix:!macx {
  	LIBS +=  /usr/lib/libring.so
}

CONFIG += warn_off
CONFIG += release

QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01

DEPLOYMENT_PLUGIN += qsqlite qsqlmysql qsqlodbc qsqppsql
