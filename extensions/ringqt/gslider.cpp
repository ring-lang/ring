
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gslider.h"

GSlider::GSlider(QWidget *parent,VM *pVM)  : QSlider(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cactionTriggeredEvent,"");
	strcpy(this->crangeChangedEvent,"");
	strcpy(this->csliderMovedEvent,"");
	strcpy(this->csliderPressedEvent,"");
	strcpy(this->csliderReleasedEvent,"");
	strcpy(this->cvalueChangedEvent,"");

	QObject::connect(this, SIGNAL(actionTriggered(int)),this, SLOT(actionTriggeredSlot()));
	QObject::connect(this, SIGNAL(rangeChanged(int,int)),this, SLOT(rangeChangedSlot()));
	QObject::connect(this, SIGNAL(sliderMoved(int)),this, SLOT(sliderMovedSlot()));
	QObject::connect(this, SIGNAL(sliderPressed()),this, SLOT(sliderPressedSlot()));
	QObject::connect(this, SIGNAL(sliderReleased()),this, SLOT(sliderReleasedSlot()));
	QObject::connect(this, SIGNAL(valueChanged(int)),this, SLOT(valueChangedSlot()));

}

GSlider::~GSlider()
{
	ring_list_delete(this->pParaList);
}

void GSlider::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GSlider::setactionTriggeredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cactionTriggeredEvent,cStr);
}

void GSlider::setrangeChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->crangeChangedEvent,cStr);
}

void GSlider::setsliderMovedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csliderMovedEvent,cStr);
}

void GSlider::setsliderPressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csliderPressedEvent,cStr);
}

void GSlider::setsliderReleasedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csliderReleasedEvent,cStr);
}

void GSlider::setvalueChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cvalueChangedEvent,cStr);
}

 
const char *GSlider::getactionTriggeredEvent(void)
{
	return this->cactionTriggeredEvent;
}

const char *GSlider::getrangeChangedEvent(void)
{
	return this->crangeChangedEvent;
}

const char *GSlider::getsliderMovedEvent(void)
{
	return this->csliderMovedEvent;
}

const char *GSlider::getsliderPressedEvent(void)
{
	return this->csliderPressedEvent;
}

const char *GSlider::getsliderReleasedEvent(void)
{
	return this->csliderReleasedEvent;
}

const char *GSlider::getvalueChangedEvent(void)
{
	return this->cvalueChangedEvent;
}


void GSlider::actionTriggeredSlot()
{
	if (strcmp(this->cactionTriggeredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cactionTriggeredEvent);
}

void GSlider::rangeChangedSlot()
{
	if (strcmp(this->crangeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crangeChangedEvent);
}

void GSlider::sliderMovedSlot()
{
	if (strcmp(this->csliderMovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csliderMovedEvent);
}

void GSlider::sliderPressedSlot()
{
	if (strcmp(this->csliderPressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csliderPressedEvent);
}

void GSlider::sliderReleasedSlot()
{
	if (strcmp(this->csliderReleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csliderReleasedEvent);
}

void GSlider::valueChangedSlot()
{
	if (strcmp(this->cvalueChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvalueChangedEvent);
}

