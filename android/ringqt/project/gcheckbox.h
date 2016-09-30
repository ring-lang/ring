
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    char cstateChangedEvent[100];
    char cclickedEvent[100];
    char cpressedEvent[100];
    char creleasedEvent[100];
    char ctoggledEvent[100];


    GCheckBox(QWidget *parent,VM *pVM );

    void setstateChangedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);
    void settoggledEvent(const char *cStr);


  public slots:

    void stateChangedSlot();
    void clickedSlot();
    void pressedSlot();
    void releasedSlot();
    void toggledSlot();

};

#endif

