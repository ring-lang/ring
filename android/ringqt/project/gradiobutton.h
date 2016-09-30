
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GRADIOBUTTON_H
#define GRADIOBUTTON_H
#include <QApplication>
#include <QRadioButton>
extern "C" {
#include "ring.h"
}

class GRadioButton : public QRadioButton
{

  Q_OBJECT

  public:

    VM *pVM;

    char cclickedEvent[100];
    char cpressedEvent[100];
    char creleasedEvent[100];
    char ctoggledEvent[100];


    GRadioButton(QWidget *parent,VM *pVM );

    void setclickedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);
    void settoggledEvent(const char *cStr);


  public slots:

    void clickedSlot();
    void pressedSlot();
    void releasedSlot();
    void toggledSlot();

};

#endif

