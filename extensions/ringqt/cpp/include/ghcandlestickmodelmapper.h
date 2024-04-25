
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GHCANDLESTICKMODELMAPPER_H
#define GHCANDLESTICKMODELMAPPER_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GHCandlestickModelMapper : public QtCharts::QHCandlestickModelMapper
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccloseColumnChangedEvent[RINGQT_EVENT_SIZE];
    char cfirstSetRowChangedEvent[RINGQT_EVENT_SIZE];
    char chighColumnChangedEvent[RINGQT_EVENT_SIZE];
    char clastSetRowChangedEvent[RINGQT_EVENT_SIZE];
    char clowColumnChangedEvent[RINGQT_EVENT_SIZE];
    char copenColumnChangedEvent[RINGQT_EVENT_SIZE];
    char ctimestampColumnChangedEvent[RINGQT_EVENT_SIZE];


    GHCandlestickModelMapper(QObject *parent,VM *pVM );

    ~GHCandlestickModelMapper();

    void geteventparameters(void) ;

    void setcloseColumnChangedEvent(const char *cStr);
    void setfirstSetRowChangedEvent(const char *cStr);
    void sethighColumnChangedEvent(const char *cStr);
    void setlastSetRowChangedEvent(const char *cStr);
    void setlowColumnChangedEvent(const char *cStr);
    void setopenColumnChangedEvent(const char *cStr);
    void settimestampColumnChangedEvent(const char *cStr);


    const char *getcloseColumnChangedEvent(void);
    const char *getfirstSetRowChangedEvent(void);
    const char *gethighColumnChangedEvent(void);
    const char *getlastSetRowChangedEvent(void);
    const char *getlowColumnChangedEvent(void);
    const char *getopenColumnChangedEvent(void);
    const char *gettimestampColumnChangedEvent(void);


  public slots:

    void closeColumnChangedSlot();
    void firstSetRowChangedSlot();
    void highColumnChangedSlot();
    void lastSetRowChangedSlot();
    void lowColumnChangedSlot();
    void openColumnChangedSlot();
    void timestampColumnChangedSlot();

};

#endif

