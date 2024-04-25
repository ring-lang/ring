
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGEOPOSITIONINFOSOURCE_H
#define GGEOPOSITIONINFOSOURCE_H
#include "ringqt.h"
#include <QGeoPositionInfoSource>
extern "C" {
#include "ring.h"
}

class GGeoPositionInfoSource : public QGeoPositionInfoSource
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cerrorEvent[RINGQT_EVENT_SIZE];
    char cpositionUpdatedEvent[RINGQT_EVENT_SIZE];
    char cupdateTimeoutEvent[RINGQT_EVENT_SIZE];


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

