
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHTRANSFERMANAGER_H
#define GBLUETOOTHTRANSFERMANAGER_H
#include "ringqt.h"
#include <QBluetoothTransferManager>
extern "C" {
#include "ring.h"
}

class GBluetoothTransferManager : public QBluetoothTransferManager
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cfinishedEvent[RINGQT_EVENT_SIZE];


    GBluetoothTransferManager(QObject *parent,VM *pVM );

    ~GBluetoothTransferManager();

    void geteventparameters(void) ;

    void setfinishedEvent(const char *cStr);


    const char *getfinishedEvent(void);


  public slots:

    void finishedSlot();

};

#endif

