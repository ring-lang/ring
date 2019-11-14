
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GOBJECTPICKER_H
#define GOBJECTPICKER_H
#include <QApplication>
#include <Qt3DRender/QObjectPicker>
extern "C" {
#include "ring.h"
}

class GObjectPicker : public Qt3DRender::QObjectPicker
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cclickedEvent[200];
    char ccontainsMouseChangedEvent[200];
    char cdragEnabledChangedEvent[200];
    char centeredEvent[200];
    char cexitedEvent[200];
    char choverEnabledChangedEvent[200];
    char cmovedEvent[200];
    char cpressedEvent[200];
    char cpressedChangedEvent[200];
    char creleasedEvent[200];


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

