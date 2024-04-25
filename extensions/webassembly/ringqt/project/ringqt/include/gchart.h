
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCHART_H
#define GCHART_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GChart : public QtCharts::QChart
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cplotAreaChangedEvent[RINGQT_EVENT_SIZE];


    GChart(QGraphicsItem *x,Qt::WindowFlags parent,VM *pVM );

    ~GChart();

    void geteventparameters(void) ;

    void setplotAreaChangedEvent(const char *cStr);


    const char *getplotAreaChangedEvent(void);


  public slots:

    void plotAreaChangedSlot();

};

#endif

