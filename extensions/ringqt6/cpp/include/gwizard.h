
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GWIZARD_H
#define GWIZARD_H
#include "ringqt.h"
#include <QWizard>

extern "C" {
#include "ring.h"
}

class GWizard : public QWizard
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccurrentIdChangedEvent[RINGQT_EVENT_SIZE];
    char cpageAddedEvent[RINGQT_EVENT_SIZE];
    char cpageRemovedEvent[RINGQT_EVENT_SIZE];


    GWizard(QWidget *parent,VM *pVM );

    ~GWizard();

    void geteventparameters(void) ;

    void setcurrentIdChangedEvent(const char *cStr);
    void setpageAddedEvent(const char *cStr);
    void setpageRemovedEvent(const char *cStr);


    const char *getcurrentIdChangedEvent(void);
    const char *getpageAddedEvent(void);
    const char *getpageRemovedEvent(void);


  public slots:

    void currentIdChangedSlot();
    void pageAddedSlot();
    void pageRemovedSlot();



};

#endif

