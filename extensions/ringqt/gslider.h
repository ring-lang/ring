
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSLIDER_H
#define GSLIDER_H
#include <QApplication>
#include <QSlider>
extern "C" {
#include "ring.h"
}

class GSlider : public QSlider
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cactionTriggeredEvent[100];
    char crangeChangedEvent[100];
    char csliderMovedEvent[100];
    char csliderPressedEvent[100];
    char csliderReleasedEvent[100];
    char cvalueChangedEvent[100];


    GSlider(QWidget *parent,VM *pVM );

    ~GSlider();

    void geteventparameters(void) ;

    void setactionTriggeredEvent(const char *cStr);
    void setrangeChangedEvent(const char *cStr);
    void setsliderMovedEvent(const char *cStr);
    void setsliderPressedEvent(const char *cStr);
    void setsliderReleasedEvent(const char *cStr);
    void setvalueChangedEvent(const char *cStr);


    const char *getactionTriggeredEvent(void);
    const char *getrangeChangedEvent(void);
    const char *getsliderMovedEvent(void);
    const char *getsliderPressedEvent(void);
    const char *getsliderReleasedEvent(void);
    const char *getvalueChangedEvent(void);


  public slots:

    void actionTriggeredSlot();
    void rangeChangedSlot();
    void sliderMovedSlot();
    void sliderPressedSlot();
    void sliderReleasedSlot();
    void valueChangedSlot();

};

#endif

