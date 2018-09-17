
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPRINTPREVIEWWIDGET_H
#define GPRINTPREVIEWWIDGET_H
#include <QApplication>
#include <QPrintPreviewWidget>
extern "C" {
#include "ring.h"
}

class GPrintPreviewWidget : public QPrintPreviewWidget
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cpaintRequestedEvent[100];
    char cpreviewChangedEvent[100];


    GPrintPreviewWidget(QPrinter *parent,VM *pVM );

    ~GPrintPreviewWidget();

    void geteventparameters(void) ;

    void setpaintRequestedEvent(const char *cStr);
    void setpreviewChangedEvent(const char *cStr);


    const char *getpaintRequestedEvent(void);
    const char *getpreviewChangedEvent(void);


  public slots:

    void paintRequestedSlot();
    void previewChangedSlot();

};

#endif

