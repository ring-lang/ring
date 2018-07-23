
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHTRANSFERMANAGER_H
#define GBLUETOOTHTRANSFERMANAGER_H
#include <QApplication>
#include <QBluetoothTransferManager>
extern "C" {
#include "ring.h"
}

class GBluetoothTransferManager : public QBluetoothTransferManager
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cfinishedEvent[100];


    GBluetoothTransferManager(QObject *parent,VM *pVM );

    ~GBluetoothTransferManager();

    void geteventparameters(void) ;

    void setfinishedEvent(const char *cStr);


    const char *getfinishedEvent(void);


  public slots:

    void finishedSlot();

};

#endif

