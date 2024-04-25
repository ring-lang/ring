
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gcandlestickseries.h"

GCandlestickSeries::GCandlestickSeries(QObject *parent,VM *pVM)  : QtCharts::QCandlestickSeries(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cbodyOutlineVisibilityChangedEvent,"");
	strcpy(this->cbodyWidthChangedEvent,"");
	strcpy(this->cbrushChangedEvent,"");
	strcpy(this->ccandlestickSetsAddedEvent,"");
	strcpy(this->ccandlestickSetsRemovedEvent,"");
	strcpy(this->ccapsVisibilityChangedEvent,"");
	strcpy(this->ccapsWidthChangedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->ccountChangedEvent,"");
	strcpy(this->cdecreasingColorChangedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->choveredEvent,"");
	strcpy(this->cincreasingColorChangedEvent,"");
	strcpy(this->cmaximumColumnWidthChangedEvent,"");
	strcpy(this->cminimumColumnWidthChangedEvent,"");
	strcpy(this->cpenChangedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");

	QObject::connect(this, SIGNAL(bodyOutlineVisibilityChanged()),this, SLOT(bodyOutlineVisibilityChangedSlot()));
	QObject::connect(this, SIGNAL(bodyWidthChanged()),this, SLOT(bodyWidthChangedSlot()));
	QObject::connect(this, SIGNAL(brushChanged()),this, SLOT(brushChangedSlot()));
	QObject::connect(this, SIGNAL(candlestickSetsAdded(const QList<QCandlestickSet *>)),this, SLOT(candlestickSetsAddedSlot()));
	QObject::connect(this, SIGNAL(candlestickSetsRemoved(const QList<QCandlestickSet *>)),this, SLOT(candlestickSetsRemovedSlot()));
	QObject::connect(this, SIGNAL(capsVisibilityChanged()),this, SLOT(capsVisibilityChangedSlot()));
	QObject::connect(this, SIGNAL(capsWidthChanged()),this, SLOT(capsWidthChangedSlot()));
	QObject::connect(this, SIGNAL(clicked(QCandlestickSet *)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(countChanged()),this, SLOT(countChangedSlot()));
	QObject::connect(this, SIGNAL(decreasingColorChanged()),this, SLOT(decreasingColorChangedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked(QCandlestickSet *)),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(hovered(bool,QCandlestickSet *)),this, SLOT(hoveredSlot()));
	QObject::connect(this, SIGNAL(increasingColorChanged()),this, SLOT(increasingColorChangedSlot()));
	QObject::connect(this, SIGNAL(maximumColumnWidthChanged()),this, SLOT(maximumColumnWidthChangedSlot()));
	QObject::connect(this, SIGNAL(minimumColumnWidthChanged()),this, SLOT(minimumColumnWidthChangedSlot()));
	QObject::connect(this, SIGNAL(penChanged()),this, SLOT(penChangedSlot()));
	QObject::connect(this, SIGNAL(pressed(QCandlestickSet *)),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released(QCandlestickSet *)),this, SLOT(releasedSlot()));

}

GCandlestickSeries::~GCandlestickSeries()
{
	ring_list_delete(this->pParaList);
}

void GCandlestickSeries::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GCandlestickSeries::setbodyOutlineVisibilityChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbodyOutlineVisibilityChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setbodyWidthChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbodyWidthChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setbrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setcandlestickSetsAddedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccandlestickSetsAddedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setcandlestickSetsRemovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccandlestickSetsRemovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setcapsVisibilityChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccapsVisibilityChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setcapsWidthChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccapsWidthChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setcountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setdecreasingColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdecreasingColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setdoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::sethoveredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->choveredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setincreasingColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cincreasingColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setmaximumColumnWidthChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmaximumColumnWidthChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setminimumColumnWidthChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cminimumColumnWidthChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setpenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCandlestickSeries::setreleasedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creleasedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GCandlestickSeries::getbodyOutlineVisibilityChangedEvent(void)
{
	return this->cbodyOutlineVisibilityChangedEvent;
}

const char *GCandlestickSeries::getbodyWidthChangedEvent(void)
{
	return this->cbodyWidthChangedEvent;
}

const char *GCandlestickSeries::getbrushChangedEvent(void)
{
	return this->cbrushChangedEvent;
}

const char *GCandlestickSeries::getcandlestickSetsAddedEvent(void)
{
	return this->ccandlestickSetsAddedEvent;
}

const char *GCandlestickSeries::getcandlestickSetsRemovedEvent(void)
{
	return this->ccandlestickSetsRemovedEvent;
}

const char *GCandlestickSeries::getcapsVisibilityChangedEvent(void)
{
	return this->ccapsVisibilityChangedEvent;
}

const char *GCandlestickSeries::getcapsWidthChangedEvent(void)
{
	return this->ccapsWidthChangedEvent;
}

const char *GCandlestickSeries::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GCandlestickSeries::getcountChangedEvent(void)
{
	return this->ccountChangedEvent;
}

const char *GCandlestickSeries::getdecreasingColorChangedEvent(void)
{
	return this->cdecreasingColorChangedEvent;
}

const char *GCandlestickSeries::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GCandlestickSeries::gethoveredEvent(void)
{
	return this->choveredEvent;
}

const char *GCandlestickSeries::getincreasingColorChangedEvent(void)
{
	return this->cincreasingColorChangedEvent;
}

const char *GCandlestickSeries::getmaximumColumnWidthChangedEvent(void)
{
	return this->cmaximumColumnWidthChangedEvent;
}

const char *GCandlestickSeries::getminimumColumnWidthChangedEvent(void)
{
	return this->cminimumColumnWidthChangedEvent;
}

const char *GCandlestickSeries::getpenChangedEvent(void)
{
	return this->cpenChangedEvent;
}

const char *GCandlestickSeries::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GCandlestickSeries::getreleasedEvent(void)
{
	return this->creleasedEvent;
}


void GCandlestickSeries::bodyOutlineVisibilityChangedSlot()
{
	if (strcmp(this->cbodyOutlineVisibilityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbodyOutlineVisibilityChangedEvent);
}

void GCandlestickSeries::bodyWidthChangedSlot()
{
	if (strcmp(this->cbodyWidthChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbodyWidthChangedEvent);
}

void GCandlestickSeries::brushChangedSlot()
{
	if (strcmp(this->cbrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbrushChangedEvent);
}

void GCandlestickSeries::candlestickSetsAddedSlot()
{
	if (strcmp(this->ccandlestickSetsAddedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccandlestickSetsAddedEvent);
}

void GCandlestickSeries::candlestickSetsRemovedSlot()
{
	if (strcmp(this->ccandlestickSetsRemovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccandlestickSetsRemovedEvent);
}

void GCandlestickSeries::capsVisibilityChangedSlot()
{
	if (strcmp(this->ccapsVisibilityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccapsVisibilityChangedEvent);
}

void GCandlestickSeries::capsWidthChangedSlot()
{
	if (strcmp(this->ccapsWidthChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccapsWidthChangedEvent);
}

void GCandlestickSeries::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GCandlestickSeries::countChangedSlot()
{
	if (strcmp(this->ccountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccountChangedEvent);
}

void GCandlestickSeries::decreasingColorChangedSlot()
{
	if (strcmp(this->cdecreasingColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdecreasingColorChangedEvent);
}

void GCandlestickSeries::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GCandlestickSeries::hoveredSlot()
{
	if (strcmp(this->choveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choveredEvent);
}

void GCandlestickSeries::increasingColorChangedSlot()
{
	if (strcmp(this->cincreasingColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cincreasingColorChangedEvent);
}

void GCandlestickSeries::maximumColumnWidthChangedSlot()
{
	if (strcmp(this->cmaximumColumnWidthChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmaximumColumnWidthChangedEvent);
}

void GCandlestickSeries::minimumColumnWidthChangedSlot()
{
	if (strcmp(this->cminimumColumnWidthChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminimumColumnWidthChangedEvent);
}

void GCandlestickSeries::penChangedSlot()
{
	if (strcmp(this->cpenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpenChangedEvent);
}

void GCandlestickSeries::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GCandlestickSeries::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

