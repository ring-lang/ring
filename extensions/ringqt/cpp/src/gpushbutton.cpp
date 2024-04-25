
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gpushbutton.h"

GPushButton::GPushButton(QWidget *parent,VM *pVM)  : QPushButton(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cClickEvent,"");

	QObject::connect(this, SIGNAL(clicked()),this, SLOT(clickedSlot()));

}

GPushButton::~GPushButton()
{
	ring_list_delete(this->pParaList);
}

void GPushButton::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GPushButton::setClickEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cClickEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GPushButton::getClickEvent(void)
{
	return this->cClickEvent;
}


void GPushButton::clickedSlot()
{
	if (strcmp(this->cClickEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cClickEvent);
}

