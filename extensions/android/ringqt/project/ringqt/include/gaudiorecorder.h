
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GAUDIORECORDER_H
#define GAUDIORECORDER_H
#include "ringqt.h"
#include <QAudioRecorder>

extern "C" {
#include "ring.h"
}

class GAudioRecorder : public QAudioRecorder
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char caudioInputChangedEvent[RINGQT_EVENT_SIZE];
    char cavailableAudioInputsChangedEvent[RINGQT_EVENT_SIZE];


    GAudioRecorder(QObject *parent,VM *pVM );

    ~GAudioRecorder();

    void geteventparameters(void) ;

    void setaudioInputChangedEvent(const char *cStr);
    void setavailableAudioInputsChangedEvent(const char *cStr);


    const char *getaudioInputChangedEvent(void);
    const char *getavailableAudioInputsChangedEvent(void);


  public slots:

    void audioInputChangedSlot();
    void availableAudioInputsChangedSlot();



};

#endif

