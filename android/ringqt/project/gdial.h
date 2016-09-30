
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GDIAL_H
#define GDIAL_H
#include <QApplication>
#include <QDial>
extern "C" {
#include "ring.h"
}

class GDial : public QDial
{

  Q_OBJECT

  public:

    VM *pVM;

    char cactionTriggeredEvent[100];
    char crangeChangedEvent[100];
    char csliderMovedEvent[100];
    char csliderPressedEvent[100];
    char csliderReleasedEvent[100];
    char cvalueChangedEvent[100];


    GDial(QWidget *parent,VM *pVM );

    void setactionTriggeredEvent(const char *cStr);
    void setrangeChangedEvent(const char *cStr);
    void setsliderMovedEvent(const char *cStr);
    void setsliderPressedEvent(const char *cStr);
    void setsliderReleasedEvent(const char *cStr);
    void setvalueChangedEvent(const char *cStr);


  public slots:

    void actionTriggeredSlot();
    void rangeChangedSlot();
    void sliderMovedSlot();
    void sliderPressedSlot();
    void sliderReleasedSlot();
    void valueChangedSlot();

};

#endif

