
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gcalendarwidget.h"

GCalendarWidget::GCalendarWidget(QWidget *parent,VM *pVM)  : QCalendarWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cactivatedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->ccurrentPageChangedEvent,"");
	strcpy(this->cselectionChangedEvent,"");

	QObject::connect(this, SIGNAL(activated(const QDate)),this, SLOT(activatedSlot()));
	QObject::connect(this, SIGNAL(clicked(const QDate)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(currentPageChanged(int,int)),this, SLOT(currentPageChangedSlot()));
	QObject::connect(this, SIGNAL(selectionChanged()),this, SLOT(selectionChangedSlot()));

}

GCalendarWidget::~GCalendarWidget()
{
	ring_list_delete(this->pParaList);
}

void GCalendarWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GCalendarWidget::setactivatedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cactivatedEvent,cStr);
}

void GCalendarWidget::setclickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cclickedEvent,cStr);
}

void GCalendarWidget::setcurrentPageChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccurrentPageChangedEvent,cStr);
}

void GCalendarWidget::setselectionChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cselectionChangedEvent,cStr);
}

 
const char *GCalendarWidget::getactivatedEvent(void)
{
	return this->cactivatedEvent;
}

const char *GCalendarWidget::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GCalendarWidget::getcurrentPageChangedEvent(void)
{
	return this->ccurrentPageChangedEvent;
}

const char *GCalendarWidget::getselectionChangedEvent(void)
{
	return this->cselectionChangedEvent;
}


void GCalendarWidget::activatedSlot()
{
	if (strcmp(this->cactivatedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cactivatedEvent);
}

void GCalendarWidget::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GCalendarWidget::currentPageChangedSlot()
{
	if (strcmp(this->ccurrentPageChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentPageChangedEvent);
}

void GCalendarWidget::selectionChangedSlot()
{
	if (strcmp(this->cselectionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cselectionChangedEvent);
}

