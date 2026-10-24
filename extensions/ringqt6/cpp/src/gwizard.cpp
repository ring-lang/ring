
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gwizard.h"

GWizard::GWizard(QWidget *parent,VM *pVM)  : QWizard(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccurrentIdChangedEvent,"");
	strcpy(this->cpageAddedEvent,"");
	strcpy(this->cpageRemovedEvent,"");

	QObject::connect(this, SIGNAL(currentIdChanged(int)),this, SLOT(currentIdChangedSlot()));
	QObject::connect(this, SIGNAL(pageAdded(int)),this, SLOT(pageAddedSlot()));
	QObject::connect(this, SIGNAL(pageRemoved(int)),this, SLOT(pageRemovedSlot()));

}

GWizard::~GWizard()
{
	ring_list_delete(this->pParaList);
}

void GWizard::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GWizard::setcurrentIdChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentIdChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWizard::setpageAddedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpageAddedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWizard::setpageRemovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpageRemovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GWizard::getcurrentIdChangedEvent(void)
{
	return this->ccurrentIdChangedEvent;
}

const char *GWizard::getpageAddedEvent(void)
{
	return this->cpageAddedEvent;
}

const char *GWizard::getpageRemovedEvent(void)
{
	return this->cpageRemovedEvent;
}


void GWizard::currentIdChangedSlot()
{
	if (strcmp(this->ccurrentIdChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentIdChangedEvent);
}

void GWizard::pageAddedSlot()
{
	if (strcmp(this->cpageAddedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpageAddedEvent);
}

void GWizard::pageRemovedSlot()
{
	if (strcmp(this->cpageRemovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpageRemovedEvent);
}

