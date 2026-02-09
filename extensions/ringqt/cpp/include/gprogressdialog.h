
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPROGRESSDIALOG_H
#define GPROGRESSDIALOG_H
#include "ringqt.h"
#include <QProgressDialog>

extern "C" {
#include "ring.h"
}

class GProgressDialog : public QProgressDialog
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccanceledEvent[RINGQT_EVENT_SIZE];


    GProgressDialog(QWidget *parent,VM *pVM );

    ~GProgressDialog();

    void geteventparameters(void) ;

    void setcanceledEvent(const char *cStr);


    const char *getcanceledEvent(void);


  public slots:

    void canceledSlot();



};

#endif

