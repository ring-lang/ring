
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GHPIEMODELMAPPER_H
#define GHPIEMODELMAPPER_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GHPieModelMapper : public QtCharts::QHPieModelMapper
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccolumnCountChangedEvent[RINGQT_EVENT_SIZE];
    char cfirstColumnChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsRowChangedEvent[RINGQT_EVENT_SIZE];
    char cmodelReplacedEvent[RINGQT_EVENT_SIZE];
    char cseriesReplacedEvent[RINGQT_EVENT_SIZE];
    char cvaluesRowChangedEvent[RINGQT_EVENT_SIZE];


    GHPieModelMapper(QObject *parent,VM *pVM );

    ~GHPieModelMapper();

    void geteventparameters(void) ;

    void setcolumnCountChangedEvent(const char *cStr);
    void setfirstColumnChangedEvent(const char *cStr);
    void setlabelsRowChangedEvent(const char *cStr);
    void setmodelReplacedEvent(const char *cStr);
    void setseriesReplacedEvent(const char *cStr);
    void setvaluesRowChangedEvent(const char *cStr);


    const char *getcolumnCountChangedEvent(void);
    const char *getfirstColumnChangedEvent(void);
    const char *getlabelsRowChangedEvent(void);
    const char *getmodelReplacedEvent(void);
    const char *getseriesReplacedEvent(void);
    const char *getvaluesRowChangedEvent(void);


  public slots:

    void columnCountChangedSlot();
    void firstColumnChangedSlot();
    void labelsRowChangedSlot();
    void modelReplacedSlot();
    void seriesReplacedSlot();
    void valuesRowChangedSlot();

};

#endif

