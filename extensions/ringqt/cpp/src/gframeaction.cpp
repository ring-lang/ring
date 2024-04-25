
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gframeaction.h"

GFrameAction::GFrameAction(Qt3DCore::QNode *parent,VM *pVM)  : Qt3DLogic::QFrameAction(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ctriggeredEvent,"");

	QObject::connect(this, SIGNAL(triggered(float)),this, SLOT(triggeredSlot()));

}

GFrameAction::~GFrameAction()
{
	ring_list_delete(this->pParaList);
}

void GFrameAction::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GFrameAction::settriggeredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctriggeredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GFrameAction::gettriggeredEvent(void)
{
	return this->ctriggeredEvent;
}


void GFrameAction::triggeredSlot()
{
	if (strcmp(this->ctriggeredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctriggeredEvent);
}

