
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GABSTRACTBARSERIES_H
#define GABSTRACTBARSERIES_H
#include "ringqt.h"
#include <QtCharts/QAbstractBarSeries>

extern "C" {
#include "ring.h"
}

class GAbstractBarSeries : public QtCharts::QAbstractBarSeries
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cbarsetsAddedEvent[RINGQT_EVENT_SIZE];
    char cbarsetsRemovedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ccountChangedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char choveredEvent[RINGQT_EVENT_SIZE];
    char clabelsAngleChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsFormatChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsPositionChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsPrecisionChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsVisibleChangedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];


    GAbstractBarSeries(QtCharts::QAbstractBarSeriesPrivate &parent,VM *pVM );

    ~GAbstractBarSeries();

    void geteventparameters(void) ;

    void setbarsetsAddedEvent(const char *cStr);
    void setbarsetsRemovedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setcountChangedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void sethoveredEvent(const char *cStr);
    void setlabelsAngleChangedEvent(const char *cStr);
    void setlabelsFormatChangedEvent(const char *cStr);
    void setlabelsPositionChangedEvent(const char *cStr);
    void setlabelsPrecisionChangedEvent(const char *cStr);
    void setlabelsVisibleChangedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);


    const char *getbarsetsAddedEvent(void);
    const char *getbarsetsRemovedEvent(void);
    const char *getclickedEvent(void);
    const char *getcountChangedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *gethoveredEvent(void);
    const char *getlabelsAngleChangedEvent(void);
    const char *getlabelsFormatChangedEvent(void);
    const char *getlabelsPositionChangedEvent(void);
    const char *getlabelsPrecisionChangedEvent(void);
    const char *getlabelsVisibleChangedEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);


  public slots:

    void barsetsAddedSlot();
    void barsetsRemovedSlot();
    void clickedSlot();
    void countChangedSlot();
    void doubleClickedSlot();
    void hoveredSlot();
    void labelsAngleChangedSlot();
    void labelsFormatChangedSlot();
    void labelsPositionChangedSlot();
    void labelsPrecisionChangedSlot();
    void labelsVisibleChangedSlot();
    void pressedSlot();
    void releasedSlot();



};

#endif

