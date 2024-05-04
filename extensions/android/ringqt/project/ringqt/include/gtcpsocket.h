
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTCPSOCKET_H
#define GTCPSOCKET_H
#include "ringqt.h"
#include <QTcpSocket>

extern "C" {
#include "ring.h"
}

class GTcpSocket : public QTcpSocket
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cconnectedEvent[RINGQT_EVENT_SIZE];
    char cdisconnectedEvent[RINGQT_EVENT_SIZE];
    char cerrorEvent[RINGQT_EVENT_SIZE];
    char chostFoundEvent[RINGQT_EVENT_SIZE];
    char cproxyAuthenticationRequiredEvent[RINGQT_EVENT_SIZE];
    char cstateChangedEvent[RINGQT_EVENT_SIZE];
    char caboutToCloseEvent[RINGQT_EVENT_SIZE];
    char cbytesWrittenEvent[RINGQT_EVENT_SIZE];
    char creadChannelFinishedEvent[RINGQT_EVENT_SIZE];
    char creadyReadEvent[RINGQT_EVENT_SIZE];


    GTcpSocket(QObject *parent,VM *pVM );

    ~GTcpSocket();

    void geteventparameters(void) ;

    void setconnectedEvent(const char *cStr);
    void setdisconnectedEvent(const char *cStr);
    void seterrorEvent(const char *cStr);
    void sethostFoundEvent(const char *cStr);
    void setproxyAuthenticationRequiredEvent(const char *cStr);
    void setstateChangedEvent(const char *cStr);
    void setaboutToCloseEvent(const char *cStr);
    void setbytesWrittenEvent(const char *cStr);
    void setreadChannelFinishedEvent(const char *cStr);
    void setreadyReadEvent(const char *cStr);


    const char *getconnectedEvent(void);
    const char *getdisconnectedEvent(void);
    const char *geterrorEvent(void);
    const char *gethostFoundEvent(void);
    const char *getproxyAuthenticationRequiredEvent(void);
    const char *getstateChangedEvent(void);
    const char *getaboutToCloseEvent(void);
    const char *getbytesWrittenEvent(void);
    const char *getreadChannelFinishedEvent(void);
    const char *getreadyReadEvent(void);


  public slots:

    void connectedSlot();
    void disconnectedSlot();
    void errorSlot();
    void hostFoundSlot();
    void proxyAuthenticationRequiredSlot();
    void stateChangedSlot();
    void aboutToCloseSlot();
    void bytesWrittenSlot();
    void readChannelFinishedSlot();
    void readyReadSlot();



};

#endif

