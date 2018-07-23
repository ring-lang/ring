
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHTRANSFERREPLY_H
#define GBLUETOOTHTRANSFERREPLY_H
#include <QApplication>
#include <QBluetoothTransferReply>
extern "C" {
#include "ring.h"
}

class GBluetoothTransferReply : public QBluetoothTransferReply
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cerrorEvent[100];
    char cfinishedEvent[100];
    char ctransferProgressEvent[100];


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

