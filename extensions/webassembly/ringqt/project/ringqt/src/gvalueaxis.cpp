
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gvalueaxis.h"

GValueAxis::GValueAxis(QObject * parent,VM *pVM)  : QtCharts::QValueAxis(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->clabelFormatChangedEvent,"");
	strcpy(this->cmaxChangedEvent,"");
	strcpy(this->cminChangedEvent,"");
	strcpy(this->cminorTickCountChangedEvent,"");
	strcpy(this->crangeChangedEvent,"");
	strcpy(this->ctickAnchorChangedEvent,"");
	strcpy(this->ctickCountChangedEvent,"");
	strcpy(this->ctickIntervalChangedEvent,"");
	strcpy(this->ctickTypeChangedEvent,"");

	QObject::connect(this, SIGNAL(labelFormatChanged(const QString)),this, SLOT(labelFormatChangedSlot()));
	QObject::connect(this, SIGNAL(maxChanged(qreal)),this, SLOT(maxChangedSlot()));
	QObject::connect(this, SIGNAL(minChanged(qreal)),this, SLOT(minChangedSlot()));
	QObject::connect(this, SIGNAL(minorTickCountChanged(int)),this, SLOT(minorTickCountChangedSlot()));
	QObject::connect(this, SIGNAL(rangeChanged(qreal,qreal)),this, SLOT(rangeChangedSlot()));
	QObject::connect(this, SIGNAL(tickAnchorChanged(qreal)),this, SLOT(tickAnchorChangedSlot()));
	QObject::connect(this, SIGNAL(tickCountChanged(int)),this, SLOT(tickCountChangedSlot()));
	QObject::connect(this, SIGNAL(tickIntervalChanged(qreal)),this, SLOT(tickIntervalChangedSlot()));
	QObject::connect(this, SIGNAL(tickTypeChanged(QValueAxis::TickType)),this, SLOT(tickTypeChangedSlot()));

}

GValueAxis::~GValueAxis()
{
	ring_list_delete(this->pParaList);
}

void GValueAxis::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GValueAxis::setlabelFormatChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelFormatChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GValueAxis::setmaxChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmaxChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GValueAxis::setminChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cminChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GValueAxis::setminorTickCountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cminorTickCountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GValueAxis::setrangeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->crangeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GValueAxis::settickAnchorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctickAnchorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GValueAxis::settickCountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctickCountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GValueAxis::settickIntervalChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctickIntervalChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GValueAxis::settickTypeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctickTypeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GValueAxis::getlabelFormatChangedEvent(void)
{
	return this->clabelFormatChangedEvent;
}

const char *GValueAxis::getmaxChangedEvent(void)
{
	return this->cmaxChangedEvent;
}

const char *GValueAxis::getminChangedEvent(void)
{
	return this->cminChangedEvent;
}

const char *GValueAxis::getminorTickCountChangedEvent(void)
{
	return this->cminorTickCountChangedEvent;
}

const char *GValueAxis::getrangeChangedEvent(void)
{
	return this->crangeChangedEvent;
}

const char *GValueAxis::gettickAnchorChangedEvent(void)
{
	return this->ctickAnchorChangedEvent;
}

const char *GValueAxis::gettickCountChangedEvent(void)
{
	return this->ctickCountChangedEvent;
}

const char *GValueAxis::gettickIntervalChangedEvent(void)
{
	return this->ctickIntervalChangedEvent;
}

const char *GValueAxis::gettickTypeChangedEvent(void)
{
	return this->ctickTypeChangedEvent;
}


void GValueAxis::labelFormatChangedSlot()
{
	if (strcmp(this->clabelFormatChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelFormatChangedEvent);
}

void GValueAxis::maxChangedSlot()
{
	if (strcmp(this->cmaxChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmaxChangedEvent);
}

void GValueAxis::minChangedSlot()
{
	if (strcmp(this->cminChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminChangedEvent);
}

void GValueAxis::minorTickCountChangedSlot()
{
	if (strcmp(this->cminorTickCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminorTickCountChangedEvent);
}

void GValueAxis::rangeChangedSlot()
{
	if (strcmp(this->crangeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crangeChangedEvent);
}

void GValueAxis::tickAnchorChangedSlot()
{
	if (strcmp(this->ctickAnchorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctickAnchorChangedEvent);
}

void GValueAxis::tickCountChangedSlot()
{
	if (strcmp(this->ctickCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctickCountChangedEvent);
}

void GValueAxis::tickIntervalChangedSlot()
{
	if (strcmp(this->ctickIntervalChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctickIntervalChangedEvent);
}

void GValueAxis::tickTypeChangedSlot()
{
	if (strcmp(this->ctickTypeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctickTypeChangedEvent);
}

