
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTHREAD_H
#define GTHREAD_H
#include "ringqt.h"
#include <QThread>
extern "C" {
#include "ring.h"
}

class GThread : public QThread
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cStartedEvent[RINGQT_EVENT_SIZE];
    char cFinishedEvent[RINGQT_EVENT_SIZE];


    GThread(QObject *parent,VM *pVM );

    ~GThread();

    void geteventparameters(void) ;

    void setStartedEvent(const char *cStr);
    void setFinishedEvent(const char *cStr);


    const char *getStartedEvent(void);
    const char *getFinishedEvent(void);


  public slots:

    void startedSlot();
    void finishedSlot();

};

#endif

