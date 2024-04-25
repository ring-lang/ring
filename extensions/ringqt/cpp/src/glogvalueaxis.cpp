
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "glogvalueaxis.h"

GLogValueAxis::GLogValueAxis(QObject *parent,VM *pVM)  : QtCharts::QLogValueAxis(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cbaseChangedEvent,"");
	strcpy(this->clabelFormatChangedEvent,"");
	strcpy(this->cmaxChangedEvent,"");
	strcpy(this->cminChangedEvent,"");
	strcpy(this->cminorTickCountChangedEvent,"");
	strcpy(this->crangeChangedEvent,"");
	strcpy(this->ctickCountChangedEvent,"");

	QObject::connect(this, SIGNAL(baseChanged(qreal)),this, SLOT(baseChangedSlot()));
	QObject::connect(this, SIGNAL(labelFormatChanged(const QString)),this, SLOT(labelFormatChangedSlot()));
	QObject::connect(this, SIGNAL(maxChanged(qreal)),this, SLOT(maxChangedSlot()));
	QObject::connect(this, SIGNAL(minChanged(qreal)),this, SLOT(minChangedSlot()));
	QObject::connect(this, SIGNAL(minorTickCountChanged(int)),this, SLOT(minorTickCountChangedSlot()));
	QObject::connect(this, SIGNAL(rangeChanged(qreal,qreal)),this, SLOT(rangeChangedSlot()));
	QObject::connect(this, SIGNAL(tickCountChanged(int)),this, SLOT(tickCountChangedSlot()));

}

GLogValueAxis::~GLogValueAxis()
{
	ring_list_delete(this->pParaList);
}

void GLogValueAxis::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GLogValueAxis::setbaseChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbaseChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLogValueAxis::setlabelFormatChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelFormatChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLogValueAxis::setmaxChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmaxChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLogValueAxis::setminChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cminChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLogValueAxis::setminorTickCountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cminorTickCountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLogValueAxis::setrangeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->crangeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLogValueAxis::settickCountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctickCountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GLogValueAxis::getbaseChangedEvent(void)
{
	return this->cbaseChangedEvent;
}

const char *GLogValueAxis::getlabelFormatChangedEvent(void)
{
	return this->clabelFormatChangedEvent;
}

const char *GLogValueAxis::getmaxChangedEvent(void)
{
	return this->cmaxChangedEvent;
}

const char *GLogValueAxis::getminChangedEvent(void)
{
	return this->cminChangedEvent;
}

const char *GLogValueAxis::getminorTickCountChangedEvent(void)
{
	return this->cminorTickCountChangedEvent;
}

const char *GLogValueAxis::getrangeChangedEvent(void)
{
	return this->crangeChangedEvent;
}

const char *GLogValueAxis::gettickCountChangedEvent(void)
{
	return this->ctickCountChangedEvent;
}


void GLogValueAxis::baseChangedSlot()
{
	if (strcmp(this->cbaseChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbaseChangedEvent);
}

void GLogValueAxis::labelFormatChangedSlot()
{
	if (strcmp(this->clabelFormatChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelFormatChangedEvent);
}

void GLogValueAxis::maxChangedSlot()
{
	if (strcmp(this->cmaxChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmaxChangedEvent);
}

void GLogValueAxis::minChangedSlot()
{
	if (strcmp(this->cminChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminChangedEvent);
}

void GLogValueAxis::minorTickCountChangedSlot()
{
	if (strcmp(this->cminorTickCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminorTickCountChangedEvent);
}

void GLogValueAxis::rangeChangedSlot()
{
	if (strcmp(this->crangeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crangeChangedEvent);
}

void GLogValueAxis::tickCountChangedSlot()
{
	if (strcmp(this->ctickCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctickCountChangedEvent);
}

