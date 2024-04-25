
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GVBOXPLOTMODELMAPPER_H
#define GVBOXPLOTMODELMAPPER_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GVBoxPlotModelMapper : public QtCharts::QVBoxPlotModelMapper
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cfirstBoxSetColumnChangedEvent[RINGQT_EVENT_SIZE];
    char cfirstRowChangedEvent[RINGQT_EVENT_SIZE];
    char clastBoxSetColumnChangedEvent[RINGQT_EVENT_SIZE];
    char cmodelReplacedEvent[RINGQT_EVENT_SIZE];
    char crowCountChangedEvent[RINGQT_EVENT_SIZE];
    char cseriesReplacedEvent[RINGQT_EVENT_SIZE];


    GVBoxPlotModelMapper(QObject * parent,VM *pVM );

    ~GVBoxPlotModelMapper();

    void geteventparameters(void) ;

    void setfirstBoxSetColumnChangedEvent(const char *cStr);
    void setfirstRowChangedEvent(const char *cStr);
    void setlastBoxSetColumnChangedEvent(const char *cStr);
    void setmodelReplacedEvent(const char *cStr);
    void setrowCountChangedEvent(const char *cStr);
    void setseriesReplacedEvent(const char *cStr);


    const char *getfirstBoxSetColumnChangedEvent(void);
    const char *getfirstRowChangedEvent(void);
    const char *getlastBoxSetColumnChangedEvent(void);
    const char *getmodelReplacedEvent(void);
    const char *getrowCountChangedEvent(void);
    const char *getseriesReplacedEvent(void);


  public slots:

    void firstBoxSetColumnChangedSlot();
    void firstRowChangedSlot();
    void lastBoxSetColumnChangedSlot();
    void modelReplacedSlot();
    void rowCountChangedSlot();
    void seriesReplacedSlot();

};

#endif

