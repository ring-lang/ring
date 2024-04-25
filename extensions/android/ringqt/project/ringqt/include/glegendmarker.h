
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GLEGENDMARKER_H
#define GLEGENDMARKER_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GLegendMarker : public QtCharts::QLegendMarker
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cbrushChangedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char cfontChangedEvent[RINGQT_EVENT_SIZE];
    char choveredEvent[RINGQT_EVENT_SIZE];
    char clabelBrushChangedEvent[RINGQT_EVENT_SIZE];
    char clabelChangedEvent[RINGQT_EVENT_SIZE];
    char cpenChangedEvent[RINGQT_EVENT_SIZE];
    char cshapeChangedEvent[RINGQT_EVENT_SIZE];
    char cvisibleChangedEvent[RINGQT_EVENT_SIZE];


    GLegendMarker(QtCharts::QLegendMarkerPrivate &parent,VM *pVM );

    ~GLegendMarker();

    void geteventparameters(void) ;

    void setbrushChangedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setfontChangedEvent(const char *cStr);
    void sethoveredEvent(const char *cStr);
    void setlabelBrushChangedEvent(const char *cStr);
    void setlabelChangedEvent(const char *cStr);
    void setpenChangedEvent(const char *cStr);
    void setshapeChangedEvent(const char *cStr);
    void setvisibleChangedEvent(const char *cStr);


    const char *getbrushChangedEvent(void);
    const char *getclickedEvent(void);
    const char *getfontChangedEvent(void);
    const char *gethoveredEvent(void);
    const char *getlabelBrushChangedEvent(void);
    const char *getlabelChangedEvent(void);
    const char *getpenChangedEvent(void);
    const char *getshapeChangedEvent(void);
    const char *getvisibleChangedEvent(void);


  public slots:

    void brushChangedSlot();
    void clickedSlot();
    void fontChangedSlot();
    void hoveredSlot();
    void labelBrushChangedSlot();
    void labelChangedSlot();
    void penChangedSlot();
    void shapeChangedSlot();
    void visibleChangedSlot();

};

#endif

