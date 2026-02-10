
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gaudioinput.h"

GAudioInput::GAudioInput(const QAudioFormat &parent,VM *pVM)  : QAudioInput(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cstateChangedEvent,"");
	strcpy(this->cnotifyEvent,"");

	QObject::connect(this, SIGNAL(stateChanged(QAudio::State)),this, SLOT(stateChangedSlot()));
	QObject::connect(this, SIGNAL(notify()),this, SLOT(notifySlot()));

}

GAudioInput::~GAudioInput()
{
	ring_list_delete(this->pParaList);
}

void GAudioInput::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GAudioInput::setstateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAudioInput::setnotifyEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cnotifyEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GAudioInput::getstateChangedEvent(void)
{
	return this->cstateChangedEvent;
}

const char *GAudioInput::getnotifyEvent(void)
{
	return this->cnotifyEvent;
}


void GAudioInput::stateChangedSlot()
{
	if (strcmp(this->cstateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstateChangedEvent);
}

void GAudioInput::notifySlot()
{
	if (strcmp(this->cnotifyEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cnotifyEvent);
}

