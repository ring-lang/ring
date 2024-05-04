
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GVBARMODELMAPPER_H
#define GVBARMODELMAPPER_H
#include "ringqt.h"
#include <QtCharts>

extern "C" {
#include "ring.h"
}

class GVBarModelMapper : public QtCharts::QVBarModelMapper
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cfirstBarSetColumnChangedEvent[RINGQT_EVENT_SIZE];
    char cfirstRowChangedEvent[RINGQT_EVENT_SIZE];
    char clastBarSetColumnChangedEvent[RINGQT_EVENT_SIZE];
    char cmodelReplacedEvent[RINGQT_EVENT_SIZE];
    char crowCountChangedEvent[RINGQT_EVENT_SIZE];
    char cseriesReplacedEvent[RINGQT_EVENT_SIZE];


    GVBarModelMapper(QObject * parent,VM *pVM );

    ~GVBarModelMapper();

    void geteventparameters(void) ;

    void setfirstBarSetColumnChangedEvent(const char *cStr);
    void setfirstRowChangedEvent(const char *cStr);
    void setlastBarSetColumnChangedEvent(const char *cStr);
    void setmodelReplacedEvent(const char *cStr);
    void setrowCountChangedEvent(const char *cStr);
    void setseriesReplacedEvent(const char *cStr);


    const char *getfirstBarSetColumnChangedEvent(void);
    const char *getfirstRowChangedEvent(void);
    const char *getlastBarSetColumnChangedEvent(void);
    const char *getmodelReplacedEvent(void);
    const char *getrowCountChangedEvent(void);
    const char *getseriesReplacedEvent(void);


  public slots:

    void firstBarSetColumnChangedSlot();
    void firstRowChangedSlot();
    void lastBarSetColumnChangedSlot();
    void modelReplacedSlot();
    void rowCountChangedSlot();
    void seriesReplacedSlot();



};

#endif

