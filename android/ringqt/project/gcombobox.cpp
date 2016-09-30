
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gcombobox.h"

GComboBox::GComboBox(QWidget *parent,VM *pVM)  : QComboBox(parent)
{
	this->pVM = pVM;
	strcpy(this->cactivatedEvent,"");
	strcpy(this->ccurrentIndexChangedEvent,"");
	strcpy(this->ceditTextChangedEvent,"");
	strcpy(this->chighlightedEvent,"");

	QObject::connect(this, SIGNAL(activated(int)),this, SLOT(activatedSlot()));
	QObject::connect(this, SIGNAL(currentIndexChanged(int)),this, SLOT(currentIndexChangedSlot()));
	QObject::connect(this, SIGNAL(editTextChanged(QString)),this, SLOT(editTextChangedSlot()));
	QObject::connect(this, SIGNAL(highlighted(int)),this, SLOT(highlightedSlot()));

}
 
void GComboBox::setactivatedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cactivatedEvent,cStr);
}

void GComboBox::setcurrentIndexChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccurrentIndexChangedEvent,cStr);
}

void GComboBox::seteditTextChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ceditTextChangedEvent,cStr);
}

void GComboBox::sethighlightedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->chighlightedEvent,cStr);
}


void GComboBox::activatedSlot()
{
	if (strcmp(this->cactivatedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cactivatedEvent);
}

void GComboBox::currentIndexChangedSlot()
{
	if (strcmp(this->ccurrentIndexChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ccurrentIndexChangedEvent);
}

void GComboBox::editTextChangedSlot()
{
	if (strcmp(this->ceditTextChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ceditTextChangedEvent);
}

void GComboBox::highlightedSlot()
{
	if (strcmp(this->chighlightedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->chighlightedEvent);
}

