
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    char cbuttonClickedEvent[100];
    char cbuttonPressedEvent[100];
    char cbuttonReleasedEvent[100];


    GButtonGroup(QObject *parent,VM *pVM );

    void setbuttonClickedEvent(const char *cStr);
    void setbuttonPressedEvent(const char *cStr);
    void setbuttonReleasedEvent(const char *cStr);


  public slots:

    void buttonClickedSlot();
    void buttonPressedSlot();
    void buttonReleasedSlot();

};

#endif

