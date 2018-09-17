
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GWEBENGINEVIEW_H
#define GWEBENGINEVIEW_H
#include <QApplication>
#include <QWebEngineView>
extern "C" {
#include "ring.h"
}

class GWebEngineView : public QWebEngineView
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cloadFinishedEvent[100];
    char cloadProgressEvent[100];
    char cloadStartedEvent[100];
    char cselectionChangedEvent[100];
    char ctitleChangedEvent[100];
    char curlChangedEvent[100];


    GWebEngineView(QWidget *parent,VM *pVM );

    ~GWebEngineView();

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

