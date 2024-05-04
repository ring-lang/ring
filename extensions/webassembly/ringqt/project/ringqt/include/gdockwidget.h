
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GDOCKWIDGET_H
#define GDOCKWIDGET_H
#include "ringqt.h"
#include <QDockWidget>

extern "C" {
#include "ring.h"
}

class GDockWidget : public QDockWidget
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char callowedAreasChangedEvent[RINGQT_EVENT_SIZE];
    char cdockLocationChangedEvent[RINGQT_EVENT_SIZE];
    char cfeaturesChangedEvent[RINGQT_EVENT_SIZE];
    char ctopLevelChangedEvent[RINGQT_EVENT_SIZE];
    char cvisibilityChangedEvent[RINGQT_EVENT_SIZE];


    GDockWidget(QWidget *x,Qt::WindowFlags parent,VM *pVM );

    ~GDockWidget();

    void geteventparameters(void) ;

    void setallowedAreasChangedEvent(const char *cStr);
    void setdockLocationChangedEvent(const char *cStr);
    void setfeaturesChangedEvent(const char *cStr);
    void settopLevelChangedEvent(const char *cStr);
    void setvisibilityChangedEvent(const char *cStr);


    const char *getallowedAreasChangedEvent(void);
    const char *getdockLocationChangedEvent(void);
    const char *getfeaturesChangedEvent(void);
    const char *gettopLevelChangedEvent(void);
    const char *getvisibilityChangedEvent(void);


  public slots:

    void allowedAreasChangedSlot();
    void dockLocationChangedSlot();
    void featuresChangedSlot();
    void topLevelChangedSlot();
    void visibilityChangedSlot();



};

#endif

