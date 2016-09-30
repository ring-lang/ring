
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GIODEVICE_H
#define GIODEVICE_H
#include <QApplication>
#include <QIODevice>
extern "C" {
#include "ring.h"
}

class GIODevice : public QIODevice
{

  Q_OBJECT

  public:

    VM *pVM;

    char caboutToCloseEvent[100];
    char cbytesWrittenEvent[100];
    char creadChannelFinishedEvent[100];
    char creadyReadEvent[100];


    GIODevice(QObject *parent,VM *pVM );

    void setaboutToCloseEvent(const char *cStr);
    void setbytesWrittenEvent(const char *cStr);
    void setreadChannelFinishedEvent(const char *cStr);
    void setreadyReadEvent(const char *cStr);


  public slots:

    void aboutToCloseSlot();
    void bytesWrittenSlot();
    void readChannelFinishedSlot();
    void readyReadSlot();

};

#endif

