
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GWINDOW_H
#define GWINDOW_H
#include "ringqt.h"
#include <QWindow>

extern "C" {
#include "ring.h"
}

class GWindow : public QWindow
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cactiveChangedEvent[RINGQT_EVENT_SIZE];
    char ccontentOrientationChangedEvent[RINGQT_EVENT_SIZE];
    char cfocusObjectChangedEvent[RINGQT_EVENT_SIZE];
    char cheightChangedEvent[RINGQT_EVENT_SIZE];
    char cmaximumHeightChangedEvent[RINGQT_EVENT_SIZE];
    char cmaximumWidthChangedEvent[RINGQT_EVENT_SIZE];
    char cminimumHeightChangedEvent[RINGQT_EVENT_SIZE];
    char cminimumWidthChangedEvent[RINGQT_EVENT_SIZE];
    char cmodalityChangedEvent[RINGQT_EVENT_SIZE];
    char copacityChangedEvent[RINGQT_EVENT_SIZE];
    char cscreenChangedEvent[RINGQT_EVENT_SIZE];
    char cvisibilityChangedEvent[RINGQT_EVENT_SIZE];
    char cvisibleChangedEvent[RINGQT_EVENT_SIZE];
    char cwidthChangedEvent[RINGQT_EVENT_SIZE];
    char cwindowStateChangedEvent[RINGQT_EVENT_SIZE];
    char cwindowTitleChangedEvent[RINGQT_EVENT_SIZE];
    char cxChangedEvent[RINGQT_EVENT_SIZE];
    char cyChangedEvent[RINGQT_EVENT_SIZE];


    GWindow(QScreen *parent,VM *pVM );

    ~GWindow();

    void geteventparameters(void) ;

    void setactiveChangedEvent(const char *cStr);
    void setcontentOrientationChangedEvent(const char *cStr);
    void setfocusObjectChangedEvent(const char *cStr);
    void setheightChangedEvent(const char *cStr);
    void setmaximumHeightChangedEvent(const char *cStr);
    void setmaximumWidthChangedEvent(const char *cStr);
    void setminimumHeightChangedEvent(const char *cStr);
    void setminimumWidthChangedEvent(const char *cStr);
    void setmodalityChangedEvent(const char *cStr);
    void setopacityChangedEvent(const char *cStr);
    void setscreenChangedEvent(const char *cStr);
    void setvisibilityChangedEvent(const char *cStr);
    void setvisibleChangedEvent(const char *cStr);
    void setwidthChangedEvent(const char *cStr);
    void setwindowStateChangedEvent(const char *cStr);
    void setwindowTitleChangedEvent(const char *cStr);
    void setxChangedEvent(const char *cStr);
    void setyChangedEvent(const char *cStr);


    const char *getactiveChangedEvent(void);
    const char *getcontentOrientationChangedEvent(void);
    const char *getfocusObjectChangedEvent(void);
    const char *getheightChangedEvent(void);
    const char *getmaximumHeightChangedEvent(void);
    const char *getmaximumWidthChangedEvent(void);
    const char *getminimumHeightChangedEvent(void);
    const char *getminimumWidthChangedEvent(void);
    const char *getmodalityChangedEvent(void);
    const char *getopacityChangedEvent(void);
    const char *getscreenChangedEvent(void);
    const char *getvisibilityChangedEvent(void);
    const char *getvisibleChangedEvent(void);
    const char *getwidthChangedEvent(void);
    const char *getwindowStateChangedEvent(void);
    const char *getwindowTitleChangedEvent(void);
    const char *getxChangedEvent(void);
    const char *getyChangedEvent(void);


  public slots:

    void activeChangedSlot();
    void contentOrientationChangedSlot();
    void focusObjectChangedSlot();
    void heightChangedSlot();
    void maximumHeightChangedSlot();
    void maximumWidthChangedSlot();
    void minimumHeightChangedSlot();
    void minimumWidthChangedSlot();
    void modalityChangedSlot();
    void opacityChangedSlot();
    void screenChangedSlot();
    void visibilityChangedSlot();
    void visibleChangedSlot();
    void widthChangedSlot();
    void windowStateChangedSlot();
    void windowTitleChangedSlot();
    void xChangedSlot();
    void yChangedSlot();



};

#endif

