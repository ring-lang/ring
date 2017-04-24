
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCOLORDIALOG_H
#define GCOLORDIALOG_H
#include <QApplication>
#include <QColorDialog>
extern "C" {
#include "ring.h"
}

class GColorDialog : public QColorDialog
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ccolorSelectedEvent[100];
    char ccurrentColorChangedEvent[100];


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

