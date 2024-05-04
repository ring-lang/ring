
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGRAPHICSSCENE_H
#define GGRAPHICSSCENE_H
#include "ringqt.h"
#include <QtWidgets>

extern "C" {
#include "ring.h"
}

class GGraphicsScene : public QGraphicsScene
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cchangedEvent[RINGQT_EVENT_SIZE];
    char cfocusItemChangedEvent[RINGQT_EVENT_SIZE];
    char csceneRectChangedEvent[RINGQT_EVENT_SIZE];
    char cselectionChangedEvent[RINGQT_EVENT_SIZE];


    GGraphicsScene(QObject * parent,VM *pVM );

    ~GGraphicsScene();

    void geteventparameters(void) ;

    void setchangedEvent(const char *cStr);
    void setfocusItemChangedEvent(const char *cStr);
    void setsceneRectChangedEvent(const char *cStr);
    void setselectionChangedEvent(const char *cStr);


    const char *getchangedEvent(void);
    const char *getfocusItemChangedEvent(void);
    const char *getsceneRectChangedEvent(void);
    const char *getselectionChangedEvent(void);


  public slots:

    void changedSlot();
    void focusItemChangedSlot();
    void sceneRectChangedSlot();
    void selectionChangedSlot();



};

#endif

