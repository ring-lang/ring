
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GOBJECTPICKER_H
#define GOBJECTPICKER_H
#include "ringqt.h"
#include <Qt3DRender/QObjectPicker>
extern "C" {
#include "ring.h"
}

class GObjectPicker : public Qt3DRender::QObjectPicker
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ccontainsMouseChangedEvent[RINGQT_EVENT_SIZE];
    char cdragEnabledChangedEvent[RINGQT_EVENT_SIZE];
    char centeredEvent[RINGQT_EVENT_SIZE];
    char cexitedEvent[RINGQT_EVENT_SIZE];
    char choverEnabledChangedEvent[RINGQT_EVENT_SIZE];
    char cmovedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char cpressedChangedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];


    GObjectPicker(Qt3DCore::QNode *parent,VM *pVM );

    ~GObjectPicker();

    void geteventparameters(void) ;

    void setclickedEvent(const char *cStr);
    void setcontainsMouseChangedEvent(const char *cStr);
    void setdragEnabledChangedEvent(const char *cStr);
    void setenteredEvent(const char *cStr);
    void setexitedEvent(const char *cStr);
    void sethoverEnabledChangedEvent(const char *cStr);
    void setmovedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setpressedChangedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);


    const char *getclickedEvent(void);
    const char *getcontainsMouseChangedEvent(void);
    const char *getdragEnabledChangedEvent(void);
    const char *getenteredEvent(void);
    const char *getexitedEvent(void);
    const char *gethoverEnabledChangedEvent(void);
    const char *getmovedEvent(void);
    const char *getpressedEvent(void);
    const char *getpressedChangedEvent(void);
    const char *getreleasedEvent(void);


  public slots:

    void clickedSlot();
    void containsMouseChangedSlot();
    void dragEnabledChangedSlot();
    void enteredSlot();
    void exitedSlot();
    void hoverEnabledChangedSlot();
    void movedSlot();
    void pressedSlot();
    void pressedChangedSlot();
    void releasedSlot();

};

#endif

