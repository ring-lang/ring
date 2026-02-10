
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gshortcut.h"

GShortcut::GShortcut(QWidget *parent,VM *pVM)  : QShortcut(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cactivatedEvent,"");
	strcpy(this->cactivatedAmbiguouslyEvent,"");

	QObject::connect(this, SIGNAL(activated()),this, SLOT(activatedSlot()));
	QObject::connect(this, SIGNAL(activatedAmbiguously()),this, SLOT(activatedAmbiguouslySlot()));

}

GShortcut::~GShortcut()
{
	ring_list_delete(this->pParaList);
}

void GShortcut::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GShortcut::setactivatedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cactivatedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GShortcut::setactivatedAmbiguouslyEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cactivatedAmbiguouslyEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GShortcut::getactivatedEvent(void)
{
	return this->cactivatedEvent;
}

const char *GShortcut::getactivatedAmbiguouslyEvent(void)
{
	return this->cactivatedAmbiguouslyEvent;
}


void GShortcut::activatedSlot()
{
	if (strcmp(this->cactivatedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cactivatedEvent);
}

void GShortcut::activatedAmbiguouslySlot()
{
	if (strcmp(this->cactivatedAmbiguouslyEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cactivatedAmbiguouslyEvent);
}

