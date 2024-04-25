
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GABSTRACTAXIS_H
#define GABSTRACTAXIS_H
#include "ringqt.h"
#include <QtCharts/QAbstractAxis>
extern "C" {
#include "ring.h"
}

class GAbstractAxis : public QtCharts::QAbstractAxis
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccolorChangedEvent[RINGQT_EVENT_SIZE];
    char cgridLineColorChangedEvent[RINGQT_EVENT_SIZE];
    char cgridLinePenChangedEvent[RINGQT_EVENT_SIZE];
    char cgridVisibleChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsAngleChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsBrushChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsColorChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsEditableChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsFontChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsVisibleChangedEvent[RINGQT_EVENT_SIZE];
    char clinePenChangedEvent[RINGQT_EVENT_SIZE];
    char clineVisibleChangedEvent[RINGQT_EVENT_SIZE];
    char cminorGridLineColorChangedEvent[RINGQT_EVENT_SIZE];
    char cminorGridLinePenChangedEvent[RINGQT_EVENT_SIZE];
    char cminorGridVisibleChangedEvent[RINGQT_EVENT_SIZE];
    char creverseChangedEvent[RINGQT_EVENT_SIZE];
    char cshadesBorderColorChangedEvent[RINGQT_EVENT_SIZE];
    char cshadesBrushChangedEvent[RINGQT_EVENT_SIZE];
    char cshadesColorChangedEvent[RINGQT_EVENT_SIZE];
    char cshadesPenChangedEvent[RINGQT_EVENT_SIZE];
    char cshadesVisibleChangedEvent[RINGQT_EVENT_SIZE];
    char ctitleBrushChangedEvent[RINGQT_EVENT_SIZE];
    char ctitleFontChangedEvent[RINGQT_EVENT_SIZE];
    char ctitleTextChangedEvent[RINGQT_EVENT_SIZE];
    char ctitleVisibleChangedEvent[RINGQT_EVENT_SIZE];
    char cvisibleChangedEvent[RINGQT_EVENT_SIZE];


    GAbstractAxis(QtCharts::QAbstractAxisPrivate &parent,VM *pVM );

    ~GAbstractAxis();

    void geteventparameters(void) ;

    void setcolorChangedEvent(const char *cStr);
    void setgridLineColorChangedEvent(const char *cStr);
    void setgridLinePenChangedEvent(const char *cStr);
    void setgridVisibleChangedEvent(const char *cStr);
    void setlabelsAngleChangedEvent(const char *cStr);
    void setlabelsBrushChangedEvent(const char *cStr);
    void setlabelsColorChangedEvent(const char *cStr);
    void setlabelsEditableChangedEvent(const char *cStr);
    void setlabelsFontChangedEvent(const char *cStr);
    void setlabelsVisibleChangedEvent(const char *cStr);
    void setlinePenChangedEvent(const char *cStr);
    void setlineVisibleChangedEvent(const char *cStr);
    void setminorGridLineColorChangedEvent(const char *cStr);
    void setminorGridLinePenChangedEvent(const char *cStr);
    void setminorGridVisibleChangedEvent(const char *cStr);
    void setreverseChangedEvent(const char *cStr);
    void setshadesBorderColorChangedEvent(const char *cStr);
    void setshadesBrushChangedEvent(const char *cStr);
    void setshadesColorChangedEvent(const char *cStr);
    void setshadesPenChangedEvent(const char *cStr);
    void setshadesVisibleChangedEvent(const char *cStr);
    void settitleBrushChangedEvent(const char *cStr);
    void settitleFontChangedEvent(const char *cStr);
    void settitleTextChangedEvent(const char *cStr);
    void settitleVisibleChangedEvent(const char *cStr);
    void setvisibleChangedEvent(const char *cStr);


    const char *getcolorChangedEvent(void);
    const char *getgridLineColorChangedEvent(void);
    const char *getgridLinePenChangedEvent(void);
    const char *getgridVisibleChangedEvent(void);
    const char *getlabelsAngleChangedEvent(void);
    const char *getlabelsBrushChangedEvent(void);
    const char *getlabelsColorChangedEvent(void);
    const char *getlabelsEditableChangedEvent(void);
    const char *getlabelsFontChangedEvent(void);
    const char *getlabelsVisibleChangedEvent(void);
    const char *getlinePenChangedEvent(void);
    const char *getlineVisibleChangedEvent(void);
    const char *getminorGridLineColorChangedEvent(void);
    const char *getminorGridLinePenChangedEvent(void);
    const char *getminorGridVisibleChangedEvent(void);
    const char *getreverseChangedEvent(void);
    const char *getshadesBorderColorChangedEvent(void);
    const char *getshadesBrushChangedEvent(void);
    const char *getshadesColorChangedEvent(void);
    const char *getshadesPenChangedEvent(void);
    const char *getshadesVisibleChangedEvent(void);
    const char *gettitleBrushChangedEvent(void);
    const char *gettitleFontChangedEvent(void);
    const char *gettitleTextChangedEvent(void);
    const char *gettitleVisibleChangedEvent(void);
    const char *getvisibleChangedEvent(void);


  public slots:

    void colorChangedSlot();
    void gridLineColorChangedSlot();
    void gridLinePenChangedSlot();
    void gridVisibleChangedSlot();
    void labelsAngleChangedSlot();
    void labelsBrushChangedSlot();
    void labelsColorChangedSlot();
    void labelsEditableChangedSlot();
    void labelsFontChangedSlot();
    void labelsVisibleChangedSlot();
    void linePenChangedSlot();
    void lineVisibleChangedSlot();
    void minorGridLineColorChangedSlot();
    void minorGridLinePenChangedSlot();
    void minorGridVisibleChangedSlot();
    void reverseChangedSlot();
    void shadesBorderColorChangedSlot();
    void shadesBrushChangedSlot();
    void shadesColorChangedSlot();
    void shadesPenChangedSlot();
    void shadesVisibleChangedSlot();
    void titleBrushChangedSlot();
    void titleFontChangedSlot();
    void titleTextChangedSlot();
    void titleVisibleChangedSlot();
    void visibleChangedSlot();

};

#endif

