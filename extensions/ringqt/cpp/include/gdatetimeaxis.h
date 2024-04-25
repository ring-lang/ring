
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GDATETIMEAXIS_H
#define GDATETIMEAXIS_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GDateTimeAxis : public QtCharts::QDateTimeAxis
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cformatChangedEvent[RINGQT_EVENT_SIZE];
    char cmaxChangedEvent[RINGQT_EVENT_SIZE];
    char cminChangedEvent[RINGQT_EVENT_SIZE];
    char crangeChangedEvent[RINGQT_EVENT_SIZE];
    char ctickCountChangedEvent[RINGQT_EVENT_SIZE];


    GDateTimeAxis(QObject *parent,VM *pVM );

    ~GDateTimeAxis();

    void geteventparameters(void) ;

    void setformatChangedEvent(const char *cStr);
    void setmaxChangedEvent(const char *cStr);
    void setminChangedEvent(const char *cStr);
    void setrangeChangedEvent(const char *cStr);
    void settickCountChangedEvent(const char *cStr);


    const char *getformatChangedEvent(void);
    const char *getmaxChangedEvent(void);
    const char *getminChangedEvent(void);
    const char *getrangeChangedEvent(void);
    const char *gettickCountChangedEvent(void);


  public slots:

    void formatChangedSlot();
    void maxChangedSlot();
    void minChangedSlot();
    void rangeChangedSlot();
    void tickCountChangedSlot();

};

#endif

