
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GVIDEOWIDGET_H
#define GVIDEOWIDGET_H
#include "ringqt.h"
#include <QVideoWidget>

extern "C" {
#include "ring.h"
}

class GVideoWidget : public QVideoWidget
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cfullScreenChangedEvent[RINGQT_EVENT_SIZE];


    GVideoWidget(QWidget *parent,VM *pVM );

    ~GVideoWidget();

    void geteventparameters(void) ;

    void setfullScreenChangedEvent(const char *cStr);


    const char *getfullScreenChangedEvent(void);


  public slots:

    void fullScreenChangedSlot();



};

#endif

