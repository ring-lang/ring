
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGEOPOSITIONINFOSOURCE_H
#define GGEOPOSITIONINFOSOURCE_H
#include <QApplication>
#include <QGeoPositionInfoSource>
extern "C" {
#include "ring.h"
}

class GGeoPositionInfoSource : public QGeoPositionInfoSource
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cerrorEvent[100];
    char cpositionUpdatedEvent[100];
    char cupdateTimeoutEvent[100];


    GGeoPositionInfoSource(QObject *parent,VM *pVM );

    ~GGeoPositionInfoSource();

    void geteventparameters(void) ;

    void seterrorEvent(const char *cStr);
    void setpositionUpdatedEvent(const char *cStr);
    void setupdateTimeoutEvent(const char *cStr);


    const char *geterrorEvent(void);
    const char *getpositionUpdatedEvent(void);
    const char *getupdateTimeoutEvent(void);


  public slots:

    void errorSlot();
    void positionUpdatedSlot();
    void updateTimeoutSlot();

};

#endif

