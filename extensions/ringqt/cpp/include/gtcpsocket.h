
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTCPSOCKET_H
#define GTCPSOCKET_H
#include <QApplication>
#include <QTcpSocket>
extern "C" {
#include "ring.h"
}

class GTcpSocket : public QTcpSocket
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cconnectedEvent[200];
    char cdisconnectedEvent[200];
    char cerrorEvent[200];
    char chostFoundEvent[200];
    char cproxyAuthenticationRequiredEvent[200];
    char cstateChangedEvent[200];
    char caboutToCloseEvent[200];
    char cbytesWrittenEvent[200];
    char creadChannelFinishedEvent[200];
    char creadyReadEvent[200];


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

