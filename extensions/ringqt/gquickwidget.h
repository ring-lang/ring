
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GQUICKWIDGET_H
#define GQUICKWIDGET_H
#include <QApplication>
#include <QQuickWidget>
extern "C" {
#include "ring.h"
}

class GQuickWidget : public QQuickWidget
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char csceneGraphErrorEvent[100];
    char cstatusChangedEvent[100];


    GQuickWidget(QWidget *parent,VM *pVM );

    ~GQuickWidget();

    void geteventparameters(void) ;

    void setsceneGraphErrorEvent(const char *cStr);
    void setstatusChangedEvent(const char *cStr);


    const char *getsceneGraphErrorEvent(void);
    const char *getstatusChangedEvent(void);


  public slots:

    void sceneGraphErrorSlot();
    void statusChangedSlot();

};

#endif

