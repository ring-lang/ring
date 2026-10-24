
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSSLSOCKET_H
#define GSSLSOCKET_H
#include "ringqt.h"
#include <QSslSocket>

extern "C" {
#include "ring.h"
}

class GSslSocket : public QSslSocket
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cencryptedEvent[RINGQT_EVENT_SIZE];
    char cencryptedBytesWrittenEvent[RINGQT_EVENT_SIZE];
    char cmodeChangedEvent[RINGQT_EVENT_SIZE];
    char cpeerVerifyErrorEvent[RINGQT_EVENT_SIZE];
    char csslErrorsEvent[RINGQT_EVENT_SIZE];


    GSslSocket(QObject *parent,VM *pVM );

    ~GSslSocket();

    void geteventparameters(void) ;

    void setencryptedEvent(const char *cStr);
    void setencryptedBytesWrittenEvent(const char *cStr);
    void setmodeChangedEvent(const char *cStr);
    void setpeerVerifyErrorEvent(const char *cStr);
    void setsslErrorsEvent(const char *cStr);


    const char *getencryptedEvent(void);
    const char *getencryptedBytesWrittenEvent(void);
    const char *getmodeChangedEvent(void);
    const char *getpeerVerifyErrorEvent(void);
    const char *getsslErrorsEvent(void);


  public slots:

    void encryptedSlot();
    void encryptedBytesWrittenSlot();
    void modeChangedSlot();
    void peerVerifyErrorSlot();
    void sslErrorsSlot();



};

#endif

