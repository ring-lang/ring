
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPRINTPREVIEWWIDGET_H
#define GPRINTPREVIEWWIDGET_H
#include "ringqt.h"
#include <QPrintPreviewWidget>

extern "C" {
#include "ring.h"
}

class GPrintPreviewWidget : public QPrintPreviewWidget
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cpaintRequestedEvent[RINGQT_EVENT_SIZE];
    char cpreviewChangedEvent[RINGQT_EVENT_SIZE];


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

