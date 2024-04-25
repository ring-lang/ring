
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGRAPHICSEFFECT_H
#define GGRAPHICSEFFECT_H
#include "ringqt.h"
#include <QGraphicsEffect>
extern "C" {
#include "ring.h"
}

class GGraphicsEffect : public QGraphicsEffect
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cenabledChangedEvent[RINGQT_EVENT_SIZE];


    GGraphicsEffect(QObject * parent,VM *pVM );

    ~GGraphicsEffect();

    void geteventparameters(void) ;

    void setenabledChangedEvent(const char *cStr);


    const char *getenabledChangedEvent(void);


  public slots:

    void enabledChangedSlot();

};

#endif

