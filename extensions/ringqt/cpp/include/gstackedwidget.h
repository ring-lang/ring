
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSTACKEDWIDGET_H
#define GSTACKEDWIDGET_H
#include "ringqt.h"
#include <QStackedWidget>

extern "C" {
#include "ring.h"
}

class GStackedWidget : public QStackedWidget
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccurrentChangedEvent[RINGQT_EVENT_SIZE];
    char cwidgetRemovedEvent[RINGQT_EVENT_SIZE];


    GStackedWidget(QWidget *parent,VM *pVM );

    ~GStackedWidget();

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

