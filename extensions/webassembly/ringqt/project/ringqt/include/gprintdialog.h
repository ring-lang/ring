
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPRINTDIALOG_H
#define GPRINTDIALOG_H
#include "ringqt.h"
#include <QPrintDialog>

extern "C" {
#include "ring.h"
}

class GPrintDialog : public QPrintDialog
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cacceptedEvent[RINGQT_EVENT_SIZE];


    GPrintDialog(QPrinter *,QWidget *parent,VM *pVM );

    ~GPrintDialog();

    void geteventparameters(void) ;

    void setacceptedEvent(const char *cStr);


    const char *getacceptedEvent(void);


  public slots:

    void acceptedSlot();



};

#endif

