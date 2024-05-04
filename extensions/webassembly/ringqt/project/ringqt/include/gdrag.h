
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GDRAG_H
#define GDRAG_H
#include "ringqt.h"
#include <QDrag>

extern "C" {
#include "ring.h"
}

class GDrag : public QDrag
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cactionChangedEvent[RINGQT_EVENT_SIZE];
    char ctargetChangedEvent[RINGQT_EVENT_SIZE];


    GDrag(QObject *parent,VM *pVM );

    ~GDrag();

    void geteventparameters(void) ;

    void setactionChangedEvent(const char *cStr);
    void settargetChangedEvent(const char *cStr);


    const char *getactionChangedEvent(void);
    const char *gettargetChangedEvent(void);


  public slots:

    void actionChangedSlot();
    void targetChangedSlot();



};

#endif

