
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTOOLBUTTON_H
#define GTOOLBUTTON_H
#include <QApplication>
#include <QToolButton>
extern "C" {
#include "ring.h"
}

class GToolButton : public QToolButton
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ctriggeredEvent[100];
    char cClickEvent[100];


    GToolButton(QWidget *parent,VM *pVM );

    ~GToolButton();

    void geteventparameters(void) ;

    void settriggeredEvent(const char *cStr);
    void setClickEvent(const char *cStr);


    const char *gettriggeredEvent(void);
    const char *getClickEvent(void);


  public slots:

    void triggeredSlot();
    void clickedSlot();

};

#endif

