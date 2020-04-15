
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPRINTPREVIEWDIALOG_H
#define GPRINTPREVIEWDIALOG_H
#include <QApplication>
#include "ringqt.h"
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

    char cpaintRequestedEvent[RINGQT_EVENT_SIZE];


    GPrintPreviewDialog(QPrinter *parent,VM *pVM );

    ~GPrintPreviewDialog();

    void geteventparameters(void) ;

    void setpaintRequestedEvent(const char *cStr);


    const char *getpaintRequestedEvent(void);


  public slots:

    void paintRequestedSlot();

};

#endif

