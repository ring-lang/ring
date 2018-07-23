
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GLISTWIDGET_H
#define GLISTWIDGET_H
#include <QApplication>
#include <QListWidget>
extern "C" {
#include "ring.h"
}

class GListWidget : public QListWidget
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ccurrentItemChangedEvent[100];
    char ccurrentRowChangedEvent[100];
    char ccurrentTextChangedEvent[100];
    char citemActivatedEvent[100];
    char citemChangedEvent[100];
    char citemClickedEvent[100];
    char citemDoubleClickedEvent[100];
    char citemEnteredEvent[100];
    char citemPressedEvent[100];
    char citemSelectionChangedEvent[100];


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

