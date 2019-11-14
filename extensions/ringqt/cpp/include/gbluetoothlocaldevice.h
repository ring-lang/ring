
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHLOCALDEVICE_H
#define GBLUETOOTHLOCALDEVICE_H
#include <QApplication>
#include <QBluetoothLocalDevice>
extern "C" {
#include "ring.h"
}

class GBluetoothLocalDevice : public QBluetoothLocalDevice
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cdeviceConnectedEvent[200];
    char cdeviceDisconnectedEvent[200];
    char cerrorEvent[200];
    char chostModeStateChangedEvent[200];
    char cpairingDisplayConfirmationEvent[200];
    char cpairingDisplayPinCodeEvent[200];
    char cpairingFinishedEvent[200];


    GBluetoothLocalDevice(QObject *parent,VM *pVM );

    ~GBluetoothLocalDevice();

    void geteventparameters(void) ;

    void setdeviceConnectedEvent(const char *cStr);
    void setdeviceDisconnectedEvent(const char *cStr);
    void seterrorEvent(const char *cStr);
    void sethostModeStateChangedEvent(const char *cStr);
    void setpairingDisplayConfirmationEvent(const char *cStr);
    void setpairingDisplayPinCodeEvent(const char *cStr);
    void setpairingFinishedEvent(const char *cStr);


    const char *getdeviceConnectedEvent(void);
    const char *getdeviceDisconnectedEvent(void);
    const char *geterrorEvent(void);
    const char *gethostModeStateChangedEvent(void);
    const char *getpairingDisplayConfirmationEvent(void);
    const char *getpairingDisplayPinCodeEvent(void);
    const char *getpairingFinishedEvent(void);


  public slots:

    void deviceConnectedSlot();
    void deviceDisconnectedSlot();
    void errorSlot();
    void hostModeStateChangedSlot();
    void pairingDisplayConfirmationSlot();
    void pairingDisplayPinCodeSlot();
    void pairingFinishedSlot();

};

#endif

