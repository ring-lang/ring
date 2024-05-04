
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBUTTONGROUP_H
#define GBUTTONGROUP_H
#include "ringqt.h"
#include <QButtonGroup>

extern "C" {
#include "ring.h"
}

class GButtonGroup : public QButtonGroup
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cbuttonClickedEvent[RINGQT_EVENT_SIZE];
    char cbuttonPressedEvent[RINGQT_EVENT_SIZE];
    char cbuttonReleasedEvent[RINGQT_EVENT_SIZE];


    GButtonGroup(QObject *parent,VM *pVM );

    ~GButtonGroup();

    void geteventparameters(void) ;

    void setbuttonClickedEvent(const char *cStr);
    void setbuttonPressedEvent(const char *cStr);
    void setbuttonReleasedEvent(const char *cStr);


    const char *getbuttonClickedEvent(void);
    const char *getbuttonPressedEvent(void);
    const char *getbuttonReleasedEvent(void);


  public slots:

    void buttonClickedSlot();
    void buttonPressedSlot();
    void buttonReleasedSlot();



};

#endif

