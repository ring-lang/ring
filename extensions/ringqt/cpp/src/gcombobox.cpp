
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gcombobox.h"

GComboBox::GComboBox(QWidget *parent,VM *pVM)  : QComboBox(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cactivatedEvent,"");
	strcpy(this->ccurrentIndexChangedEvent,"");
	strcpy(this->ceditTextChangedEvent,"");
	strcpy(this->chighlightedEvent,"");

	QObject::connect(this, SIGNAL(activated(int)),this, SLOT(activatedSlot()));
	QObject::connect(this, SIGNAL(currentIndexChanged(int)),this, SLOT(currentIndexChangedSlot()));
	QObject::connect(this, SIGNAL(editTextChanged(QString)),this, SLOT(editTextChangedSlot()));
	QObject::connect(this, SIGNAL(highlighted(int)),this, SLOT(highlightedSlot()));

}

GComboBox::~GComboBox()
{
	ring_list_delete(this->pParaList);
}

void GComboBox::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GComboBox::setactivatedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cactivatedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GComboBox::setcurrentIndexChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentIndexChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GComboBox::seteditTextChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ceditTextChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GComboBox::sethighlightedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->chighlightedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GComboBox::getactivatedEvent(void)
{
	return this->cactivatedEvent;
}

const char *GComboBox::getcurrentIndexChangedEvent(void)
{
	return this->ccurrentIndexChangedEvent;
}

const char *GComboBox::geteditTextChangedEvent(void)
{
	return this->ceditTextChangedEvent;
}

const char *GComboBox::gethighlightedEvent(void)
{
	return this->chighlightedEvent;
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

