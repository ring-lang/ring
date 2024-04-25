
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTREEVIEW_H
#define GTREEVIEW_H
#include "ringqt.h"
#include <QTreeView>
extern "C" {
#include "ring.h"
}

class GTreeView : public QTreeView
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccollapsedEvent[RINGQT_EVENT_SIZE];
    char cexpandedEvent[RINGQT_EVENT_SIZE];
    char cactivatedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char centeredEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char cviewportEnteredEvent[RINGQT_EVENT_SIZE];


    GTreeView(QWidget *parent,VM *pVM );

    ~GTreeView();

    void geteventparameters(void) ;

    void setcollapsedEvent(const char *cStr);
    void setexpandedEvent(const char *cStr);
    void setactivatedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void setenteredEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setviewportEnteredEvent(const char *cStr);


    const char *getcollapsedEvent(void);
    const char *getexpandedEvent(void);
    const char *getactivatedEvent(void);
    const char *getclickedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *getenteredEvent(void);
    const char *getpressedEvent(void);
    const char *getviewportEnteredEvent(void);


  public slots:

    void collapsedSlot();
    void expandedSlot();
    void activatedSlot();
    void clickedSlot();
    void doubleClickedSlot();
    void enteredSlot();
    void pressedSlot();
    void viewportEnteredSlot();

};

#endif

