
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GHXYMODELMAPPER_H
#define GHXYMODELMAPPER_H
#include <QApplication>
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GHXYModelMapper : public QtCharts::QHXYModelMapper
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ccolumnCountChangedEvent[RINGQT_EVENT_SIZE];
    char cfirstColumnChangedEvent[RINGQT_EVENT_SIZE];
    char cmodelReplacedEvent[RINGQT_EVENT_SIZE];
    char cseriesReplacedEvent[RINGQT_EVENT_SIZE];
    char cxRowChangedEvent[RINGQT_EVENT_SIZE];
    char cyRowChangedEvent[RINGQT_EVENT_SIZE];


    GHXYModelMapper(QObject *parent,VM *pVM );

    ~GHXYModelMapper();

    void geteventparameters(void) ;

    void setcolumnCountChangedEvent(const char *cStr);
    void setfirstColumnChangedEvent(const char *cStr);
    void setmodelReplacedEvent(const char *cStr);
    void setseriesReplacedEvent(const char *cStr);
    void setxRowChangedEvent(const char *cStr);
    void setyRowChangedEvent(const char *cStr);


    const char *getcolumnCountChangedEvent(void);
    const char *getfirstColumnChangedEvent(void);
    const char *getmodelReplacedEvent(void);
    const char *getseriesReplacedEvent(void);
    const char *getxRowChangedEvent(void);
    const char *getyRowChangedEvent(void);


  public slots:

    void columnCountChangedSlot();
    void firstColumnChangedSlot();
    void modelReplacedSlot();
    void seriesReplacedSlot();
    void xRowChangedSlot();
    void yRowChangedSlot();

};

#endif

