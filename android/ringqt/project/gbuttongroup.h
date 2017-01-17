
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBUTTONGROUP_H
#define GBUTTONGROUP_H
#include <QApplication>
#include <QButtonGroup>
extern "C" {
#include "ring.h"
}

class GButtonGroup : public QButtonGroup
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cbuttonClickedEvent[100];
    char cbuttonPressedEvent[100];
    char cbuttonReleasedEvent[100];


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

