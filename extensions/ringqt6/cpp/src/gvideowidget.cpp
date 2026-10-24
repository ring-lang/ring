
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gvideowidget.h"

GVideoWidget::GVideoWidget(QWidget *parent,VM *pVM)  : QVideoWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cfullScreenChangedEvent,"");

	QObject::connect(this, SIGNAL(fullScreenChanged(bool)),this, SLOT(fullScreenChangedSlot()));

}

GVideoWidget::~GVideoWidget()
{
	ring_list_delete(this->pParaList);
}

void GVideoWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GVideoWidget::setfullScreenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfullScreenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GVideoWidget::getfullScreenChangedEvent(void)
{
	return this->cfullScreenChangedEvent;
}


void GVideoWidget::fullScreenChangedSlot()
{
	if (strcmp(this->cfullScreenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfullScreenChangedEvent);
}

