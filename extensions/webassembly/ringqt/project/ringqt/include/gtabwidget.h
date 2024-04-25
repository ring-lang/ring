
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTABWIDGET_H
#define GTABWIDGET_H
#include "ringqt.h"
#include <QTabWidget>
extern "C" {
#include "ring.h"
}

class GTabWidget : public QTabWidget
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccurrentChangedEvent[RINGQT_EVENT_SIZE];
    char ctabCloseRequestedEvent[RINGQT_EVENT_SIZE];


    GTabWidget(QWidget *parent,VM *pVM );

    ~GTabWidget();

    void geteventparameters(void) ;

    void setcurrentChangedEvent(const char *cStr);
    void settabCloseRequestedEvent(const char *cStr);


    const char *getcurrentChangedEvent(void);
    const char *gettabCloseRequestedEvent(void);


  public slots:

    void currentChangedSlot();
    void tabCloseRequestedSlot(int p1);

};

#endif

