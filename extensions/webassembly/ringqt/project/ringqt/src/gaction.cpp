
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
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
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cClickEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
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

