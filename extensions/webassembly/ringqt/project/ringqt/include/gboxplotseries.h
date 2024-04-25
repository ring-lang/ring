
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBOXPLOTSERIES_H
#define GBOXPLOTSERIES_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GBoxPlotSeries : public QtCharts::QBoxPlotSeries
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cboxOutlineVisibilityChangedEvent[RINGQT_EVENT_SIZE];
    char cboxWidthChangedEvent[RINGQT_EVENT_SIZE];
    char cboxsetsAddedEvent[RINGQT_EVENT_SIZE];
    char cboxsetsRemovedEvent[RINGQT_EVENT_SIZE];
    char cbrushChangedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ccountChangedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char choveredEvent[RINGQT_EVENT_SIZE];
    char cpenChangedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];


    GBoxPlotSeries(QObject *parent,VM *pVM );

    ~GBoxPlotSeries();

    void geteventparameters(void) ;

    void setboxOutlineVisibilityChangedEvent(const char *cStr);
    void setboxWidthChangedEvent(const char *cStr);
    void setboxsetsAddedEvent(const char *cStr);
    void setboxsetsRemovedEvent(const char *cStr);
    void setbrushChangedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setcountChangedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void sethoveredEvent(const char *cStr);
    void setpenChangedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);


    const char *getboxOutlineVisibilityChangedEvent(void);
    const char *getboxWidthChangedEvent(void);
    const char *getboxsetsAddedEvent(void);
    const char *getboxsetsRemovedEvent(void);
    const char *getbrushChangedEvent(void);
    const char *getclickedEvent(void);
    const char *getcountChangedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *gethoveredEvent(void);
    const char *getpenChangedEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);


  public slots:

    void boxOutlineVisibilityChangedSlot();
    void boxWidthChangedSlot();
    void boxsetsAddedSlot();
    void boxsetsRemovedSlot();
    void brushChangedSlot();
    void clickedSlot();
    void countChangedSlot();
    void doubleClickedSlot();
    void hoveredSlot();
    void penChangedSlot();
    void pressedSlot();
    void releasedSlot();

};

#endif

