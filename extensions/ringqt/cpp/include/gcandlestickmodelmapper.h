
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCANDLESTICKMODELMAPPER_H
#define GCANDLESTICKMODELMAPPER_H
#include <QApplication>
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GCandlestickModelMapper : public QtCharts::QCandlestickModelMapper
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cmodelReplacedEvent[RINGQT_EVENT_SIZE];
    char cseriesReplacedEvent[RINGQT_EVENT_SIZE];


    GCandlestickModelMapper(QObject *parent,VM *pVM );

    ~GCandlestickModelMapper();

    void geteventparameters(void) ;

    void setmodelReplacedEvent(const char *cStr);
    void setseriesReplacedEvent(const char *cStr);


    const char *getmodelReplacedEvent(void);
    const char *getseriesReplacedEvent(void);


  public slots:

    void modelReplacedSlot();
    void seriesReplacedSlot();

};

#endif

