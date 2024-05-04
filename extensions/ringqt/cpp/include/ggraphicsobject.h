
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGRAPHICSOBJECT_H
#define GGRAPHICSOBJECT_H
#include "ringqt.h"
#include <QGraphicsObject>

extern "C" {
#include "ring.h"
}

class GGraphicsObject : public QGraphicsObject
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cenabledChangedEvent[RINGQT_EVENT_SIZE];
    char copacityChangedEvent[RINGQT_EVENT_SIZE];
    char cparentChangedEvent[RINGQT_EVENT_SIZE];
    char crotationChangedEvent[RINGQT_EVENT_SIZE];
    char cscaleChangedEvent[RINGQT_EVENT_SIZE];
    char cvisibleChangedEvent[RINGQT_EVENT_SIZE];
    char cxChangedEvent[RINGQT_EVENT_SIZE];
    char cyChangedEvent[RINGQT_EVENT_SIZE];
    char czChangedEvent[RINGQT_EVENT_SIZE];


    GGraphicsObject(QGraphicsItem * parent,VM *pVM );

    ~GGraphicsObject();

    void geteventparameters(void) ;

    void setenabledChangedEvent(const char *cStr);
    void setopacityChangedEvent(const char *cStr);
    void setparentChangedEvent(const char *cStr);
    void setrotationChangedEvent(const char *cStr);
    void setscaleChangedEvent(const char *cStr);
    void setvisibleChangedEvent(const char *cStr);
    void setxChangedEvent(const char *cStr);
    void setyChangedEvent(const char *cStr);
    void setzChangedEvent(const char *cStr);


    const char *getenabledChangedEvent(void);
    const char *getopacityChangedEvent(void);
    const char *getparentChangedEvent(void);
    const char *getrotationChangedEvent(void);
    const char *getscaleChangedEvent(void);
    const char *getvisibleChangedEvent(void);
    const char *getxChangedEvent(void);
    const char *getyChangedEvent(void);
    const char *getzChangedEvent(void);


  public slots:

    void enabledChangedSlot();
    void opacityChangedSlot();
    void parentChangedSlot();
    void rotationChangedSlot();
    void scaleChangedSlot();
    void visibleChangedSlot();
    void xChangedSlot();
    void yChangedSlot();
    void zChangedSlot();



};

#endif

