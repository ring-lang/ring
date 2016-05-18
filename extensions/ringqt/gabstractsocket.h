
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GABSTRACTSOCKET_H
#define GABSTRACTSOCKET_H
#include <QApplication>
#include <QAbstractSocket>
extern "C" {
#include "ring.h"
}

class GAbstractSocket : public QAbstractSocket
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


    GAbstractSocket(QAbstractSocket::SocketType x,QObject *parent,VM *pVM );

    void setconnectedEvent(const char *cStr);
    void setdisconnectedEvent(const char *cStr);
    void seterrorEvent(const char *cStr);
    void sethostFoundEvent(const char *cStr);
    void setproxyAuthenticationRequiredEvent(const char *cStr);
    void setstateChangedEvent(const char *cStr);


  public slots:

    void connectedSlot();
    void disconnectedSlot();
    void errorSlot();
    void hostFoundSlot();
    void proxyAuthenticationRequiredSlot();
    void stateChangedSlot();

};

#endif

