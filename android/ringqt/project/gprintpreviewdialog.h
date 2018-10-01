
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPRINTPREVIEWDIALOG_H
#define GPRINTPREVIEWDIALOG_H
#include <QApplication>
#include <QPrintPreviewDialog>
extern "C" {
#include "ring.h"
}

class GPrintPreviewDialog : public QPrintPreviewDialog
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cpaintRequestedEvent[100];


    GPrintPreviewDialog(QPrinter *parent,VM *pVM );

    ~GPrintPreviewDialog();

    void geteventparameters(void) ;

    void setpaintRequestedEvent(const char *cStr);


    const char *getpaintRequestedEvent(void);


  public slots:

    void paintRequestedSlot();

};

#endif

