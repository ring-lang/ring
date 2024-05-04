
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GHBARMODELMAPPER_H
#define GHBARMODELMAPPER_H
#include "ringqt.h"
#include <QtCharts>

extern "C" {
#include "ring.h"
}

class GHBarModelMapper : public QtCharts::QHBarModelMapper
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccolumnCountChangedEvent[RINGQT_EVENT_SIZE];
    char cfirstBarSetRowChangedEvent[RINGQT_EVENT_SIZE];
    char cfirstColumnChangedEvent[RINGQT_EVENT_SIZE];
    char clastBarSetRowChangedEvent[RINGQT_EVENT_SIZE];
    char cmodelReplacedEvent[RINGQT_EVENT_SIZE];
    char cseriesReplacedEvent[RINGQT_EVENT_SIZE];


    GHBarModelMapper(QObject *parent,VM *pVM );

    ~GHBarModelMapper();

    void geteventparameters(void) ;

    void setcolumnCountChangedEvent(const char *cStr);
    void setfirstBarSetRowChangedEvent(const char *cStr);
    void setfirstColumnChangedEvent(const char *cStr);
    void setlastBarSetRowChangedEvent(const char *cStr);
    void setmodelReplacedEvent(const char *cStr);
    void setseriesReplacedEvent(const char *cStr);


    const char *getcolumnCountChangedEvent(void);
    const char *getfirstBarSetRowChangedEvent(void);
    const char *getfirstColumnChangedEvent(void);
    const char *getlastBarSetRowChangedEvent(void);
    const char *getmodelReplacedEvent(void);
    const char *getseriesReplacedEvent(void);


  public slots:

    void columnCountChangedSlot();
    void firstBarSetRowChangedSlot();
    void firstColumnChangedSlot();
    void lastBarSetRowChangedSlot();
    void modelReplacedSlot();
    void seriesReplacedSlot();



};

#endif

