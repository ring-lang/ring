
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtabwidget.h"

GTabWidget::GTabWidget(QWidget *parent,VM *pVM)  : QTabWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccurrentChangedEvent,"");
	strcpy(this->ctabCloseRequestedEvent,"");

	QObject::connect(this, SIGNAL(currentChanged(int)),this, SLOT(currentChangedSlot()));
	QObject::connect(this, SIGNAL(tabCloseRequested(int)),this, SLOT(tabCloseRequestedSlot(int)));

}

GTabWidget::~GTabWidget()
{
	ring_list_delete(this->pParaList);
}

void GTabWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GTabWidget::setcurrentChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTabWidget::settabCloseRequestedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctabCloseRequestedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GTabWidget::getcurrentChangedEvent(void)
{
	return this->ccurrentChangedEvent;
}

const char *GTabWidget::gettabCloseRequestedEvent(void)
{
	return this->ctabCloseRequestedEvent;
}


void GTabWidget::currentChangedSlot()
{
	if (strcmp(this->ccurrentChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentChangedEvent);
}

void GTabWidget::tabCloseRequestedSlot(int p1)
{
	if (strcmp(this->ctabCloseRequestedEvent,"")==0)
		return ;

		ring_list_deleteallitems(this->pParaList);
		ring_list_adddouble(this->pParaList, (double) p1 ) ;	
	
	ring_vm_runcode(this->pVM,this->ctabCloseRequestedEvent);
}

