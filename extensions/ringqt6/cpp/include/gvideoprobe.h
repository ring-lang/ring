
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GVIDEOPROBE_H
#define GVIDEOPROBE_H
#include "ringqt.h"
#include <QVideoProbe>

extern "C" {
#include "ring.h"
}

class GVideoProbe : public QVideoProbe
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cvideoFrameProbedEvent[RINGQT_EVENT_SIZE];
    char cflushEvent[RINGQT_EVENT_SIZE];


    GVideoProbe(QObject *parent,VM *pVM );

    ~GVideoProbe();

    void geteventparameters(void) ;

    void setvideoFrameProbedEvent(const char *cStr);
    void setflushEvent(const char *cStr);


    const char *getvideoFrameProbedEvent(void);
    const char *getflushEvent(void);


  public slots:

    void videoFrameProbedSlot();
    void flushSlot();



};

#endif

