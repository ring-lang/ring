
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtablewidget.h"

GTableWidget::GTableWidget(QWidget *parent,VM *pVM)  : QTableWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccellActivatedEvent,"");
	strcpy(this->ccellChangedEvent,"");
	strcpy(this->ccellClickedEvent,"");
	strcpy(this->ccellDoubleClickedEvent,"");
	strcpy(this->ccellEnteredEvent,"");
	strcpy(this->ccellPressedEvent,"");
	strcpy(this->ccurrentCellChangedEvent,"");
	strcpy(this->ccurrentItemChangedEvent,"");
	strcpy(this->citemActivatedEvent,"");
	strcpy(this->citemChangedEvent,"");
	strcpy(this->citemClickedEvent,"");
	strcpy(this->citemDoubleClickedEvent,"");
	strcpy(this->citemEnteredEvent,"");
	strcpy(this->citemPressedEvent,"");
	strcpy(this->citemSelectionChangedEvent,"");

	QObject::connect(this, SIGNAL(cellActivated(int,int)),this, SLOT(cellActivatedSlot()));
	QObject::connect(this, SIGNAL(cellChanged(int,int)),this, SLOT(cellChangedSlot()));
	QObject::connect(this, SIGNAL(cellClicked(int,int)),this, SLOT(cellClickedSlot()));
	QObject::connect(this, SIGNAL(cellDoubleClicked(int,int)),this, SLOT(cellDoubleClickedSlot()));
	QObject::connect(this, SIGNAL(cellEntered(int,int)),this, SLOT(cellEnteredSlot()));
	QObject::connect(this, SIGNAL(cellPressed(int,int)),this, SLOT(cellPressedSlot()));
	QObject::connect(this, SIGNAL(currentCellChanged(int,int,int,int)),this, SLOT(currentCellChangedSlot()));
	QObject::connect(this, SIGNAL(currentItemChanged(QTableWidgetItem *,QTableWidgetItem *)),this, SLOT(currentItemChangedSlot()));
	QObject::connect(this, SIGNAL(itemActivated(QTableWidgetItem *)),this, SLOT(itemActivatedSlot()));
	QObject::connect(this, SIGNAL(itemChanged(QTableWidgetItem *)),this, SLOT(itemChangedSlot()));
	QObject::connect(this, SIGNAL(itemClicked(QTableWidgetItem *)),this, SLOT(itemClickedSlot()));
	QObject::connect(this, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),this, SLOT(itemDoubleClickedSlot()));
	QObject::connect(this, SIGNAL(itemEntered(QTableWidgetItem *)),this, SLOT(itemEnteredSlot()));
	QObject::connect(this, SIGNAL(itemPressed(QTableWidgetItem *)),this, SLOT(itemPressedSlot()));
	QObject::connect(this, SIGNAL(itemSelectionChanged()),this, SLOT(itemSelectionChangedSlot()));

}

GTableWidget::~GTableWidget()
{
	ring_list_delete(this->pParaList);
}

void GTableWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GTableWidget::setcellActivatedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccellActivatedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setcellChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccellChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setcellClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccellClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setcellDoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccellDoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setcellEnteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccellEnteredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setcellPressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccellPressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setcurrentCellChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentCellChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setcurrentItemChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentItemChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setitemActivatedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemActivatedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setitemChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setitemClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setitemDoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemDoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setitemEnteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemEnteredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setitemPressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemPressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTableWidget::setitemSelectionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemSelectionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GTableWidget::getcellActivatedEvent(void)
{
	return this->ccellActivatedEvent;
}

const char *GTableWidget::getcellChangedEvent(void)
{
	return this->ccellChangedEvent;
}

const char *GTableWidget::getcellClickedEvent(void)
{
	return this->ccellClickedEvent;
}

const char *GTableWidget::getcellDoubleClickedEvent(void)
{
	return this->ccellDoubleClickedEvent;
}

const char *GTableWidget::getcellEnteredEvent(void)
{
	return this->ccellEnteredEvent;
}

const char *GTableWidget::getcellPressedEvent(void)
{
	return this->ccellPressedEvent;
}

const char *GTableWidget::getcurrentCellChangedEvent(void)
{
	return this->ccurrentCellChangedEvent;
}

const char *GTableWidget::getcurrentItemChangedEvent(void)
{
	return this->ccurrentItemChangedEvent;
}

const char *GTableWidget::getitemActivatedEvent(void)
{
	return this->citemActivatedEvent;
}

const char *GTableWidget::getitemChangedEvent(void)
{
	return this->citemChangedEvent;
}

const char *GTableWidget::getitemClickedEvent(void)
{
	return this->citemClickedEvent;
}

const char *GTableWidget::getitemDoubleClickedEvent(void)
{
	return this->citemDoubleClickedEvent;
}

const char *GTableWidget::getitemEnteredEvent(void)
{
	return this->citemEnteredEvent;
}

const char *GTableWidget::getitemPressedEvent(void)
{
	return this->citemPressedEvent;
}

const char *GTableWidget::getitemSelectionChangedEvent(void)
{
	return this->citemSelectionChangedEvent;
}


void GTableWidget::cellActivatedSlot()
{
	if (strcmp(this->ccellActivatedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccellActivatedEvent);
}

void GTableWidget::cellChangedSlot()
{
	if (strcmp(this->ccellChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccellChangedEvent);
}

void GTableWidget::cellClickedSlot()
{
	if (strcmp(this->ccellClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccellClickedEvent);
}

void GTableWidget::cellDoubleClickedSlot()
{
	if (strcmp(this->ccellDoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccellDoubleClickedEvent);
}

void GTableWidget::cellEnteredSlot()
{
	if (strcmp(this->ccellEnteredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccellEnteredEvent);
}

void GTableWidget::cellPressedSlot()
{
	if (strcmp(this->ccellPressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccellPressedEvent);
}

void GTableWidget::currentCellChangedSlot()
{
	if (strcmp(this->ccurrentCellChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentCellChangedEvent);
}

void GTableWidget::currentItemChangedSlot()
{
	if (strcmp(this->ccurrentItemChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentItemChangedEvent);
}

void GTableWidget::itemActivatedSlot()
{
	if (strcmp(this->citemActivatedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemActivatedEvent);
}

void GTableWidget::itemChangedSlot()
{
	if (strcmp(this->citemChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemChangedEvent);
}

void GTableWidget::itemClickedSlot()
{
	if (strcmp(this->citemClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemClickedEvent);
}

void GTableWidget::itemDoubleClickedSlot()
{
	if (strcmp(this->citemDoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemDoubleClickedEvent);
}

void GTableWidget::itemEnteredSlot()
{
	if (strcmp(this->citemEnteredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemEnteredEvent);
}

void GTableWidget::itemPressedSlot()
{
	if (strcmp(this->citemPressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemPressedEvent);
}

void GTableWidget::itemSelectionChangedSlot()
{
	if (strcmp(this->citemSelectionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->citemSelectionChangedEvent);
}

