
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gpieseries.h"

GPieSeries::GPieSeries(QObject * parent,VM *pVM)  : QtCharts::QPieSeries(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->caddedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->ccountChangedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->choveredEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");
	strcpy(this->cremovedEvent,"");
	strcpy(this->csumChangedEvent,"");

	QObject::connect(this, SIGNAL(added(QList<QPieSlice *>)),this, SLOT(addedSlot()));
	QObject::connect(this, SIGNAL(clicked(QPieSlice *)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(countChanged()),this, SLOT(countChangedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked(QPieSlice *)),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(hovered(QPieSlice *,bool)),this, SLOT(hoveredSlot()));
	QObject::connect(this, SIGNAL(pressed(QPieSlice *)),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released(QPieSlice *)),this, SLOT(releasedSlot()));
	QObject::connect(this, SIGNAL(removed(QList<QPieSlice *>)),this, SLOT(removedSlot()));
	QObject::connect(this, SIGNAL(sumChanged()),this, SLOT(sumChangedSlot()));

}

GPieSeries::~GPieSeries()
{
	ring_list_delete(this->pParaList);
}

void GPieSeries::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GPieSeries::setaddedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->caddedEvent,cStr);
}

void GPieSeries::setclickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cclickedEvent,cStr);
}

void GPieSeries::setcountChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccountChangedEvent,cStr);
}

void GPieSeries::setdoubleClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cdoubleClickedEvent,cStr);
}

void GPieSeries::sethoveredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->choveredEvent,cStr);
}

void GPieSeries::setpressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpressedEvent,cStr);
}

void GPieSeries::setreleasedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->creleasedEvent,cStr);
}

void GPieSeries::setremovedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cremovedEvent,cStr);
}

void GPieSeries::setsumChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csumChangedEvent,cStr);
}

 
const char *GPieSeries::getaddedEvent(void)
{
	return this->caddedEvent;
}

const char *GPieSeries::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GPieSeries::getcountChangedEvent(void)
{
	return this->ccountChangedEvent;
}

const char *GPieSeries::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GPieSeries::gethoveredEvent(void)
{
	return this->choveredEvent;
}

const char *GPieSeries::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GPieSeries::getreleasedEvent(void)
{
	return this->creleasedEvent;
}

const char *GPieSeries::getremovedEvent(void)
{
	return this->cremovedEvent;
}

const char *GPieSeries::getsumChangedEvent(void)
{
	return this->csumChangedEvent;
}


void GPieSeries::addedSlot()
{
	if (strcmp(this->caddedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->caddedEvent);
}

void GPieSeries::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GPieSeries::countChangedSlot()
{
	if (strcmp(this->ccountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccountChangedEvent);
}

void GPieSeries::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GPieSeries::hoveredSlot()
{
	if (strcmp(this->choveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choveredEvent);
}

void GPieSeries::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GPieSeries::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

void GPieSeries::removedSlot()
{
	if (strcmp(this->cremovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cremovedEvent);
}

void GPieSeries::sumChangedSlot()
{
	if (strcmp(this->csumChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csumChangedEvent);
}

