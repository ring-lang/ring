
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTEXTTOSPEECH_H
#define GTEXTTOSPEECH_H
#include "ringqt.h"
#include <QTextToSpeech>
extern "C" {
#include "ring.h"
}

class GTextToSpeech : public QTextToSpeech
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char clocaleChangedEvent[RINGQT_EVENT_SIZE];
    char cpitchChangedEvent[RINGQT_EVENT_SIZE];
    char crateChangedEvent[RINGQT_EVENT_SIZE];
    char cstateChangedEvent[RINGQT_EVENT_SIZE];
    char cvoiceChangedEvent[RINGQT_EVENT_SIZE];
    char cvolumeChangedEvent[RINGQT_EVENT_SIZE];


    GTextToSpeech(QObject *parent,VM *pVM );

    ~GTextToSpeech();

    void geteventparameters(void) ;

    void setlocaleChangedEvent(const char *cStr);
    void setpitchChangedEvent(const char *cStr);
    void setrateChangedEvent(const char *cStr);
    void setstateChangedEvent(const char *cStr);
    void setvoiceChangedEvent(const char *cStr);
    void setvolumeChangedEvent(const char *cStr);


    const char *getlocaleChangedEvent(void);
    const char *getpitchChangedEvent(void);
    const char *getrateChangedEvent(void);
    const char *getstateChangedEvent(void);
    const char *getvoiceChangedEvent(void);
    const char *getvolumeChangedEvent(void);


  public slots:

    void localeChangedSlot();
    void pitchChangedSlot();
    void rateChangedSlot();
    void stateChangedSlot();
    void voiceChangedSlot();
    void volumeChangedSlot();

};

#endif

