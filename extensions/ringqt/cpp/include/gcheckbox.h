
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCHECKBOX_H
#define GCHECKBOX_H
#include "ringqt.h"
#include <QCheckBox>

extern "C" {
#include "ring.h"
}

class GCheckBox : public QCheckBox
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cstateChangedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];
    char ctoggledEvent[RINGQT_EVENT_SIZE];


    GCheckBox(QWidget *parent,VM *pVM );

    ~GCheckBox();

    void geteventparameters(void) ;

    void setstateChangedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);
    void settoggledEvent(const char *cStr);


    const char *getstateChangedEvent(void);
    const char *getclickedEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);
    const char *gettoggledEvent(void);


  public slots:

    void stateChangedSlot();
    void clickedSlot();
    void pressedSlot();
    void releasedSlot();
    void toggledSlot();



};

#endif

