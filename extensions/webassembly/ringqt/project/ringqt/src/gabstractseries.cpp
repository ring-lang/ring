
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gabstractseries.h"

GAbstractSeries::GAbstractSeries(QtCharts::QAbstractSeriesPrivate &parent,VM *pVM)  : QtCharts::QAbstractSeries(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cnameChangedEvent,"");
	strcpy(this->copacityChangedEvent,"");
	strcpy(this->cuseOpenGLChangedEvent,"");
	strcpy(this->cvisibleChangedEvent,"");

	QObject::connect(this, SIGNAL(nameChanged()),this, SLOT(nameChangedSlot()));
	QObject::connect(this, SIGNAL(opacityChanged()),this, SLOT(opacityChangedSlot()));
	QObject::connect(this, SIGNAL(useOpenGLChanged()),this, SLOT(useOpenGLChangedSlot()));
	QObject::connect(this, SIGNAL(visibleChanged()),this, SLOT(visibleChangedSlot()));

}

GAbstractSeries::~GAbstractSeries()
{
	ring_list_delete(this->pParaList);
}

void GAbstractSeries::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GAbstractSeries::setnameChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cnameChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractSeries::setopacityChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->copacityChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractSeries::setuseOpenGLChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cuseOpenGLChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractSeries::setvisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GAbstractSeries::getnameChangedEvent(void)
{
	return this->cnameChangedEvent;
}

const char *GAbstractSeries::getopacityChangedEvent(void)
{
	return this->copacityChangedEvent;
}

const char *GAbstractSeries::getuseOpenGLChangedEvent(void)
{
	return this->cuseOpenGLChangedEvent;
}

const char *GAbstractSeries::getvisibleChangedEvent(void)
{
	return this->cvisibleChangedEvent;
}


void GAbstractSeries::nameChangedSlot()
{
	if (strcmp(this->cnameChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cnameChangedEvent);
}

void GAbstractSeries::opacityChangedSlot()
{
	if (strcmp(this->copacityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->copacityChangedEvent);
}

void GAbstractSeries::useOpenGLChangedSlot()
{
	if (strcmp(this->cuseOpenGLChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cuseOpenGLChangedEvent);
}

void GAbstractSeries::visibleChangedSlot()
{
	if (strcmp(this->cvisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvisibleChangedEvent);
}

