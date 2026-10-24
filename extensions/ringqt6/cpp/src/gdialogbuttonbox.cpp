
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gdialogbuttonbox.h"

GDialogButtonBox::GDialogButtonBox(QWidget *parent,VM *pVM)  : QDialogButtonBox(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cacceptedEvent,"");
	strcpy(this->crejectedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->chelpRequestedEvent,"");

	QObject::connect(this, SIGNAL(accepted()),this, SLOT(acceptedSlot()));
	QObject::connect(this, SIGNAL(rejected()),this, SLOT(rejectedSlot()));
	QObject::connect(this, SIGNAL(clicked(QAbstractButton *)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(helpRequested()),this, SLOT(helpRequestedSlot()));

}

GDialogButtonBox::~GDialogButtonBox()
{
	ring_list_delete(this->pParaList);
}

void GDialogButtonBox::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GDialogButtonBox::setacceptedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cacceptedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDialogButtonBox::setrejectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->crejectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDialogButtonBox::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDialogButtonBox::sethelpRequestedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->chelpRequestedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GDialogButtonBox::getacceptedEvent(void)
{
	return this->cacceptedEvent;
}

const char *GDialogButtonBox::getrejectedEvent(void)
{
	return this->crejectedEvent;
}

const char *GDialogButtonBox::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GDialogButtonBox::gethelpRequestedEvent(void)
{
	return this->chelpRequestedEvent;
}


void GDialogButtonBox::acceptedSlot()
{
	if (strcmp(this->cacceptedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cacceptedEvent);
}

void GDialogButtonBox::rejectedSlot()
{
	if (strcmp(this->crejectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crejectedEvent);
}

void GDialogButtonBox::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GDialogButtonBox::helpRequestedSlot()
{
	if (strcmp(this->chelpRequestedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->chelpRequestedEvent);
}

