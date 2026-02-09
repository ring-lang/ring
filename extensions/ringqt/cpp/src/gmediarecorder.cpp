
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gmediarecorder.h"

GMediaRecorder::GMediaRecorder(QMediaObject *parent,VM *pVM)  : QMediaRecorder(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cactualLocationChangedEvent,"");
	strcpy(this->cdurationChangedEvent,"");
	strcpy(this->cerrorEvent,"");
	strcpy(this->cmetaDataChangedEvent,"");
	strcpy(this->cmutedChangedEvent,"");
	strcpy(this->cstateChangedEvent,"");
	strcpy(this->cstatusChangedEvent,"");
	strcpy(this->cvolumeChangedEvent,"");

	QObject::connect(this, SIGNAL(actualLocationChanged(QUrl)),this, SLOT(actualLocationChangedSlot()));
	QObject::connect(this, SIGNAL(durationChanged(qint64)),this, SLOT(durationChangedSlot()));
	QObject::connect(this, SIGNAL(error(QMediaRecorder::Error)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(metaDataChanged()),this, SLOT(metaDataChangedSlot()));
	QObject::connect(this, SIGNAL(mutedChanged(bool)),this, SLOT(mutedChangedSlot()));
	QObject::connect(this, SIGNAL(stateChanged(QMediaRecorder::State)),this, SLOT(stateChangedSlot()));
	QObject::connect(this, SIGNAL(statusChanged(QMediaRecorder::Status)),this, SLOT(statusChangedSlot()));
	QObject::connect(this, SIGNAL(volumeChanged(qreal)),this, SLOT(volumeChangedSlot()));

}

GMediaRecorder::~GMediaRecorder()
{
	ring_list_delete(this->pParaList);
}

void GMediaRecorder::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GMediaRecorder::setactualLocationChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cactualLocationChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMediaRecorder::setdurationChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdurationChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMediaRecorder::seterrorEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cerrorEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMediaRecorder::setmetaDataChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmetaDataChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMediaRecorder::setmutedChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmutedChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMediaRecorder::setstateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMediaRecorder::setstatusChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstatusChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GMediaRecorder::setvolumeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvolumeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GMediaRecorder::getactualLocationChangedEvent(void)
{
	return this->cactualLocationChangedEvent;
}

const char *GMediaRecorder::getdurationChangedEvent(void)
{
	return this->cdurationChangedEvent;
}

const char *GMediaRecorder::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GMediaRecorder::getmetaDataChangedEvent(void)
{
	return this->cmetaDataChangedEvent;
}

const char *GMediaRecorder::getmutedChangedEvent(void)
{
	return this->cmutedChangedEvent;
}

const char *GMediaRecorder::getstateChangedEvent(void)
{
	return this->cstateChangedEvent;
}

const char *GMediaRecorder::getstatusChangedEvent(void)
{
	return this->cstatusChangedEvent;
}

const char *GMediaRecorder::getvolumeChangedEvent(void)
{
	return this->cvolumeChangedEvent;
}


void GMediaRecorder::actualLocationChangedSlot()
{
	if (strcmp(this->cactualLocationChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cactualLocationChangedEvent);
}

void GMediaRecorder::durationChangedSlot()
{
	if (strcmp(this->cdurationChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdurationChangedEvent);
}

void GMediaRecorder::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GMediaRecorder::metaDataChangedSlot()
{
	if (strcmp(this->cmetaDataChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmetaDataChangedEvent);
}

void GMediaRecorder::mutedChangedSlot()
{
	if (strcmp(this->cmutedChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmutedChangedEvent);
}

void GMediaRecorder::stateChangedSlot()
{
	if (strcmp(this->cstateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstateChangedEvent);
}

void GMediaRecorder::statusChangedSlot()
{
	if (strcmp(this->cstatusChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstatusChangedEvent);
}

void GMediaRecorder::volumeChangedSlot()
{
	if (strcmp(this->cvolumeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvolumeChangedEvent);
}

