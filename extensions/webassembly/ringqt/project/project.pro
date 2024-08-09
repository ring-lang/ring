#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T17:41:04
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets testlib printsupport widgets  quick quickwidgets qml  texttospeech charts svg

qtHaveModule(webengine) {
	QT += webengine
	DEFINES += QT_WEBVIEW_WEBENGINE_BACKEND
}

DEPLOYMENT_PLUGIN += qsqlite

TARGET = project
TEMPLATE = app

DEFINES -= UNICODE

INCLUDEPATH += ring/include
INCLUDEPATH += ringqt/include

SOURCES +=   \
    main.cpp \
    ring/src/ext.c \
    ringqt/src/gpushbutton.cpp \
    ringqt/src/gaction.cpp \
    ringqt/src/glineedit.cpp \
    ringqt/src/gtextedit.cpp \
    ringqt/src/glistwidget.cpp \
    ringqt/src/gtreeview.cpp \
    ringqt/src/gtreewidget.cpp \
    ringqt/src/gcombobox.cpp \
    ringqt/src/gtabwidget.cpp \
    ringqt/src/gtablewidget.cpp \
    ringqt/src/gprogressbar.cpp \
    ringqt/src/gspinbox.cpp \
    ringqt/src/gslider.cpp \
    ringqt/src/gdial.cpp \
    ringqt/src/gcheckbox.cpp \
    ringqt/src/gradiobutton.cpp \
    ringqt/src/gbuttongroup.cpp \
    ringqt/src/gvideowidget.cpp \
    ringqt/src/gtimer.cpp \
    ringqt/src/gtcpserver.cpp \
    ringqt/src/giodevice.cpp \
    ringqt/src/gabstractsocket.cpp \
    ringqt/src/gtcpsocket.cpp \
    ringqt/src/gallevents.cpp \
    ringqt/src/highlighter.cpp \
    ringqt/src/codeeditor.cpp \
    ringqt/src/gthread.cpp \
    ringqt/src/gplaintextedit.cpp \
    ringqt/src/gheaderview.cpp \
    ringqt/src/gprocess.cpp \
    ringqt/src/gtoolbutton.cpp \
    ringqt/src/gwindow.cpp \
    ringqt/src/gguiapplication.cpp \
    ringqt/src/gtextbrowser.cpp \
    ringqt/src/gdockwidget.cpp \
    ringqt/src/gstackedwidget.cpp \
    ringqt/src/gcalendarwidget.cpp \
    ringqt/src/gtabbar.cpp \
    ringqt/src/gquickwidget.cpp \
    ringqt/src/gdrag.cpp \
    ringqt/src/gprintpreviewwidget.cpp \
    ringqt/src/gprintpreviewdialog.cpp \
    ringqt/src/gprintdialog.cpp \
    ringqt/src/gtexttospeech.cpp \
    ringqt/src/gabstractaxis.cpp \
    ringqt/src/gabstractbarseries.cpp \
    ringqt/src/gabstractseries.cpp \
    ringqt/src/gareaseries.cpp \
    ringqt/src/gbarcategoryaxis.cpp \
    ringqt/src/gbarset.cpp \
    ringqt/src/gboxplotseries.cpp \
    ringqt/src/gboxset.cpp \
    ringqt/src/gcandlestickmodelmapper.cpp \
    ringqt/src/gcandlestickseries.cpp \
    ringqt/src/gcandlestickset.cpp \
    ringqt/src/gcategoryaxis.cpp \
    ringqt/src/gchart.cpp \
    ringqt/src/gdatetimeaxis.cpp \
    ringqt/src/ghbarmodelmapper.cpp \
    ringqt/src/ghboxplotmodelmapper.cpp \
    ringqt/src/ghcandlestickmodelmapper.cpp \
    ringqt/src/ghpiemodelmapper.cpp \
    ringqt/src/ghxymodelmapper.cpp \
    ringqt/src/glegendmarker.cpp \
    ringqt/src/glogvalueaxis.cpp \
    ringqt/src/gpieseries.cpp \
    ringqt/src/gpieslice.cpp \
    ringqt/src/gscatterseries.cpp \
    ringqt/src/gvbarmodelmapper.cpp \
    ringqt/src/gvboxplotmodelmapper.cpp \
    ringqt/src/gvcandlestickmodelmapper.cpp \
    ringqt/src/gvpiemodelmapper.cpp \
    ringqt/src/gvxymodelmapper.cpp \
    ringqt/src/gvalueaxis.cpp \
    ringqt/src/gxyseries.cpp \
    ringqt/src/ggraphicsscene.cpp \
    ringqt/src/ggraphicseffect.cpp \
    ringqt/src/ggraphicsobject.cpp \
    ringqt/src/ggraphicstextitem.cpp \
    ringqt/src/ggraphicsview.cpp \
    ringqt/src/ggraphicswidget.cpp \
    ringqt/src/gmovie.cpp \
    ringqt/src/gcolordialog.cpp \
    ringqt/src/gfontdialog.cpp \
    ringqt/src/gfiledialog.cpp \
    ringqt/src/gdatetimeedit.cpp \
    ringqt/src/mscompleter.cpp \
    ringqt/src/ring_qt.cpp

HEADERS  += \
    ring/include/ext.h \
    ring/include/ring.h \
    ringqt/include/gpushbutton.h \
    ringqt/include/gaction.h \
    ringqt/include/glineedit.h \
    ringqt/include/gtextedit.h \
    ringqt/include/glistwidget.h \
    ringqt/include/gtreeview.h \
    ringqt/include/gtreewidget.h \
    ringqt/include/gcombobox.h \
    ringqt/include/gtabwidget.h \
    ringqt/include/gtablewidget.h \
    ringqt/include/gprogressbar.h \
    ringqt/include/gspinbox.h \
    ringqt/include/gslider.h \
    ringqt/include/gdial.h \
    ringqt/include/gcheckbox.h \
    ringqt/include/gradiobutton.h \
    ringqt/include/gbuttongroup.h \
    ringqt/include/gvideowidget.h \
    ringqt/include/gtimer.h \
    ringqt/include/gtcpserver.h \
    ringqt/include/giodevice.h \
    ringqt/include/gabstractsocket.h \
    ringqt/include/gtcpsocket.h \
    ringqt/include/gallevents.h \
    ringqt/include/highlighter.h \
    ringqt/include/codeeditor.h \
    ringqt/include/gthread.h \
    ringqt/include/gplaintextedit.h \
    ringqt/include/gheaderview.h \
    ringqt/include/gprocess.h \
    ringqt/include/gtoolbutton.h \
    ringqt/include/gguiapplication.h \
    ringqt/include/gtextbrowser.h \
    ringqt/include/gwindow.h \
    ringqt/include/gstackedwidget.h \
    ringqt/include/gcalendarwidget.h \
    ringqt/include/gdockwidget.h \
    ringqt/include/gtabbar.h \
    ringqt/include/gquickwidget.h \
    ringqt/include/gdrag.h \
    ringqt/include/gprintpreviewwidget.h \
    ringqt/include/gprintpreviewdialog.h \
    ringqt/include/gprintdialog.h \
    ringqt/include/gtexttospeech.h \
    ringqt/include/gabstractaxis.h \
    ringqt/include/gabstractbarseries.h \
    ringqt/include/gabstractseries.h \
    ringqt/include/gareaseries.h \
    ringqt/include/gbarcategoryaxis.h \
    ringqt/include/gboxplotseries.h \
    ringqt/include/gbarset.h \
    ringqt/include/gboxset.h \
    ringqt/include/gcandlestickmodelmapper.h \
    ringqt/include/gcandlestickseries.h \
    ringqt/include/gcandlestickset.h \
    ringqt/include/gcategoryaxis.h \
    ringqt/include/gdatetimeaxis.h \
    ringqt/include/gchart.h \
    ringqt/include/ghbarmodelmapper.h \
    ringqt/include/ghboxplotmodelmapper.h \
    ringqt/include/ghcandlestickmodelmapper.h \
    ringqt/include/ghpiemodelmapper.h \
    ringqt/include/ghxymodelmapper.h \
    ringqt/include/glegendmarker.h \
    ringqt/include/glogvalueaxis.h \
    ringqt/include/gpieseries.h \
    ringqt/include/gscatterseries.h \
    ringqt/include/gpieslice.h \
    ringqt/include/gvbarmodelmapper.h \
    ringqt/include/gvboxplotmodelmapper.h \
    ringqt/include/gvcandlestickmodelmapper.h \
    ringqt/include/gvxymodelmapper.h \
    ringqt/include/gvpiemodelmapper.h \
    ringqt/include/gvalueaxis.h \
    ringqt/include/gxyseries.h \
    ringqt/include/ggraphicsscene.h \
    ringqt/include/ggraphicseffect.h \
    ringqt/include/ggraphicsobject.h \
    ringqt/include/ggraphicstextitem.h \
    ringqt/include/ggraphicsview.h \
    ringqt/include/ggraphicswidget.h \
    ringqt/include/gmovie.h \
    ringqt/include/gcolordialog.h \
    ringqt/include/gfontdialog.h \
    ringqt/include/gfiledialog.h \
    ringqt/include/gdatetimeedit.h \
    ringqt/include/mscompleter.h 

CONFIG += warn_off

RESOURCES = project.qrc
