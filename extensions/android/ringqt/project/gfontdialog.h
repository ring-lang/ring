
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GFONTDIALOG_H
#define GFONTDIALOG_H
#include <QApplication>
#include "ringqt.h"
#include <QFontDialog>
extern "C" {
#include "ring.h"
}

class GFontDialog : public QFontDialog
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ccurrentFontChangedEvent[RINGQT_EVENT_SIZE];
    char cfontSelectedEvent[RINGQT_EVENT_SIZE];


    GFontDialog(QWidget * parent,VM *pVM );

    ~GFontDialog();

    void geteventparameters(void) ;

    void setcurrentFontChangedEvent(const char *cStr);
    void setfontSelectedEvent(const char *cStr);


    const char *getcurrentFontChangedEvent(void);
    const char *getfontSelectedEvent(void);


  public slots:

    void currentFontChangedSlot();
    void fontSelectedSlot();

};

#endif

