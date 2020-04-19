
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSPINBOX_H
#define GSPINBOX_H
#include <QApplication>
#include "ringqt.h"
#include <QSpinBox>
extern "C" {
#include "ring.h"
}

class GSpinBox : public QSpinBox
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cvalueChangedEvent[RINGQT_EVENT_SIZE];


    GSpinBox(QWidget *parent,VM *pVM );

    ~GSpinBox();

    void geteventparameters(void) ;

    void setvalueChangedEvent(const char *cStr);


    const char *getvalueChangedEvent(void);


  public slots:

    void valueChangedSlot();

};

#endif

