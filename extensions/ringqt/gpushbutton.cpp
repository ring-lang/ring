
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gpushbutton.h"

GPushButton::GPushButton(QWidget *parent,VM *pVM)  : QPushButton(parent)
{
	this->pVM = pVM;
	strcpy(this->cClickEvent,"");

	QObject::connect(this, SIGNAL(clicked()),this, SLOT(clickedSlot()));

}
 
void GPushButton::setClickEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cClickEvent,cStr);
}


void GPushButton::clickedSlot()
{
	if (strcmp(this->cClickEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cClickEvent);
}

