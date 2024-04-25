
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "ggraphicsobject.h"

GGraphicsObject::GGraphicsObject(QGraphicsItem * parent,VM *pVM)  : QGraphicsObject(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cenabledChangedEvent,"");
	strcpy(this->copacityChangedEvent,"");
	strcpy(this->cparentChangedEvent,"");
	strcpy(this->crotationChangedEvent,"");
	strcpy(this->cscaleChangedEvent,"");
	strcpy(this->cvisibleChangedEvent,"");
	strcpy(this->cxChangedEvent,"");
	strcpy(this->cyChangedEvent,"");
	strcpy(this->czChangedEvent,"");

	QObject::connect(this, SIGNAL(enabledChanged()),this, SLOT(enabledChangedSlot()));
	QObject::connect(this, SIGNAL(opacityChanged()),this, SLOT(opacityChangedSlot()));
	QObject::connect(this, SIGNAL(parentChanged()),this, SLOT(parentChangedSlot()));
	QObject::connect(this, SIGNAL(rotationChanged()),this, SLOT(rotationChangedSlot()));
	QObject::connect(this, SIGNAL(scaleChanged()),this, SLOT(scaleChangedSlot()));
	QObject::connect(this, SIGNAL(visibleChanged()),this, SLOT(visibleChangedSlot()));
	QObject::connect(this, SIGNAL(xChanged()),this, SLOT(xChangedSlot()));
	QObject::connect(this, SIGNAL(yChanged()),this, SLOT(yChangedSlot()));
	QObject::connect(this, SIGNAL(zChanged()),this, SLOT(zChangedSlot()));

}

GGraphicsObject::~GGraphicsObject()
{
	ring_list_delete(this->pParaList);
}

void GGraphicsObject::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GGraphicsObject::setenabledChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cenabledChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGraphicsObject::setopacityChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->copacityChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGraphicsObject::setparentChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cparentChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGraphicsObject::setrotationChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->crotationChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGraphicsObject::setscaleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cscaleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGraphicsObject::setvisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGraphicsObject::setxChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cxChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGraphicsObject::setyChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cyChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGraphicsObject::setzChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->czChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GGraphicsObject::getenabledChangedEvent(void)
{
	return this->cenabledChangedEvent;
}

const char *GGraphicsObject::getopacityChangedEvent(void)
{
	return this->copacityChangedEvent;
}

const char *GGraphicsObject::getparentChangedEvent(void)
{
	return this->cparentChangedEvent;
}

const char *GGraphicsObject::getrotationChangedEvent(void)
{
	return this->crotationChangedEvent;
}

const char *GGraphicsObject::getscaleChangedEvent(void)
{
	return this->cscaleChangedEvent;
}

const char *GGraphicsObject::getvisibleChangedEvent(void)
{
	return this->cvisibleChangedEvent;
}

const char *GGraphicsObject::getxChangedEvent(void)
{
	return this->cxChangedEvent;
}

const char *GGraphicsObject::getyChangedEvent(void)
{
	return this->cyChangedEvent;
}

const char *GGraphicsObject::getzChangedEvent(void)
{
	return this->czChangedEvent;
}


void GGraphicsObject::enabledChangedSlot()
{
	if (strcmp(this->cenabledChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cenabledChangedEvent);
}

void GGraphicsObject::opacityChangedSlot()
{
	if (strcmp(this->copacityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->copacityChangedEvent);
}

void GGraphicsObject::parentChangedSlot()
{
	if (strcmp(this->cparentChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cparentChangedEvent);
}

void GGraphicsObject::rotationChangedSlot()
{
	if (strcmp(this->crotationChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crotationChangedEvent);
}

void GGraphicsObject::scaleChangedSlot()
{
	if (strcmp(this->cscaleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cscaleChangedEvent);
}

void GGraphicsObject::visibleChangedSlot()
{
	if (strcmp(this->cvisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvisibleChangedEvent);
}

void GGraphicsObject::xChangedSlot()
{
	if (strcmp(this->cxChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cxChangedEvent);
}

void GGraphicsObject::yChangedSlot()
{
	if (strcmp(this->cyChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cyChangedEvent);
}

void GGraphicsObject::zChangedSlot()
{
	if (strcmp(this->czChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->czChangedEvent);
}

