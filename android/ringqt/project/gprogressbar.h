
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    List *pParaList;

    char cvalueChangedEvent[100];


    GProgressBar(QWidget *parent,VM *pVM );

    ~GProgressBar();

    void geteventparameters(void) ;

    void setvalueChangedEvent(const char *cStr);


    const char *getvalueChangedEvent(void);


  public slots:

    void valueChangedSlot();

};

#endif

