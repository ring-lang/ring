
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTABBAR_H
#define GTABBAR_H
#include <QApplication>
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

    char ccurrentChangedEvent[200];
    char ctabCloseRequestedEvent[200];
    char ctabMovedEvent[200];


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

