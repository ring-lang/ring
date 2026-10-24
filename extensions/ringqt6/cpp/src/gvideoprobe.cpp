
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gvideoprobe.h"

GVideoProbe::GVideoProbe(QObject *parent,VM *pVM)  : QVideoProbe(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cvideoFrameProbedEvent,"");
	strcpy(this->cflushEvent,"");

	QObject::connect(this, SIGNAL(videoFrameProbed(QVideoFrame)),this, SLOT(videoFrameProbedSlot()));
	QObject::connect(this, SIGNAL(flush()),this, SLOT(flushSlot()));

}

GVideoProbe::~GVideoProbe()
{
	ring_list_delete(this->pParaList);
}

void GVideoProbe::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GVideoProbe::setvideoFrameProbedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvideoFrameProbedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GVideoProbe::setflushEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cflushEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GVideoProbe::getvideoFrameProbedEvent(void)
{
	return this->cvideoFrameProbedEvent;
}

const char *GVideoProbe::getflushEvent(void)
{
	return this->cflushEvent;
}


void GVideoProbe::videoFrameProbedSlot()
{
	if (strcmp(this->cvideoFrameProbedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvideoFrameProbedEvent);
}

void GVideoProbe::flushSlot()
{
	if (strcmp(this->cflushEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cflushEvent);
}

