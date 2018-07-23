
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTHREAD_H
#define GTHREAD_H
#include <QApplication>
#include <QThread>
extern "C" {
#include "ring.h"
}

class GThread : public QThread
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cStartedEvent[100];
    char cFinishedEvent[100];


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

