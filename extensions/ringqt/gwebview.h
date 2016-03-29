
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

    char ciconChangedEvent[100];
    char clinkClickedEvent[100];
    char cloadFinishedEvent[100];
    char cloadProgressEvent[100];
    char cloadStartedEvent[100];
    char cselectionChangedEvent[100];
    char cstatusBarMessageEvent[100];
    char ctitleChangedEvent[100];
    char curlChangedEvent[100];


    GWebView(QWidget *parent,VM *pVM );

    void seticonChangedEvent(const char *cStr);
    void setlinkClickedEvent(const char *cStr);
    void setloadFinishedEvent(const char *cStr);
    void setloadProgressEvent(const char *cStr);
    void setloadStartedEvent(const char *cStr);
    void setselectionChangedEvent(const char *cStr);
    void setstatusBarMessageEvent(const char *cStr);
    void settitleChangedEvent(const char *cStr);
    void seturlChangedEvent(const char *cStr);


  public slots:

    void iconChangedSlot();
    void linkClickedSlot();
    void loadFinishedSlot();
    void loadProgressSlot();
    void loadStartedSlot();
    void selectionChangedSlot();
    void statusBarMessageSlot();
    void titleChangedSlot();
    void urlChangedSlot();

};

#endif

