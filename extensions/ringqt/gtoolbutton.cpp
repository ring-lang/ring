
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtoolbutton.h"

GToolButton::GToolButton(QWidget *parent,VM *pVM)  : QToolButton(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ctriggeredEvent,"");

	QObject::connect(this, SIGNAL(triggered(QAction *)),this, SLOT(triggeredSlot()));

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
	if (strlen(cStr)<100)
		strcpy(this->ctriggeredEvent,cStr);
}

 
const char *GToolButton::gettriggeredEvent(void)
{
	return this->ctriggeredEvent;
}


void GToolButton::triggeredSlot()
{
	if (strcmp(this->ctriggeredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctriggeredEvent);
}

