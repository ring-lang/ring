
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCOLORDIALOG_H
#define GCOLORDIALOG_H
#include "ringqt.h"
#include <QColorDialog>
extern "C" {
#include "ring.h"
}

class GColorDialog : public QColorDialog
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccolorSelectedEvent[RINGQT_EVENT_SIZE];
    char ccurrentColorChangedEvent[RINGQT_EVENT_SIZE];


    GColorDialog(QWidget *parent,VM *pVM );

    ~GColorDialog();

    void geteventparameters(void) ;

    void setcolorSelectedEvent(const char *cStr);
    void setcurrentColorChangedEvent(const char *cStr);


    const char *getcolorSelectedEvent(void);
    const char *getcurrentColorChangedEvent(void);


  public slots:

    void colorSelectedSlot();
    void currentColorChangedSlot();

};

#endif

