
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHSERVICEDISCOVERYAGENT_H
#define GBLUETOOTHSERVICEDISCOVERYAGENT_H
#include <QApplication>
#include "ringqt.h"
#include <QBluetoothServiceDiscoveryAgent>
extern "C" {
#include "ring.h"
}

class GBluetoothServiceDiscoveryAgent : public QBluetoothServiceDiscoveryAgent
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ccanceledEvent[RINGQT_EVENT_SIZE];
    char cerrorEvent[RINGQT_EVENT_SIZE];
    char cfinishedEvent[RINGQT_EVENT_SIZE];
    char cserviceDiscoveredEvent[RINGQT_EVENT_SIZE];


    GBluetoothServiceDiscoveryAgent(QObject *parent,VM *pVM );

    ~GBluetoothServiceDiscoveryAgent();

    void geteventparameters(void) ;

    void setcanceledEvent(const char *cStr);
    void seterrorEvent(const char *cStr);
    void setfinishedEvent(const char *cStr);
    void setserviceDiscoveredEvent(const char *cStr);


    const char *getcanceledEvent(void);
    const char *geterrorEvent(void);
    const char *getfinishedEvent(void);
    const char *getserviceDiscoveredEvent(void);


  public slots:

    void canceledSlot();
    void errorSlot();
    void finishedSlot();
    void serviceDiscoveredSlot();

};

#endif

