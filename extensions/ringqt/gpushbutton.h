
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    List *pParaList;

    char cClickEvent[100];


    GPushButton(QWidget *parent,VM *pVM );

    ~GPushButton();

    void geteventparameters(void) ;

    void setClickEvent(const char *cStr);


    const char *getClickEvent(void);


  public slots:

    void clickedSlot();

};

#endif

