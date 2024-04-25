
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "ggeopositioninfosource.h"

GGeoPositionInfoSource::GGeoPositionInfoSource(QObject *parent,VM *pVM)  : QGeoPositionInfoSource(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cerrorEvent,"");
	strcpy(this->cpositionUpdatedEvent,"");
	strcpy(this->cupdateTimeoutEvent,"");

	QObject::connect(this, SIGNAL(error(QGeoPositionInfoSource::Error)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(positionUpdated(const QGeoPositionInfo)),this, SLOT(positionUpdatedSlot()));
	QObject::connect(this, SIGNAL(updateTimeout()),this, SLOT(updateTimeoutSlot()));

}

GGeoPositionInfoSource::~GGeoPositionInfoSource()
{
	ring_list_delete(this->pParaList);
}

void GGeoPositionInfoSource::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GGeoPositionInfoSource::seterrorEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cerrorEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGeoPositionInfoSource::setpositionUpdatedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpositionUpdatedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGeoPositionInfoSource::setupdateTimeoutEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cupdateTimeoutEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GGeoPositionInfoSource::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GGeoPositionInfoSource::getpositionUpdatedEvent(void)
{
	return this->cpositionUpdatedEvent;
}

const char *GGeoPositionInfoSource::getupdateTimeoutEvent(void)
{
	return this->cupdateTimeoutEvent;
}


void GGeoPositionInfoSource::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GGeoPositionInfoSource::positionUpdatedSlot()
{
	if (strcmp(this->cpositionUpdatedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpositionUpdatedEvent);
}

void GGeoPositionInfoSource::updateTimeoutSlot()
{
	if (strcmp(this->cupdateTimeoutEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cupdateTimeoutEvent);
}

