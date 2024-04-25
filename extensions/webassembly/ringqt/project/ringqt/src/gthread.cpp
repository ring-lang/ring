
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gthread.h"

GThread::GThread(QObject *parent,VM *pVM)  : QThread(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cStartedEvent,"");
	strcpy(this->cFinishedEvent,"");

	QObject::connect(this, SIGNAL(started()),this, SLOT(startedSlot()));
	QObject::connect(this, SIGNAL(finished()),this, SLOT(finishedSlot()));

}

GThread::~GThread()
{
	ring_list_delete(this->pParaList);
}

void GThread::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GThread::setStartedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cStartedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GThread::setFinishedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cFinishedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GThread::getStartedEvent(void)
{
	return this->cStartedEvent;
}

const char *GThread::getFinishedEvent(void)
{
	return this->cFinishedEvent;
}


void GThread::startedSlot()
{
	if (strcmp(this->cStartedEvent,"")==0)
		return ;

	ring_vm_runcodefromthread(this->pVM,this->cStartedEvent);
}

void GThread::finishedSlot()
{
	if (strcmp(this->cFinishedEvent,"")==0)
		return ;

	ring_vm_runcodefromthread(this->pVM,this->cFinishedEvent);
}

