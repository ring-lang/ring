
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBARSET_H
#define GBARSET_H
#include "ringqt.h"
#include <QtCharts>

extern "C" {
#include "ring.h"
}

class GBarSet : public QtCharts::QBarSet
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cborderColorChangedEvent[RINGQT_EVENT_SIZE];
    char cbrushChangedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ccolorChangedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char choveredEvent[RINGQT_EVENT_SIZE];
    char clabelBrushChangedEvent[RINGQT_EVENT_SIZE];
    char clabelChangedEvent[RINGQT_EVENT_SIZE];
    char clabelColorChangedEvent[RINGQT_EVENT_SIZE];
    char clabelFontChangedEvent[RINGQT_EVENT_SIZE];
    char cpenChangedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];
    char cvalueChangedEvent[RINGQT_EVENT_SIZE];
    char cvaluesAddedEvent[RINGQT_EVENT_SIZE];
    char cvaluesRemovedEvent[RINGQT_EVENT_SIZE];


    GBarSet(const QString x,QObject *parent,VM *pVM );

    ~GBarSet();

    void geteventparameters(void) ;

    void setborderColorChangedEvent(const char *cStr);
    void setbrushChangedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setcolorChangedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void sethoveredEvent(const char *cStr);
    void setlabelBrushChangedEvent(const char *cStr);
    void setlabelChangedEvent(const char *cStr);
    void setlabelColorChangedEvent(const char *cStr);
    void setlabelFontChangedEvent(const char *cStr);
    void setpenChangedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);
    void setvalueChangedEvent(const char *cStr);
    void setvaluesAddedEvent(const char *cStr);
    void setvaluesRemovedEvent(const char *cStr);


    const char *getborderColorChangedEvent(void);
    const char *getbrushChangedEvent(void);
    const char *getclickedEvent(void);
    const char *getcolorChangedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *gethoveredEvent(void);
    const char *getlabelBrushChangedEvent(void);
    const char *getlabelChangedEvent(void);
    const char *getlabelColorChangedEvent(void);
    const char *getlabelFontChangedEvent(void);
    const char *getpenChangedEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);
    const char *getvalueChangedEvent(void);
    const char *getvaluesAddedEvent(void);
    const char *getvaluesRemovedEvent(void);


  public slots:

    void borderColorChangedSlot();
    void brushChangedSlot();
    void clickedSlot();
    void colorChangedSlot();
    void doubleClickedSlot();
    void hoveredSlot();
    void labelBrushChangedSlot();
    void labelChangedSlot();
    void labelColorChangedSlot();
    void labelFontChangedSlot();
    void penChangedSlot();
    void pressedSlot();
    void releasedSlot();
    void valueChangedSlot();
    void valuesAddedSlot();
    void valuesRemovedSlot();



};

#endif

