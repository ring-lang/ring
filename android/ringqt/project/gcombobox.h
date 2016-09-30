
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    char cactivatedEvent[100];
    char ccurrentIndexChangedEvent[100];
    char ceditTextChangedEvent[100];
    char chighlightedEvent[100];


    GComboBox(QWidget *parent,VM *pVM );

    void setactivatedEvent(const char *cStr);
    void setcurrentIndexChangedEvent(const char *cStr);
    void seteditTextChangedEvent(const char *cStr);
    void sethighlightedEvent(const char *cStr);


  public slots:

    void activatedSlot();
    void currentIndexChangedSlot();
    void editTextChangedSlot();
    void highlightedSlot();

};

#endif

