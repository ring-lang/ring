
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "glistwidget.h"

GListWidget::GListWidget(QWidget *parent,VM *pVM)  : QListWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccurrentItemChangedEvent,"");
	strcpy(this->ccurrentRowChangedEvent,"");
	strcpy(this->ccurrentTextChangedEvent,"");
	strcpy(this->citemActivatedEvent,"");
	strcpy(this->citemChangedEvent,"");
	strcpy(this->citemClickedEvent,"");
	strcpy(this->citemDoubleClickedEvent,"");
	strcpy(this->citemEnteredEvent,"");
	strcpy(this->citemPressedEvent,"");
	strcpy(this->citemSelectionChangedEvent,"");

	QObject::connect(this, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this, SLOT(currentItemChangedSlot()));
	QObject::connect(this, SIGNAL(currentRowChanged(int)),this, SLOT(currentRowChangedSlot()));
	QObject::connect(this, SIGNAL(currentTextChanged(QString)),this, SLOT(currentTextChangedSlot()));
	QObject::connect(this, SIGNAL(itemActivated(QListWidgetItem*)),this, SLOT(itemActivatedSlot()));
	QObject::connect(this, SIGNAL(itemChanged(QListWidgetItem*)),this, SLOT(itemChangedSlot()));
	QObject::connect(this, SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT(itemClickedSlot()));
	QObject::connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem*)),this, SLOT(itemDoubleClickedSlot()));
	QObject::connect(this, SIGNAL(itemEntered(QListWidgetItem*)),this, SLOT(itemEnteredSlot()));
	QObject::connect(this, SIGNAL(itemPressed(QListWidgetItem*)),this, SLOT(itemPressedSlot()));
	QObject::connect(this, SIGNAL(itemSelectionChanged()),this, SLOT(itemSelectionChangedSlot()));

}

GListWidget::~GListWidget()
{
	ring_list_delete(this->pParaList);
}

void GListWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GListWidget::setcurrentItemChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentItemChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GListWidget::setcurrentRowChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentRowChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GListWidget::setcurrentTextChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentTextChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GListWidget::setitemActivatedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemActivatedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GListWidget::setitemChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GListWidget::setitemClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GListWidget::setitemDoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemDoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GListWidget::setitemEnteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemEnteredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GListWidget::setitemPressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemPressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GListWidget::setitemSelectionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemSelectionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GListWidget::getcurrentItemChangedEvent(void)
{
	return this->ccurrentItemChangedEvent;
}

const char *GListWidget::getcurrentRowChangedEvent(void)
{
	return this->ccurrentRowChangedEvent;
}

const char *GListWidget::getcurrentTextChangedEvent(void)
{
	return this->ccurrentTextChangedEvent;
}

const char *GListWidget::getitemActivatedEvent(void)
{
	return this->citemActivatedEvent;
}

const char *GListWidget::getitemChangedEvent(void)
{
	return this->citemChangedEvent;
}

const char *GListWidget::getitemClickedEvent(void)
{
	return this->citemClickedEvent;
}

const char *GListWidget::getitemDoubleClickedEvent(void)
{
	return this->citemDoubleClickedEvent;
}

const char *GListWidget::getitemEnteredEvent(void)
{
	return this->citemEnteredEvent;
}

const char *GListWidget::getitemPressedEvent(void)
{
	return this->citemPressedEvent;
}

const char *GListWidget::getitemSelectionChangedEvent(void)
{
	return this->citemSelectionChangedEvent;
}


void GListWidget::currentItemChangedSlot()
{
	if (strcmp(this->ccurrentItemChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentItemChangedEvent);
}

void GListWidget::currentRowChangedSlot()
{
	if (strcmp(this->ccurrentRowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentRowChangedEvent);
}

void GListWidget::currentTextChangedSlot()
{
	if (strcmp(this->ccurrentTextChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentTextChangedEvent);
}

void GListWidget::itemActivatedSlot()
{
	if (strcmp(this->citemActivatedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemActivatedEvent);
}

void GListWidget::itemChangedSlot()
{
	if (strcmp(this->citemChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemChangedEvent);
}

void GListWidget::itemClickedSlot()
{
	if (strcmp(this->citemClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemClickedEvent);
}

void GListWidget::itemDoubleClickedSlot()
{
	if (strcmp(this->citemDoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemDoubleClickedEvent);
}

void GListWidget::itemEnteredSlot()
{
	if (strcmp(this->citemEnteredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemEnteredEvent);
}

void GListWidget::itemPressedSlot()
{
	if (strcmp(this->citemPressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemPressedEvent);
}

void GListWidget::itemSelectionChangedSlot()
{
	if (strcmp(this->citemSelectionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemSelectionChangedEvent);
}

