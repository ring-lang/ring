
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gcheckbox.h"

GCheckBox::GCheckBox(QWidget *parent,VM *pVM)  : QCheckBox(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cstateChangedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");
	strcpy(this->ctoggledEvent,"");

	QObject::connect(this, SIGNAL(stateChanged(int)),this, SLOT(stateChangedSlot()));
	QObject::connect(this, SIGNAL(clicked(bool)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(pressed()),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released()),this, SLOT(releasedSlot()));
	QObject::connect(this, SIGNAL(toggled(bool)),this, SLOT(toggledSlot()));

}

GCheckBox::~GCheckBox()
{
	ring_list_delete(this->pParaList);
}

void GCheckBox::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GCheckBox::setstateChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cstateChangedEvent,cStr);
}

void GCheckBox::setclickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cclickedEvent,cStr);
}

void GCheckBox::setpressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpressedEvent,cStr);
}

void GCheckBox::setreleasedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->creleasedEvent,cStr);
}

void GCheckBox::settoggledEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ctoggledEvent,cStr);
}

 
const char *GCheckBox::getstateChangedEvent(void)
{
	return this->cstateChangedEvent;
}

const char *GCheckBox::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GCheckBox::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GCheckBox::getreleasedEvent(void)
{
	return this->creleasedEvent;
}

const char *GCheckBox::gettoggledEvent(void)
{
	return this->ctoggledEvent;
}


void GCheckBox::stateChangedSlot()
{
	if (strcmp(this->cstateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstateChangedEvent);
}

void GCheckBox::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GCheckBox::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GCheckBox::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

void GCheckBox::toggledSlot()
{
	if (strcmp(this->ctoggledEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctoggledEvent);
}

