
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "ggraphicstextitem.h"

GGraphicsTextItem::GGraphicsTextItem(QGraphicsItem * parent,VM *pVM)  : QGraphicsTextItem(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->clinkActivatedEvent,"");
	strcpy(this->clinkHoveredEvent,"");

	QObject::connect(this, SIGNAL(linkActivated(const QString)),this, SLOT(linkActivatedSlot()));
	QObject::connect(this, SIGNAL(linkHovered(const QString)),this, SLOT(linkHoveredSlot()));

}

GGraphicsTextItem::~GGraphicsTextItem()
{
	ring_list_delete(this->pParaList);
}

void GGraphicsTextItem::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GGraphicsTextItem::setlinkActivatedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clinkActivatedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGraphicsTextItem::setlinkHoveredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clinkHoveredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GGraphicsTextItem::getlinkActivatedEvent(void)
{
	return this->clinkActivatedEvent;
}

const char *GGraphicsTextItem::getlinkHoveredEvent(void)
{
	return this->clinkHoveredEvent;
}


void GGraphicsTextItem::linkActivatedSlot()
{
	if (strcmp(this->clinkActivatedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clinkActivatedEvent);
}

void GGraphicsTextItem::linkHoveredSlot()
{
	if (strcmp(this->clinkHoveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clinkHoveredEvent);
}

