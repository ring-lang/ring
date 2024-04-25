
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GACTION_H
#define GACTION_H
#include "ringqt.h"
#include <QAction>
extern "C" {
#include "ring.h"
}

class GAction : public QAction
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cClickEvent[RINGQT_EVENT_SIZE];


    GAction(QWidget *parent,VM *pVM );

    ~GAction();

    void geteventparameters(void) ;

    void setClickEvent(const char *cStr);


    const char *getClickEvent(void);


  public slots:

    void clickedSlot();

};

#endif

