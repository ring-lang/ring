
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gstackedlayout.h"

GStackedLayout::GStackedLayout(QWidget *parent,VM *pVM)  : QStackedLayout(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccurrentChangedEvent,"");
	strcpy(this->cwidgetRemovedEvent,"");

	QObject::connect(this, SIGNAL(currentChanged(int)),this, SLOT(currentChangedSlot()));
	QObject::connect(this, SIGNAL(widgetRemoved(int)),this, SLOT(widgetRemovedSlot()));

}

GStackedLayout::~GStackedLayout()
{
	ring_list_delete(this->pParaList);
}

void GStackedLayout::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GStackedLayout::setcurrentChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GStackedLayout::setwidgetRemovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cwidgetRemovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GStackedLayout::getcurrentChangedEvent(void)
{
	return this->ccurrentChangedEvent;
}

const char *GStackedLayout::getwidgetRemovedEvent(void)
{
	return this->cwidgetRemovedEvent;
}


void GStackedLayout::currentChangedSlot()
{
	if (strcmp(this->ccurrentChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentChangedEvent);
}

void GStackedLayout::widgetRemovedSlot()
{
	if (strcmp(this->cwidgetRemovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cwidgetRemovedEvent);
}

