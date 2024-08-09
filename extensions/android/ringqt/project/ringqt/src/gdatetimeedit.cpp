
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gdatetimeedit.h"

GDateTimeEdit::GDateTimeEdit(QWidget *parent,VM *pVM)  : QDateTimeEdit(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cdateChangedEvent,"");
	strcpy(this->cdateTimeChangedEvent,"");
	strcpy(this->ctimeChangedEvent,"");

	QObject::connect(this, SIGNAL(dateChanged(QDate)),this, SLOT(dateChangedSlot()));
	QObject::connect(this, SIGNAL(dateTimeChanged(QDateTime)),this, SLOT(dateTimeChangedSlot()));
	QObject::connect(this, SIGNAL(timeChanged(QTime)),this, SLOT(timeChangedSlot()));

}

GDateTimeEdit::~GDateTimeEdit()
{
	ring_list_delete(this->pParaList);
}

void GDateTimeEdit::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GDateTimeEdit::setdateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDateTimeEdit::setdateTimeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdateTimeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDateTimeEdit::settimeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctimeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GDateTimeEdit::getdateChangedEvent(void)
{
	return this->cdateChangedEvent;
}

const char *GDateTimeEdit::getdateTimeChangedEvent(void)
{
	return this->cdateTimeChangedEvent;
}

const char *GDateTimeEdit::gettimeChangedEvent(void)
{
	return this->ctimeChangedEvent;
}


void GDateTimeEdit::dateChangedSlot()
{
	if (strcmp(this->cdateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdateChangedEvent);
}

void GDateTimeEdit::dateTimeChangedSlot()
{
	if (strcmp(this->cdateTimeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdateTimeChangedEvent);
}

void GDateTimeEdit::timeChangedSlot()
{
	if (strcmp(this->ctimeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctimeChangedEvent);
}

