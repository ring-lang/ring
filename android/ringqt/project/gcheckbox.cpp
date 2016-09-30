
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gcheckbox.h"

GCheckBox::GCheckBox(QWidget *parent,VM *pVM)  : QCheckBox(parent)
{
	this->pVM = pVM;
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

