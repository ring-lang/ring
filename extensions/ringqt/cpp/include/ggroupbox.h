
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGROUPBOX_H
#define GGROUPBOX_H
#include "ringqt.h"
#include <QGroupBox>

extern "C" {
#include "ring.h"
}

class GGroupBox : public QGroupBox
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ctoggledEvent[RINGQT_EVENT_SIZE];


    GGroupBox(QWidget * parent,VM *pVM );

    ~GGroupBox();

    void geteventparameters(void) ;

    void setclickedEvent(const char *cStr);
    void settoggledEvent(const char *cStr);


    const char *getclickedEvent(void);
    const char *gettoggledEvent(void);


  public slots:

    void clickedSlot();
    void toggledSlot();



};

#endif

