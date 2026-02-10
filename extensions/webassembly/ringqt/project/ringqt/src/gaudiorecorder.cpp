
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gaudiorecorder.h"

GAudioRecorder::GAudioRecorder(QObject *parent,VM *pVM)  : QAudioRecorder(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->caudioInputChangedEvent,"");
	strcpy(this->cavailableAudioInputsChangedEvent,"");

	QObject::connect(this, SIGNAL(audioInputChanged(QString)),this, SLOT(audioInputChangedSlot()));
	QObject::connect(this, SIGNAL(availableAudioInputsChanged()),this, SLOT(availableAudioInputsChangedSlot()));

}

GAudioRecorder::~GAudioRecorder()
{
	ring_list_delete(this->pParaList);
}

void GAudioRecorder::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GAudioRecorder::setaudioInputChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->caudioInputChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAudioRecorder::setavailableAudioInputsChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cavailableAudioInputsChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GAudioRecorder::getaudioInputChangedEvent(void)
{
	return this->caudioInputChangedEvent;
}

const char *GAudioRecorder::getavailableAudioInputsChangedEvent(void)
{
	return this->cavailableAudioInputsChangedEvent;
}


void GAudioRecorder::audioInputChangedSlot()
{
	if (strcmp(this->caudioInputChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->caudioInputChangedEvent);
}

void GAudioRecorder::availableAudioInputsChangedSlot()
{
	if (strcmp(this->cavailableAudioInputsChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cavailableAudioInputsChangedEvent);
}

