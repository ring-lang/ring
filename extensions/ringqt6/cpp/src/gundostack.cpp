
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gundostack.h"

GUndoStack::GUndoStack(QObject *parent,VM *pVM)  : QUndoStack(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccanRedoChangedEvent,"");
	strcpy(this->ccanUndoChangedEvent,"");
	strcpy(this->ccleanChangedEvent,"");
	strcpy(this->cindexChangedEvent,"");
	strcpy(this->credoTextChangedEvent,"");
	strcpy(this->cundoTextChangedEvent,"");

	QObject::connect(this, SIGNAL(canRedoChanged(bool)),this, SLOT(canRedoChangedSlot()));
	QObject::connect(this, SIGNAL(canUndoChanged(bool)),this, SLOT(canUndoChangedSlot()));
	QObject::connect(this, SIGNAL(cleanChanged(bool)),this, SLOT(cleanChangedSlot()));
	QObject::connect(this, SIGNAL(indexChanged(int)),this, SLOT(indexChangedSlot()));
	QObject::connect(this, SIGNAL(redoTextChanged(QString)),this, SLOT(redoTextChangedSlot()));
	QObject::connect(this, SIGNAL(undoTextChanged(QString)),this, SLOT(undoTextChangedSlot()));

}

GUndoStack::~GUndoStack()
{
	ring_list_delete(this->pParaList);
}

void GUndoStack::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GUndoStack::setcanRedoChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccanRedoChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GUndoStack::setcanUndoChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccanUndoChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GUndoStack::setcleanChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccleanChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GUndoStack::setindexChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cindexChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GUndoStack::setredoTextChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->credoTextChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GUndoStack::setundoTextChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cundoTextChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GUndoStack::getcanRedoChangedEvent(void)
{
	return this->ccanRedoChangedEvent;
}

const char *GUndoStack::getcanUndoChangedEvent(void)
{
	return this->ccanUndoChangedEvent;
}

const char *GUndoStack::getcleanChangedEvent(void)
{
	return this->ccleanChangedEvent;
}

const char *GUndoStack::getindexChangedEvent(void)
{
	return this->cindexChangedEvent;
}

const char *GUndoStack::getredoTextChangedEvent(void)
{
	return this->credoTextChangedEvent;
}

const char *GUndoStack::getundoTextChangedEvent(void)
{
	return this->cundoTextChangedEvent;
}


void GUndoStack::canRedoChangedSlot()
{
	if (strcmp(this->ccanRedoChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccanRedoChangedEvent);
}

void GUndoStack::canUndoChangedSlot()
{
	if (strcmp(this->ccanUndoChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccanUndoChangedEvent);
}

void GUndoStack::cleanChangedSlot()
{
	if (strcmp(this->ccleanChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccleanChangedEvent);
}

void GUndoStack::indexChangedSlot()
{
	if (strcmp(this->cindexChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cindexChangedEvent);
}

void GUndoStack::redoTextChangedSlot()
{
	if (strcmp(this->credoTextChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->credoTextChangedEvent);
}

void GUndoStack::undoTextChangedSlot()
{
	if (strcmp(this->cundoTextChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cundoTextChangedEvent);
}

