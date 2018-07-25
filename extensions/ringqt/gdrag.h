
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GDRAG_H
#define GDRAG_H
#include <QApplication>
#include <QDrag>
extern "C" {
#include "ring.h"
}

class GDrag : public QDrag
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cactionChangedEvent[100];
    char ctargetChangedEvent[100];


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

