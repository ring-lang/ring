
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTABLEWIDGET_H
#define GTABLEWIDGET_H
#include <QApplication>
#include <QTableWidget>
extern "C" {
#include "ring.h"
}

class GTableWidget : public QTableWidget
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ccellActivatedEvent[200];
    char ccellChangedEvent[200];
    char ccellClickedEvent[200];
    char ccellDoubleClickedEvent[200];
    char ccellEnteredEvent[200];
    char ccellPressedEvent[200];
    char ccurrentCellChangedEvent[200];
    char ccurrentItemChangedEvent[200];
    char citemActivatedEvent[200];
    char citemChangedEvent[200];
    char citemClickedEvent[200];
    char citemDoubleClickedEvent[200];
    char citemEnteredEvent[200];
    char citemPressedEvent[200];
    char citemSelectionChangedEvent[200];


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

