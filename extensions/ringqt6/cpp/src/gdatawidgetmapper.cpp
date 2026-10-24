
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gdatawidgetmapper.h"

GDataWidgetMapper::GDataWidgetMapper(QObject *parent,VM *pVM)  : QDataWidgetMapper(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccurrentIndexChangedEvent,"");

	QObject::connect(this, SIGNAL(currentIndexChanged(int)),this, SLOT(currentIndexChangedSlot()));

}

GDataWidgetMapper::~GDataWidgetMapper()
{
	ring_list_delete(this->pParaList);
}

void GDataWidgetMapper::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GDataWidgetMapper::setcurrentIndexChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentIndexChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GDataWidgetMapper::getcurrentIndexChangedEvent(void)
{
	return this->ccurrentIndexChangedEvent;
}


void GDataWidgetMapper::currentIndexChangedSlot()
{
	if (strcmp(this->ccurrentIndexChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentIndexChangedEvent);
}

