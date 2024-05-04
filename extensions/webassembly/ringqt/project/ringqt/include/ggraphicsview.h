
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGRAPHICSVIEW_H
#define GGRAPHICSVIEW_H
#include "ringqt.h"
#include <QGraphicsView>

extern "C" {
#include "ring.h"
}

class GGraphicsView : public QGraphicsView
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char crubberBandChangedEvent[RINGQT_EVENT_SIZE];


    GGraphicsView(QWidget * parent,VM *pVM );

    ~GGraphicsView();

    void geteventparameters(void) ;

    void setrubberBandChangedEvent(const char *cStr);


    const char *getrubberBandChangedEvent(void);


  public slots:

    void rubberBandChangedSlot();



};

#endif

