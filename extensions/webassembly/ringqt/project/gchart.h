
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCHART_H
#define GCHART_H
#include <QApplication>
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GChart : public QtCharts::QChart
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

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

