
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    char ccolorSelectedEvent[100];
    char ccurrentColorChangedEvent[100];


    GColorDialog(QWidget *parent,VM *pVM );

    void setcolorSelectedEvent(const char *cStr);
    void setcurrentColorChangedEvent(const char *cStr);


  public slots:

    void colorSelectedSlot();
    void currentColorChangedSlot();

};

#endif

