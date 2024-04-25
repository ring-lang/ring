
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTABLEWIDGET_H
#define GTABLEWIDGET_H
#include "ringqt.h"
#include <QTableWidget>
extern "C" {
#include "ring.h"
}

class GTableWidget : public QTableWidget
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccellActivatedEvent[RINGQT_EVENT_SIZE];
    char ccellChangedEvent[RINGQT_EVENT_SIZE];
    char ccellClickedEvent[RINGQT_EVENT_SIZE];
    char ccellDoubleClickedEvent[RINGQT_EVENT_SIZE];
    char ccellEnteredEvent[RINGQT_EVENT_SIZE];
    char ccellPressedEvent[RINGQT_EVENT_SIZE];
    char ccurrentCellChangedEvent[RINGQT_EVENT_SIZE];
    char ccurrentItemChangedEvent[RINGQT_EVENT_SIZE];
    char citemActivatedEvent[RINGQT_EVENT_SIZE];
    char citemChangedEvent[RINGQT_EVENT_SIZE];
    char citemClickedEvent[RINGQT_EVENT_SIZE];
    char citemDoubleClickedEvent[RINGQT_EVENT_SIZE];
    char citemEnteredEvent[RINGQT_EVENT_SIZE];
    char citemPressedEvent[RINGQT_EVENT_SIZE];
    char citemSelectionChangedEvent[RINGQT_EVENT_SIZE];


    GTableWidget(QWidget *parent,VM *pVM );

    ~GTableWidget();

    void geteventparameters(void) ;

    void setcellActivatedEvent(const char *cStr);
    void setcellChangedEvent(const char *cStr);
    void setcellClickedEvent(const char *cStr);
    void setcellDoubleClickedEvent(const char *cStr);
    void setcellEnteredEvent(const char *cStr);
    void setcellPressedEvent(const char *cStr);
    void setcurrentCellChangedEvent(const char *cStr);
    void setcurrentItemChangedEvent(const char *cStr);
    void setitemActivatedEvent(const char *cStr);
    void setitemChangedEvent(const char *cStr);
    void setitemClickedEvent(const char *cStr);
    void setitemDoubleClickedEvent(const char *cStr);
    void setitemEnteredEvent(const char *cStr);
    void setitemPressedEvent(const char *cStr);
    void setitemSelectionChangedEvent(const char *cStr);


    const char *getcellActivatedEvent(void);
    const char *getcellChangedEvent(void);
    const char *getcellClickedEvent(void);
    const char *getcellDoubleClickedEvent(void);
    const char *getcellEnteredEvent(void);
    const char *getcellPressedEvent(void);
    const char *getcurrentCellChangedEvent(void);
    const char *getcurrentItemChangedEvent(void);
    const char *getitemActivatedEvent(void);
    const char *getitemChangedEvent(void);
    const char *getitemClickedEvent(void);
    const char *getitemDoubleClickedEvent(void);
    const char *getitemEnteredEvent(void);
    const char *getitemPressedEvent(void);
    const char *getitemSelectionChangedEvent(void);


  public slots:

    void cellActivatedSlot();
    void cellChangedSlot();
    void cellClickedSlot();
    void cellDoubleClickedSlot();
    void cellEnteredSlot();
    void cellPressedSlot();
    void currentCellChangedSlot();
    void currentItemChangedSlot();
    void itemActivatedSlot();
    void itemChangedSlot();
    void itemClickedSlot();
    void itemDoubleClickedSlot();
    void itemEnteredSlot();
    void itemPressedSlot();
    void itemSelectionChangedSlot();

};

#endif

