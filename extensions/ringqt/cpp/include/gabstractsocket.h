
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    List *pParaList;

    char cconnectedEvent[200];
    char cdisconnectedEvent[200];
    char cerrorEvent[200];
    char chostFoundEvent[200];
    char cproxyAuthenticationRequiredEvent[200];
    char cstateChangedEvent[200];


    GAbstractSocket(QAbstractSocket::SocketType x,QObject *parent,VM *pVM );

    ~GAbstractSocket();

    void geteventparameters(void) ;

    void setconnectedEvent(const char *cStr);
    void setdisconnectedEvent(const char *cStr);
    void seterrorEvent(const char *cStr);
    void sethostFoundEvent(const char *cStr);
    void setproxyAuthenticationRequiredEvent(const char *cStr);
    void setstateChangedEvent(const char *cStr);


    const char *getconnectedEvent(void);
    const char *getdisconnectedEvent(void);
    const char *geterrorEvent(void);
    const char *gethostFoundEvent(void);
    const char *getproxyAuthenticationRequiredEvent(void);
    const char *getstateChangedEvent(void);


  public slots:

    void connectedSlot();
    void disconnectedSlot();
    void errorSlot();
    void hostFoundSlot();
    void proxyAuthenticationRequiredSlot();
    void stateChangedSlot();

};

#endif

