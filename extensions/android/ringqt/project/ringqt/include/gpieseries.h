
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPIESERIES_H
#define GPIESERIES_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GPieSeries : public QtCharts::QPieSeries
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char caddedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ccountChangedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char choveredEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];
    char cremovedEvent[RINGQT_EVENT_SIZE];
    char csumChangedEvent[RINGQT_EVENT_SIZE];


    GPieSeries(QObject * parent,VM *pVM );

    ~GPieSeries();

    void geteventparameters(void) ;

    void setaddedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setcountChangedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void sethoveredEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);
    void setremovedEvent(const char *cStr);
    void setsumChangedEvent(const char *cStr);


    const char *getaddedEvent(void);
    const char *getclickedEvent(void);
    const char *getcountChangedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *gethoveredEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);
    const char *getremovedEvent(void);
    const char *getsumChangedEvent(void);


  public slots:

    void addedSlot();
    void clickedSlot();
    void countChangedSlot();
    void doubleClickedSlot();
    void hoveredSlot();
    void pressedSlot();
    void releasedSlot();
    void removedSlot();
    void sumChangedSlot();

};

#endif

