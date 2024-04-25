
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GVPIEMODELMAPPER_H
#define GVPIEMODELMAPPER_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GVPieModelMapper : public QtCharts::QVPieModelMapper
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cfirstRowChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsColumnChangedEvent[RINGQT_EVENT_SIZE];
    char cmodelReplacedEvent[RINGQT_EVENT_SIZE];
    char crowCountChangedEvent[RINGQT_EVENT_SIZE];
    char cseriesReplacedEvent[RINGQT_EVENT_SIZE];
    char cvaluesColumnChangedEvent[RINGQT_EVENT_SIZE];


    GVPieModelMapper(QObject * parent,VM *pVM );

    ~GVPieModelMapper();

    void geteventparameters(void) ;

    void setfirstRowChangedEvent(const char *cStr);
    void setlabelsColumnChangedEvent(const char *cStr);
    void setmodelReplacedEvent(const char *cStr);
    void setrowCountChangedEvent(const char *cStr);
    void setseriesReplacedEvent(const char *cStr);
    void setvaluesColumnChangedEvent(const char *cStr);


    const char *getfirstRowChangedEvent(void);
    const char *getlabelsColumnChangedEvent(void);
    const char *getmodelReplacedEvent(void);
    const char *getrowCountChangedEvent(void);
    const char *getseriesReplacedEvent(void);
    const char *getvaluesColumnChangedEvent(void);


  public slots:

    void firstRowChangedSlot();
    void labelsColumnChangedSlot();
    void modelReplacedSlot();
    void rowCountChangedSlot();
    void seriesReplacedSlot();
    void valuesColumnChangedSlot();

};

#endif

