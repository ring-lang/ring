
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTEXTTOSPEECH_H
#define GTEXTTOSPEECH_H
#include <QApplication>
#include <QTextToSpeech>
extern "C" {
#include "ring.h"
}

class GTextToSpeech : public QTextToSpeech
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char clocaleChangedEvent[200];
    char cpitchChangedEvent[200];
    char crateChangedEvent[200];
    char cstateChangedEvent[200];
    char cvoiceChangedEvent[200];
    char cvolumeChangedEvent[200];


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

