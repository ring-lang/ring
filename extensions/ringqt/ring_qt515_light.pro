#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T17:41:04
#
#-------------------------------------------------

QT       += core gui testlib widgets

TARGET = ringqt_light
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
    cpp/src/gcheckbox.cpp \
    cpp/src/gradiobutton.cpp \
    cpp/src/gbuttongroup.cpp \
    cpp/src/gtimer.cpp \
    cpp/src/giodevice.cpp \
    cpp/src/gallevents.cpp \
    cpp/src/gthread.cpp \
    cpp/src/highlighter.cpp \
    cpp/src/codeeditor.cpp \
    cpp/src/gplaintextedit.cpp \
    cpp/src/gprocess.cpp \
    cpp/src/gheaderview.cpp \
    cpp/src/gtoolbutton.cpp \
    cpp/src/gwindow.cpp \
    cpp/src/gguiapplication.cpp \
    cpp/src/gtextbrowser.cpp \
    cpp/src/gdockwidget.cpp \
    cpp/src/gstackedwidget.cpp \
    cpp/src/gcalendarwidget.cpp \
    cpp/src/gtabbar.cpp \
    cpp/src/gdrag.cpp \
    cpp/src/ggraphicsscene.cpp \
    cpp/src/ggraphicseffect.cpp \
    cpp/src/gmovie.cpp \
    cpp/src/gcolordialog.cpp \
    cpp/src/gfontdialog.cpp \
    cpp/src/gfiledialog.cpp \
    cpp/src/mscompleter.cpp \
    cpp/src/ring_qt_light.cpp

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
    cpp/include/gcheckbox.h \
    cpp/include/gradiobutton.h \
    cpp/include/gbuttongroup.h \
    cpp/include/gtimer.h \
    cpp/include/giodevice.h \
    cpp/include/gallevents.h \
    cpp/include/highlighter.h \
    cpp/include/codeeditor.h \
    cpp/include/gthread.h \
    cpp/include/gplaintextedit.h \
    cpp/include/gprocess.h  \
    cpp/include/gtoolbutton.h \
    cpp/include/gheaderview.h \
    cpp/include/gguiapplication.h \
    cpp/include/gtextbrowser.h \
    cpp/include/gwindow.h \
    cpp/include/gstackedwidget.h \
    cpp/include/gcalendarwidget.h \
    cpp/include/gdockwidget.h \
    cpp/include/gtabbar.h \
    cpp/include/gdrag.h \
    cpp/include/ggraphicsscene.h \
    cpp/include/ggraphicseffect.h \
    cpp/include/gmovie.h \
    cpp/include/gcolordialog.h \
    cpp/include/gfontdialog.h \
    cpp/include/gfiledialog.h \
    cpp/include/mscompleter.h 

INCLUDEPATH += ../../language/include
INCLUDEPATH += cpp/include

win32 {
	LIBS +=  ../../lib/ring.lib
	SOURCES += cpp/src/openglwidget.cpp 
	HEADERS += cpp/include/openglwidget.h 
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
