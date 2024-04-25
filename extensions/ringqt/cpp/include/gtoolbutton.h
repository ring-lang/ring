
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTOOLBUTTON_H
#define GTOOLBUTTON_H
#include "ringqt.h"
#include <QToolButton>
extern "C" {
#include "ring.h"
}

class GToolButton : public QToolButton
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ctriggeredEvent[RINGQT_EVENT_SIZE];
    char cClickEvent[RINGQT_EVENT_SIZE];


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

