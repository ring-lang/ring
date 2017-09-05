
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHSERVER_H
#define GBLUETOOTHSERVER_H
#include <QApplication>
#include <QBluetoothServer>
extern "C" {
#include "ring.h"
}

class GBluetoothServer : public QBluetoothServer
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cerrorEvent[100];
    char cnewConnectionEvent[100];


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

