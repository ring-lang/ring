
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GDIALOGBUTTONBOX_H
#define GDIALOGBUTTONBOX_H
#include "ringqt.h"
#include <QDialogButtonBox>

extern "C" {
#include "ring.h"
}

class GDialogButtonBox : public QDialogButtonBox
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cacceptedEvent[RINGQT_EVENT_SIZE];
    char crejectedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char chelpRequestedEvent[RINGQT_EVENT_SIZE];


    GDialogButtonBox(QWidget *parent,VM *pVM );

    ~GDialogButtonBox();

    void geteventparameters(void) ;

    void setacceptedEvent(const char *cStr);
    void setrejectedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void sethelpRequestedEvent(const char *cStr);


    const char *getacceptedEvent(void);
    const char *getrejectedEvent(void);
    const char *getclickedEvent(void);
    const char *gethelpRequestedEvent(void);


  public slots:

    void acceptedSlot();
    void rejectedSlot();
    void clickedSlot();
    void helpRequestedSlot();



};

#endif

