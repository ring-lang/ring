
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPROCESS_H
#define GPROCESS_H
#include "ringqt.h"
#include <QProcess>

extern "C" {
#include "ring.h"
}

class GProcess : public QProcess
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char creadyReadStandardErrorEvent[RINGQT_EVENT_SIZE];
    char creadyReadStandardOutputEvent[RINGQT_EVENT_SIZE];


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

