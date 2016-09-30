
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    char cvalueChangedEvent[100];


    GSpinBox(QWidget *parent,VM *pVM );

    void setvalueChangedEvent(const char *cStr);


  public slots:

    void valueChangedSlot();

};

#endif

