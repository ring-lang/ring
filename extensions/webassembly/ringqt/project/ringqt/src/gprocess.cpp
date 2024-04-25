
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gprocess.h"

GProcess::GProcess(QObject *parent,VM *pVM)  : QProcess(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->creadyReadStandardErrorEvent,"");
	strcpy(this->creadyReadStandardOutputEvent,"");

	QObject::connect(this, SIGNAL(readyReadStandardError()),this, SLOT(readyReadStandardErrorSlot()));
	QObject::connect(this, SIGNAL(readyReadStandardOutput()),this, SLOT(readyReadStandardOutputSlot()));

}

GProcess::~GProcess()
{
	ring_list_delete(this->pParaList);
}

void GProcess::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GProcess::setreadyReadStandardErrorEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creadyReadStandardErrorEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GProcess::setreadyReadStandardOutputEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creadyReadStandardOutputEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GProcess::getreadyReadStandardErrorEvent(void)
{
	return this->creadyReadStandardErrorEvent;
}

const char *GProcess::getreadyReadStandardOutputEvent(void)
{
	return this->creadyReadStandardOutputEvent;
}


void GProcess::readyReadStandardErrorSlot()
{
	if (strcmp(this->creadyReadStandardErrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creadyReadStandardErrorEvent);
}

void GProcess::readyReadStandardOutputSlot()
{
	if (strcmp(this->creadyReadStandardOutputEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creadyReadStandardOutputEvent);
}

