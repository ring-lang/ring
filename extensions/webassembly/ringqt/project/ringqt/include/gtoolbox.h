
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTOOLBOX_H
#define GTOOLBOX_H
#include "ringqt.h"
#include <QToolBox>

extern "C" {
#include "ring.h"
}

class GToolBox : public QToolBox
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccurrentChangedEvent[RINGQT_EVENT_SIZE];


    GToolBox(QWidget *parent,VM *pVM );

    ~GToolBox();

    void geteventparameters(void) ;

    void setcurrentChangedEvent(const char *cStr);


    const char *getcurrentChangedEvent(void);


  public slots:

    void currentChangedSlot();



};

#endif

