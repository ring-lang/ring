
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTIMER_H
#define GTIMER_H
#include "ringqt.h"
#include <QTimer>
extern "C" {
#include "ring.h"
}

class GTimer : public QTimer
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ctimeoutEvent[RINGQT_EVENT_SIZE];


    GTimer(QObject *parent,VM *pVM );

    ~GTimer();

    void geteventparameters(void) ;

    void settimeoutEvent(const char *cStr);


    const char *gettimeoutEvent(void);


  public slots:

    void timeoutSlot();

};

#endif

