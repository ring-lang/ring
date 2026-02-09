
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCOLUMNVIEW_H
#define GCOLUMNVIEW_H
#include "ringqt.h"
#include <QColumnView>

extern "C" {
#include "ring.h"
}

class GColumnView : public QColumnView
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cupdatePreviewWidgetEvent[RINGQT_EVENT_SIZE];


    GColumnView(QWidget *parent,VM *pVM );

    ~GColumnView();

    void geteventparameters(void) ;

    void setupdatePreviewWidgetEvent(const char *cStr);


    const char *getupdatePreviewWidgetEvent(void);


  public slots:

    void updatePreviewWidgetSlot();



};

#endif

