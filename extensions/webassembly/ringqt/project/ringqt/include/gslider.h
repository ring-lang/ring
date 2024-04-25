
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSLIDER_H
#define GSLIDER_H
#include "ringqt.h"
#include <QSlider>
extern "C" {
#include "ring.h"
}

class GSlider : public QSlider
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cactionTriggeredEvent[RINGQT_EVENT_SIZE];
    char crangeChangedEvent[RINGQT_EVENT_SIZE];
    char csliderMovedEvent[RINGQT_EVENT_SIZE];
    char csliderPressedEvent[RINGQT_EVENT_SIZE];
    char csliderReleasedEvent[RINGQT_EVENT_SIZE];
    char cvalueChangedEvent[RINGQT_EVENT_SIZE];


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

