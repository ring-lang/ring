
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPROGRESSBAR_H
#define GPROGRESSBAR_H
#include <QApplication>
#include <QProgressBar>
extern "C" {
#include "ring.h"
}

class GProgressBar : public QProgressBar
{

  Q_OBJECT

  public:

    VM *pVM;

    char cvalueChangedEvent[100];


    GProgressBar(QWidget *parent,VM *pVM );

    void setvalueChangedEvent(const char *cStr);


  public slots:

    void valueChangedSlot();

};

#endif

