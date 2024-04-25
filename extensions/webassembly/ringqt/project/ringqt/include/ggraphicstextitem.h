
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGRAPHICSTEXTITEM_H
#define GGRAPHICSTEXTITEM_H
#include "ringqt.h"
#include <QGraphicsTextItem>
extern "C" {
#include "ring.h"
}

class GGraphicsTextItem : public QGraphicsTextItem
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char clinkActivatedEvent[RINGQT_EVENT_SIZE];
    char clinkHoveredEvent[RINGQT_EVENT_SIZE];


    GGraphicsTextItem(QGraphicsItem * parent,VM *pVM );

    ~GGraphicsTextItem();

    void geteventparameters(void) ;

    void setlinkActivatedEvent(const char *cStr);
    void setlinkHoveredEvent(const char *cStr);


    const char *getlinkActivatedEvent(void);
    const char *getlinkHoveredEvent(void);


  public slots:

    void linkActivatedSlot();
    void linkHoveredSlot();

};

#endif

