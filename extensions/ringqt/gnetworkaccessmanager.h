
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GNETWORKACCESSMANAGER_H
#define GNETWORKACCESSMANAGER_H
#include <QApplication>
#include <QNetworkAccessManager>
extern "C" {
#include "ring.h"
}

class GNetworkAccessManager : public QNetworkAccessManager
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cfinishedEvent[100];


    GNetworkAccessManager(QObject *parent,VM *pVM );

    ~GNetworkAccessManager();

    void geteventparameters(void) ;

    void setfinishedEvent(const char *cStr);


    const char *getfinishedEvent(void);


  public slots:

    void finishedSlot(QNetworkReply *p1);

};

#endif

