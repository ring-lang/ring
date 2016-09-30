/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */

extern "C" {
#include "ring.h"
}
#include "gallevents.h"

GAllEvents::GAllEvents(QWidget *parent,VM *pVM)  : QWidget()
{
	this->pVM = pVM;
	this->pEvent = NULL;
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
}

bool GAllEvents::eventFilter(QObject *object, QEvent *event)
{
	this->pEvent = event ;
	if ((event->type() == QEvent::KeyPress) && (strcmp(this->cKeyPressEvent,"")!=0) ) {
	        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
		this->nKeyCode = keyEvent->key();
		this->callKeyPressEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::MouseButtonPress) && (strcmp(this->cMouseButtonPressEvent,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseButtonPressEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::MouseButtonRelease) && (strcmp(this->cMouseButtonReleaseEvent,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseButtonReleaseEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::MouseButtonDblClick) && (strcmp(this->cMouseButtonDblClickEvent,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseButtonDblClickEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::MouseMove) && (strcmp(this->cMouseMoveEvent,"")!=0) ) {
		this->storeMouseState(event);
		this->callMouseMoveEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::Close) && (strcmp(this->cCloseEvent,"")!=0) ) {
		this->callCloseEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::ContextMenu) && (strcmp(this->cContextMenuEvent,"")!=0) ) {
		this->callContextMenuEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::DragEnter) && (strcmp(this->cDragEnterEvent,"")!=0) ) {
		this->callDragEnterEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::DragLeave) && (strcmp(this->cDragLeaveEvent,"")!=0) ) {
		this->callDragLeaveEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::DragMove) && (strcmp(this->cDragMoveEvent,"")!=0) ) {
		this->callDragMoveEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::Drop) && (strcmp(this->cDropEvent,"")!=0) ) {
		this->callDropEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::Enter) && (strcmp(this->cEnterEvent,"")!=0) ) {
		this->callEnterEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::FocusIn) && (strcmp(this->cFocusInEvent,"")!=0) ) {
		this->callFocusInEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::FocusOut) && (strcmp(this->cFocusOutEvent,"")!=0) ) {
		this->callFocusOutEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::KeyRelease) && (strcmp(this->cKeyReleaseEvent,"")!=0) ) {
		this->callKeyReleaseEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::Leave) && (strcmp(this->cLeaveEvent,"")!=0) ) {
		this->callLeaveEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseButtonDblClick) && (strcmp(this->cNonClientAreaMouseButtonDblClickEvent,"")!=0) ) {
		this->callNonClientAreaMouseButtonDblClickEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseButtonPress) && (strcmp(this->cNonClientAreaMouseButtonPressEvent,"")!=0) ) {
		this->callNonClientAreaMouseButtonPressEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseButtonRelease) && (strcmp(this->cNonClientAreaMouseButtonReleaseEvent,"")!=0) ) {
		this->callNonClientAreaMouseButtonReleaseEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::NonClientAreaMouseMove) && (strcmp(this->cNonClientAreaMouseMoveEvent,"")!=0) ) {
		this->callNonClientAreaMouseMoveEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::Move) && (strcmp(this->cMoveEvent,"")!=0) ) {
		this->callMoveEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::Resize) && (strcmp(this->cResizeEvent,"")!=0) ) {
		this->callResizeEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::WindowActivate) && (strcmp(this->cWindowActivateEvent,"")!=0) ) {
		this->callWindowActivateEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::WindowBlocked) && (strcmp(this->cWindowBlockedEvent,"")!=0) ) {
		this->callWindowBlockedEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::WindowDeactivate) && (strcmp(this->cWindowDeactivateEvent,"")!=0) ) {
		this->callWindowDeactivateEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::WindowStateChange) && (strcmp(this->cWindowStateChangeEvent,"")!=0) ) {
		this->callWindowStateChangeEvent();
 		return true;
    	}
        else if ((event->type() == QEvent::WindowUnblocked) && (strcmp(this->cWindowUnblockedEvent,"")!=0) ) {
		this->callWindowUnblockedEvent();
 		return true;
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