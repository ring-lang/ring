
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtabbar.h"

GTabBar::GTabBar(QWidget *parent,VM *pVM)  : QTabBar(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccurrentChangedEvent,"");
	strcpy(this->ctabCloseRequestedEvent,"");
	strcpy(this->ctabMovedEvent,"");

	QObject::connect(this, SIGNAL(currentChanged(int)),this, SLOT(currentChangedSlot()));
	QObject::connect(this, SIGNAL(tabCloseRequested(int)),this, SLOT(tabCloseRequestedSlot()));
	QObject::connect(this, SIGNAL(tabMoved(int,int)),this, SLOT(tabMovedSlot()));

}

GTabBar::~GTabBar()
{
	ring_list_delete(this->pParaList);
}

void GTabBar::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GTabBar::setcurrentChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTabBar::settabCloseRequestedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctabCloseRequestedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTabBar::settabMovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctabMovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GTabBar::getcurrentChangedEvent(void)
{
	return this->ccurrentChangedEvent;
}

const char *GTabBar::gettabCloseRequestedEvent(void)
{
	return this->ctabCloseRequestedEvent;
}

const char *GTabBar::gettabMovedEvent(void)
{
	return this->ctabMovedEvent;
}


void GTabBar::currentChangedSlot()
{
	if (strcmp(this->ccurrentChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentChangedEvent);
}

void GTabBar::tabCloseRequestedSlot()
{
	if (strcmp(this->ctabCloseRequestedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctabCloseRequestedEvent);
}

void GTabBar::tabMovedSlot()
{
	if (strcmp(this->ctabMovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctabMovedEvent);
}

