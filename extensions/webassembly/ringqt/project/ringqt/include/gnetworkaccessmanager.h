
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GNETWORKACCESSMANAGER_H
#define GNETWORKACCESSMANAGER_H
#include "ringqt.h"
#include <QNetworkAccessManager>

extern "C" {
#include "ring.h"
}

class GNetworkAccessManager : public QNetworkAccessManager
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cfinishedEvent[RINGQT_EVENT_SIZE];


    GNetworkAccessManager(QObject *parent,VM *pVM );

    ~GNetworkAccessManager();

    void geteventparameters(void) ;

    void setfinishedEvent(const char *cStr);


    const char *getfinishedEvent(void);


  public slots:

    void finishedSlot(QNetworkReply *p1);



};

#endif

