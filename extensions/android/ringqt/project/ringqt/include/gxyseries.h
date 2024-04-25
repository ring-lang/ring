
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GXYSERIES_H
#define GXYSERIES_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GXYSeries : public QtCharts::QXYSeries
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cclickedEvent[RINGQT_EVENT_SIZE];
    char ccolorChangedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char choveredEvent[RINGQT_EVENT_SIZE];
    char cpenChangedEvent[RINGQT_EVENT_SIZE];
    char cpointAddedEvent[RINGQT_EVENT_SIZE];
    char cpointLabelsClippingChangedEvent[RINGQT_EVENT_SIZE];
    char cpointLabelsColorChangedEvent[RINGQT_EVENT_SIZE];
    char cpointLabelsFontChangedEvent[RINGQT_EVENT_SIZE];
    char cpointLabelsFormatChangedEvent[RINGQT_EVENT_SIZE];
    char cpointLabelsVisibilityChangedEvent[RINGQT_EVENT_SIZE];
    char cpointRemovedEvent[RINGQT_EVENT_SIZE];
    char cpointReplacedEvent[RINGQT_EVENT_SIZE];
    char cpointsRemovedEvent[RINGQT_EVENT_SIZE];
    char cpointsReplacedEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char creleasedEvent[RINGQT_EVENT_SIZE];


    GXYSeries(QtCharts::QXYSeriesPrivate &parent,VM *pVM );

    ~GXYSeries();

    void geteventparameters(void) ;

    void setclickedEvent(const char *cStr);
    void setcolorChangedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void sethoveredEvent(const char *cStr);
    void setpenChangedEvent(const char *cStr);
    void setpointAddedEvent(const char *cStr);
    void setpointLabelsClippingChangedEvent(const char *cStr);
    void setpointLabelsColorChangedEvent(const char *cStr);
    void setpointLabelsFontChangedEvent(const char *cStr);
    void setpointLabelsFormatChangedEvent(const char *cStr);
    void setpointLabelsVisibilityChangedEvent(const char *cStr);
    void setpointRemovedEvent(const char *cStr);
    void setpointReplacedEvent(const char *cStr);
    void setpointsRemovedEvent(const char *cStr);
    void setpointsReplacedEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setreleasedEvent(const char *cStr);


    const char *getclickedEvent(void);
    const char *getcolorChangedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *gethoveredEvent(void);
    const char *getpenChangedEvent(void);
    const char *getpointAddedEvent(void);
    const char *getpointLabelsClippingChangedEvent(void);
    const char *getpointLabelsColorChangedEvent(void);
    const char *getpointLabelsFontChangedEvent(void);
    const char *getpointLabelsFormatChangedEvent(void);
    const char *getpointLabelsVisibilityChangedEvent(void);
    const char *getpointRemovedEvent(void);
    const char *getpointReplacedEvent(void);
    const char *getpointsRemovedEvent(void);
    const char *getpointsReplacedEvent(void);
    const char *getpressedEvent(void);
    const char *getreleasedEvent(void);


  public slots:

    void clickedSlot();
    void colorChangedSlot();
    void doubleClickedSlot();
    void hoveredSlot();
    void penChangedSlot();
    void pointAddedSlot();
    void pointLabelsClippingChangedSlot();
    void pointLabelsColorChangedSlot();
    void pointLabelsFontChangedSlot();
    void pointLabelsFormatChangedSlot();
    void pointLabelsVisibilityChangedSlot();
    void pointRemovedSlot();
    void pointReplacedSlot();
    void pointsRemovedSlot();
    void pointsReplacedSlot();
    void pressedSlot();
    void releasedSlot();

};

#endif

