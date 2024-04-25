
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
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
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->caddedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSeries::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSeries::setcountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSeries::setdoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSeries::sethoveredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->choveredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSeries::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSeries::setreleasedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creleasedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSeries::setremovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cremovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSeries::setsumChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csumChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
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

