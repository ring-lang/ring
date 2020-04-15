
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPRINTDIALOG_H
#define GPRINTDIALOG_H
#include <QApplication>
#include "ringqt.h"
#include <QPrintDialog>
extern "C" {
#include "ring.h"
}

class GPrintDialog : public QPrintDialog
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

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

