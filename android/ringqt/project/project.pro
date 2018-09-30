#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T17:41:04
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets testlib printsupport widgets sql bluetooth quick quickwidgets qml positioning

DEPLOYMENT_PLUGIN += qsqlite

TARGET = project
TEMPLATE = app

DEFINES -= UNICODE

SOURCES +=   \
    main.cpp \
    ring_ext.c \
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
    gquickwidget.cpp \
    gdrag.cpp \
    ggeopositioninfosource.cpp \
    gprintpreviewwidget.cpp \
	gprintpreviewdialog.cpp \
	gprintdialog.cpp \
    ring_qt.cpp

HEADERS  += \
    ring_ext.h \
    ring.h \
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
    gheaderview.h \
    gprocess.h \
    gtoolbutton.h \
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
    gtabbar.h \
    gquickwidget.h \
    gdrag.h \
    ggeopositioninfosource.h \
    gprintpreviewwidget.h \
	gprintpreviewdialog.h \
	gprintdialog.h

CONFIG += warn_off

RESOURCES = project.qrc

