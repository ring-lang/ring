
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gabstractbarseries.h"

GAbstractBarSeries::GAbstractBarSeries(QtCharts::QAbstractBarSeriesPrivate &parent,VM *pVM)  : QtCharts::QAbstractBarSeries(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cbarsetsAddedEvent,"");
	strcpy(this->cbarsetsRemovedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->ccountChangedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->choveredEvent,"");
	strcpy(this->clabelsAngleChangedEvent,"");
	strcpy(this->clabelsFormatChangedEvent,"");
	strcpy(this->clabelsPositionChangedEvent,"");
	strcpy(this->clabelsPrecisionChangedEvent,"");
	strcpy(this->clabelsVisibleChangedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");

	QObject::connect(this, SIGNAL(barsetsAdded(QList<QBarSet *>)),this, SLOT(barsetsAddedSlot()));
	QObject::connect(this, SIGNAL(barsetsRemoved(QList<QBarSet *>)),this, SLOT(barsetsRemovedSlot()));
	QObject::connect(this, SIGNAL(clicked(int,QBarSet *)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(countChanged()),this, SLOT(countChangedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked(int,QBarSet *)),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(hovered(bool,int,QBarSet *)),this, SLOT(hoveredSlot()));
	QObject::connect(this, SIGNAL(labelsAngleChanged(qreal)),this, SLOT(labelsAngleChangedSlot()));
	QObject::connect(this, SIGNAL(labelsFormatChanged(const QString)),this, SLOT(labelsFormatChangedSlot()));
	QObject::connect(this, SIGNAL(labelsPositionChanged(QAbstractBarSeries::LabelsPosition)),this, SLOT(labelsPositionChangedSlot()));
	QObject::connect(this, SIGNAL(labelsPrecisionChanged(int)),this, SLOT(labelsPrecisionChangedSlot()));
	QObject::connect(this, SIGNAL(labelsVisibleChanged()),this, SLOT(labelsVisibleChangedSlot()));
	QObject::connect(this, SIGNAL(pressed(int,QBarSet *)),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released(int,QBarSet *)),this, SLOT(releasedSlot()));

}

GAbstractBarSeries::~GAbstractBarSeries()
{
	ring_list_delete(this->pParaList);
}

void GAbstractBarSeries::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GAbstractBarSeries::setbarsetsAddedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbarsetsAddedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::setbarsetsRemovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbarsetsRemovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::setcountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::setdoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::sethoveredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->choveredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::setlabelsAngleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsAngleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::setlabelsFormatChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsFormatChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::setlabelsPositionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsPositionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::setlabelsPrecisionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsPrecisionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::setlabelsVisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsVisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractBarSeries::setreleasedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creleasedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GAbstractBarSeries::getbarsetsAddedEvent(void)
{
	return this->cbarsetsAddedEvent;
}

const char *GAbstractBarSeries::getbarsetsRemovedEvent(void)
{
	return this->cbarsetsRemovedEvent;
}

const char *GAbstractBarSeries::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GAbstractBarSeries::getcountChangedEvent(void)
{
	return this->ccountChangedEvent;
}

const char *GAbstractBarSeries::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GAbstractBarSeries::gethoveredEvent(void)
{
	return this->choveredEvent;
}

const char *GAbstractBarSeries::getlabelsAngleChangedEvent(void)
{
	return this->clabelsAngleChangedEvent;
}

const char *GAbstractBarSeries::getlabelsFormatChangedEvent(void)
{
	return this->clabelsFormatChangedEvent;
}

const char *GAbstractBarSeries::getlabelsPositionChangedEvent(void)
{
	return this->clabelsPositionChangedEvent;
}

const char *GAbstractBarSeries::getlabelsPrecisionChangedEvent(void)
{
	return this->clabelsPrecisionChangedEvent;
}

const char *GAbstractBarSeries::getlabelsVisibleChangedEvent(void)
{
	return this->clabelsVisibleChangedEvent;
}

const char *GAbstractBarSeries::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GAbstractBarSeries::getreleasedEvent(void)
{
	return this->creleasedEvent;
}


void GAbstractBarSeries::barsetsAddedSlot()
{
	if (strcmp(this->cbarsetsAddedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbarsetsAddedEvent);
}

void GAbstractBarSeries::barsetsRemovedSlot()
{
	if (strcmp(this->cbarsetsRemovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbarsetsRemovedEvent);
}

void GAbstractBarSeries::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GAbstractBarSeries::countChangedSlot()
{
	if (strcmp(this->ccountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccountChangedEvent);
}

void GAbstractBarSeries::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GAbstractBarSeries::hoveredSlot()
{
	if (strcmp(this->choveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choveredEvent);
}

void GAbstractBarSeries::labelsAngleChangedSlot()
{
	if (strcmp(this->clabelsAngleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsAngleChangedEvent);
}

void GAbstractBarSeries::labelsFormatChangedSlot()
{
	if (strcmp(this->clabelsFormatChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsFormatChangedEvent);
}

void GAbstractBarSeries::labelsPositionChangedSlot()
{
	if (strcmp(this->clabelsPositionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsPositionChangedEvent);
}

void GAbstractBarSeries::labelsPrecisionChangedSlot()
{
	if (strcmp(this->clabelsPrecisionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsPrecisionChangedEvent);
}

void GAbstractBarSeries::labelsVisibleChangedSlot()
{
	if (strcmp(this->clabelsVisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsVisibleChangedEvent);
}

void GAbstractBarSeries::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GAbstractBarSeries::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

