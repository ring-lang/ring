#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T17:41:04
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets testlib printsupport widgets  quick quickwidgets qml  texttospeech charts

qtHaveModule(webengine) {
	QT += webengine
	DEFINES += QT_WEBVIEW_WEBENGINE_BACKEND
}

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
    highlighter.cpp \
    codeeditor.cpp \
    gthread.cpp \
    gplaintextedit.cpp \
    gheaderview.cpp \
    gprocess.cpp \
    gtoolbutton.cpp \
    gwindow.cpp \
    gguiapplication.cpp \
    gtextbrowser.cpp \
    gdockwidget.cpp \
    gstackedwidget.cpp \
    gcalendarwidget.cpp \
    gtabbar.cpp \
    gquickwidget.cpp \
    gdrag.cpp \
    gprintpreviewwidget.cpp \
    gprintpreviewdialog.cpp \
    gprintdialog.cpp \
    gtexttospeech.cpp \
    gabstractaxis.cpp \
    gabstractbarseries.cpp \
    gabstractseries.cpp \
    gareaseries.cpp \
    gbarcategoryaxis.cpp \
    gbarset.cpp \
    gboxplotseries.cpp \
    gboxset.cpp \
    gcandlestickmodelmapper.cpp \
    gcandlestickseries.cpp \
    gcandlestickset.cpp \
    gcategoryaxis.cpp \
    gchart.cpp \
    gdatetimeaxis.cpp \
    ghbarmodelmapper.cpp \
    ghboxplotmodelmapper.cpp \
    ghcandlestickmodelmapper.cpp \
    ghpiemodelmapper.cpp \
    ghxymodelmapper.cpp \
    glegendmarker.cpp \
    glogvalueaxis.cpp \
    gpieseries.cpp \
    gpieslice.cpp \
    gscatterseries.cpp \
    gvbarmodelmapper.cpp \
    gvboxplotmodelmapper.cpp \
    gvcandlestickmodelmapper.cpp \
    gvpiemodelmapper.cpp \
    gvxymodelmapper.cpp \
    gvalueaxis.cpp \
    gxyseries.cpp \
    ggraphicsscene.cpp \
    gmovie.cpp \
    gcolordialog.cpp \
    gfontdialog.cpp \
    gfiledialog.cpp \
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
    highlighter.h \
    codeeditor.h \
    gthread.h \
    gplaintextedit.h \
    gheaderview.h \
    gprocess.h \
    gtoolbutton.h \
    gguiapplication.h \
    gtextbrowser.h \
    gwindow.h \
    gstackedwidget.h \
    gcalendarwidget.h \
    gdockwidget.h \
    gtabbar.h \
    gquickwidget.h \
    gdrag.h \
    gprintpreviewwidget.h \
    gprintpreviewdialog.h \
    gprintdialog.h \
    gtexttospeech.h \
    gabstractaxis.h \
    gabstractbarseries.h \
    gabstractseries.h \
    gareaseries.h \
    gbarcategoryaxis.h \
    gboxplotseries.h \
    gbarset.h \
    gboxset.h \
    gcandlestickmodelmapper.h \
    gcandlestickseries.h \
    gcandlestickset.h \
    gcategoryaxis.h \
    gdatetimeaxis.h \
    gchart.h \
    ghbarmodelmapper.h \
    ghboxplotmodelmapper.h \
    ghcandlestickmodelmapper.h \
    ghpiemodelmapper.h \
    ghxymodelmapper.h \
    glegendmarker.h \
    glogvalueaxis.h \
    gpieseries.h \
    gscatterseries.h \
    gpieslice.h \
    gvbarmodelmapper.h \
    gvboxplotmodelmapper.h \
    gvcandlestickmodelmapper.h \
    gvxymodelmapper.h \
    gvpiemodelmapper.h \
    gvalueaxis.h \
    gxyseries.h \
    ggraphicsscene.h \
    gmovie.h \
    gcolordialog.h \
    gfontdialog.h \
    gfiledialog.h

CONFIG += warn_off

RESOURCES = project.qrc
