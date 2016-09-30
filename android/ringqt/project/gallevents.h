/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef GALLEVENTS_H
#define GALLEVENTS_H
#include <QApplication>
#include <QWidget>
#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>

extern "C" {
#include "ring.h"
}

class GAllEvents : public QWidget
{

  Q_OBJECT

  public:

    VM *pVM;

    int nKeyCode ;
    int nX ;
    int nY ;
    int nGlobalX ;
    int nGlobalY ;
    int nButton ;
    int nButtons ;

    char cKeyPressEvent[100];
    char cMouseButtonPressEvent[100];
    char cMouseButtonReleaseEvent[100];
    char cMouseButtonDblClickEvent[100];
    char cMouseMoveEvent[100];
    char cCloseEvent[100];
    char cContextMenuEvent[100];
    char cDragEnterEvent[100];
    char cDragLeaveEvent[100];
    char cDragMoveEvent[100];
    char cDropEvent[100];
    char cEnterEvent[100];
    char cFocusInEvent[100];
    char cFocusOutEvent[100];
    char cKeyReleaseEvent[100];
    char cLeaveEvent[100];
    char cNonClientAreaMouseButtonDblClickEvent[100];
    char cNonClientAreaMouseButtonPressEvent[100];
    char cNonClientAreaMouseButtonReleaseEvent[100];
    char cNonClientAreaMouseMoveEvent[100];
    char cMoveEvent[100];
    char cResizeEvent[100];
    char cWindowActivateEvent[100];
    char cWindowBlockedEvent[100];
    char cWindowDeactivateEvent[100];
    char cWindowStateChangeEvent[100];
    char cWindowUnblockedEvent[100];

    QEvent *pEvent;

    GAllEvents(QWidget *parent,VM *pVM );

    bool eventFilter(QObject *object, QEvent *event);

    void accept(void);
    void ignore(void);

    int  getKeyCode(void);
    int  getx(void);
    int  gety(void);
    int  getglobalx(void);
    int  getglobaly(void);
    int  getbutton(void);
    int  getbuttons(void);

    void setKeyPressEvent(const char *cStr);
    void setMouseButtonPressEvent(const char *cStr);
    void setMouseButtonReleaseEvent(const char *cStr);
    void setMouseButtonDblClickEvent(const char *cStr);
    void setMouseMoveEvent(const char *cStr);
    void setCloseEvent(const char *cStr);

    void setContextMenuEvent(const char *cStr);
    void setDragEnterEvent(const char *cStr);
    void setDragLeaveEvent(const char *cStr);
    void setDragMoveEvent(const char *cStr);
    void setDropEvent(const char *cStr);
    void setEnterEvent(const char *cStr);
    void setFocusInEvent(const char *cStr);
    void setFocusOutEvent(const char *cStr);
    void setKeyReleaseEvent(const char *cStr);
    void setLeaveEvent(const char *cStr);
    void setNonClientAreaMouseButtonDblClickEvent(const char *cStr);
    void setNonClientAreaMouseButtonPressEvent(const char *cStr);
    void setNonClientAreaMouseButtonReleaseEvent(const char *cStr);
    void setNonClientAreaMouseMoveEvent(const char *cStr);
    void setMoveEvent(const char *cStr);
    void setResizeEvent(const char *cStr);
    void setWindowActivateEvent(const char *cStr);
    void setWindowBlockedEvent(const char *cStr);
    void setWindowDeactivateEvent(const char *cStr);
    void setWindowStateChangeEvent(const char *cStr);
    void setWindowUnblockedEvent(const char *cStr);
  
  private:

    void callKeyPressEvent(void);
    void storeMouseState(QEvent *event);
    void callMouseButtonPressEvent(void);
    void callMouseButtonReleaseEvent(void);
    void callMouseButtonDblClickEvent(void);
    void callMouseMoveEvent(void);
    void callCloseEvent(void);
    void callContextMenuEvent(void);
    void callDragEnterEvent(void);
    void callDragLeaveEvent(void);
    void callDragMoveEvent(void);
    void callDropEvent(void);
    void callEnterEvent(void);
    void callFocusInEvent(void);
    void callFocusOutEvent(void);
    void callKeyReleaseEvent(void);
    void callLeaveEvent(void);
    void callNonClientAreaMouseButtonDblClickEvent(void);
    void callNonClientAreaMouseButtonPressEvent(void);
    void callNonClientAreaMouseButtonReleaseEvent(void);
    void callNonClientAreaMouseMoveEvent(void);
    void callMoveEvent(void);
    void callResizeEvent(void);
    void callWindowActivateEvent(void);
    void callWindowBlockedEvent(void);
    void callWindowDeactivateEvent(void);
    void callWindowStateChangeEvent(void);
    void callWindowUnblockedEvent(void);
	
};

#endif 

