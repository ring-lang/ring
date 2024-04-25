
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GMOVIE_H
#define GMOVIE_H
#include "ringqt.h"
#include <QtGui>
extern "C" {
#include "ring.h"
}

class GMovie : public QMovie
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cerrorEvent[RINGQT_EVENT_SIZE];
    char cfinishedEvent[RINGQT_EVENT_SIZE];
    char cframeChangedEvent[RINGQT_EVENT_SIZE];
    char cresizedEvent[RINGQT_EVENT_SIZE];
    char cstartedEvent[RINGQT_EVENT_SIZE];
    char cstateChangedEvent[RINGQT_EVENT_SIZE];
    char cupdatedEvent[RINGQT_EVENT_SIZE];


    GMovie(QObject * parent,VM *pVM );

    ~GMovie();

    void geteventparameters(void) ;

    void seterrorEvent(const char *cStr);
    void setfinishedEvent(const char *cStr);
    void setframeChangedEvent(const char *cStr);
    void setresizedEvent(const char *cStr);
    void setstartedEvent(const char *cStr);
    void setstateChangedEvent(const char *cStr);
    void setupdatedEvent(const char *cStr);


    const char *geterrorEvent(void);
    const char *getfinishedEvent(void);
    const char *getframeChangedEvent(void);
    const char *getresizedEvent(void);
    const char *getstartedEvent(void);
    const char *getstateChangedEvent(void);
    const char *getupdatedEvent(void);


  public slots:

    void errorSlot();
    void finishedSlot();
    void frameChangedSlot();
    void resizedSlot();
    void startedSlot();
    void stateChangedSlot();
    void updatedSlot();

};

#endif

