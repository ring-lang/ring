
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GFILESYSTEMWATCHER_H
#define GFILESYSTEMWATCHER_H
#include "ringqt.h"
#include <QFileSystemWatcher>

extern "C" {
#include "ring.h"
}

class GFileSystemWatcher : public QFileSystemWatcher
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cdirectoryChangedEvent[RINGQT_EVENT_SIZE];
    char cfileChangedEvent[RINGQT_EVENT_SIZE];


    GFileSystemWatcher(QObject *parent,VM *pVM );

    ~GFileSystemWatcher();

    void geteventparameters(void) ;

    void setdirectoryChangedEvent(const char *cStr);
    void setfileChangedEvent(const char *cStr);


    const char *getdirectoryChangedEvent(void);
    const char *getfileChangedEvent(void);


  public slots:

    void directoryChangedSlot();
    void fileChangedSlot();



};

#endif

