
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHTRANSFERREPLY_H
#define GBLUETOOTHTRANSFERREPLY_H
#include "ringqt.h"
#include <QBluetoothTransferReply>

extern "C" {
#include "ring.h"
}

class GBluetoothTransferReply : public QBluetoothTransferReply
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cerrorEvent[RINGQT_EVENT_SIZE];
    char cfinishedEvent[RINGQT_EVENT_SIZE];
    char ctransferProgressEvent[RINGQT_EVENT_SIZE];


    GBluetoothTransferReply(QObject *parent,VM *pVM );

    ~GBluetoothTransferReply();

    void geteventparameters(void) ;

    void seterrorEvent(const char *cStr);
    void setfinishedEvent(const char *cStr);
    void settransferProgressEvent(const char *cStr);


    const char *geterrorEvent(void);
    const char *getfinishedEvent(void);
    const char *gettransferProgressEvent(void);


  public slots:

    void errorSlot();
    void finishedSlot();
    void transferProgressSlot();



};

#endif

