
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    char cfinishedEvent[100];


    GNetworkAccessManager(QObject *parent,VM *pVM );

    void setfinishedEvent(const char *cStr);


  public slots:

    void finishedSlot(QNetworkReply*);

};

#endif

