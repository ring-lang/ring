
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gbuttongroup.h"

GButtonGroup::GButtonGroup(QObject *parent,VM *pVM)  : QButtonGroup(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cbuttonClickedEvent,"");
	strcpy(this->cbuttonPressedEvent,"");
	strcpy(this->cbuttonReleasedEvent,"");

	QObject::connect(this, SIGNAL(buttonClicked(int)),this, SLOT(buttonClickedSlot()));
	QObject::connect(this, SIGNAL(buttonPressed(int)),this, SLOT(buttonPressedSlot()));
	QObject::connect(this, SIGNAL(buttonReleased(int)),this, SLOT(buttonReleasedSlot()));

}

GButtonGroup::~GButtonGroup()
{
	ring_list_delete(this->pParaList);
}

void GButtonGroup::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GButtonGroup::setbuttonClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cbuttonClickedEvent,cStr);
}

void GButtonGroup::setbuttonPressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cbuttonPressedEvent,cStr);
}

void GButtonGroup::setbuttonReleasedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cbuttonReleasedEvent,cStr);
}

 
const char *GButtonGroup::getbuttonClickedEvent(void)
{
	return this->cbuttonClickedEvent;
}

const char *GButtonGroup::getbuttonPressedEvent(void)
{
	return this->cbuttonPressedEvent;
}

const char *GButtonGroup::getbuttonReleasedEvent(void)
{
	return this->cbuttonReleasedEvent;
}


void GButtonGroup::buttonClickedSlot()
{
	if (strcmp(this->cbuttonClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbuttonClickedEvent);
}

void GButtonGroup::buttonPressedSlot()
{
	if (strcmp(this->cbuttonPressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbuttonPressedEvent);
}

void GButtonGroup::buttonReleasedSlot()
{
	if (strcmp(this->cbuttonReleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbuttonReleasedEvent);
}

