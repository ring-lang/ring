
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GMEDIARECORDER_H
#define GMEDIARECORDER_H
#include "ringqt.h"
#include <QMediaRecorder>

extern "C" {
#include "ring.h"
}

class GMediaRecorder : public QMediaRecorder
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cactualLocationChangedEvent[RINGQT_EVENT_SIZE];
    char cdurationChangedEvent[RINGQT_EVENT_SIZE];
    char cstateChangedEvent[RINGQT_EVENT_SIZE];
    char cerrorEvent[RINGQT_EVENT_SIZE];


    GMediaRecorder(QObject *parent,VM *pVM );

    ~GMediaRecorder();

    void geteventparameters(void) ;

    void setactualLocationChangedEvent(const char *cStr);
    void setdurationChangedEvent(const char *cStr);
    void setstateChangedEvent(const char *cStr);
    void seterrorEvent(const char *cStr);


    const char *getactualLocationChangedEvent(void);
    const char *getdurationChangedEvent(void);
    const char *getstateChangedEvent(void);
    const char *geterrorEvent(void);


  public slots:

    void actualLocationChangedSlot();
    void durationChangedSlot();
    void stateChangedSlot();
    void errorSlot();



};

#endif

