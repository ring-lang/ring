
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTEXTBROWSER_H
#define GTEXTBROWSER_H
#include "ringqt.h"
#include <QTextBrowser>
extern "C" {
#include "ring.h"
}

class GTextBrowser : public QTextBrowser
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char canchorClickedEvent[RINGQT_EVENT_SIZE];
    char cbackwardAvailableEvent[RINGQT_EVENT_SIZE];
    char cforwardAvailableEvent[RINGQT_EVENT_SIZE];
    char chighlightedEvent[RINGQT_EVENT_SIZE];
    char chistoryChangedEvent[RINGQT_EVENT_SIZE];
    char csourceChangedEvent[RINGQT_EVENT_SIZE];


    GTextBrowser(QWidget *parent,VM *pVM );

    ~GTextBrowser();

    void geteventparameters(void) ;

    void setanchorClickedEvent(const char *cStr);
    void setbackwardAvailableEvent(const char *cStr);
    void setforwardAvailableEvent(const char *cStr);
    void sethighlightedEvent(const char *cStr);
    void sethistoryChangedEvent(const char *cStr);
    void setsourceChangedEvent(const char *cStr);


    const char *getanchorClickedEvent(void);
    const char *getbackwardAvailableEvent(void);
    const char *getforwardAvailableEvent(void);
    const char *gethighlightedEvent(void);
    const char *gethistoryChangedEvent(void);
    const char *getsourceChangedEvent(void);


  public slots:

    void anchorClickedSlot();
    void backwardAvailableSlot();
    void forwardAvailableSlot();
    void highlightedSlot();
    void historyChangedSlot();
    void sourceChangedSlot();

};

#endif

