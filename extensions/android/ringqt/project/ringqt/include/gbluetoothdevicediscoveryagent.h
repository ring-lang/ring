
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHDEVICEDISCOVERYAGENT_H
#define GBLUETOOTHDEVICEDISCOVERYAGENT_H
#include "ringqt.h"
#include <QBluetoothDeviceDiscoveryAgent>
extern "C" {
#include "ring.h"
}

class GBluetoothDeviceDiscoveryAgent : public QBluetoothDeviceDiscoveryAgent
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccanceledEvent[RINGQT_EVENT_SIZE];
    char cdeviceDiscoveredEvent[RINGQT_EVENT_SIZE];
    char cerrorEvent[RINGQT_EVENT_SIZE];
    char cfinishedEvent[RINGQT_EVENT_SIZE];


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

