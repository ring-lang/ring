
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gdatetimeaxis.h"

GDateTimeAxis::GDateTimeAxis(QObject *parent,VM *pVM)  : QtCharts::QDateTimeAxis(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cformatChangedEvent,"");
	strcpy(this->cmaxChangedEvent,"");
	strcpy(this->cminChangedEvent,"");
	strcpy(this->crangeChangedEvent,"");
	strcpy(this->ctickCountChangedEvent,"");

	QObject::connect(this, SIGNAL(formatChanged(QString)),this, SLOT(formatChangedSlot()));
	QObject::connect(this, SIGNAL(maxChanged(QDateTime)),this, SLOT(maxChangedSlot()));
	QObject::connect(this, SIGNAL(minChanged(QDateTime)),this, SLOT(minChangedSlot()));
	QObject::connect(this, SIGNAL(rangeChanged(QDateTime,QDateTime)),this, SLOT(rangeChangedSlot()));
	QObject::connect(this, SIGNAL(tickCountChanged(int)),this, SLOT(tickCountChangedSlot()));

}

GDateTimeAxis::~GDateTimeAxis()
{
	ring_list_delete(this->pParaList);
}

void GDateTimeAxis::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GDateTimeAxis::setformatChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cformatChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDateTimeAxis::setmaxChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmaxChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDateTimeAxis::setminChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cminChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDateTimeAxis::setrangeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->crangeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDateTimeAxis::settickCountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctickCountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GDateTimeAxis::getformatChangedEvent(void)
{
	return this->cformatChangedEvent;
}

const char *GDateTimeAxis::getmaxChangedEvent(void)
{
	return this->cmaxChangedEvent;
}

const char *GDateTimeAxis::getminChangedEvent(void)
{
	return this->cminChangedEvent;
}

const char *GDateTimeAxis::getrangeChangedEvent(void)
{
	return this->crangeChangedEvent;
}

const char *GDateTimeAxis::gettickCountChangedEvent(void)
{
	return this->ctickCountChangedEvent;
}


void GDateTimeAxis::formatChangedSlot()
{
	if (strcmp(this->cformatChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cformatChangedEvent);
}

void GDateTimeAxis::maxChangedSlot()
{
	if (strcmp(this->cmaxChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmaxChangedEvent);
}

void GDateTimeAxis::minChangedSlot()
{
	if (strcmp(this->cminChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminChangedEvent);
}

void GDateTimeAxis::rangeChangedSlot()
{
	if (strcmp(this->crangeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crangeChangedEvent);
}

void GDateTimeAxis::tickCountChangedSlot()
{
	if (strcmp(this->ctickCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctickCountChangedEvent);
}

