
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTCPSERVER_H
#define GTCPSERVER_H
#include "ringqt.h"
#include <QTcpServer>

extern "C" {
#include "ring.h"
}

class GTcpServer : public QTcpServer
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cacceptErrorEvent[RINGQT_EVENT_SIZE];
    char cnewConnectionEvent[RINGQT_EVENT_SIZE];


    GTcpServer(QObject *parent,VM *pVM );

    ~GTcpServer();

    void geteventparameters(void) ;

    void setacceptErrorEvent(const char *cStr);
    void setnewConnectionEvent(const char *cStr);


    const char *getacceptErrorEvent(void);
    const char *getnewConnectionEvent(void);


  public slots:

    void acceptErrorSlot();
    void newConnectionSlot();



};

#endif

