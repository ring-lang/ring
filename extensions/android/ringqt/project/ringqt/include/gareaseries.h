
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GAREASERIES_H
#define GAREASERIES_H
#include "ringqt.h"
#include <QtCharts/QAreaSeries>
extern "C" {
#include "ring.h"
}

class GAreaSeries : public QtCharts::QAreaSeries
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cborderColorChangedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ccolorChangedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char choveredEvent[RINGQT_EVENT_SIZE];
    char cpointLabelsClippingChangedEvent[RINGQT_EVENT_SIZE];
    char cpointLabelsColorChangedEvent[RINGQT_EVENT_SIZE];
    char cpointLabelsFontChangedEvent[RINGQT_EVENT_SIZE];
    char cpointLabelsFormatChangedEvent[RINGQT_EVENT_SIZE];
    char cpointLabelsVisibilityChangedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];


    GAreaSeries(QObject *parent,VM *pVM );

    ~GAreaSeries();

    void geteventparameters(void) ;

    void setborderColorChangedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setcolorChangedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void sethoveredEvent(const char *cStr);
    void setpointLabelsClippingChangedEvent(const char *cStr);
    void setpointLabelsColorChangedEvent(const char *cStr);
    void setpointLabelsFontChangedEvent(const char *cStr);
    void setpointLabelsFormatChangedEvent(const char *cStr);
    void setpointLabelsVisibilityChangedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);


    const char *getborderColorChangedEvent(void);
    const char *getclickedEvent(void);
    const char *getcolorChangedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *gethoveredEvent(void);
    const char *getpointLabelsClippingChangedEvent(void);
    const char *getpointLabelsColorChangedEvent(void);
    const char *getpointLabelsFontChangedEvent(void);
    const char *getpointLabelsFormatChangedEvent(void);
    const char *getpointLabelsVisibilityChangedEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);


  public slots:

    void borderColorChangedSlot();
    void clickedSlot();
    void colorChangedSlot();
    void doubleClickedSlot();
    void hoveredSlot();
    void pointLabelsClippingChangedSlot();
    void pointLabelsColorChangedSlot();
    void pointLabelsFontChangedSlot();
    void pointLabelsFormatChangedSlot();
    void pointLabelsVisibilityChangedSlot();
    void pressedSlot();
    void releasedSlot();

};

#endif

