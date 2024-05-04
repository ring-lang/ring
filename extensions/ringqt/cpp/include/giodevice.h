
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GIODEVICE_H
#define GIODEVICE_H
#include "ringqt.h"
#include <QIODevice>

extern "C" {
#include "ring.h"
}

class GIODevice : public QIODevice
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char caboutToCloseEvent[RINGQT_EVENT_SIZE];
    char cbytesWrittenEvent[RINGQT_EVENT_SIZE];
    char creadChannelFinishedEvent[RINGQT_EVENT_SIZE];
    char creadyReadEvent[RINGQT_EVENT_SIZE];


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

