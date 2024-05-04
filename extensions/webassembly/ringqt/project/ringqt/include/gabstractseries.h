
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GABSTRACTSERIES_H
#define GABSTRACTSERIES_H
#include "ringqt.h"
#include <QtCharts/QAbstractSeries>

extern "C" {
#include "ring.h"
}

class GAbstractSeries : public QtCharts::QAbstractSeries
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cnameChangedEvent[RINGQT_EVENT_SIZE];
    char copacityChangedEvent[RINGQT_EVENT_SIZE];
    char cuseOpenGLChangedEvent[RINGQT_EVENT_SIZE];
    char cvisibleChangedEvent[RINGQT_EVENT_SIZE];


    GAbstractSeries(QtCharts::QAbstractSeriesPrivate &parent,VM *pVM );

    ~GAbstractSeries();

    void geteventparameters(void) ;

    void setnameChangedEvent(const char *cStr);
    void setopacityChangedEvent(const char *cStr);
    void setuseOpenGLChangedEvent(const char *cStr);
    void setvisibleChangedEvent(const char *cStr);


    const char *getnameChangedEvent(void);
    const char *getopacityChangedEvent(void);
    const char *getuseOpenGLChangedEvent(void);
    const char *getvisibleChangedEvent(void);


  public slots:

    void nameChangedSlot();
    void opacityChangedSlot();
    void useOpenGLChangedSlot();
    void visibleChangedSlot();



};

#endif

