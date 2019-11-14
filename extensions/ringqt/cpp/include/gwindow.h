
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GWINDOW_H
#define GWINDOW_H
#include <QApplication>
#include <QWindow>
extern "C" {
#include "ring.h"
}

class GWindow : public QWindow
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cactiveChangedEvent[200];
    char ccontentOrientationChangedEvent[200];
    char cfocusObjectChangedEvent[200];
    char cheightChangedEvent[200];
    char cmaximumHeightChangedEvent[200];
    char cmaximumWidthChangedEvent[200];
    char cminimumHeightChangedEvent[200];
    char cminimumWidthChangedEvent[200];
    char cmodalityChangedEvent[200];
    char copacityChangedEvent[200];
    char cscreenChangedEvent[200];
    char cvisibilityChangedEvent[200];
    char cvisibleChangedEvent[200];
    char cwidthChangedEvent[200];
    char cwindowStateChangedEvent[200];
    char cwindowTitleChangedEvent[200];
    char cxChangedEvent[200];
    char cyChangedEvent[200];


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

