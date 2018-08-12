
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHSERVICEDISCOVERYAGENT_H
#define GBLUETOOTHSERVICEDISCOVERYAGENT_H
#include <QApplication>
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

    char ccanceledEvent[100];
    char cerrorEvent[100];
    char cfinishedEvent[100];
    char cserviceDiscoveredEvent[100];


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

