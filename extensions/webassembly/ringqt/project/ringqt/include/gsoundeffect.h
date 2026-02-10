
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSOUNDEFFECT_H
#define GSOUNDEFFECT_H
#include "ringqt.h"
#include <QSoundEffect>

extern "C" {
#include "ring.h"
}

class GSoundEffect : public QSoundEffect
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccategoryChangedEvent[RINGQT_EVENT_SIZE];
    char cloadedChangedEvent[RINGQT_EVENT_SIZE];
    char cloopCountChangedEvent[RINGQT_EVENT_SIZE];
    char cloopsRemainingChangedEvent[RINGQT_EVENT_SIZE];
    char cmutedChangedEvent[RINGQT_EVENT_SIZE];
    char cplayingChangedEvent[RINGQT_EVENT_SIZE];
    char csourceChangedEvent[RINGQT_EVENT_SIZE];
    char cstatusChangedEvent[RINGQT_EVENT_SIZE];
    char cvolumeChangedEvent[RINGQT_EVENT_SIZE];


    GSoundEffect(QObject *parent,VM *pVM );

    ~GSoundEffect();

    void geteventparameters(void) ;

    void setcategoryChangedEvent(const char *cStr);
    void setloadedChangedEvent(const char *cStr);
    void setloopCountChangedEvent(const char *cStr);
    void setloopsRemainingChangedEvent(const char *cStr);
    void setmutedChangedEvent(const char *cStr);
    void setplayingChangedEvent(const char *cStr);
    void setsourceChangedEvent(const char *cStr);
    void setstatusChangedEvent(const char *cStr);
    void setvolumeChangedEvent(const char *cStr);


    const char *getcategoryChangedEvent(void);
    const char *getloadedChangedEvent(void);
    const char *getloopCountChangedEvent(void);
    const char *getloopsRemainingChangedEvent(void);
    const char *getmutedChangedEvent(void);
    const char *getplayingChangedEvent(void);
    const char *getsourceChangedEvent(void);
    const char *getstatusChangedEvent(void);
    const char *getvolumeChangedEvent(void);


  public slots:

    void categoryChangedSlot();
    void loadedChangedSlot();
    void loopCountChangedSlot();
    void loopsRemainingChangedSlot();
    void mutedChangedSlot();
    void playingChangedSlot();
    void sourceChangedSlot();
    void statusChangedSlot();
    void volumeChangedSlot();



};

#endif

