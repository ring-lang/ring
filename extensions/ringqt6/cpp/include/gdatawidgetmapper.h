
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GDATAWIDGETMAPPER_H
#define GDATAWIDGETMAPPER_H
#include "ringqt.h"
#include <QDataWidgetMapper>

extern "C" {
#include "ring.h"
}

class GDataWidgetMapper : public QDataWidgetMapper
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccurrentIndexChangedEvent[RINGQT_EVENT_SIZE];


    GDataWidgetMapper(QObject *parent,VM *pVM );

    ~GDataWidgetMapper();

    void geteventparameters(void) ;

    void setcurrentIndexChangedEvent(const char *cStr);


    const char *getcurrentIndexChangedEvent(void);


  public slots:

    void currentIndexChangedSlot();



};

#endif

