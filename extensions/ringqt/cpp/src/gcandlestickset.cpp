
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gcandlestickset.h"

GCandlestickSet::GCandlestickSet(qreal x,QObject *parent,VM *pVM)  : QtCharts::QCandlestickSet(x,parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cbrushChangedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->ccloseChangedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->chighChangedEvent,"");
	strcpy(this->choveredEvent,"");
	strcpy(this->clowChangedEvent,"");
	strcpy(this->copenChangedEvent,"");
	strcpy(this->cpenChangedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");
	strcpy(this->ctimestampChangedEvent,"");

	QObject::connect(this, SIGNAL(brushChanged()),this, SLOT(brushChangedSlot()));
	QObject::connect(this, SIGNAL(clicked()),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(closeChanged()),this, SLOT(closeChangedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked()),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(highChanged()),this, SLOT(highChangedSlot()));
	QObject::connect(this, SIGNAL(hovered(bool)),this, SLOT(hoveredSlot()));
	QObject::connect(this, SIGNAL(lowChanged()),this, SLOT(lowChangedSlot()));
	QObject::connect(this, SIGNAL(openChanged()),this, SLOT(openChangedSlot()));
	QObject::connect(this, SIGNAL(penChanged()),this, SLOT(penChangedSlot()));
	QObject::connect(this, SIGNAL(pressed()),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released()),this, SLOT(releasedSlot()));
	QObject::connect(this, SIGNAL(timestampChanged()),this, SLOT(timestampChangedSlot()));

}

GCandlestickSet::~GCandlestickSet()
{
	ring_list_delete(this->pParaList);
}

void GCandlestickSet::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GCandlestickSet::setbrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSet::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSet::setcloseChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccloseChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSet::setdoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSet::sethighChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->chighChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSet::sethoveredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->choveredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSet::setlowChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clowChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSet::setopenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->copenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSet::setpenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSet::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSet::setreleasedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creleasedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSet::settimestampChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctimestampChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GCandlestickSet::getbrushChangedEvent(void)
{
	return this->cbrushChangedEvent;
}

const char *GCandlestickSet::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GCandlestickSet::getcloseChangedEvent(void)
{
	return this->ccloseChangedEvent;
}

const char *GCandlestickSet::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GCandlestickSet::gethighChangedEvent(void)
{
	return this->chighChangedEvent;
}

const char *GCandlestickSet::gethoveredEvent(void)
{
	return this->choveredEvent;
}

const char *GCandlestickSet::getlowChangedEvent(void)
{
	return this->clowChangedEvent;
}

const char *GCandlestickSet::getopenChangedEvent(void)
{
	return this->copenChangedEvent;
}

const char *GCandlestickSet::getpenChangedEvent(void)
{
	return this->cpenChangedEvent;
}

const char *GCandlestickSet::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GCandlestickSet::getreleasedEvent(void)
{
	return this->creleasedEvent;
}

const char *GCandlestickSet::gettimestampChangedEvent(void)
{
	return this->ctimestampChangedEvent;
}


void GCandlestickSet::brushChangedSlot()
{
	if (strcmp(this->cbrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbrushChangedEvent);
}

void GCandlestickSet::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GCandlestickSet::closeChangedSlot()
{
	if (strcmp(this->ccloseChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccloseChangedEvent);
}

void GCandlestickSet::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GCandlestickSet::highChangedSlot()
{
	if (strcmp(this->chighChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->chighChangedEvent);
}

void GCandlestickSet::hoveredSlot()
{
	if (strcmp(this->choveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choveredEvent);
}

void GCandlestickSet::lowChangedSlot()
{
	if (strcmp(this->clowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clowChangedEvent);
}

void GCandlestickSet::openChangedSlot()
{
	if (strcmp(this->copenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->copenChangedEvent);
}

void GCandlestickSet::penChangedSlot()
{
	if (strcmp(this->cpenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpenChangedEvent);
}

void GCandlestickSet::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GCandlestickSet::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

void GCandlestickSet::timestampChangedSlot()
{
	if (strcmp(this->ctimestampChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctimestampChangedEvent);
}

