
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GNETWORKCONFIGURATIONMANAGER_H
#define GNETWORKCONFIGURATIONMANAGER_H
#include "ringqt.h"
#include <QNetworkConfigurationManager>

extern "C" {
#include "ring.h"
}

class GNetworkConfigurationManager : public QNetworkConfigurationManager
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cconfigurationAddedEvent[RINGQT_EVENT_SIZE];
    char cconfigurationChangedEvent[RINGQT_EVENT_SIZE];
    char cconfigurationRemovedEvent[RINGQT_EVENT_SIZE];
    char conlineStateChangedEvent[RINGQT_EVENT_SIZE];
    char cupdateCompletedEvent[RINGQT_EVENT_SIZE];


    GNetworkConfigurationManager(QObject *parent,VM *pVM );

    ~GNetworkConfigurationManager();

    void geteventparameters(void) ;

    void setconfigurationAddedEvent(const char *cStr);
    void setconfigurationChangedEvent(const char *cStr);
    void setconfigurationRemovedEvent(const char *cStr);
    void setonlineStateChangedEvent(const char *cStr);
    void setupdateCompletedEvent(const char *cStr);


    const char *getconfigurationAddedEvent(void);
    const char *getconfigurationChangedEvent(void);
    const char *getconfigurationRemovedEvent(void);
    const char *getonlineStateChangedEvent(void);
    const char *getupdateCompletedEvent(void);


  public slots:

    void configurationAddedSlot();
    void configurationChangedSlot();
    void configurationRemovedSlot();
    void onlineStateChangedSlot();
    void updateCompletedSlot();



};

#endif

