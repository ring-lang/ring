
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gdrag.h"

GDrag::GDrag(QObject *parent,VM *pVM)  : QDrag(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cactionChangedEvent,"");
	strcpy(this->ctargetChangedEvent,"");

	QObject::connect(this, SIGNAL(actionChanged(Qt::DropAction)),this, SLOT(actionChangedSlot()));
	QObject::connect(this, SIGNAL(targetChanged(QObject *)),this, SLOT(targetChangedSlot()));

}

GDrag::~GDrag()
{
	ring_list_delete(this->pParaList);
}

void GDrag::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GDrag::setactionChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cactionChangedEvent,cStr);
}

void GDrag::settargetChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ctargetChangedEvent,cStr);
}

 
const char *GDrag::getactionChangedEvent(void)
{
	return this->cactionChangedEvent;
}

const char *GDrag::gettargetChangedEvent(void)
{
	return this->ctargetChangedEvent;
}


void GDrag::actionChangedSlot()
{
	if (strcmp(this->cactionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cactionChangedEvent);
}

void GDrag::targetChangedSlot()
{
	if (strcmp(this->ctargetChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctargetChangedEvent);
}

