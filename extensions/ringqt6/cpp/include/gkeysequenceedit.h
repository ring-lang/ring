
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GKEYSEQUENCEEDIT_H
#define GKEYSEQUENCEEDIT_H
#include "ringqt.h"
#include <QKeySequenceEdit>

extern "C" {
#include "ring.h"
}

class GKeySequenceEdit : public QKeySequenceEdit
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ceditingFinishedEvent[RINGQT_EVENT_SIZE];
    char ckeySequenceChangedEvent[RINGQT_EVENT_SIZE];


    GKeySequenceEdit(QWidget *parent,VM *pVM );

    ~GKeySequenceEdit();

    void geteventparameters(void) ;

    void seteditingFinishedEvent(const char *cStr);
    void setkeySequenceChangedEvent(const char *cStr);


    const char *geteditingFinishedEvent(void);
    const char *getkeySequenceChangedEvent(void);


  public slots:

    void editingFinishedSlot();
    void keySequenceChangedSlot();



};

#endif

