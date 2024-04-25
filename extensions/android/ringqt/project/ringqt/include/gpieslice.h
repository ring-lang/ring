
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPIESLICE_H
#define GPIESLICE_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GPieSlice : public QtCharts::QPieSlice
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cangleSpanChangedEvent[RINGQT_EVENT_SIZE];
    char cborderColorChangedEvent[RINGQT_EVENT_SIZE];
    char cborderWidthChangedEvent[RINGQT_EVENT_SIZE];
    char cbrushChangedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ccolorChangedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char choveredEvent[RINGQT_EVENT_SIZE];
    char clabelBrushChangedEvent[RINGQT_EVENT_SIZE];
    char clabelChangedEvent[RINGQT_EVENT_SIZE];
    char clabelColorChangedEvent[RINGQT_EVENT_SIZE];
    char clabelFontChangedEvent[RINGQT_EVENT_SIZE];
    char clabelVisibleChangedEvent[RINGQT_EVENT_SIZE];
    char cpenChangedEvent[RINGQT_EVENT_SIZE];
    char cpercentageChangedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];
    char cstartAngleChangedEvent[RINGQT_EVENT_SIZE];
    char cvalueChangedEvent[RINGQT_EVENT_SIZE];


    GPieSlice(QObject * parent,VM *pVM );

    ~GPieSlice();

    void geteventparameters(void) ;

    void setangleSpanChangedEvent(const char *cStr);
    void setborderColorChangedEvent(const char *cStr);
    void setborderWidthChangedEvent(const char *cStr);
    void setbrushChangedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setcolorChangedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void sethoveredEvent(const char *cStr);
    void setlabelBrushChangedEvent(const char *cStr);
    void setlabelChangedEvent(const char *cStr);
    void setlabelColorChangedEvent(const char *cStr);
    void setlabelFontChangedEvent(const char *cStr);
    void setlabelVisibleChangedEvent(const char *cStr);
    void setpenChangedEvent(const char *cStr);
    void setpercentageChangedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);
    void setstartAngleChangedEvent(const char *cStr);
    void setvalueChangedEvent(const char *cStr);


    const char *getangleSpanChangedEvent(void);
    const char *getborderColorChangedEvent(void);
    const char *getborderWidthChangedEvent(void);
    const char *getbrushChangedEvent(void);
    const char *getclickedEvent(void);
    const char *getcolorChangedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *gethoveredEvent(void);
    const char *getlabelBrushChangedEvent(void);
    const char *getlabelChangedEvent(void);
    const char *getlabelColorChangedEvent(void);
    const char *getlabelFontChangedEvent(void);
    const char *getlabelVisibleChangedEvent(void);
    const char *getpenChangedEvent(void);
    const char *getpercentageChangedEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);
    const char *getstartAngleChangedEvent(void);
    const char *getvalueChangedEvent(void);


  public slots:

    void angleSpanChangedSlot();
    void borderColorChangedSlot();
    void borderWidthChangedSlot();
    void brushChangedSlot();
    void clickedSlot();
    void colorChangedSlot();
    void doubleClickedSlot();
    void hoveredSlot();
    void labelBrushChangedSlot();
    void labelChangedSlot();
    void labelColorChangedSlot();
    void labelFontChangedSlot();
    void labelVisibleChangedSlot();
    void penChangedSlot();
    void percentageChangedSlot();
    void pressedSlot();
    void releasedSlot();
    void startAngleChangedSlot();
    void valueChangedSlot();

};

#endif

