
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GLOGVALUEAXIS_H
#define GLOGVALUEAXIS_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GLogValueAxis : public QtCharts::QLogValueAxis
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cbaseChangedEvent[RINGQT_EVENT_SIZE];
    char clabelFormatChangedEvent[RINGQT_EVENT_SIZE];
    char cmaxChangedEvent[RINGQT_EVENT_SIZE];
    char cminChangedEvent[RINGQT_EVENT_SIZE];
    char cminorTickCountChangedEvent[RINGQT_EVENT_SIZE];
    char crangeChangedEvent[RINGQT_EVENT_SIZE];
    char ctickCountChangedEvent[RINGQT_EVENT_SIZE];


    GLogValueAxis(QObject *parent,VM *pVM );

    ~GLogValueAxis();

    void geteventparameters(void) ;

    void setbaseChangedEvent(const char *cStr);
    void setlabelFormatChangedEvent(const char *cStr);
    void setmaxChangedEvent(const char *cStr);
    void setminChangedEvent(const char *cStr);
    void setminorTickCountChangedEvent(const char *cStr);
    void setrangeChangedEvent(const char *cStr);
    void settickCountChangedEvent(const char *cStr);


    const char *getbaseChangedEvent(void);
    const char *getlabelFormatChangedEvent(void);
    const char *getmaxChangedEvent(void);
    const char *getminChangedEvent(void);
    const char *getminorTickCountChangedEvent(void);
    const char *getrangeChangedEvent(void);
    const char *gettickCountChangedEvent(void);


  public slots:

    void baseChangedSlot();
    void labelFormatChangedSlot();
    void maxChangedSlot();
    void minChangedSlot();
    void minorTickCountChangedSlot();
    void rangeChangedSlot();
    void tickCountChangedSlot();

};

#endif

