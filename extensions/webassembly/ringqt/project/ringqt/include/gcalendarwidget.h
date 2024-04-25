
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCALENDARWIDGET_H
#define GCALENDARWIDGET_H
#include "ringqt.h"
#include <QCalendarWidget>
extern "C" {
#include "ring.h"
}

class GCalendarWidget : public QCalendarWidget
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cactivatedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ccurrentPageChangedEvent[RINGQT_EVENT_SIZE];
    char cselectionChangedEvent[RINGQT_EVENT_SIZE];


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

