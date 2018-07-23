
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

    char cconnectedEvent[100];
    char cdisconnectedEvent[100];
    char cerrorEvent[100];
    char chostFoundEvent[100];
    char cproxyAuthenticationRequiredEvent[100];
    char cstateChangedEvent[100];
    char caboutToCloseEvent[100];
    char cbytesWrittenEvent[100];
    char creadChannelFinishedEvent[100];
    char creadyReadEvent[100];


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

