
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPUSHBUTTON_H
#define GPUSHBUTTON_H
#include <QApplication>
#include "ringqt.h"
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

    char cClickEvent[RINGQT_EVENT_SIZE];


    GPushButton(QWidget *parent,VM *pVM );

    ~GPushButton();

    void geteventparameters(void) ;

    void setClickEvent(const char *cStr);


    const char *getClickEvent(void);


  public slots:

    void clickedSlot();

};

#endif

