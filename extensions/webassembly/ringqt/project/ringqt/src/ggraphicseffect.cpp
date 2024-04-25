
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "ggraphicseffect.h"

GGraphicsEffect::GGraphicsEffect(QObject * parent,VM *pVM)  : QGraphicsEffect(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cenabledChangedEvent,"");

	QObject::connect(this, SIGNAL(enabledChanged(bool)),this, SLOT(enabledChangedSlot()));

}

GGraphicsEffect::~GGraphicsEffect()
{
	ring_list_delete(this->pParaList);
}

void GGraphicsEffect::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GGraphicsEffect::setenabledChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cenabledChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GGraphicsEffect::getenabledChangedEvent(void)
{
	return this->cenabledChangedEvent;
}


void GGraphicsEffect::enabledChangedSlot()
{
	if (strcmp(this->cenabledChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cenabledChangedEvent);
}

