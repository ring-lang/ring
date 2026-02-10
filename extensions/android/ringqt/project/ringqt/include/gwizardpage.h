
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GWIZARDPAGE_H
#define GWIZARDPAGE_H
#include "ringqt.h"
#include <QWizardPage>

extern "C" {
#include "ring.h"
}

class GWizardPage : public QWizardPage
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccompleteChangedEvent[RINGQT_EVENT_SIZE];


    GWizardPage(QWidget *parent,VM *pVM );

    ~GWizardPage();

    void geteventparameters(void) ;

    void setcompleteChangedEvent(const char *cStr);


    const char *getcompleteChangedEvent(void);


  public slots:

    void completeChangedSlot();



};

#endif

