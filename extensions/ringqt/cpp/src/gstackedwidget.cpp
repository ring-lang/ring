
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gstackedwidget.h"

GStackedWidget::GStackedWidget(QWidget *parent,VM *pVM)  : QStackedWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccurrentChangedEvent,"");
	strcpy(this->cwidgetRemovedEvent,"");

	QObject::connect(this, SIGNAL(currentChanged(int)),this, SLOT(currentChangedSlot()));
	QObject::connect(this, SIGNAL(widgetRemoved(int)),this, SLOT(widgetRemovedSlot()));

}

GStackedWidget::~GStackedWidget()
{
	ring_list_delete(this->pParaList);
}

void GStackedWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GStackedWidget::setcurrentChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GStackedWidget::setwidgetRemovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cwidgetRemovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GStackedWidget::getcurrentChangedEvent(void)
{
	return this->ccurrentChangedEvent;
}

const char *GStackedWidget::getwidgetRemovedEvent(void)
{
	return this->cwidgetRemovedEvent;
}


void GStackedWidget::currentChangedSlot()
{
	if (strcmp(this->ccurrentChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentChangedEvent);
}

void GStackedWidget::widgetRemovedSlot()
{
	if (strcmp(this->cwidgetRemovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cwidgetRemovedEvent);
}

