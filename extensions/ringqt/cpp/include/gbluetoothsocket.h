
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHSOCKET_H
#define GBLUETOOTHSOCKET_H
#include "ringqt.h"
#include <QBluetoothSocket>

extern "C" {
#include "ring.h"
}

class GBluetoothSocket : public QBluetoothSocket
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cconnectedEvent[RINGQT_EVENT_SIZE];
    char cdisconnectedEvent[RINGQT_EVENT_SIZE];
    char cerrorEvent[RINGQT_EVENT_SIZE];
    char cstateChangedEvent[RINGQT_EVENT_SIZE];


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

