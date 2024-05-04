
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GVALUEAXIS_H
#define GVALUEAXIS_H
#include "ringqt.h"
#include <QtCharts>

extern "C" {
#include "ring.h"
}

class GValueAxis : public QtCharts::QValueAxis
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char clabelFormatChangedEvent[RINGQT_EVENT_SIZE];
    char cmaxChangedEvent[RINGQT_EVENT_SIZE];
    char cminChangedEvent[RINGQT_EVENT_SIZE];
    char cminorTickCountChangedEvent[RINGQT_EVENT_SIZE];
    char crangeChangedEvent[RINGQT_EVENT_SIZE];
    char ctickAnchorChangedEvent[RINGQT_EVENT_SIZE];
    char ctickCountChangedEvent[RINGQT_EVENT_SIZE];
    char ctickIntervalChangedEvent[RINGQT_EVENT_SIZE];
    char ctickTypeChangedEvent[RINGQT_EVENT_SIZE];


    GValueAxis(QObject * parent,VM *pVM );

    ~GValueAxis();

    void geteventparameters(void) ;

    void setlabelFormatChangedEvent(const char *cStr);
    void setmaxChangedEvent(const char *cStr);
    void setminChangedEvent(const char *cStr);
    void setminorTickCountChangedEvent(const char *cStr);
    void setrangeChangedEvent(const char *cStr);
    void settickAnchorChangedEvent(const char *cStr);
    void settickCountChangedEvent(const char *cStr);
    void settickIntervalChangedEvent(const char *cStr);
    void settickTypeChangedEvent(const char *cStr);


    const char *getlabelFormatChangedEvent(void);
    const char *getmaxChangedEvent(void);
    const char *getminChangedEvent(void);
    const char *getminorTickCountChangedEvent(void);
    const char *getrangeChangedEvent(void);
    const char *gettickAnchorChangedEvent(void);
    const char *gettickCountChangedEvent(void);
    const char *gettickIntervalChangedEvent(void);
    const char *gettickTypeChangedEvent(void);


  public slots:

    void labelFormatChangedSlot();
    void maxChangedSlot();
    void minChangedSlot();
    void minorTickCountChangedSlot();
    void rangeChangedSlot();
    void tickAnchorChangedSlot();
    void tickCountChangedSlot();
    void tickIntervalChangedSlot();
    void tickTypeChangedSlot();



};

#endif

