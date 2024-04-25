
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtimer.h"

GTimer::GTimer(QObject *parent,VM *pVM)  : QTimer(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ctimeoutEvent,"");

	QObject::connect(this, SIGNAL(timeout()),this, SLOT(timeoutSlot()));

}

GTimer::~GTimer()
{
	ring_list_delete(this->pParaList);
}

void GTimer::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GTimer::settimeoutEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctimeoutEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GTimer::gettimeoutEvent(void)
{
	return this->ctimeoutEvent;
}


void GTimer::timeoutSlot()
{
	if (strcmp(this->ctimeoutEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctimeoutEvent);
}

