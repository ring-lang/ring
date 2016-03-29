
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPUSHBUTTON_H
#define GPUSHBUTTON_H
#include <QApplication>
#include <QPushButton>
extern "C" {
#include "ring.h"
}

class GPushButton : public QPushButton
{

  Q_OBJECT

  public:

    VM *pVM;

    char cClickEvent[100];


    GPushButton(QWidget *parent,VM *pVM );

    void setClickEvent(const char *cStr);


  public slots:

    void clickedSlot();

};

#endif

