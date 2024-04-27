#------------------------------------------------------------
#
# RingQt Project - A project file to support QtCore only
#
#------------------------------------------------------------

QT       += core 

TARGET = ringqt_core
TEMPLATE = lib

DEFINES -= UNICODE

SOURCES +=   \
    cpp/src/gtimer.cpp \
    cpp/src/giodevice.cpp \
    cpp/src/gprocess.cpp \
    cpp/src/gthread.cpp \
    cpp/src/ring_qt_core.cpp

HEADERS  += \
    cpp/include/gtimer.h \
    cpp/include/giodevice.h \
    cpp/include/gprocess.h \
    cpp/include/gthread.h 

INCLUDEPATH += ../../language/include
INCLUDEPATH += cpp/include

win32 {
	LIBS += ../../lib/ring.lib
}

macx {
	LIBS +=  ../../lib/libring.dylib
}

unix:!macx {
  	LIBS +=  /usr/lib/libring.so
}

CONFIG += warn_off
CONFIG += release