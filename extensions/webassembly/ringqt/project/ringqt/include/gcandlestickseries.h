
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCANDLESTICKSERIES_H
#define GCANDLESTICKSERIES_H
#include "ringqt.h"
#include <QtCharts>

extern "C" {
#include "ring.h"
}

class GCandlestickSeries : public QtCharts::QCandlestickSeries
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cbodyOutlineVisibilityChangedEvent[RINGQT_EVENT_SIZE];
    char cbodyWidthChangedEvent[RINGQT_EVENT_SIZE];
    char cbrushChangedEvent[RINGQT_EVENT_SIZE];
    char ccandlestickSetsAddedEvent[RINGQT_EVENT_SIZE];
    char ccandlestickSetsRemovedEvent[RINGQT_EVENT_SIZE];
    char ccapsVisibilityChangedEvent[RINGQT_EVENT_SIZE];
    char ccapsWidthChangedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ccountChangedEvent[RINGQT_EVENT_SIZE];
    char cdecreasingColorChangedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char choveredEvent[RINGQT_EVENT_SIZE];
    char cincreasingColorChangedEvent[RINGQT_EVENT_SIZE];
    char cmaximumColumnWidthChangedEvent[RINGQT_EVENT_SIZE];
    char cminimumColumnWidthChangedEvent[RINGQT_EVENT_SIZE];
    char cpenChangedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];


    GCandlestickSeries(QObject *parent,VM *pVM );

    ~GCandlestickSeries();

    void geteventparameters(void) ;

    void setbodyOutlineVisibilityChangedEvent(const char *cStr);
    void setbodyWidthChangedEvent(const char *cStr);
    void setbrushChangedEvent(const char *cStr);
    void setcandlestickSetsAddedEvent(const char *cStr);
    void setcandlestickSetsRemovedEvent(const char *cStr);
    void setcapsVisibilityChangedEvent(const char *cStr);
    void setcapsWidthChangedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setcountChangedEvent(const char *cStr);
    void setdecreasingColorChangedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void sethoveredEvent(const char *cStr);
    void setincreasingColorChangedEvent(const char *cStr);
    void setmaximumColumnWidthChangedEvent(const char *cStr);
    void setminimumColumnWidthChangedEvent(const char *cStr);
    void setpenChangedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);


    const char *getbodyOutlineVisibilityChangedEvent(void);
    const char *getbodyWidthChangedEvent(void);
    const char *getbrushChangedEvent(void);
    const char *getcandlestickSetsAddedEvent(void);
    const char *getcandlestickSetsRemovedEvent(void);
    const char *getcapsVisibilityChangedEvent(void);
    const char *getcapsWidthChangedEvent(void);
    const char *getclickedEvent(void);
    const char *getcountChangedEvent(void);
    const char *getdecreasingColorChangedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *gethoveredEvent(void);
    const char *getincreasingColorChangedEvent(void);
    const char *getmaximumColumnWidthChangedEvent(void);
    const char *getminimumColumnWidthChangedEvent(void);
    const char *getpenChangedEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);


  public slots:

    void bodyOutlineVisibilityChangedSlot();
    void bodyWidthChangedSlot();
    void brushChangedSlot();
    void candlestickSetsAddedSlot();
    void candlestickSetsRemovedSlot();
    void capsVisibilityChangedSlot();
    void capsWidthChangedSlot();
    void clickedSlot();
    void countChangedSlot();
    void decreasingColorChangedSlot();
    void doubleClickedSlot();
    void hoveredSlot();
    void increasingColorChangedSlot();
    void maximumColumnWidthChangedSlot();
    void minimumColumnWidthChangedSlot();
    void penChangedSlot();
    void pressedSlot();
    void releasedSlot();



};

#endif

