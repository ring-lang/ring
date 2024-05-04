
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GVCANDLESTICKMODELMAPPER_H
#define GVCANDLESTICKMODELMAPPER_H
#include "ringqt.h"
#include <QtCharts>

extern "C" {
#include "ring.h"
}

class GVCandlestickModelMapper : public QtCharts::QVCandlestickModelMapper
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccloseRowChangedEvent[RINGQT_EVENT_SIZE];
    char cfirstSetColumnChangedEvent[RINGQT_EVENT_SIZE];
    char chighRowChangedEvent[RINGQT_EVENT_SIZE];
    char clastSetColumnChangedEvent[RINGQT_EVENT_SIZE];
    char clowRowChangedEvent[RINGQT_EVENT_SIZE];
    char copenRowChangedEvent[RINGQT_EVENT_SIZE];
    char ctimestampRowChangedEvent[RINGQT_EVENT_SIZE];


    GVCandlestickModelMapper(QObject * parent,VM *pVM );

    ~GVCandlestickModelMapper();

    void geteventparameters(void) ;

    void setcloseRowChangedEvent(const char *cStr);
    void setfirstSetColumnChangedEvent(const char *cStr);
    void sethighRowChangedEvent(const char *cStr);
    void setlastSetColumnChangedEvent(const char *cStr);
    void setlowRowChangedEvent(const char *cStr);
    void setopenRowChangedEvent(const char *cStr);
    void settimestampRowChangedEvent(const char *cStr);


    const char *getcloseRowChangedEvent(void);
    const char *getfirstSetColumnChangedEvent(void);
    const char *gethighRowChangedEvent(void);
    const char *getlastSetColumnChangedEvent(void);
    const char *getlowRowChangedEvent(void);
    const char *getopenRowChangedEvent(void);
    const char *gettimestampRowChangedEvent(void);


  public slots:

    void closeRowChangedSlot();
    void firstSetColumnChangedSlot();
    void highRowChangedSlot();
    void lastSetColumnChangedSlot();
    void lowRowChangedSlot();
    void openRowChangedSlot();
    void timestampRowChangedSlot();



};

#endif

