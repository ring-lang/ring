
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGRAPHICSWIDGET_H
#define GGRAPHICSWIDGET_H
#include "ringqt.h"
#include <QGraphicsWidget>
extern "C" {
#include "ring.h"
}

class GGraphicsWidget : public QGraphicsWidget
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cgeometryChangedEvent[RINGQT_EVENT_SIZE];
    char clayoutChangedEvent[RINGQT_EVENT_SIZE];


    GGraphicsWidget(QGraphicsItem *x,Qt::WindowFlags parent,VM *pVM );

    ~GGraphicsWidget();

    void geteventparameters(void) ;

    void setgeometryChangedEvent(const char *cStr);
    void setlayoutChangedEvent(const char *cStr);


    const char *getgeometryChangedEvent(void);
    const char *getlayoutChangedEvent(void);


  public slots:

    void geometryChangedSlot();
    void layoutChangedSlot();

};

#endif

