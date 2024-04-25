
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBOXSET_H
#define GBOXSET_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GBoxSet : public QtCharts::QBoxSet
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cbrushChangedEvent[RINGQT_EVENT_SIZE];
    char cclearedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char choveredEvent[RINGQT_EVENT_SIZE];
    char cpenChangedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];
    char cvalueChangedEvent[RINGQT_EVENT_SIZE];
    char cvaluesChangedEvent[RINGQT_EVENT_SIZE];


    GBoxSet(QString x,QObject *parent,VM *pVM );

    ~GBoxSet();

    void geteventparameters(void) ;

    void setbrushChangedEvent(const char *cStr);
    void setclearedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void sethoveredEvent(const char *cStr);
    void setpenChangedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);
    void setvalueChangedEvent(const char *cStr);
    void setvaluesChangedEvent(const char *cStr);


    const char *getbrushChangedEvent(void);
    const char *getclearedEvent(void);
    const char *getclickedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *gethoveredEvent(void);
    const char *getpenChangedEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);
    const char *getvalueChangedEvent(void);
    const char *getvaluesChangedEvent(void);


  public slots:

    void brushChangedSlot();
    void clearedSlot();
    void clickedSlot();
    void doubleClickedSlot();
    void hoveredSlot();
    void penChangedSlot();
    void pressedSlot();
    void releasedSlot();
    void valueChangedSlot();
    void valuesChangedSlot();

};

#endif

