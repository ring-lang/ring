
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gmovie.h"

GMovie::GMovie(QObject * parent,VM *pVM)  : QMovie(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cerrorEvent,"");
	strcpy(this->cfinishedEvent,"");
	strcpy(this->cframeChangedEvent,"");
	strcpy(this->cresizedEvent,"");
	strcpy(this->cstartedEvent,"");
	strcpy(this->cstateChangedEvent,"");
	strcpy(this->cupdatedEvent,"");

	QObject::connect(this, SIGNAL(error(QImageReader::ImageReaderError)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(finished()),this, SLOT(finishedSlot()));
	QObject::connect(this, SIGNAL(frameChanged(int)),this, SLOT(frameChangedSlot()));
	QObject::connect(this, SIGNAL(resized(const QSize)),this, SLOT(resizedSlot()));
	QObject::connect(this, SIGNAL(started()),this, SLOT(startedSlot()));
	QObject::connect(this, SIGNAL(stateChanged(QMovie::MovieState)),this, SLOT(stateChangedSlot()));
	QObject::connect(this, SIGNAL(updated(const QRect)),this, SLOT(updatedSlot()));

}

GMovie::~GMovie()
{
	ring_list_delete(this->pParaList);
}

void GMovie::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GMovie::seterrorEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cerrorEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMovie::setfinishedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfinishedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMovie::setframeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cframeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMovie::setresizedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cresizedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMovie::setstartedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstartedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMovie::setstateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMovie::setupdatedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cupdatedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GMovie::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GMovie::getfinishedEvent(void)
{
	return this->cfinishedEvent;
}

const char *GMovie::getframeChangedEvent(void)
{
	return this->cframeChangedEvent;
}

const char *GMovie::getresizedEvent(void)
{
	return this->cresizedEvent;
}

const char *GMovie::getstartedEvent(void)
{
	return this->cstartedEvent;
}

const char *GMovie::getstateChangedEvent(void)
{
	return this->cstateChangedEvent;
}

const char *GMovie::getupdatedEvent(void)
{
	return this->cupdatedEvent;
}


void GMovie::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GMovie::finishedSlot()
{
	if (strcmp(this->cfinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfinishedEvent);
}

void GMovie::frameChangedSlot()
{
	if (strcmp(this->cframeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cframeChangedEvent);
}

void GMovie::resizedSlot()
{
	if (strcmp(this->cresizedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cresizedEvent);
}

void GMovie::startedSlot()
{
	if (strcmp(this->cstartedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstartedEvent);
}

void GMovie::stateChangedSlot()
{
	if (strcmp(this->cstateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstateChangedEvent);
}

void GMovie::updatedSlot()
{
	if (strcmp(this->cupdatedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cupdatedEvent);
}

