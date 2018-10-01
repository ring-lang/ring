
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGEOAREAMONITORSOURCE_H
#define GGEOAREAMONITORSOURCE_H
#include <QApplication>
#include <QGeoAreaMonitorSource>
extern "C" {
#include "ring.h"
}

class GGeoAreaMonitorSource : public QGeoAreaMonitorSource
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cEvent[100];
    char cEvent[100];
    char cEvent[100];
    char cEvent[100];


    GGeoAreaMonitorSource(QObject *parent,VM *pVM );

    ~GGeoAreaMonitorSource();

    void geteventparameters(void) ;

    void setEvent(const char *cStr);
    void setEvent(const char *cStr);
    void setEvent(const char *cStr);
    void setEvent(const char *cStr);


    const char *getEvent(void);
    const char *getEvent(void);
    const char *getEvent(void);
    const char *getEvent(void);


  public slots:

    void Slot();
    void Slot();
    void Slot();
    void Slot();

};

#endif

