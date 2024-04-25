
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtreeview.h"

GTreeView::GTreeView(QWidget *parent,VM *pVM)  : QTreeView(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccollapsedEvent,"");
	strcpy(this->cexpandedEvent,"");
	strcpy(this->cactivatedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->centeredEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->cviewportEnteredEvent,"");

	QObject::connect(this, SIGNAL(collapsed(QModelIndex)),this, SLOT(collapsedSlot()));
	QObject::connect(this, SIGNAL(expanded(QModelIndex)),this, SLOT(expandedSlot()));
	QObject::connect(this, SIGNAL(activated(QModelIndex)),this, SLOT(activatedSlot()));
	QObject::connect(this, SIGNAL(clicked(QModelIndex)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked(QModelIndex)),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(entered(QModelIndex)),this, SLOT(enteredSlot()));
	QObject::connect(this, SIGNAL(pressed(QModelIndex)),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(viewportEntered()),this, SLOT(viewportEnteredSlot()));

}

GTreeView::~GTreeView()
{
	ring_list_delete(this->pParaList);
}

void GTreeView::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GTreeView::setcollapsedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccollapsedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeView::setexpandedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cexpandedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeView::setactivatedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cactivatedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeView::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeView::setdoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeView::setenteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->centeredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeView::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeView::setviewportEnteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cviewportEnteredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GTreeView::getcollapsedEvent(void)
{
	return this->ccollapsedEvent;
}

const char *GTreeView::getexpandedEvent(void)
{
	return this->cexpandedEvent;
}

const char *GTreeView::getactivatedEvent(void)
{
	return this->cactivatedEvent;
}

const char *GTreeView::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GTreeView::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GTreeView::getenteredEvent(void)
{
	return this->centeredEvent;
}

const char *GTreeView::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GTreeView::getviewportEnteredEvent(void)
{
	return this->cviewportEnteredEvent;
}


void GTreeView::collapsedSlot()
{
	if (strcmp(this->ccollapsedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccollapsedEvent);
}

void GTreeView::expandedSlot()
{
	if (strcmp(this->cexpandedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cexpandedEvent);
}

void GTreeView::activatedSlot()
{
	if (strcmp(this->cactivatedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cactivatedEvent);
}

void GTreeView::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GTreeView::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GTreeView::enteredSlot()
{
	if (strcmp(this->centeredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->centeredEvent);
}

void GTreeView::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GTreeView::viewportEnteredSlot()
{
	if (strcmp(this->cviewportEnteredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cviewportEnteredEvent);
}

