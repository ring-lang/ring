
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTCPSERVER_H
#define GTCPSERVER_H
#include <QApplication>
#include <QTcpServer>
extern "C" {
#include "ring.h"
}

class GTcpServer : public QTcpServer
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cacceptErrorEvent[100];
    char cnewConnectionEvent[100];


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

