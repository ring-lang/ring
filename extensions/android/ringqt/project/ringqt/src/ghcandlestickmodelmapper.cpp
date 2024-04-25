
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "ghcandlestickmodelmapper.h"

GHCandlestickModelMapper::GHCandlestickModelMapper(QObject *parent,VM *pVM)  : QtCharts::QHCandlestickModelMapper(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccloseColumnChangedEvent,"");
	strcpy(this->cfirstSetRowChangedEvent,"");
	strcpy(this->chighColumnChangedEvent,"");
	strcpy(this->clastSetRowChangedEvent,"");
	strcpy(this->clowColumnChangedEvent,"");
	strcpy(this->copenColumnChangedEvent,"");
	strcpy(this->ctimestampColumnChangedEvent,"");

	QObject::connect(this, SIGNAL(closeColumnChanged()),this, SLOT(closeColumnChangedSlot()));
	QObject::connect(this, SIGNAL(firstSetRowChanged()),this, SLOT(firstSetRowChangedSlot()));
	QObject::connect(this, SIGNAL(highColumnChanged()),this, SLOT(highColumnChangedSlot()));
	QObject::connect(this, SIGNAL(lastSetRowChanged()),this, SLOT(lastSetRowChangedSlot()));
	QObject::connect(this, SIGNAL(lowColumnChanged()),this, SLOT(lowColumnChangedSlot()));
	QObject::connect(this, SIGNAL(openColumnChanged()),this, SLOT(openColumnChangedSlot()));
	QObject::connect(this, SIGNAL(timestampColumnChanged()),this, SLOT(timestampColumnChangedSlot()));

}

GHCandlestickModelMapper::~GHCandlestickModelMapper()
{
	ring_list_delete(this->pParaList);
}

void GHCandlestickModelMapper::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GHCandlestickModelMapper::setcloseColumnChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccloseColumnChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHCandlestickModelMapper::setfirstSetRowChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfirstSetRowChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHCandlestickModelMapper::sethighColumnChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->chighColumnChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHCandlestickModelMapper::setlastSetRowChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clastSetRowChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHCandlestickModelMapper::setlowColumnChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clowColumnChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHCandlestickModelMapper::setopenColumnChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->copenColumnChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHCandlestickModelMapper::settimestampColumnChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctimestampColumnChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GHCandlestickModelMapper::getcloseColumnChangedEvent(void)
{
	return this->ccloseColumnChangedEvent;
}

const char *GHCandlestickModelMapper::getfirstSetRowChangedEvent(void)
{
	return this->cfirstSetRowChangedEvent;
}

const char *GHCandlestickModelMapper::gethighColumnChangedEvent(void)
{
	return this->chighColumnChangedEvent;
}

const char *GHCandlestickModelMapper::getlastSetRowChangedEvent(void)
{
	return this->clastSetRowChangedEvent;
}

const char *GHCandlestickModelMapper::getlowColumnChangedEvent(void)
{
	return this->clowColumnChangedEvent;
}

const char *GHCandlestickModelMapper::getopenColumnChangedEvent(void)
{
	return this->copenColumnChangedEvent;
}

const char *GHCandlestickModelMapper::gettimestampColumnChangedEvent(void)
{
	return this->ctimestampColumnChangedEvent;
}


void GHCandlestickModelMapper::closeColumnChangedSlot()
{
	if (strcmp(this->ccloseColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccloseColumnChangedEvent);
}

void GHCandlestickModelMapper::firstSetRowChangedSlot()
{
	if (strcmp(this->cfirstSetRowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfirstSetRowChangedEvent);
}

void GHCandlestickModelMapper::highColumnChangedSlot()
{
	if (strcmp(this->chighColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->chighColumnChangedEvent);
}

void GHCandlestickModelMapper::lastSetRowChangedSlot()
{
	if (strcmp(this->clastSetRowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clastSetRowChangedEvent);
}

void GHCandlestickModelMapper::lowColumnChangedSlot()
{
	if (strcmp(this->clowColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clowColumnChangedEvent);
}

void GHCandlestickModelMapper::openColumnChangedSlot()
{
	if (strcmp(this->copenColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->copenColumnChangedEvent);
}

void GHCandlestickModelMapper::timestampColumnChangedSlot()
{
	if (strcmp(this->ctimestampColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctimestampColumnChangedEvent);
}

