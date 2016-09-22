
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gthread.h"

GThread::GThread(QObject *parent,VM *pVM)  : QThread(parent)
{
	this->pVM = pVM;
	strcpy(this->cStartedEvent,"");
	strcpy(this->cFinishedEvent,"");

	QObject::connect(this, SIGNAL(started()),this, SLOT(startedSlot()));
	QObject::connect(this, SIGNAL(finished()),this, SLOT(finishedSlot()));

}
 
void GThread::setStartedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cStartedEvent,cStr);
}

void GThread::setFinishedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cFinishedEvent,cStr);
}


void GThread::startedSlot()
{
	if (strcmp(this->cStartedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cStartedEvent);
}

void GThread::finishedSlot()
{
	if (strcmp(this->cFinishedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cFinishedEvent);
}

