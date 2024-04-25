
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPROGRESSBAR_H
#define GPROGRESSBAR_H
#include "ringqt.h"
#include <QProgressBar>
extern "C" {
#include "ring.h"
}

class GProgressBar : public QProgressBar
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cvalueChangedEvent[RINGQT_EVENT_SIZE];


    GProgressBar(QWidget *parent,VM *pVM );

    ~GProgressBar();

    void geteventparameters(void) ;

    void setvalueChangedEvent(const char *cStr);


    const char *getvalueChangedEvent(void);


  public slots:

    void valueChangedSlot();

};

#endif

