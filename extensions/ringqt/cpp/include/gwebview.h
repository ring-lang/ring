
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GWEBVIEW_H
#define GWEBVIEW_H
#include <QApplication>
#include <QWebView>
extern "C" {
#include "ring.h"
}

class GWebView : public QWebView
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cloadFinishedEvent[200];
    char cloadProgressEvent[200];
    char cloadStartedEvent[200];
    char cselectionChangedEvent[200];
    char ctitleChangedEvent[200];
    char curlChangedEvent[200];


    GWebView(QWidget *parent,VM *pVM );

    ~GWebView();

    void geteventparameters(void) ;

    void setloadFinishedEvent(const char *cStr);
    void setloadProgressEvent(const char *cStr);
    void setloadStartedEvent(const char *cStr);
    void setselectionChangedEvent(const char *cStr);
    void settitleChangedEvent(const char *cStr);
    void seturlChangedEvent(const char *cStr);


    const char *getloadFinishedEvent(void);
    const char *getloadProgressEvent(void);
    const char *getloadStartedEvent(void);
    const char *getselectionChangedEvent(void);
    const char *gettitleChangedEvent(void);
    const char *geturlChangedEvent(void);


  public slots:

    void loadFinishedSlot();
    void loadProgressSlot();
    void loadStartedSlot();
    void selectionChangedSlot();
    void titleChangedSlot();
    void urlChangedSlot();

};

#endif

