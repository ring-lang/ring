
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GHBOXPLOTMODELMAPPER_H
#define GHBOXPLOTMODELMAPPER_H
#include "ringqt.h"
#include <QtCharts>

extern "C" {
#include "ring.h"
}

class GHBoxPlotModelMapper : public QtCharts::QHBoxPlotModelMapper
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccolumnCountChangedEvent[RINGQT_EVENT_SIZE];
    char cfirstBoxSetRowChangedEvent[RINGQT_EVENT_SIZE];
    char cfirstColumnChangedEvent[RINGQT_EVENT_SIZE];
    char clastBoxSetRowChangedEvent[RINGQT_EVENT_SIZE];
    char cmodelReplacedEvent[RINGQT_EVENT_SIZE];
    char cseriesReplacedEvent[RINGQT_EVENT_SIZE];


    GHBoxPlotModelMapper(QObject *parent,VM *pVM );

    ~GHBoxPlotModelMapper();

    void geteventparameters(void) ;

    void setcolumnCountChangedEvent(const char *cStr);
    void setfirstBoxSetRowChangedEvent(const char *cStr);
    void setfirstColumnChangedEvent(const char *cStr);
    void setlastBoxSetRowChangedEvent(const char *cStr);
    void setmodelReplacedEvent(const char *cStr);
    void setseriesReplacedEvent(const char *cStr);


    const char *getcolumnCountChangedEvent(void);
    const char *getfirstBoxSetRowChangedEvent(void);
    const char *getfirstColumnChangedEvent(void);
    const char *getlastBoxSetRowChangedEvent(void);
    const char *getmodelReplacedEvent(void);
    const char *getseriesReplacedEvent(void);


  public slots:

    void columnCountChangedSlot();
    void firstBoxSetRowChangedSlot();
    void firstColumnChangedSlot();
    void lastBoxSetRowChangedSlot();
    void modelReplacedSlot();
    void seriesReplacedSlot();



};

#endif

