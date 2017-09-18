
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGUIAPPLICATION_H
#define GGUIAPPLICATION_H
#include <QApplication>
#include <QGuiApplication>
extern "C" {
#include "ring.h"
}

class GGuiApplication : public QGuiApplication
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char capplicationDisplayNameChangedEvent[100];
    char capplicationStateChangedEvent[100];
    char ccommitDataRequestEvent[100];
    char cfocusObjectChangedEvent[100];
    char cfocusWindowChangedEvent[100];
    char cfontDatabaseChangedEvent[100];
    char clastWindowClosedEvent[100];
    char clayoutDirectionChangedEvent[100];
    char cpaletteChangedEvent[100];
    char cprimaryScreenChangedEvent[100];
    char csaveStateRequestEvent[100];
    char cscreenAddedEvent[100];
    char cscreenRemovedEvent[100];


    GGuiApplication(int argc,char **parent,VM *pVM );

    ~GGuiApplication();

    void geteventparameters(void) ;

    void setapplicationDisplayNameChangedEvent(const char *cStr);
    void setapplicationStateChangedEvent(const char *cStr);
    void setcommitDataRequestEvent(const char *cStr);
    void setfocusObjectChangedEvent(const char *cStr);
    void setfocusWindowChangedEvent(const char *cStr);
    void setfontDatabaseChangedEvent(const char *cStr);
    void setlastWindowClosedEvent(const char *cStr);
    void setlayoutDirectionChangedEvent(const char *cStr);
    void setpaletteChangedEvent(const char *cStr);
    void setprimaryScreenChangedEvent(const char *cStr);
    void setsaveStateRequestEvent(const char *cStr);
    void setscreenAddedEvent(const char *cStr);
    void setscreenRemovedEvent(const char *cStr);


    const char *getapplicationDisplayNameChangedEvent(void);
    const char *getapplicationStateChangedEvent(void);
    const char *getcommitDataRequestEvent(void);
    const char *getfocusObjectChangedEvent(void);
    const char *getfocusWindowChangedEvent(void);
    const char *getfontDatabaseChangedEvent(void);
    const char *getlastWindowClosedEvent(void);
    const char *getlayoutDirectionChangedEvent(void);
    const char *getpaletteChangedEvent(void);
    const char *getprimaryScreenChangedEvent(void);
    const char *getsaveStateRequestEvent(void);
    const char *getscreenAddedEvent(void);
    const char *getscreenRemovedEvent(void);


  public slots:

    void applicationDisplayNameChangedSlot();
    void applicationStateChangedSlot();
    void commitDataRequestSlot();
    void focusObjectChangedSlot();
    void focusWindowChangedSlot();
    void fontDatabaseChangedSlot();
    void lastWindowClosedSlot();
    void layoutDirectionChangedSlot();
    void paletteChangedSlot();
    void primaryScreenChangedSlot();
    void saveStateRequestSlot();
    void screenAddedSlot();
    void screenRemovedSlot();

};

#endif

