
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gaction.h"

GAction::GAction(QWidget *parent,VM *pVM)  : QAction(parent)
{
	this->pVM = pVM;
	strcpy(this->cClickEvent,"");

	QObject::connect(this, SIGNAL(triggered()),this, SLOT(clickedSlot()));

}
 
void GAction::setClickEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cClickEvent,cStr);
}


void GAction::clickedSlot()
{
	if (strcmp(this->cClickEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cClickEvent);
}

