
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GUDPSOCKET_H
#define GUDPSOCKET_H
#include "ringqt.h"
#include <QUdpSocket>

extern "C" {
#include "ring.h"
}

class GUdpSocket : public QUdpSocket
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cconnectedEvent[RINGQT_EVENT_SIZE];
    char cdisconnectedEvent[RINGQT_EVENT_SIZE];
    char cerrorEvent[RINGQT_EVENT_SIZE];
    char chostFoundEvent[RINGQT_EVENT_SIZE];
    char cstateChangedEvent[RINGQT_EVENT_SIZE];
    char creadyReadEvent[RINGQT_EVENT_SIZE];


    GUdpSocket(QObject *parent,VM *pVM );

    ~GUdpSocket();

    void geteventparameters(void) ;

    void setconnectedEvent(const char *cStr);
    void setdisconnectedEvent(const char *cStr);
    void seterrorEvent(const char *cStr);
    void sethostFoundEvent(const char *cStr);
    void setstateChangedEvent(const char *cStr);
    void setreadyReadEvent(const char *cStr);


    const char *getconnectedEvent(void);
    const char *getdisconnectedEvent(void);
    const char *geterrorEvent(void);
    const char *gethostFoundEvent(void);
    const char *getstateChangedEvent(void);
    const char *getreadyReadEvent(void);


  public slots:

    void connectedSlot();
    void disconnectedSlot();
    void errorSlot();
    void hostFoundSlot();
    void stateChangedSlot();
    void readyReadSlot();



};

#endif

