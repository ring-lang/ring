
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTABBAR_H
#define GTABBAR_H
#include <QApplication>
#include "ringqt.h"
#include <QTabBar>
extern "C" {
#include "ring.h"
}

class GTabBar : public QTabBar
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ccurrentChangedEvent[RINGQT_EVENT_SIZE];
    char ctabCloseRequestedEvent[RINGQT_EVENT_SIZE];
    char ctabMovedEvent[RINGQT_EVENT_SIZE];


    GTabBar(QWidget *parent,VM *pVM );

    ~GTabBar();

    void geteventparameters(void) ;

    void setcurrentChangedEvent(const char *cStr);
    void settabCloseRequestedEvent(const char *cStr);
    void settabMovedEvent(const char *cStr);


    const char *getcurrentChangedEvent(void);
    const char *gettabCloseRequestedEvent(void);
    const char *gettabMovedEvent(void);


  public slots:

    void currentChangedSlot();
    void tabCloseRequestedSlot();
    void tabMovedSlot();

};

#endif

