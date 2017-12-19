
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHSOCKET_H
#define GBLUETOOTHSOCKET_H
#include <QApplication>
#include <QBluetoothSocket>
extern "C" {
#include "ring.h"
}

class GBluetoothSocket : public QBluetoothSocket
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cconnectedEvent[100];
    char cdisconnectedEvent[100];
    char cerrorEvent[100];
    char cstateChangedEvent[100];


    GBluetoothSocket(QBluetoothServiceInfo::Protocol x,QObject *parent,VM *pVM );

    ~GBluetoothSocket();

    void geteventparameters(void) ;

    void setconnectedEvent(const char *cStr);
    void setdisconnectedEvent(const char *cStr);
    void seterrorEvent(const char *cStr);
    void setstateChangedEvent(const char *cStr);


    const char *getconnectedEvent(void);
    const char *getdisconnectedEvent(void);
    const char *geterrorEvent(void);
    const char *getstateChangedEvent(void);


  public slots:

    void connectedSlot();
    void disconnectedSlot();
    void errorSlot();
    void stateChangedSlot();

};

#endif

