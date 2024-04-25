
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GRADIOBUTTON_H
#define GRADIOBUTTON_H
#include "ringqt.h"
#include <QRadioButton>
extern "C" {
#include "ring.h"
}

class GRadioButton : public QRadioButton
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cclickedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];
    char ctoggledEvent[RINGQT_EVENT_SIZE];


    GRadioButton(QWidget *parent,VM *pVM );

    ~GRadioButton();

    void geteventparameters(void) ;

    void setclickedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);
    void settoggledEvent(const char *cStr);


    const char *getclickedEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);
    const char *gettoggledEvent(void);


  public slots:

    void clickedSlot();
    void pressedSlot();
    void releasedSlot();
    void toggledSlot();

};

#endif

