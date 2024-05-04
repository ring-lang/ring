
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GFILEDIALOG_H
#define GFILEDIALOG_H
#include "ringqt.h"
#include <QFileDialog>

extern "C" {
#include "ring.h"
}

class GFileDialog : public QFileDialog
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccurrentChangedEvent[RINGQT_EVENT_SIZE];
    char ccurrentUrlChangedEvent[RINGQT_EVENT_SIZE];
    char cdirectoryEnteredEvent[RINGQT_EVENT_SIZE];
    char cdirectoryUrlEnteredEvent[RINGQT_EVENT_SIZE];
    char cfileSelectedEvent[RINGQT_EVENT_SIZE];
    char cfilesSelectedEvent[RINGQT_EVENT_SIZE];
    char cfilterSelectedEvent[RINGQT_EVENT_SIZE];
    char curlSelectedEvent[RINGQT_EVENT_SIZE];
    char curlsSelectedEvent[RINGQT_EVENT_SIZE];


    GFileDialog(QWidget *parent,VM *pVM );

    ~GFileDialog();

    void geteventparameters(void) ;

    void setcurrentChangedEvent(const char *cStr);
    void setcurrentUrlChangedEvent(const char *cStr);
    void setdirectoryEnteredEvent(const char *cStr);
    void setdirectoryUrlEnteredEvent(const char *cStr);
    void setfileSelectedEvent(const char *cStr);
    void setfilesSelectedEvent(const char *cStr);
    void setfilterSelectedEvent(const char *cStr);
    void seturlSelectedEvent(const char *cStr);
    void seturlsSelectedEvent(const char *cStr);


    const char *getcurrentChangedEvent(void);
    const char *getcurrentUrlChangedEvent(void);
    const char *getdirectoryEnteredEvent(void);
    const char *getdirectoryUrlEnteredEvent(void);
    const char *getfileSelectedEvent(void);
    const char *getfilesSelectedEvent(void);
    const char *getfilterSelectedEvent(void);
    const char *geturlSelectedEvent(void);
    const char *geturlsSelectedEvent(void);


  public slots:

    void currentChangedSlot();
    void currentUrlChangedSlot();
    void directoryEnteredSlot();
    void directoryUrlEnteredSlot();
    void fileSelectedSlot();
    void filesSelectedSlot();
    void filterSelectedSlot();
    void urlSelectedSlot();
    void urlsSelectedSlot();



};

#endif

