
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtimer.h"

GTimer::GTimer(QObject *parent,VM *pVM)  : QTimer(parent)
{
	this->pVM = pVM;
	strcpy(this->ctimeoutEvent,"");

	QObject::connect(this, SIGNAL(timeout()),this, SLOT(timeoutSlot()));

}
 
void GTimer::settimeoutEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ctimeoutEvent,cStr);
}


void GTimer::timeoutSlot()
{
	if (strcmp(this->ctimeoutEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ctimeoutEvent);
}

