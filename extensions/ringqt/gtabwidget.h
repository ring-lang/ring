
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTABWIDGET_H
#define GTABWIDGET_H
#include <QApplication>
#include <QTabWidget>
extern "C" {
#include "ring.h"
}

class GTabWidget : public QTabWidget
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ccurrentChangedEvent[100];
    char ctabCloseRequestedEvent[100];


    GTabWidget(QWidget *parent,VM *pVM );

    ~GTabWidget();

    void geteventparameters(void) ;

    void setcurrentChangedEvent(const char *cStr);
    void settabCloseRequestedEvent(const char *cStr);


    const char *getcurrentChangedEvent(void);
    const char *gettabCloseRequestedEvent(void);


  public slots:

    void currentChangedSlot();
    void tabCloseRequestedSlot();

};

#endif

