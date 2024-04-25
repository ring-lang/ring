
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSCATTERSERIES_H
#define GSCATTERSERIES_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GScatterSeries : public QtCharts::QScatterSeries
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cborderColorChangedEvent[RINGQT_EVENT_SIZE];
    char ccolorChangedEvent[RINGQT_EVENT_SIZE];
    char cmarkerShapeChangedEvent[RINGQT_EVENT_SIZE];
    char cmarkerSizeChangedEvent[RINGQT_EVENT_SIZE];


    GScatterSeries(QObject * parent,VM *pVM );

    ~GScatterSeries();

    void geteventparameters(void) ;

    void setborderColorChangedEvent(const char *cStr);
    void setcolorChangedEvent(const char *cStr);
    void setmarkerShapeChangedEvent(const char *cStr);
    void setmarkerSizeChangedEvent(const char *cStr);


    const char *getborderColorChangedEvent(void);
    const char *getcolorChangedEvent(void);
    const char *getmarkerShapeChangedEvent(void);
    const char *getmarkerSizeChangedEvent(void);


  public slots:

    void borderColorChangedSlot();
    void colorChangedSlot();
    void markerShapeChangedSlot();
    void markerSizeChangedSlot();

};

#endif

