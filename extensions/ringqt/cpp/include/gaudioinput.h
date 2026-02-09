
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GAUDIOINPUT_H
#define GAUDIOINPUT_H
#include "ringqt.h"
#include <QAudioInput>

extern "C" {
#include "ring.h"
}

class GAudioInput : public QAudioInput
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cstateChangedEvent[RINGQT_EVENT_SIZE];
    char cnotifyEvent[RINGQT_EVENT_SIZE];


    GAudioInput(const QAudioFormat &parent,VM *pVM );

    ~GAudioInput();

    void geteventparameters(void) ;

    void setstateChangedEvent(const char *cStr);
    void setnotifyEvent(const char *cStr);


    const char *getstateChangedEvent(void);
    const char *getnotifyEvent(void);


  public slots:

    void stateChangedSlot();
    void notifySlot();



};

#endif

