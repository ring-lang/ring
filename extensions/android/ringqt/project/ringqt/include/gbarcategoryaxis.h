
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GBARCATEGORYAXIS_H
#define GBARCATEGORYAXIS_H
#include "ringqt.h"
#include <QtCharts>
extern "C" {
#include "ring.h"
}

class GBarCategoryAxis : public QtCharts::QBarCategoryAxis
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccategoriesChangedEvent[RINGQT_EVENT_SIZE];
    char ccountChangedEvent[RINGQT_EVENT_SIZE];
    char cmaxChangedEvent[RINGQT_EVENT_SIZE];
    char cminChangedEvent[RINGQT_EVENT_SIZE];
    char crangeChangedEvent[RINGQT_EVENT_SIZE];


    GBarCategoryAxis(QObject *parent,VM *pVM );

    ~GBarCategoryAxis();

    void geteventparameters(void) ;

    void setcategoriesChangedEvent(const char *cStr);
    void setcountChangedEvent(const char *cStr);
    void setmaxChangedEvent(const char *cStr);
    void setminChangedEvent(const char *cStr);
    void setrangeChangedEvent(const char *cStr);


    const char *getcategoriesChangedEvent(void);
    const char *getcountChangedEvent(void);
    const char *getmaxChangedEvent(void);
    const char *getminChangedEvent(void);
    const char *getrangeChangedEvent(void);


  public slots:

    void categoriesChangedSlot();
    void countChangedSlot();
    void maxChangedSlot();
    void minChangedSlot();
    void rangeChangedSlot();

};

#endif

