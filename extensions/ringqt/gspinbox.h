
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSPINBOX_H
#define GSPINBOX_H
#include <QApplication>
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

    char cvalueChangedEvent[100];


    GSpinBox(QWidget *parent,VM *pVM );

    ~GSpinBox();

    void geteventparameters(void) ;

    void setvalueChangedEvent(const char *cStr);


    const char *getvalueChangedEvent(void);


  public slots:

    void valueChangedSlot();

};

#endif

