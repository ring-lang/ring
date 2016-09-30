
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    char ccellActivatedEvent[100];
    char ccellChangedEvent[100];
    char ccellClickedEvent[100];
    char ccellDoubleClickedEvent[100];
    char ccellEnteredEvent[100];
    char ccellPressedEvent[100];
    char ccurrentCellChangedEvent[100];
    char ccurrentItemChangedEvent[100];
    char citemActivatedEvent[100];
    char citemChangedEvent[100];
    char citemClickedEvent[100];
    char citemDoubleClickedEvent[100];
    char citemEnteredEvent[100];
    char citemPressedEvent[100];
    char citemSelectionChangedEvent[100];


    GTableWidget(QWidget *parent,VM *pVM );

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

