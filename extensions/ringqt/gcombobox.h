
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCOMBOBOX_H
#define GCOMBOBOX_H
#include <QApplication>
#include <QComboBox>
extern "C" {
#include "ring.h"
}

class GComboBox : public QComboBox
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cactivatedEvent[100];
    char ccurrentIndexChangedEvent[100];
    char ceditTextChangedEvent[100];
    char chighlightedEvent[100];


    GComboBox(QWidget *parent,VM *pVM );

    ~GComboBox();

    void geteventparameters(void) ;

    void setactivatedEvent(const char *cStr);
    void setcurrentIndexChangedEvent(const char *cStr);
    void seteditTextChangedEvent(const char *cStr);
    void sethighlightedEvent(const char *cStr);


    const char *getactivatedEvent(void);
    const char *getcurrentIndexChangedEvent(void);
    const char *geteditTextChangedEvent(void);
    const char *gethighlightedEvent(void);


  public slots:

    void activatedSlot();
    void currentIndexChangedSlot();
    void editTextChangedSlot();
    void highlightedSlot();

};

#endif

