
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPROCESS_H
#define GPROCESS_H
#include <QApplication>
#include <QProcess>
extern "C" {
#include "ring.h"
}

class GProcess : public QProcess
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char creadyReadStandardErrorEvent[200];
    char creadyReadStandardOutputEvent[200];


    GProcess(QObject *parent,VM *pVM );

    ~GProcess();

    void geteventparameters(void) ;

    void setreadyReadStandardErrorEvent(const char *cStr);
    void setreadyReadStandardOutputEvent(const char *cStr);


    const char *getreadyReadStandardErrorEvent(void);
    const char *getreadyReadStandardOutputEvent(void);


  public slots:

    void readyReadStandardErrorSlot();
    void readyReadStandardOutputSlot();

};

#endif

