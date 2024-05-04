
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GCATEGORYAXIS_H
#define GCATEGORYAXIS_H
#include "ringqt.h"
#include <QtCharts>

extern "C" {
#include "ring.h"
}

class GCategoryAxis : public QtCharts::QCategoryAxis
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccategoriesChangedEvent[RINGQT_EVENT_SIZE];
    char clabelsPositionChangedEvent[RINGQT_EVENT_SIZE];


    GCategoryAxis(QObject *parent,VM *pVM );

    ~GCategoryAxis();

    void geteventparameters(void) ;

    void setcategoriesChangedEvent(const char *cStr);
    void setlabelsPositionChangedEvent(const char *cStr);


    const char *getcategoriesChangedEvent(void);
    const char *getlabelsPositionChangedEvent(void);


  public slots:

    void categoriesChangedSlot();
    void labelsPositionChangedSlot();



};

#endif

