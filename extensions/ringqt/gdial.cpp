
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gdial.h"

GDial::GDial(QWidget *parent,VM *pVM)  : QDial(parent)
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

GDial::~GDial()
{
	ring_list_delete(this->pParaList);
}

void GDial::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GDial::setactionTriggeredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cactionTriggeredEvent,cStr);
}

void GDial::setrangeChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->crangeChangedEvent,cStr);
}

void GDial::setsliderMovedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csliderMovedEvent,cStr);
}

void GDial::setsliderPressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csliderPressedEvent,cStr);
}

void GDial::setsliderReleasedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csliderReleasedEvent,cStr);
}

void GDial::setvalueChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cvalueChangedEvent,cStr);
}

 
const char *GDial::getactionTriggeredEvent(void)
{
	return this->cactionTriggeredEvent;
}

const char *GDial::getrangeChangedEvent(void)
{
	return this->crangeChangedEvent;
}

const char *GDial::getsliderMovedEvent(void)
{
	return this->csliderMovedEvent;
}

const char *GDial::getsliderPressedEvent(void)
{
	return this->csliderPressedEvent;
}

const char *GDial::getsliderReleasedEvent(void)
{
	return this->csliderReleasedEvent;
}

const char *GDial::getvalueChangedEvent(void)
{
	return this->cvalueChangedEvent;
}


void GDial::actionTriggeredSlot()
{
	if (strcmp(this->cactionTriggeredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cactionTriggeredEvent);
}

void GDial::rangeChangedSlot()
{
	if (strcmp(this->crangeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crangeChangedEvent);
}

void GDial::sliderMovedSlot()
{
	if (strcmp(this->csliderMovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csliderMovedEvent);
}

void GDial::sliderPressedSlot()
{
	if (strcmp(this->csliderPressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csliderPressedEvent);
}

void GDial::sliderReleasedSlot()
{
	if (strcmp(this->csliderReleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csliderReleasedEvent);
}

void GDial::valueChangedSlot()
{
	if (strcmp(this->cvalueChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvalueChangedEvent);
}

