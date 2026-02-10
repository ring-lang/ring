
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSHORTCUT_H
#define GSHORTCUT_H
#include "ringqt.h"
#include <QShortcut>

extern "C" {
#include "ring.h"
}

class GShortcut : public QShortcut
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cactivatedEvent[RINGQT_EVENT_SIZE];
    char cactivatedAmbiguouslyEvent[RINGQT_EVENT_SIZE];


    GShortcut(QWidget *parent,VM *pVM );

    ~GShortcut();

    void geteventparameters(void) ;

    void setactivatedEvent(const char *cStr);
    void setactivatedAmbiguouslyEvent(const char *cStr);


    const char *getactivatedEvent(void);
    const char *getactivatedAmbiguouslyEvent(void);


  public slots:

    void activatedSlot();
    void activatedAmbiguouslySlot();



};

#endif

