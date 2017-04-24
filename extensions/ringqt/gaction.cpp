
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gaction.h"

GAction::GAction(QWidget *parent,VM *pVM)  : QAction(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cClickEvent,"");

	QObject::connect(this, SIGNAL(triggered()),this, SLOT(clickedSlot()));

}

GAction::~GAction()
{
	ring_list_delete(this->pParaList);
}

void GAction::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GAction::setClickEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cClickEvent,cStr);
}

 
const char *GAction::getClickEvent(void)
{
	return this->cClickEvent;
}


void GAction::clickedSlot()
{
	if (strcmp(this->cClickEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cClickEvent);
}

