
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GABSTRACTSOCKET_H
#define GABSTRACTSOCKET_H
#include "ringqt.h"
#include <QAbstractSocket>
extern "C" {
#include "ring.h"
}

class GAbstractSocket : public QAbstractSocket
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

