
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GGUIAPPLICATION_H
#define GGUIAPPLICATION_H
#include "ringqt.h"
#include <QGuiApplication>

extern "C" {
#include "ring.h"
}

class GGuiApplication : public QGuiApplication
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char capplicationDisplayNameChangedEvent[RINGQT_EVENT_SIZE];
    char capplicationStateChangedEvent[RINGQT_EVENT_SIZE];
    char ccommitDataRequestEvent[RINGQT_EVENT_SIZE];
    char cfocusObjectChangedEvent[RINGQT_EVENT_SIZE];
    char cfocusWindowChangedEvent[RINGQT_EVENT_SIZE];
    char cfontDatabaseChangedEvent[RINGQT_EVENT_SIZE];
    char clastWindowClosedEvent[RINGQT_EVENT_SIZE];
    char clayoutDirectionChangedEvent[RINGQT_EVENT_SIZE];
    char cpaletteChangedEvent[RINGQT_EVENT_SIZE];
    char cprimaryScreenChangedEvent[RINGQT_EVENT_SIZE];
    char csaveStateRequestEvent[RINGQT_EVENT_SIZE];
    char cscreenAddedEvent[RINGQT_EVENT_SIZE];
    char cscreenRemovedEvent[RINGQT_EVENT_SIZE];


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

