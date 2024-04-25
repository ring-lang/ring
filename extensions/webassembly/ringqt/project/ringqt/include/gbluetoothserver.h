
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHSERVER_H
#define GBLUETOOTHSERVER_H
#include "ringqt.h"
#include <QBluetoothServer>
extern "C" {
#include "ring.h"
}

class GBluetoothServer : public QBluetoothServer
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cerrorEvent[RINGQT_EVENT_SIZE];
    char cnewConnectionEvent[RINGQT_EVENT_SIZE];


    GBluetoothServer(QBluetoothServiceInfo::Protocol x,QObject *parent,VM *pVM );

    ~GBluetoothServer();

    void geteventparameters(void) ;

    void seterrorEvent(const char *cStr);
    void setnewConnectionEvent(const char *cStr);


    const char *geterrorEvent(void);
    const char *getnewConnectionEvent(void);


  public slots:

    void errorSlot();
    void newConnectionSlot();

};

#endif

