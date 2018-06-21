
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTEXTBROWSER_H
#define GTEXTBROWSER_H
#include <QApplication>
#include <QTextBrowser>
extern "C" {
#include "ring.h"
}

class GTextBrowser : public QTextBrowser
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char canchorClickedEvent[100];
    char cbackwardAvailableEvent[100];
    char cforwardAvailableEvent[100];
    char chighlightedEvent[100];
    char chistoryChangedEvent[100];
    char csourceChangedEvent[100];


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

