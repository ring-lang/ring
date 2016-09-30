
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTIMER_H
#define GTIMER_H
#include <QApplication>
#include <QTimer>
extern "C" {
#include "ring.h"
}

class GTimer : public QTimer
{

  Q_OBJECT

  public:

    VM *pVM;

    char ctimeoutEvent[100];


    GTimer(QObject *parent,VM *pVM );

    void settimeoutEvent(const char *cStr);


  public slots:

    void timeoutSlot();

};

#endif

