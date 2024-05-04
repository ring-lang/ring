
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCANDLESTICKSET_H
#define GCANDLESTICKSET_H
#include "ringqt.h"
#include <QtCharts>

extern "C" {
#include "ring.h"
}

class GCandlestickSet : public QtCharts::QCandlestickSet
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cbrushChangedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ccloseChangedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char chighChangedEvent[RINGQT_EVENT_SIZE];
    char choveredEvent[RINGQT_EVENT_SIZE];
    char clowChangedEvent[RINGQT_EVENT_SIZE];
    char copenChangedEvent[RINGQT_EVENT_SIZE];
    char cpenChangedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];
    char ctimestampChangedEvent[RINGQT_EVENT_SIZE];


    GCandlestickSet(qreal x,QObject *parent,VM *pVM );

    ~GCandlestickSet();

    void geteventparameters(void) ;

    void setbrushChangedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setcloseChangedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void sethighChangedEvent(const char *cStr);
    void sethoveredEvent(const char *cStr);
    void setlowChangedEvent(const char *cStr);
    void setopenChangedEvent(const char *cStr);
    void setpenChangedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);
    void settimestampChangedEvent(const char *cStr);


    const char *getbrushChangedEvent(void);
    const char *getclickedEvent(void);
    const char *getcloseChangedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *gethighChangedEvent(void);
    const char *gethoveredEvent(void);
    const char *getlowChangedEvent(void);
    const char *getopenChangedEvent(void);
    const char *getpenChangedEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);
    const char *gettimestampChangedEvent(void);


  public slots:

    void brushChangedSlot();
    void clickedSlot();
    void closeChangedSlot();
    void doubleClickedSlot();
    void highChangedSlot();
    void hoveredSlot();
    void lowChangedSlot();
    void openChangedSlot();
    void penChangedSlot();
    void pressedSlot();
    void releasedSlot();
    void timestampChangedSlot();



};

#endif

