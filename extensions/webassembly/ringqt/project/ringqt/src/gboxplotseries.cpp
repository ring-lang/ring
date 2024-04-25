
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gboxplotseries.h"

GBoxPlotSeries::GBoxPlotSeries(QObject *parent,VM *pVM)  : QtCharts::QBoxPlotSeries(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cboxOutlineVisibilityChangedEvent,"");
	strcpy(this->cboxWidthChangedEvent,"");
	strcpy(this->cboxsetsAddedEvent,"");
	strcpy(this->cboxsetsRemovedEvent,"");
	strcpy(this->cbrushChangedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->ccountChangedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->choveredEvent,"");
	strcpy(this->cpenChangedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");

	QObject::connect(this, SIGNAL(boxOutlineVisibilityChanged()),this, SLOT(boxOutlineVisibilityChangedSlot()));
	QObject::connect(this, SIGNAL(boxWidthChanged()),this, SLOT(boxWidthChangedSlot()));
	QObject::connect(this, SIGNAL(boxsetsAdded(QList<QBoxSet *>)),this, SLOT(boxsetsAddedSlot()));
	QObject::connect(this, SIGNAL(boxsetsRemoved(QList<QBoxSet *>)),this, SLOT(boxsetsRemovedSlot()));
	QObject::connect(this, SIGNAL(brushChanged()),this, SLOT(brushChangedSlot()));
	QObject::connect(this, SIGNAL(clicked(QBoxSet *)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(countChanged()),this, SLOT(countChangedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked(QBoxSet *)),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(hovered(bool,QBoxSet *)),this, SLOT(hoveredSlot()));
	QObject::connect(this, SIGNAL(penChanged()),this, SLOT(penChangedSlot()));
	QObject::connect(this, SIGNAL(pressed(QBoxSet *)),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released(QBoxSet *)),this, SLOT(releasedSlot()));

}

GBoxPlotSeries::~GBoxPlotSeries()
{
	ring_list_delete(this->pParaList);
}

void GBoxPlotSeries::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GBoxPlotSeries::setboxOutlineVisibilityChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cboxOutlineVisibilityChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBoxPlotSeries::setboxWidthChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cboxWidthChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBoxPlotSeries::setboxsetsAddedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cboxsetsAddedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBoxPlotSeries::setboxsetsRemovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cboxsetsRemovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBoxPlotSeries::setbrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBoxPlotSeries::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBoxPlotSeries::setcountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBoxPlotSeries::setdoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBoxPlotSeries::sethoveredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->choveredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBoxPlotSeries::setpenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBoxPlotSeries::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBoxPlotSeries::setreleasedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creleasedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GBoxPlotSeries::getboxOutlineVisibilityChangedEvent(void)
{
	return this->cboxOutlineVisibilityChangedEvent;
}

const char *GBoxPlotSeries::getboxWidthChangedEvent(void)
{
	return this->cboxWidthChangedEvent;
}

const char *GBoxPlotSeries::getboxsetsAddedEvent(void)
{
	return this->cboxsetsAddedEvent;
}

const char *GBoxPlotSeries::getboxsetsRemovedEvent(void)
{
	return this->cboxsetsRemovedEvent;
}

const char *GBoxPlotSeries::getbrushChangedEvent(void)
{
	return this->cbrushChangedEvent;
}

const char *GBoxPlotSeries::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GBoxPlotSeries::getcountChangedEvent(void)
{
	return this->ccountChangedEvent;
}

const char *GBoxPlotSeries::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GBoxPlotSeries::gethoveredEvent(void)
{
	return this->choveredEvent;
}

const char *GBoxPlotSeries::getpenChangedEvent(void)
{
	return this->cpenChangedEvent;
}

const char *GBoxPlotSeries::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GBoxPlotSeries::getreleasedEvent(void)
{
	return this->creleasedEvent;
}


void GBoxPlotSeries::boxOutlineVisibilityChangedSlot()
{
	if (strcmp(this->cboxOutlineVisibilityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cboxOutlineVisibilityChangedEvent);
}

void GBoxPlotSeries::boxWidthChangedSlot()
{
	if (strcmp(this->cboxWidthChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cboxWidthChangedEvent);
}

void GBoxPlotSeries::boxsetsAddedSlot()
{
	if (strcmp(this->cboxsetsAddedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cboxsetsAddedEvent);
}

void GBoxPlotSeries::boxsetsRemovedSlot()
{
	if (strcmp(this->cboxsetsRemovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cboxsetsRemovedEvent);
}

void GBoxPlotSeries::brushChangedSlot()
{
	if (strcmp(this->cbrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbrushChangedEvent);
}

void GBoxPlotSeries::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GBoxPlotSeries::countChangedSlot()
{
	if (strcmp(this->ccountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccountChangedEvent);
}

void GBoxPlotSeries::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GBoxPlotSeries::hoveredSlot()
{
	if (strcmp(this->choveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choveredEvent);
}

void GBoxPlotSeries::penChangedSlot()
{
	if (strcmp(this->cpenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpenChangedEvent);
}

void GBoxPlotSeries::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GBoxPlotSeries::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

