
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GDOUBLESPINBOX_H
#define GDOUBLESPINBOX_H
#include "ringqt.h"
#include <QDoubleSpinBox>

extern "C" {
#include "ring.h"
}

class GDoubleSpinBox : public QDoubleSpinBox
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cvalueChangedEvent[RINGQT_EVENT_SIZE];


    GDoubleSpinBox(QWidget *parent,VM *pVM );

    ~GDoubleSpinBox();

    void geteventparameters(void) ;

    void setvalueChangedEvent(const char *cStr);


    const char *getvalueChangedEvent(void);


  public slots:

    void valueChangedSlot();



};

#endif

