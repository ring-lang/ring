
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCOMBOBOX_H
#define GCOMBOBOX_H
#include "ringqt.h"
#include <QComboBox>

extern "C" {
#include "ring.h"
}

class GComboBox : public QComboBox
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cactivatedEvent[RINGQT_EVENT_SIZE];
    char ccurrentIndexChangedEvent[RINGQT_EVENT_SIZE];
    char ceditTextChangedEvent[RINGQT_EVENT_SIZE];
    char chighlightedEvent[RINGQT_EVENT_SIZE];


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

