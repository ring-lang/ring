
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "glistwidget.h"

GListWidget::GListWidget(QWidget *parent,VM *pVM)  : QListWidget(parent)
{
	this->pVM = pVM;
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
 
void GListWidget::setcurrentItemChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccurrentItemChangedEvent,cStr);
}

void GListWidget::setcurrentRowChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccurrentRowChangedEvent,cStr);
}

void GListWidget::setcurrentTextChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccurrentTextChangedEvent,cStr);
}

void GListWidget::setitemActivatedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemActivatedEvent,cStr);
}

void GListWidget::setitemChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemChangedEvent,cStr);
}

void GListWidget::setitemClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemClickedEvent,cStr);
}

void GListWidget::setitemDoubleClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemDoubleClickedEvent,cStr);
}

void GListWidget::setitemEnteredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemEnteredEvent,cStr);
}

void GListWidget::setitemPressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemPressedEvent,cStr);
}

void GListWidget::setitemSelectionChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemSelectionChangedEvent,cStr);
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

