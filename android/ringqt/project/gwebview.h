
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    char cloadFinishedEvent[100];
    char cloadProgressEvent[100];
    char cloadStartedEvent[100];
    char cselectionChangedEvent[100];
    char ctitleChangedEvent[100];
    char curlChangedEvent[100];


    GWebView(QObject *parent,VM *pVM );

    void setloadFinishedEvent(const char *cStr);
    void setloadProgressEvent(const char *cStr);
    void setloadStartedEvent(const char *cStr);
    void setselectionChangedEvent(const char *cStr);
    void settitleChangedEvent(const char *cStr);
    void seturlChangedEvent(const char *cStr);


  public slots:

    void loadFinishedSlot();
    void loadProgressSlot();
    void loadStartedSlot();
    void selectionChangedSlot();
    void titleChangedSlot();
    void urlChangedSlot();

};

#endif

