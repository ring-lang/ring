
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtoolbutton.h"

GToolButton::GToolButton(QWidget *parent,VM *pVM)  : QToolButton(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ctriggeredEvent,"");
	strcpy(this->cClickEvent,"");

	QObject::connect(this, SIGNAL(triggered(QAction *)),this, SLOT(triggeredSlot()));
	QObject::connect(this, SIGNAL(clicked()),this, SLOT(clickedSlot()));

}

GToolButton::~GToolButton()
{
	ring_list_delete(this->pParaList);
}

void GToolButton::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GToolButton::settriggeredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctriggeredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GToolButton::setClickEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cClickEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GToolButton::gettriggeredEvent(void)
{
	return this->ctriggeredEvent;
}

const char *GToolButton::getClickEvent(void)
{
	return this->cClickEvent;
}


void GToolButton::triggeredSlot()
{
	if (strcmp(this->ctriggeredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctriggeredEvent);
}

void GToolButton::clickedSlot()
{
	if (strcmp(this->cClickEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cClickEvent);
}

