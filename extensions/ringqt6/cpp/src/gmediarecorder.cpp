
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gmediarecorder.h"

GMediaRecorder::GMediaRecorder(QObject *parent,VM *pVM)  : QMediaRecorder(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cactualLocationChangedEvent,"");
	strcpy(this->cdurationChangedEvent,"");
	strcpy(this->cstateChangedEvent,"");
	strcpy(this->cerrorEvent,"");

	QObject::connect(this, SIGNAL(actualLocationChanged(QUrl)),this, SLOT(actualLocationChangedSlot()));
	QObject::connect(this, SIGNAL(durationChanged(qint64)),this, SLOT(durationChangedSlot()));
	QObject::connect(this, SIGNAL(recorderStateChanged(QMediaRecorder::RecorderState)),this, SLOT(stateChangedSlot()));
	QObject::connect(this, SIGNAL(errorOccurred(QMediaRecorder::Error,const QString &)),this, SLOT(errorSlot()));

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

void GMediaRecorder::setstateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstateChangedEvent,cStr);
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

 
const char *GMediaRecorder::getactualLocationChangedEvent(void)
{
	return this->cactualLocationChangedEvent;
}

const char *GMediaRecorder::getdurationChangedEvent(void)
{
	return this->cdurationChangedEvent;
}

const char *GMediaRecorder::getstateChangedEvent(void)
{
	return this->cstateChangedEvent;
}

const char *GMediaRecorder::geterrorEvent(void)
{
	return this->cerrorEvent;
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

void GMediaRecorder::stateChangedSlot()
{
	if (strcmp(this->cstateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstateChangedEvent);
}

void GMediaRecorder::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

