/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */

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
    QString cKeyText ;
    int nModifiers ;
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
    char cPaintEvent[100];
    char cChildAddedEvent[100];
    char cChildPolishedEvent[100];
    char cChildRemovedEvent[100];	

    char cKeyPressFunc[100];
    char cMouseButtonPressFunc[100];
    char cMouseButtonReleaseFunc[100];
    char cMouseButtonDblClickFunc[100];
    char cMouseMoveFunc[100];
    char cCloseFunc[100];
    char cContextMenuFunc[100];
    char cDragEnterFunc[100];
    char cDragLeaveFunc[100];
    char cDragMoveFunc[100];
    char cDropFunc[100];
    char cEnterFunc[100];
    char cFocusInFunc[100];
    char cFocusOutFunc[100];
    char cKeyReleaseFunc[100];
    char cLeaveFunc[100];
    char cNonClientAreaMouseButtonDblClickFunc[100];
    char cNonClientAreaMouseButtonPressFunc[100];
    char cNonClientAreaMouseButtonReleaseFunc[100];
    char cNonClientAreaMouseMoveFunc[100];
    char cMoveFunc[100];
    char cResizeFunc[100];
    char cWindowActivateFunc[100];
    char cWindowBlockedFunc[100];
    char cWindowDeactivateFunc[100];
    char cWindowStateChangeFunc[100];
    char cWindowUnblockedFunc[100];
    char cPaintFunc[100];
    char cChildAddedFunc[100];
    char cChildPolishedFunc[100];
    char cChildRemovedFunc[100];	


    bool lEventOutput ;	

    QObject *pParentObject;
    QWidget *pParentWidget;

    QEvent *pEvent;
    QDropEvent *getDropEventObject(void);
    QDragMoveEvent *getDragMoveEventObject(void);
    QDragEnterEvent *getDragEnterEventObject(void);
    QDragLeaveEvent *getDragLeaveEventObject(void);
    QChildEvent *getChildEventObject(void);

    GAllEvents(QWidget *parent,VM *pVM );

    bool eventFilter(QObject *object, QEvent *event);

    void accept(void);
    void ignore(void);

    int  getKeyCode(void);
    QString getKeyText(void);
    int  getModifiers(void);
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
    void setPaintEvent(const char *cStr);
    void setChildAddedEvent(const char *cStr);
    void setChildPolishedEvent(const char *cStr);
    void setChildRemovedEvent(const char *cStr);

    const char *getKeyPressEvent(void);
    const char *getMouseButtonPressEvent(void);
    const char *getMouseButtonReleaseEvent(void);
    const char *getMouseButtonDblClickEvent(void);
    const char *getMouseMoveEvent(void);
    const char *getCloseEvent(void);
    const char *getContextMenuEvent(void);
    const char *getDragEnterEvent(void);
    const char *getDragLeaveEvent(void);
    const char *getDragMoveEvent(void);
    const char *getDropEvent(void);
    const char *getEnterEvent(void);
    const char *getFocusInEvent(void);
    const char *getFocusOutEvent(void);
    const char *getKeyReleaseEvent(void);
    const char *getLeaveEvent(void);
    const char *getNonClientAreaMouseButtonDblClickEvent(void);
    const char *getNonClientAreaMouseButtonPressEvent(void);
    const char *getNonClientAreaMouseButtonReleaseEvent(void);
    const char *getNonClientAreaMouseMoveEvent(void);
    const char *getMoveEvent(void);
    const char *getResizeEvent(void);
    const char *getWindowActivateEvent(void);
    const char *getWindowBlockedEvent(void);
    const char *getWindowDeactivateEvent(void);
    const char *getWindowStateChangeEvent(void);
    const char *getWindowUnblockedEvent(void);
    const char *getPaintEvent(void);
    const char *getChildAddedEvent(void);
    const char *getChildPolishedEvent(void);
    const char *getChildRemovedEvent(void);


    void setKeyPressFunc(const char *cStr);
    void setMouseButtonPressFunc(const char *cStr);
    void setMouseButtonReleaseFunc(const char *cStr);
    void setMouseButtonDblClickFunc(const char *cStr);
    void setMouseMoveFunc(const char *cStr);
    void setCloseFunc(const char *cStr);

    void setContextMenuFunc(const char *cStr);
    void setDragEnterFunc(const char *cStr);
    void setDragLeaveFunc(const char *cStr);
    void setDragMoveFunc(const char *cStr);
    void setDropFunc(const char *cStr);
    void setEnterFunc(const char *cStr);
    void setFocusInFunc(const char *cStr);
    void setFocusOutFunc(const char *cStr);
    void setKeyReleaseFunc(const char *cStr);
    void setLeaveFunc(const char *cStr);
    void setNonClientAreaMouseButtonDblClickFunc(const char *cStr);
    void setNonClientAreaMouseButtonPressFunc(const char *cStr);
    void setNonClientAreaMouseButtonReleaseFunc(const char *cStr);
    void setNonClientAreaMouseMoveFunc(const char *cStr);
    void setMoveFunc(const char *cStr);
    void setResizeFunc(const char *cStr);
    void setWindowActivateFunc(const char *cStr);
    void setWindowBlockedFunc(const char *cStr);
    void setWindowDeactivateFunc(const char *cStr);
    void setWindowStateChangeFunc(const char *cStr);
    void setWindowUnblockedFunc(const char *cStr);
    void setPaintFunc(const char *cStr);
    void setChildAddedFunc(const char *cStr);
    void setChildPolishedFunc(const char *cStr);
    void setChildRemovedFunc(const char *cStr);

    const char *getKeyPressFunc(void);
    const char *getMouseButtonPressFunc(void);
    const char *getMouseButtonReleaseFunc(void);
    const char *getMouseButtonDblClickFunc(void);
    const char *getMouseMoveFunc(void);
    const char *getCloseFunc(void);
    const char *getContextMenuFunc(void);
    const char *getDragEnterFunc(void);
    const char *getDragLeaveFunc(void);
    const char *getDragMoveFunc(void);
    const char *getDropFunc(void);
    const char *getEnterFunc(void);
    const char *getFocusInFunc(void);
    const char *getFocusOutFunc(void);
    const char *getKeyReleaseFunc(void);
    const char *getLeaveFunc(void);
    const char *getNonClientAreaMouseButtonDblClickFunc(void);
    const char *getNonClientAreaMouseButtonPressFunc(void);
    const char *getNonClientAreaMouseButtonReleaseFunc(void);
    const char *getNonClientAreaMouseMoveFunc(void);
    const char *getMoveFunc(void);
    const char *getResizeFunc(void);
    const char *getWindowActivateFunc(void);
    const char *getWindowBlockedFunc(void);
    const char *getWindowDeactivateFunc(void);
    const char *getWindowStateChangeFunc(void);
    const char *getWindowUnblockedFunc(void);
    const char *getPaintFunc(void);
    const char *getChildAddedFunc(void);
    const char *getChildPolishedFunc(void);
    const char *getChildRemovedFunc(void);

    void setEventOutput(bool x);

    QObject *getParentObject(void);
    QWidget *getParentWidget(void);
  
  private:

    void storeMouseState(QEvent *event);

    void callKeyPressEvent(void);
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
    void callPaintEvent(void);
    void callChildAddedEvent(void);
    void callChildPolishedEvent(void);
    void callChildRemovedEvent(void);

    void callKeyPressFunc(void);
    void callMouseButtonPressFunc(void);
    void callMouseButtonReleaseFunc(void);
    void callMouseButtonDblClickFunc(void);
    void callMouseMoveFunc(void);
    void callCloseFunc(void);
    void callContextMenuFunc(void);
    void callDragEnterFunc(void);
    void callDragLeaveFunc(void);
    void callDragMoveFunc(void);
    void callDropFunc(void);
    void callEnterFunc(void);
    void callFocusInFunc(void);
    void callFocusOutFunc(void);
    void callKeyReleaseFunc(void);
    void callLeaveFunc(void);
    void callNonClientAreaMouseButtonDblClickFunc(void);
    void callNonClientAreaMouseButtonPressFunc(void);
    void callNonClientAreaMouseButtonReleaseFunc(void);
    void callNonClientAreaMouseMoveFunc(void);
    void callMoveFunc(void);
    void callResizeFunc(void);
    void callWindowActivateFunc(void);
    void callWindowBlockedFunc(void);
    void callWindowDeactivateFunc(void);
    void callWindowStateChangeFunc(void);
    void callWindowUnblockedFunc(void);
    void callPaintFunc(void);
    void callChildAddedFunc(void);	
    void callChildPolishedFunc(void);
    void callChildRemovedFunc(void);
};

#endif 

