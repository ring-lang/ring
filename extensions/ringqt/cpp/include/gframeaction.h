
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GFRAMEACTION_H
#define GFRAMEACTION_H
#include <QApplication>
#include "ringqt.h"
#include <Qt3DLogic/QFrameAction>
extern "C" {
#include "ring.h"
}

class GFrameAction : public Qt3DLogic::QFrameAction
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ctriggeredEvent[RINGQT_EVENT_SIZE];


    GFrameAction(Qt3DCore::QNode *parent,VM *pVM );

    ~GFrameAction();

    void geteventparameters(void) ;

    void settriggeredEvent(const char *cStr);


    const char *gettriggeredEvent(void);


  public slots:

    void triggeredSlot();

};

#endif

