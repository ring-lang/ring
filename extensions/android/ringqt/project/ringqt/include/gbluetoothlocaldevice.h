
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBLUETOOTHLOCALDEVICE_H
#define GBLUETOOTHLOCALDEVICE_H
#include "ringqt.h"
#include <QBluetoothLocalDevice>
extern "C" {
#include "ring.h"
}

class GBluetoothLocalDevice : public QBluetoothLocalDevice
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cdeviceConnectedEvent[RINGQT_EVENT_SIZE];
    char cdeviceDisconnectedEvent[RINGQT_EVENT_SIZE];
    char cerrorEvent[RINGQT_EVENT_SIZE];
    char chostModeStateChangedEvent[RINGQT_EVENT_SIZE];
    char cpairingDisplayConfirmationEvent[RINGQT_EVENT_SIZE];
    char cpairingDisplayPinCodeEvent[RINGQT_EVENT_SIZE];
    char cpairingFinishedEvent[RINGQT_EVENT_SIZE];


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

