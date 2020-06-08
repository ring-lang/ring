
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GVXYMODELMAPPER_H
#define GVXYMODELMAPPER_H
#include <QApplication>
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GVXYModelMapper : public QtCharts::QVXYModelMapper
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cfirstRowChangedEvent[RINGQT_EVENT_SIZE];
    char cmodelReplacedEvent[RINGQT_EVENT_SIZE];
    char crowCountChangedEvent[RINGQT_EVENT_SIZE];
    char cseriesReplacedEvent[RINGQT_EVENT_SIZE];
    char cxColumnChangedEvent[RINGQT_EVENT_SIZE];
    char cyColumnChangedEvent[RINGQT_EVENT_SIZE];


    GVXYModelMapper(QObject * parent,VM *pVM );

    ~GVXYModelMapper();

    void geteventparameters(void) ;

    void setfirstRowChangedEvent(const char *cStr);
    void setmodelReplacedEvent(const char *cStr);
    void setrowCountChangedEvent(const char *cStr);
    void setseriesReplacedEvent(const char *cStr);
    void setxColumnChangedEvent(const char *cStr);
    void setyColumnChangedEvent(const char *cStr);


    const char *getfirstRowChangedEvent(void);
    const char *getmodelReplacedEvent(void);
    const char *getrowCountChangedEvent(void);
    const char *getseriesReplacedEvent(void);
    const char *getxColumnChangedEvent(void);
    const char *getyColumnChangedEvent(void);


  public slots:

    void firstRowChangedSlot();
    void modelReplacedSlot();
    void rowCountChangedSlot();
    void seriesReplacedSlot();
    void xColumnChangedSlot();
    void yColumnChangedSlot();

};

#endif

