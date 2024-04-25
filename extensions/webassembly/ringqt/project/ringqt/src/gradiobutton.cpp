
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gradiobutton.h"

GRadioButton::GRadioButton(QWidget *parent,VM *pVM)  : QRadioButton(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cclickedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");
	strcpy(this->ctoggledEvent,"");

	QObject::connect(this, SIGNAL(clicked(bool)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(pressed()),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released()),this, SLOT(releasedSlot()));
	QObject::connect(this, SIGNAL(toggled(bool)),this, SLOT(toggledSlot()));

}

GRadioButton::~GRadioButton()
{
	ring_list_delete(this->pParaList);
}

void GRadioButton::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GRadioButton::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GRadioButton::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GRadioButton::setreleasedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creleasedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GRadioButton::settoggledEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctoggledEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GRadioButton::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GRadioButton::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GRadioButton::getreleasedEvent(void)
{
	return this->creleasedEvent;
}

const char *GRadioButton::gettoggledEvent(void)
{
	return this->ctoggledEvent;
}


void GRadioButton::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GRadioButton::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GRadioButton::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

void GRadioButton::toggledSlot()
{
	if (strcmp(this->ctoggledEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctoggledEvent);
}

