
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHDEVICEDISCOVERYAGENT_H
#define GBLUETOOTHDEVICEDISCOVERYAGENT_H
#include <QApplication>
#include <QBluetoothDeviceDiscoveryAgent>
extern "C" {
#include "ring.h"
}

class GBluetoothDeviceDiscoveryAgent : public QBluetoothDeviceDiscoveryAgent
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ccanceledEvent[100];
    char cdeviceDiscoveredEvent[100];
    char cerrorEvent[100];
    char cfinishedEvent[100];


    GBluetoothDeviceDiscoveryAgent(QObject *parent,VM *pVM );

    ~GBluetoothDeviceDiscoveryAgent();

    void geteventparameters(void) ;

    void setcanceledEvent(const char *cStr);
    void setdeviceDiscoveredEvent(const char *cStr);
    void seterrorEvent(const char *cStr);
    void setfinishedEvent(const char *cStr);


    const char *getcanceledEvent(void);
    const char *getdeviceDiscoveredEvent(void);
    const char *geterrorEvent(void);
    const char *getfinishedEvent(void);


  public slots:

    void canceledSlot();
    void deviceDiscoveredSlot();
    void errorSlot();
    void finishedSlot();

};

#endif

