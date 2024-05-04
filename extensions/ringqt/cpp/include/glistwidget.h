
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GLISTWIDGET_H
#define GLISTWIDGET_H
#include "ringqt.h"
#include <QListWidget>

extern "C" {
#include "ring.h"
}

class GListWidget : public QListWidget
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccurrentItemChangedEvent[RINGQT_EVENT_SIZE];
    char ccurrentRowChangedEvent[RINGQT_EVENT_SIZE];
    char ccurrentTextChangedEvent[RINGQT_EVENT_SIZE];
    char citemActivatedEvent[RINGQT_EVENT_SIZE];
    char citemChangedEvent[RINGQT_EVENT_SIZE];
    char citemClickedEvent[RINGQT_EVENT_SIZE];
    char citemDoubleClickedEvent[RINGQT_EVENT_SIZE];
    char citemEnteredEvent[RINGQT_EVENT_SIZE];
    char citemPressedEvent[RINGQT_EVENT_SIZE];
    char citemSelectionChangedEvent[RINGQT_EVENT_SIZE];


    GListWidget(QWidget *parent,VM *pVM );

    ~GListWidget();

    void geteventparameters(void) ;

    void setcurrentItemChangedEvent(const char *cStr);
    void setcurrentRowChangedEvent(const char *cStr);
    void setcurrentTextChangedEvent(const char *cStr);
    void setitemActivatedEvent(const char *cStr);
    void setitemChangedEvent(const char *cStr);
    void setitemClickedEvent(const char *cStr);
    void setitemDoubleClickedEvent(const char *cStr);
    void setitemEnteredEvent(const char *cStr);
    void setitemPressedEvent(const char *cStr);
    void setitemSelectionChangedEvent(const char *cStr);


    const char *getcurrentItemChangedEvent(void);
    const char *getcurrentRowChangedEvent(void);
    const char *getcurrentTextChangedEvent(void);
    const char *getitemActivatedEvent(void);
    const char *getitemChangedEvent(void);
    const char *getitemClickedEvent(void);
    const char *getitemDoubleClickedEvent(void);
    const char *getitemEnteredEvent(void);
    const char *getitemPressedEvent(void);
    const char *getitemSelectionChangedEvent(void);


  public slots:

    void currentItemChangedSlot();
    void currentRowChangedSlot();
    void currentTextChangedSlot();
    void itemActivatedSlot();
    void itemChangedSlot();
    void itemClickedSlot();
    void itemDoubleClickedSlot();
    void itemEnteredSlot();
    void itemPressedSlot();
    void itemSelectionChangedSlot();



};

#endif

