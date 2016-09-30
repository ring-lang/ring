
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
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

