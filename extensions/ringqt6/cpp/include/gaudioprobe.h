
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GAUDIOPROBE_H
#define GAUDIOPROBE_H
#include "ringqt.h"
#include <QAudioProbe>

extern "C" {
#include "ring.h"
}

class GAudioProbe : public QAudioProbe
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char caudioBufferProbedEvent[RINGQT_EVENT_SIZE];
    char cflushEvent[RINGQT_EVENT_SIZE];


    GAudioProbe(QObject *parent,VM *pVM );

    ~GAudioProbe();

    void geteventparameters(void) ;

    void setaudioBufferProbedEvent(const char *cStr);
    void setflushEvent(const char *cStr);


    const char *getaudioBufferProbedEvent(void);
    const char *getflushEvent(void);


  public slots:

    void audioBufferProbedSlot();
    void flushSlot();



};

#endif

