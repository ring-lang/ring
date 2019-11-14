
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCALENDARWIDGET_H
#define GCALENDARWIDGET_H
#include <QApplication>
#include <QCalendarWidget>
extern "C" {
#include "ring.h"
}

class GCalendarWidget : public QCalendarWidget
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cactivatedEvent[200];
    char cclickedEvent[200];
    char ccurrentPageChangedEvent[200];
    char cselectionChangedEvent[200];


    GCalendarWidget(QWidget *parent,VM *pVM );

    ~GCalendarWidget();

    void geteventparameters(void) ;

    void setactivatedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setcurrentPageChangedEvent(const char *cStr);
    void setselectionChangedEvent(const char *cStr);


    const char *getactivatedEvent(void);
    const char *getclickedEvent(void);
    const char *getcurrentPageChangedEvent(void);
    const char *getselectionChangedEvent(void);


  public slots:

    void activatedSlot();
    void clickedSlot();
    void currentPageChangedSlot();
    void selectionChangedSlot();

};

#endif

