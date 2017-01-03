
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCHECKBOX_H
#define GCHECKBOX_H
#include <QApplication>
#include <QCheckBox>
extern "C" {
#include "ring.h"
}

class GCheckBox : public QCheckBox
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cstateChangedEvent[100];
    char cclickedEvent[100];
    char cpressedEvent[100];
    char creleasedEvent[100];
    char ctoggledEvent[100];


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

