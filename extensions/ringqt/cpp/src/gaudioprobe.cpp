
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gaudioprobe.h"

GAudioProbe::GAudioProbe(QObject *parent,VM *pVM)  : QAudioProbe(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->caudioBufferProbedEvent,"");
	strcpy(this->cflushEvent,"");

	QObject::connect(this, SIGNAL(audioBufferProbed(QAudioBuffer)),this, SLOT(audioBufferProbedSlot()));
	QObject::connect(this, SIGNAL(flush()),this, SLOT(flushSlot()));

}

GAudioProbe::~GAudioProbe()
{
	ring_list_delete(this->pParaList);
}

void GAudioProbe::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GAudioProbe::setaudioBufferProbedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->caudioBufferProbedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAudioProbe::setflushEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cflushEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GAudioProbe::getaudioBufferProbedEvent(void)
{
	return this->caudioBufferProbedEvent;
}

const char *GAudioProbe::getflushEvent(void)
{
	return this->cflushEvent;
}


void GAudioProbe::audioBufferProbedSlot()
{
	if (strcmp(this->caudioBufferProbedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->caudioBufferProbedEvent);
}

void GAudioProbe::flushSlot()
{
	if (strcmp(this->cflushEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cflushEvent);
}

