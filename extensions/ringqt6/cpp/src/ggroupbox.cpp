
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "ggroupbox.h"

GGroupBox::GGroupBox(QWidget * parent,VM *pVM)  : QGroupBox(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cclickedEvent,"");
	strcpy(this->ctoggledEvent,"");

	QObject::connect(this, SIGNAL(clicked(bool checked =)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(toggled(bool)),this, SLOT(toggledSlot()));

}

GGroupBox::~GGroupBox()
{
	ring_list_delete(this->pParaList);
}

void GGroupBox::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GGroupBox::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGroupBox::settoggledEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctoggledEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GGroupBox::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GGroupBox::gettoggledEvent(void)
{
	return this->ctoggledEvent;
}


void GGroupBox::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GGroupBox::toggledSlot()
{
	if (strcmp(this->ctoggledEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctoggledEvent);
}

