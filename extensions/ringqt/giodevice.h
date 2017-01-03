
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    List *pParaList;

    char caboutToCloseEvent[100];
    char cbytesWrittenEvent[100];
    char creadChannelFinishedEvent[100];
    char creadyReadEvent[100];


    GIODevice(QObject *parent,VM *pVM );

    ~GIODevice();

    void geteventparameters(void) ;

    void setaboutToCloseEvent(const char *cStr);
    void setbytesWrittenEvent(const char *cStr);
    void setreadChannelFinishedEvent(const char *cStr);
    void setreadyReadEvent(const char *cStr);


    const char *getaboutToCloseEvent(void);
    const char *getbytesWrittenEvent(void);
    const char *getreadChannelFinishedEvent(void);
    const char *getreadyReadEvent(void);


  public slots:

    void aboutToCloseSlot();
    void bytesWrittenSlot();
    void readChannelFinishedSlot();
    void readyReadSlot();

};

#endif

