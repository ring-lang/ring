
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gobjectpicker.h"

GObjectPicker::GObjectPicker(Qt3DCore::QNode *parent,VM *pVM)  : Qt3DRender::QObjectPicker(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cclickedEvent,"");
	strcpy(this->ccontainsMouseChangedEvent,"");
	strcpy(this->cdragEnabledChangedEvent,"");
	strcpy(this->centeredEvent,"");
	strcpy(this->cexitedEvent,"");
	strcpy(this->choverEnabledChangedEvent,"");
	strcpy(this->cmovedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->cpressedChangedEvent,"");
	strcpy(this->creleasedEvent,"");

	QObject::connect(this, SIGNAL(clicked(Qt3DRender::QPickEvent *)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(containsMouseChanged(bool)),this, SLOT(containsMouseChangedSlot()));
	QObject::connect(this, SIGNAL(dragEnabledChanged(bool)),this, SLOT(dragEnabledChangedSlot()));
	QObject::connect(this, SIGNAL(entered()),this, SLOT(enteredSlot()));
	QObject::connect(this, SIGNAL(exited()),this, SLOT(exitedSlot()));
	QObject::connect(this, SIGNAL(hoverEnabledChanged(bool)),this, SLOT(hoverEnabledChangedSlot()));
	QObject::connect(this, SIGNAL(moved(Qt3DRender::QPickEvent *)),this, SLOT(movedSlot()));
	QObject::connect(this, SIGNAL(pressed(Qt3DRender::QPickEvent *)),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(pressedChanged(bool)),this, SLOT(pressedChangedSlot()));
	QObject::connect(this, SIGNAL(released(Qt3DRender::QPickEvent *)),this, SLOT(releasedSlot()));

}

GObjectPicker::~GObjectPicker()
{
	ring_list_delete(this->pParaList);
}

void GObjectPicker::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GObjectPicker::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GObjectPicker::setcontainsMouseChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccontainsMouseChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GObjectPicker::setdragEnabledChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdragEnabledChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GObjectPicker::setenteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->centeredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GObjectPicker::setexitedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cexitedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GObjectPicker::sethoverEnabledChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->choverEnabledChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GObjectPicker::setmovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GObjectPicker::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GObjectPicker::setpressedChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GObjectPicker::setreleasedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creleasedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GObjectPicker::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GObjectPicker::getcontainsMouseChangedEvent(void)
{
	return this->ccontainsMouseChangedEvent;
}

const char *GObjectPicker::getdragEnabledChangedEvent(void)
{
	return this->cdragEnabledChangedEvent;
}

const char *GObjectPicker::getenteredEvent(void)
{
	return this->centeredEvent;
}

const char *GObjectPicker::getexitedEvent(void)
{
	return this->cexitedEvent;
}

const char *GObjectPicker::gethoverEnabledChangedEvent(void)
{
	return this->choverEnabledChangedEvent;
}

const char *GObjectPicker::getmovedEvent(void)
{
	return this->cmovedEvent;
}

const char *GObjectPicker::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GObjectPicker::getpressedChangedEvent(void)
{
	return this->cpressedChangedEvent;
}

const char *GObjectPicker::getreleasedEvent(void)
{
	return this->creleasedEvent;
}


void GObjectPicker::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GObjectPicker::containsMouseChangedSlot()
{
	if (strcmp(this->ccontainsMouseChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccontainsMouseChangedEvent);
}

void GObjectPicker::dragEnabledChangedSlot()
{
	if (strcmp(this->cdragEnabledChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdragEnabledChangedEvent);
}

void GObjectPicker::enteredSlot()
{
	if (strcmp(this->centeredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->centeredEvent);
}

void GObjectPicker::exitedSlot()
{
	if (strcmp(this->cexitedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cexitedEvent);
}

void GObjectPicker::hoverEnabledChangedSlot()
{
	if (strcmp(this->choverEnabledChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choverEnabledChangedEvent);
}

void GObjectPicker::movedSlot()
{
	if (strcmp(this->cmovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmovedEvent);
}

void GObjectPicker::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GObjectPicker::pressedChangedSlot()
{
	if (strcmp(this->cpressedChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedChangedEvent);
}

void GObjectPicker::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

