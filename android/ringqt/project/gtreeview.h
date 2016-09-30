
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTREEVIEW_H
#define GTREEVIEW_H
#include <QApplication>
#include <QTreeView>
extern "C" {
#include "ring.h"
}

class GTreeView : public QTreeView
{

  Q_OBJECT

  public:

    VM *pVM;

    char ccollapsedEvent[100];
    char cexpandedEvent[100];
    char cactivatedEvent[100];
    char cclickedEvent[100];
    char cdoubleClickedEvent[100];
    char centeredEvent[100];
    char cpressedEvent[100];
    char cviewportEnteredEvent[100];


    GTreeView(QWidget *parent,VM *pVM );

    void setcollapsedEvent(const char *cStr);
    void setexpandedEvent(const char *cStr);
    void setactivatedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void setenteredEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setviewportEnteredEvent(const char *cStr);


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

