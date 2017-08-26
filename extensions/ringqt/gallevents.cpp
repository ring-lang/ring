/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */

extern "C" {
#include "ring.h"
}
#include "gallevents.h"

GAllEvents::GAllEvents(QWidget *parent,VM *pVM)  : QWidget()
{
	this->pVM = pVM;
	this->pEvent = NULL;
	this->pParentWidget = parent;
	strcpy(this->cKeyPressEvent,"");
	strcpy(this->cMouseButtonPressEvent,"");
	strcpy(this->cMouseButtonReleaseEvent,"");
	strcpy(this->cMouseButtonDblClickEvent,"");
	strcpy(this->cMouseMoveEvent,"");
	strcpy(this->cCloseEvent,"");
	strcpy(this->cContextMenuEvent,"");
	strcpy(this->cDragEnterEvent,"");
	strcpy(this->cDragLeaveEvent,"");
	strcpy(this->cDragMoveEvent,"");
	strcpy(this->cDropEvent,"");
	strcpy(this->cEnterEvent,"");
	strcpy(this->cFocusInEvent,"");
	strcpy(this->cFocusOutEvent,"");
	strcpy(this->cKeyReleaseEvent,"");
	strcpy(this->cLeaveEvent,"");
	strcpy(this->cNonClientAreaMouseButtonDblClickEvent,"");
	strcpy(this->cNonClientAreaMouseButtonPressEvent,"");
	strcpy(this->cNonClientAreaMouseButtonReleaseEvent,"");
	strcpy(this->cNonClientAreaMouseMoveEvent,"");
	strcpy(this->cMoveEvent,"");
	strcpy(this->cResizeEvent,"");
	strcpy(this->cWindowActivateEvent,"");
	strcpy(this->cWindowBlockedEvent,"");
	strcpy(this->cWindowDeactivateEvent,"");
	strcpy(this->cWindowStateChangeEvent,"");
	strcpy(this->cWindowUnblockedEvent,"");
	strcpy(this->cPaintEvent,"");
	this->lEventOutput = true ;
}

bool GAllEvents::eventFilter(QObject *object, QEvent *event)
{
	this->pEvent = event ;
	this->lEventOutput = true ;
	this->pParentObject = object;
	if ((event->type() == QEvent::KeyPress) && (strcmp(this->cKeyPressEvent,"")!=0) ) {
	        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
		this->nKeyCode = keyEvent->key();
		this->nModifiers = keyEvent->modifiers();
		this->callKeyPressEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::MouseButtonPress) && (strcmp(this->cMouseButtonPressEvent,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseButtonPressEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::MouseButtonRelease) && (strcmp(this->cMouseButtonReleaseEvent,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseButtonReleaseEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::MouseButtonDblClick) && (strcmp(this->cMouseButtonDblClickEvent,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseButtonDblClickEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::MouseMove) && (strcmp(this->cMouseMoveEvent,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseMoveEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Close) && (strcmp(this->cCloseEvent,"")!=0) ) {
		this->callCloseEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::ContextMenu) && (strcmp(this->cContextMenuEvent,"")!=0) ) {
		this->callContextMenuEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::DragEnter) && (strcmp(this->cDragEnterEvent,"")!=0) ) {
		this->callDragEnterEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::DragLeave) && (strcmp(this->cDragLeaveEvent,"")!=0) ) {
		this->callDragLeaveEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::DragMove) && (strcmp(this->cDragMoveEvent,"")!=0) ) {
		this->callDragMoveEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Drop) && (strcmp(this->cDropEvent,"")!=0) ) {
		this->callDropEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Enter) && (strcmp(this->cEnterEvent,"")!=0) ) {
		this->callEnterEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::FocusIn) && (strcmp(this->cFocusInEvent,"")!=0) ) {
		this->callFocusInEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::FocusOut) && (strcmp(this->cFocusOutEvent,"")!=0) ) {
		this->callFocusOutEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::KeyRelease) && (strcmp(this->cKeyReleaseEvent,"")!=0) ) {
		this->callKeyReleaseEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Leave) && (strcmp(this->cLeaveEvent,"")!=0) ) {
		this->callLeaveEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseButtonDblClick) && (strcmp(this->cNonClientAreaMouseButtonDblClickEvent,"")!=0) ) {
		this->callNonClientAreaMouseButtonDblClickEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseButtonPress) && (strcmp(this->cNonClientAreaMouseButtonPressEvent,"")!=0) ) {
		this->callNonClientAreaMouseButtonPressEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseButtonRelease) && (strcmp(this->cNonClientAreaMouseButtonReleaseEvent,"")!=0) ) {
		this->callNonClientAreaMouseButtonReleaseEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseMove) && (strcmp(this->cNonClientAreaMouseMoveEvent,"")!=0) ) {
		this->callNonClientAreaMouseMoveEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Move) && (strcmp(this->cMoveEvent,"")!=0) ) {
		this->callMoveEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Resize) && (strcmp(this->cResizeEvent,"")!=0) ) {
		this->callResizeEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::WindowActivate) && (strcmp(this->cWindowActivateEvent,"")!=0) ) {
		this->callWindowActivateEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::WindowBlocked) && (strcmp(this->cWindowBlockedEvent,"")!=0) ) {
		this->callWindowBlockedEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::WindowDeactivate) && (strcmp(this->cWindowDeactivateEvent,"")!=0) ) {
		this->callWindowDeactivateEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::WindowStateChange) && (strcmp(this->cWindowStateChangeEvent,"")!=0) ) {
		this->callWindowStateChangeEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::WindowUnblocked) && (strcmp(this->cWindowUnblockedEvent,"")!=0) ) {
		this->callWindowUnblockedEvent();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Paint) && (strcmp(this->cPaintEvent,"")!=0) ) {
		this->callPaintEvent();
 		return this->lEventOutput;
    	}


	if ((event->type() == QEvent::KeyPress) && (strcmp(this->cKeyPressFunc,"")!=0) ) {
	        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
		this->nKeyCode = keyEvent->key();
		this->nModifiers = keyEvent->modifiers();
		this->callKeyPressFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::MouseButtonPress) && (strcmp(this->cMouseButtonPressFunc,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseButtonPressFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::MouseButtonRelease) && (strcmp(this->cMouseButtonReleaseFunc,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseButtonReleaseFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::MouseButtonDblClick) && (strcmp(this->cMouseButtonDblClickFunc,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseButtonDblClickFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::MouseMove) && (strcmp(this->cMouseMoveFunc,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseMoveFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Close) && (strcmp(this->cCloseFunc,"")!=0) ) {
		this->callCloseFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::ContextMenu) && (strcmp(this->cContextMenuFunc,"")!=0) ) {
		this->callContextMenuFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::DragEnter) && (strcmp(this->cDragEnterFunc,"")!=0) ) {
		this->callDragEnterFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::DragLeave) && (strcmp(this->cDragLeaveFunc,"")!=0) ) {
		this->callDragLeaveFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::DragMove) && (strcmp(this->cDragMoveFunc,"")!=0) ) {
		this->callDragMoveFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Drop) && (strcmp(this->cDropFunc,"")!=0) ) {
		this->callDropFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Enter) && (strcmp(this->cEnterFunc,"")!=0) ) {
		this->callEnterFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::FocusIn) && (strcmp(this->cFocusInFunc,"")!=0) ) {
		this->callFocusInFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::FocusOut) && (strcmp(this->cFocusOutFunc,"")!=0) ) {
		this->callFocusOutFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::KeyRelease) && (strcmp(this->cKeyReleaseFunc,"")!=0) ) {
		this->callKeyReleaseFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Leave) && (strcmp(this->cLeaveFunc,"")!=0) ) {
		this->callLeaveFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseButtonDblClick) && (strcmp(this->cNonClientAreaMouseButtonDblClickFunc,"")!=0) ) {
		this->callNonClientAreaMouseButtonDblClickFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseButtonPress) && (strcmp(this->cNonClientAreaMouseButtonPressFunc,"")!=0) ) {
		this->callNonClientAreaMouseButtonPressFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseButtonRelease) && (strcmp(this->cNonClientAreaMouseButtonReleaseFunc,"")!=0) ) {
		this->callNonClientAreaMouseButtonReleaseFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseMove) && (strcmp(this->cNonClientAreaMouseMoveFunc,"")!=0) ) {
		this->callNonClientAreaMouseMoveFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Move) && (strcmp(this->cMoveFunc,"")!=0) ) {
		this->callMoveFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Resize) && (strcmp(this->cResizeFunc,"")!=0) ) {
		this->callResizeFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::WindowActivate) && (strcmp(this->cWindowActivateFunc,"")!=0) ) {
		this->callWindowActivateFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::WindowBlocked) && (strcmp(this->cWindowBlockedFunc,"")!=0) ) {
		this->callWindowBlockedFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::WindowDeactivate) && (strcmp(this->cWindowDeactivateFunc,"")!=0) ) {
		this->callWindowDeactivateFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::WindowStateChange) && (strcmp(this->cWindowStateChangeFunc,"")!=0) ) {
		this->callWindowStateChangeFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::WindowUnblocked) && (strcmp(this->cWindowUnblockedFunc,"")!=0) ) {
		this->callWindowUnblockedFunc();
 		return this->lEventOutput;
    	}
        else if ((event->type() == QEvent::Paint) && (strcmp(this->cPaintFunc,"")!=0) ) {
		this->callPaintFunc();
 		return this->lEventOutput;
    	}


	return false;
}

void GAllEvents::accept(void)
{
	if (this->pEvent != NULL)
		this->pEvent->accept();
}

void GAllEvents::ignore(void)
{
	if (this->pEvent != NULL)
		this->pEvent->ignore();
}

void GAllEvents::storeMouseState(QEvent *event)
{
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
	this->nX = mouseEvent->x();
	this->nY = mouseEvent->y();
	this->nGlobalX = mouseEvent->globalX();
	this->nGlobalY = mouseEvent->globalY();
	this->nButton = mouseEvent->button();
	this->nButtons = mouseEvent->buttons();
}
 
int GAllEvents::getKeyCode(void)
{
	return this->nKeyCode ;
}

int GAllEvents::getModifiers(void)
{
	return this->nModifiers ;
}


int GAllEvents::getx(void)
{
	return this->nX ;
}

int GAllEvents::gety(void)
{
	return this->nY ;
}

int GAllEvents::getglobalx(void)
{
	return this->nGlobalX ;
}

int GAllEvents::getglobaly(void)
{
	return this->nGlobalY ;
}

int GAllEvents::getbutton(void)
{
	return this->nButton ;
}

int GAllEvents::getbuttons(void)
{
	return this->nButtons ;
}

void GAllEvents::setKeyPressEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cKeyPressEvent,cStr);
}


void GAllEvents::callKeyPressEvent(void)
{
	if (strcmp(this->cKeyPressEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cKeyPressEvent);
}

void GAllEvents::setMouseButtonPressEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cMouseButtonPressEvent,cStr);
}

void GAllEvents::callMouseButtonPressEvent(void)
{
	if (strcmp(this->cMouseButtonPressEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cMouseButtonPressEvent);
}

void GAllEvents::setMouseButtonReleaseEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cMouseButtonReleaseEvent,cStr);
}

void GAllEvents::callMouseButtonReleaseEvent(void)
{
	if (strcmp(this->cMouseButtonReleaseEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cMouseButtonReleaseEvent);
}

void GAllEvents::setMouseButtonDblClickEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cMouseButtonDblClickEvent,cStr);
}

void GAllEvents::callMouseButtonDblClickEvent(void)
{
	if (strcmp(this->cMouseButtonDblClickEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cMouseButtonDblClickEvent);
}

void GAllEvents::setMouseMoveEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cMouseMoveEvent,cStr);
}

void GAllEvents::callMouseMoveEvent(void)
{
	if (strcmp(this->cMouseMoveEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cMouseMoveEvent);
}

void GAllEvents::setCloseEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cCloseEvent,cStr);
}

void GAllEvents::callCloseEvent(void)
{
	if (strcmp(this->cCloseEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cCloseEvent);
}

void GAllEvents::setContextMenuEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cContextMenuEvent,cStr);
}

void GAllEvents::callContextMenuEvent(void)
{
	if (strcmp(this->cContextMenuEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cContextMenuEvent);
}

void GAllEvents::setDragEnterEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cDragEnterEvent,cStr);
}

void GAllEvents::callDragEnterEvent(void)
{
	if (strcmp(this->cDragEnterEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cDragEnterEvent);
}

void GAllEvents::setDragLeaveEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cDragLeaveEvent,cStr);
}

void GAllEvents::callDragLeaveEvent(void)
{
	if (strcmp(this->cDragLeaveEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cDragLeaveEvent);
}

void GAllEvents::setDragMoveEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cDragMoveEvent,cStr);
}

void GAllEvents::callDragMoveEvent(void)
{
	if (strcmp(this->cDragMoveEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cDragMoveEvent);
}

void GAllEvents::setDropEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cDropEvent,cStr);
}

void GAllEvents::callDropEvent(void)
{
	if (strcmp(this->cDropEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cDropEvent);
}

void GAllEvents::setEnterEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cEnterEvent,cStr);
}

void GAllEvents::callEnterEvent(void)
{
	if (strcmp(this->cEnterEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cEnterEvent);
}

void GAllEvents::setFocusInEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cFocusInEvent,cStr);
}

void GAllEvents::callFocusInEvent(void)
{
	if (strcmp(this->cFocusInEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cFocusInEvent);
}

void GAllEvents::setFocusOutEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cFocusOutEvent,cStr);
}

void GAllEvents::callFocusOutEvent(void)
{
	if (strcmp(this->cFocusOutEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cFocusOutEvent);
}

void GAllEvents::setKeyReleaseEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cKeyReleaseEvent,cStr);
}

void GAllEvents::callKeyReleaseEvent(void)
{
	if (strcmp(this->cKeyReleaseEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cKeyReleaseEvent);
}

void GAllEvents::setLeaveEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cLeaveEvent,cStr);
}

void GAllEvents::callLeaveEvent(void)
{
	if (strcmp(this->cLeaveEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cLeaveEvent);
}

void GAllEvents::setNonClientAreaMouseButtonDblClickEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cNonClientAreaMouseButtonDblClickEvent,cStr);
}

void GAllEvents::callNonClientAreaMouseButtonDblClickEvent(void)
{
	if (strcmp(this->cNonClientAreaMouseButtonDblClickEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cNonClientAreaMouseButtonDblClickEvent);
}

void GAllEvents::setNonClientAreaMouseButtonPressEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cNonClientAreaMouseButtonPressEvent,cStr);
}

void GAllEvents::callNonClientAreaMouseButtonPressEvent(void)
{
	if (strcmp(this->cNonClientAreaMouseButtonPressEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cNonClientAreaMouseButtonPressEvent);
}

void GAllEvents::setNonClientAreaMouseButtonReleaseEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cNonClientAreaMouseButtonReleaseEvent,cStr);
}

void GAllEvents::callNonClientAreaMouseButtonReleaseEvent(void)
{
	if (strcmp(this->cNonClientAreaMouseButtonReleaseEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cNonClientAreaMouseButtonReleaseEvent);
}

void GAllEvents::setNonClientAreaMouseMoveEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cNonClientAreaMouseMoveEvent,cStr);
}

void GAllEvents::callNonClientAreaMouseMoveEvent(void)
{
	if (strcmp(this->cNonClientAreaMouseMoveEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cNonClientAreaMouseMoveEvent);
}

void GAllEvents::setMoveEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cMoveEvent,cStr);
}

void GAllEvents::callMoveEvent(void)
{
	if (strcmp(this->cMoveEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cMoveEvent);
}

void GAllEvents::setResizeEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cResizeEvent,cStr);
}

void GAllEvents::callResizeEvent(void)
{
	if (strcmp(this->cResizeEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cResizeEvent);
}

void GAllEvents::setWindowActivateEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cWindowActivateEvent,cStr);
}

void GAllEvents::callWindowActivateEvent(void)
{
	if (strcmp(this->cWindowActivateEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cWindowActivateEvent);
}

void GAllEvents::setWindowBlockedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cWindowBlockedEvent,cStr);
}

void GAllEvents::callWindowBlockedEvent(void)
{
	if (strcmp(this->cWindowBlockedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cWindowBlockedEvent);
}

void GAllEvents::setWindowDeactivateEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cWindowDeactivateEvent,cStr);
}

void GAllEvents::callWindowDeactivateEvent(void)
{
	if (strcmp(this->cWindowDeactivateEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cWindowDeactivateEvent);
}

void GAllEvents::setWindowStateChangeEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cWindowStateChangeEvent,cStr);
}

void GAllEvents::callWindowStateChangeEvent(void)
{
	if (strcmp(this->cWindowStateChangeEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cWindowStateChangeEvent);
}

void GAllEvents::setWindowUnblockedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cWindowUnblockedEvent,cStr);
}

void GAllEvents::callWindowUnblockedEvent(void)
{
	if (strcmp(this->cWindowUnblockedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cWindowUnblockedEvent);
}

void GAllEvents::setPaintEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cPaintEvent,cStr);
}

void GAllEvents::callPaintEvent(void)
{
	if (strcmp(this->cPaintEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cPaintEvent);
}

const char *GAllEvents::getKeyPressEvent(void)
{
	return this->cKeyPressEvent  ;
}

const char *GAllEvents::getMouseButtonPressEvent(void)
{
	return this->cMouseButtonPressEvent  ;
}

const char *GAllEvents::getMouseButtonReleaseEvent(void)
{
	return this->cMouseButtonReleaseEvent  ;
}

const char *GAllEvents::getMouseButtonDblClickEvent(void)
{
	return this->cMouseButtonDblClickEvent  ;
}

const char *GAllEvents::getMouseMoveEvent(void)
{
	return this->cMouseMoveEvent  ;
}

const char *GAllEvents::getCloseEvent(void)
{
	return this->cCloseEvent  ;
}

const char *GAllEvents::getContextMenuEvent(void)
{
	return this->cContextMenuEvent  ;
}

const char *GAllEvents::getDragEnterEvent(void)
{
	return this->cDragEnterEvent  ;
}

const char *GAllEvents::getDragLeaveEvent(void)
{
	return this->cDragLeaveEvent ;
}

const char *GAllEvents::getDragMoveEvent(void)
{
	return this->cDragMoveEvent  ;
}

const char *GAllEvents::getDropEvent(void)
{
	return this->cDropEvent  ;
}

const char *GAllEvents::getEnterEvent(void)
{
	return this->cEnterEvent  ;
}

const char *GAllEvents::getFocusInEvent(void)
{
	return this->cFocusInEvent  ;
}

const char *GAllEvents::getFocusOutEvent(void)
{
	return this->cFocusOutEvent  ;
}

const char *GAllEvents::getKeyReleaseEvent(void)
{
	return this->cKeyReleaseEvent  ;
}

const char *GAllEvents::getLeaveEvent(void)
{
	return this->cLeaveEvent  ;
}

const char *GAllEvents::getNonClientAreaMouseButtonDblClickEvent(void)
{
	return this->cNonClientAreaMouseButtonDblClickEvent  ;
}

const char *GAllEvents::getNonClientAreaMouseButtonPressEvent(void)
{
	return this->cNonClientAreaMouseButtonPressEvent  ;
}

const char *GAllEvents::getNonClientAreaMouseButtonReleaseEvent(void)
{
	return this->cNonClientAreaMouseButtonReleaseEvent  ;
}

const char *GAllEvents::getNonClientAreaMouseMoveEvent(void)
{
	return this->cNonClientAreaMouseMoveEvent  ;
}

const char *GAllEvents::getMoveEvent(void)
{
	return this->cMoveEvent  ;
}

const char *GAllEvents::getResizeEvent(void)
{
	return this->cResizeEvent  ;
}

const char *GAllEvents::getWindowActivateEvent(void)
{
	return this->cWindowActivateEvent  ;
}

const char *GAllEvents::getWindowBlockedEvent(void)
{
	return this->cWindowBlockedEvent  ;
}

const char *GAllEvents::getWindowDeactivateEvent(void)
{
	return this->cWindowDeactivateEvent  ;
}

const char *GAllEvents::getWindowStateChangeEvent(void)
{
	return this->cWindowStateChangeEvent  ;
}

const char *GAllEvents::getWindowUnblockedEvent(void)
{
	return this->cWindowUnblockedEvent  ;
}

const char *GAllEvents::getPaintEvent(void)
{
	return this->cPaintEvent  ;
}

void GAllEvents::setEventOutput(bool x)
{
	this->lEventOutput = x ;
}

QObject *GAllEvents::getParentObject(void)
{
	return this->pParentObject;
}

QWidget *GAllEvents::getParentWidget(void)
{
	return this->pParentWidget;
}


// Using Function Call Directly Instead of Eval()

void GAllEvents::setKeyPressFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cKeyPressFunc,cStr);
}


void GAllEvents::callKeyPressFunc(void)
{
	if (strcmp(this->cKeyPressFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cKeyPressFunc);
}

void GAllEvents::setMouseButtonPressFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cMouseButtonPressFunc,cStr);
}

void GAllEvents::callMouseButtonPressFunc(void)
{
	if (strcmp(this->cMouseButtonPressFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cMouseButtonPressFunc);
}

void GAllEvents::setMouseButtonReleaseFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cMouseButtonReleaseFunc,cStr);
}

void GAllEvents::callMouseButtonReleaseFunc(void)
{
	if (strcmp(this->cMouseButtonReleaseFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cMouseButtonReleaseFunc);
}

void GAllEvents::setMouseButtonDblClickFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cMouseButtonDblClickFunc,cStr);
}

void GAllEvents::callMouseButtonDblClickFunc(void)
{
	if (strcmp(this->cMouseButtonDblClickFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cMouseButtonDblClickFunc);
}

void GAllEvents::setMouseMoveFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cMouseMoveFunc,cStr);
}

void GAllEvents::callMouseMoveFunc(void)
{
	if (strcmp(this->cMouseMoveFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cMouseMoveFunc);
}

void GAllEvents::setCloseFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cCloseFunc,cStr);
}

void GAllEvents::callCloseFunc(void)
{
	if (strcmp(this->cCloseFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cCloseFunc);
}

void GAllEvents::setContextMenuFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cContextMenuFunc,cStr);
}

void GAllEvents::callContextMenuFunc(void)
{
	if (strcmp(this->cContextMenuFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cContextMenuFunc);
}

void GAllEvents::setDragEnterFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cDragEnterFunc,cStr);
}

void GAllEvents::callDragEnterFunc(void)
{
	if (strcmp(this->cDragEnterFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cDragEnterFunc);
}

void GAllEvents::setDragLeaveFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cDragLeaveFunc,cStr);
}

void GAllEvents::callDragLeaveFunc(void)
{
	if (strcmp(this->cDragLeaveFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cDragLeaveFunc);
}

void GAllEvents::setDragMoveFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cDragMoveFunc,cStr);
}

void GAllEvents::callDragMoveFunc(void)
{
	if (strcmp(this->cDragMoveFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cDragMoveFunc);
}

void GAllEvents::setDropFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cDropFunc,cStr);
}

void GAllEvents::callDropFunc(void)
{
	if (strcmp(this->cDropFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cDropFunc);
}

void GAllEvents::setEnterFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cEnterFunc,cStr);
}

void GAllEvents::callEnterFunc(void)
{
	if (strcmp(this->cEnterFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cEnterFunc);
}

void GAllEvents::setFocusInFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cFocusInFunc,cStr);
}

void GAllEvents::callFocusInFunc(void)
{
	if (strcmp(this->cFocusInFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cFocusInFunc);
}

void GAllEvents::setFocusOutFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cFocusOutFunc,cStr);
}

void GAllEvents::callFocusOutFunc(void)
{
	if (strcmp(this->cFocusOutFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cFocusOutFunc);
}

void GAllEvents::setKeyReleaseFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cKeyReleaseFunc,cStr);
}

void GAllEvents::callKeyReleaseFunc(void)
{
	if (strcmp(this->cKeyReleaseFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cKeyReleaseFunc);
}

void GAllEvents::setLeaveFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cLeaveFunc,cStr);
}

void GAllEvents::callLeaveFunc(void)
{
	if (strcmp(this->cLeaveFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cLeaveFunc);
}

void GAllEvents::setNonClientAreaMouseButtonDblClickFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cNonClientAreaMouseButtonDblClickFunc,cStr);
}

void GAllEvents::callNonClientAreaMouseButtonDblClickFunc(void)
{
	if (strcmp(this->cNonClientAreaMouseButtonDblClickFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cNonClientAreaMouseButtonDblClickFunc);
}

void GAllEvents::setNonClientAreaMouseButtonPressFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cNonClientAreaMouseButtonPressFunc,cStr);
}

void GAllEvents::callNonClientAreaMouseButtonPressFunc(void)
{
	if (strcmp(this->cNonClientAreaMouseButtonPressFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cNonClientAreaMouseButtonPressFunc);
}

void GAllEvents::setNonClientAreaMouseButtonReleaseFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cNonClientAreaMouseButtonReleaseFunc,cStr);
}

void GAllEvents::callNonClientAreaMouseButtonReleaseFunc(void)
{
	if (strcmp(this->cNonClientAreaMouseButtonReleaseFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cNonClientAreaMouseButtonReleaseFunc);
}

void GAllEvents::setNonClientAreaMouseMoveFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cNonClientAreaMouseMoveFunc,cStr);
}

void GAllEvents::callNonClientAreaMouseMoveFunc(void)
{
	if (strcmp(this->cNonClientAreaMouseMoveFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cNonClientAreaMouseMoveFunc);
}

void GAllEvents::setMoveFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cMoveFunc,cStr);
}

void GAllEvents::callMoveFunc(void)
{
	if (strcmp(this->cMoveFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cMoveFunc);
}

void GAllEvents::setResizeFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cResizeFunc,cStr);
}

void GAllEvents::callResizeFunc(void)
{
	if (strcmp(this->cResizeFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cResizeFunc);
}

void GAllEvents::setWindowActivateFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cWindowActivateFunc,cStr);
}

void GAllEvents::callWindowActivateFunc(void)
{
	if (strcmp(this->cWindowActivateFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cWindowActivateFunc);
}

void GAllEvents::setWindowBlockedFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cWindowBlockedFunc,cStr);
}

void GAllEvents::callWindowBlockedFunc(void)
{
	if (strcmp(this->cWindowBlockedFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cWindowBlockedFunc);
}

void GAllEvents::setWindowDeactivateFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cWindowDeactivateFunc,cStr);
}

void GAllEvents::callWindowDeactivateFunc(void)
{
	if (strcmp(this->cWindowDeactivateFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cWindowDeactivateFunc);
}

void GAllEvents::setWindowStateChangeFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cWindowStateChangeFunc,cStr);
}

void GAllEvents::callWindowStateChangeFunc(void)
{
	if (strcmp(this->cWindowStateChangeFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cWindowStateChangeFunc);
}

void GAllEvents::setWindowUnblockedFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cWindowUnblockedFunc,cStr);
}

void GAllEvents::callWindowUnblockedFunc(void)
{
	if (strcmp(this->cWindowUnblockedFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cWindowUnblockedFunc);
}

void GAllEvents::setPaintFunc(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cPaintFunc,cStr);
}

void GAllEvents::callPaintFunc(void)
{
	if (strcmp(this->cPaintFunc,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cPaintFunc);
}

const char *GAllEvents::getKeyPressFunc(void)
{
	return this->cKeyPressFunc  ;
}

const char *GAllEvents::getMouseButtonPressFunc(void)
{
	return this->cMouseButtonPressFunc  ;
}

const char *GAllEvents::getMouseButtonReleaseFunc(void)
{
	return this->cMouseButtonReleaseFunc  ;
}

const char *GAllEvents::getMouseButtonDblClickFunc(void)
{
	return this->cMouseButtonDblClickFunc  ;
}

const char *GAllEvents::getMouseMoveFunc(void)
{
	return this->cMouseMoveFunc  ;
}

const char *GAllEvents::getCloseFunc(void)
{
	return this->cCloseFunc  ;
}

const char *GAllEvents::getContextMenuFunc(void)
{
	return this->cContextMenuFunc  ;
}

const char *GAllEvents::getDragEnterFunc(void)
{
	return this->cDragEnterFunc  ;
}

const char *GAllEvents::getDragLeaveFunc(void)
{
	return this->cDragLeaveFunc ;
}

const char *GAllEvents::getDragMoveFunc(void)
{
	return this->cDragMoveFunc  ;
}

const char *GAllEvents::getDropFunc(void)
{
	return this->cDropFunc  ;
}

const char *GAllEvents::getEnterFunc(void)
{
	return this->cEnterFunc  ;
}

const char *GAllEvents::getFocusInFunc(void)
{
	return this->cFocusInFunc  ;
}

const char *GAllEvents::getFocusOutFunc(void)
{
	return this->cFocusOutFunc  ;
}

const char *GAllEvents::getKeyReleaseFunc(void)
{
	return this->cKeyReleaseFunc  ;
}

const char *GAllEvents::getLeaveFunc(void)
{
	return this->cLeaveFunc  ;
}

const char *GAllEvents::getNonClientAreaMouseButtonDblClickFunc(void)
{
	return this->cNonClientAreaMouseButtonDblClickFunc  ;
}

const char *GAllEvents::getNonClientAreaMouseButtonPressFunc(void)
{
	return this->cNonClientAreaMouseButtonPressFunc  ;
}

const char *GAllEvents::getNonClientAreaMouseButtonReleaseFunc(void)
{
	return this->cNonClientAreaMouseButtonReleaseFunc  ;
}

const char *GAllEvents::getNonClientAreaMouseMoveFunc(void)
{
	return this->cNonClientAreaMouseMoveFunc  ;
}

const char *GAllEvents::getMoveFunc(void)
{
	return this->cMoveFunc  ;
}

const char *GAllEvents::getResizeFunc(void)
{
	return this->cResizeFunc  ;
}

const char *GAllEvents::getWindowActivateFunc(void)
{
	return this->cWindowActivateFunc  ;
}

const char *GAllEvents::getWindowBlockedFunc(void)
{
	return this->cWindowBlockedFunc  ;
}

const char *GAllEvents::getWindowDeactivateFunc(void)
{
	return this->cWindowDeactivateFunc  ;
}

const char *GAllEvents::getWindowStateChangeFunc(void)
{
	return this->cWindowStateChangeFunc  ;
}

const char *GAllEvents::getWindowUnblockedFunc(void)
{
	return this->cWindowUnblockedFunc  ;
}

const char *GAllEvents::getPaintFunc(void)
{
	return this->cPaintFunc  ;
}

