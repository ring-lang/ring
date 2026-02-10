
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSTACKEDLAYOUT_H
#define GSTACKEDLAYOUT_H
#include "ringqt.h"
#include <QStackedLayout>

extern "C" {
#include "ring.h"
}

class GStackedLayout : public QStackedLayout
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccurrentChangedEvent[RINGQT_EVENT_SIZE];
    char cwidgetRemovedEvent[RINGQT_EVENT_SIZE];


    GStackedLayout(QWidget *parent,VM *pVM );

    ~GStackedLayout();

    void geteventparameters(void) ;

    void setcurrentChangedEvent(const char *cStr);
    void setwidgetRemovedEvent(const char *cStr);


    const char *getcurrentChangedEvent(void);
    const char *getwidgetRemovedEvent(void);


  public slots:

    void currentChangedSlot();
    void widgetRemovedSlot();



};

#endif

