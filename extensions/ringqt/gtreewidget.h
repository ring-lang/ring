
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTREEWIDGET_H
#define GTREEWIDGET_H
#include <QApplication>
#include <QTreeWidget>
extern "C" {
#include "ring.h"
}

class GTreeWidget : public QTreeWidget
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
    char ccurrentItemChangedEvent[100];
    char citemActivatedEvent[100];
    char citemChangedEvent[100];
    char citemClickedEvent[100];
    char citemCollapsedEvent[100];
    char citemDoubleClickedEvent[100];
    char citemEnteredEvent[100];
    char citemExpandedEvent[100];
    char citemPressedEvent[100];
    char citemSelectionChangedEvent[100];


    GTreeWidget(QWidget *parent,VM *pVM );

    void setcollapsedEvent(const char *cStr);
    void setexpandedEvent(const char *cStr);
    void setactivatedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void setenteredEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setviewportEnteredEvent(const char *cStr);
    void setcurrentItemChangedEvent(const char *cStr);
    void setitemActivatedEvent(const char *cStr);
    void setitemChangedEvent(const char *cStr);
    void setitemClickedEvent(const char *cStr);
    void setitemCollapsedEvent(const char *cStr);
    void setitemDoubleClickedEvent(const char *cStr);
    void setitemEnteredEvent(const char *cStr);
    void setitemExpandedEvent(const char *cStr);
    void setitemPressedEvent(const char *cStr);
    void setitemSelectionChangedEvent(const char *cStr);


  public slots:

    void collapsedSlot();
    void expandedSlot();
    void activatedSlot();
    void clickedSlot();
    void doubleClickedSlot();
    void enteredSlot();
    void pressedSlot();
    void viewportEnteredSlot();
    void currentItemChangedSlot();
    void itemActivatedSlot();
    void itemChangedSlot();
    void itemClickedSlot();
    void itemCollapsedSlot();
    void itemDoubleClickedSlot();
    void itemEnteredSlot();
    void itemExpandedSlot();
    void itemPressedSlot();
    void itemSelectionChangedSlot();

};

#endif

