
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gareaseries.h"

GAreaSeries::GAreaSeries(QObject *parent,VM *pVM)  : QtCharts::QAreaSeries(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cborderColorChangedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->ccolorChangedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->choveredEvent,"");
	strcpy(this->cpointLabelsClippingChangedEvent,"");
	strcpy(this->cpointLabelsColorChangedEvent,"");
	strcpy(this->cpointLabelsFontChangedEvent,"");
	strcpy(this->cpointLabelsFormatChangedEvent,"");
	strcpy(this->cpointLabelsVisibilityChangedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");

	QObject::connect(this, SIGNAL(borderColorChanged(QColor)),this, SLOT(borderColorChangedSlot()));
	QObject::connect(this, SIGNAL(clicked(const QPointF)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(colorChanged(QColor)),this, SLOT(colorChangedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked(const QPointF)),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(hovered(const QPointF,bool)),this, SLOT(hoveredSlot()));
	QObject::connect(this, SIGNAL(pointLabelsClippingChanged(bool)),this, SLOT(pointLabelsClippingChangedSlot()));
	QObject::connect(this, SIGNAL(pointLabelsColorChanged(const QColor)),this, SLOT(pointLabelsColorChangedSlot()));
	QObject::connect(this, SIGNAL(pointLabelsFontChanged(const QFont)),this, SLOT(pointLabelsFontChangedSlot()));
	QObject::connect(this, SIGNAL(pointLabelsFormatChanged(const QString)),this, SLOT(pointLabelsFormatChangedSlot()));
	QObject::connect(this, SIGNAL(pointLabelsVisibilityChanged(bool)),this, SLOT(pointLabelsVisibilityChangedSlot()));
	QObject::connect(this, SIGNAL(pressed(const QPointF)),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released(const QPointF)),this, SLOT(releasedSlot()));

}

GAreaSeries::~GAreaSeries()
{
	ring_list_delete(this->pParaList);
}

void GAreaSeries::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GAreaSeries::setborderColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cborderColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAreaSeries::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAreaSeries::setcolorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccolorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAreaSeries::setdoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAreaSeries::sethoveredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->choveredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAreaSeries::setpointLabelsClippingChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpointLabelsClippingChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAreaSeries::setpointLabelsColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpointLabelsColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAreaSeries::setpointLabelsFontChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpointLabelsFontChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAreaSeries::setpointLabelsFormatChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpointLabelsFormatChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAreaSeries::setpointLabelsVisibilityChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpointLabelsVisibilityChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAreaSeries::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAreaSeries::setreleasedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creleasedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GAreaSeries::getborderColorChangedEvent(void)
{
	return this->cborderColorChangedEvent;
}

const char *GAreaSeries::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GAreaSeries::getcolorChangedEvent(void)
{
	return this->ccolorChangedEvent;
}

const char *GAreaSeries::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GAreaSeries::gethoveredEvent(void)
{
	return this->choveredEvent;
}

const char *GAreaSeries::getpointLabelsClippingChangedEvent(void)
{
	return this->cpointLabelsClippingChangedEvent;
}

const char *GAreaSeries::getpointLabelsColorChangedEvent(void)
{
	return this->cpointLabelsColorChangedEvent;
}

const char *GAreaSeries::getpointLabelsFontChangedEvent(void)
{
	return this->cpointLabelsFontChangedEvent;
}

const char *GAreaSeries::getpointLabelsFormatChangedEvent(void)
{
	return this->cpointLabelsFormatChangedEvent;
}

const char *GAreaSeries::getpointLabelsVisibilityChangedEvent(void)
{
	return this->cpointLabelsVisibilityChangedEvent;
}

const char *GAreaSeries::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GAreaSeries::getreleasedEvent(void)
{
	return this->creleasedEvent;
}


void GAreaSeries::borderColorChangedSlot()
{
	if (strcmp(this->cborderColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cborderColorChangedEvent);
}

void GAreaSeries::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GAreaSeries::colorChangedSlot()
{
	if (strcmp(this->ccolorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccolorChangedEvent);
}

void GAreaSeries::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GAreaSeries::hoveredSlot()
{
	if (strcmp(this->choveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choveredEvent);
}

void GAreaSeries::pointLabelsClippingChangedSlot()
{
	if (strcmp(this->cpointLabelsClippingChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointLabelsClippingChangedEvent);
}

void GAreaSeries::pointLabelsColorChangedSlot()
{
	if (strcmp(this->cpointLabelsColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointLabelsColorChangedEvent);
}

void GAreaSeries::pointLabelsFontChangedSlot()
{
	if (strcmp(this->cpointLabelsFontChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointLabelsFontChangedEvent);
}

void GAreaSeries::pointLabelsFormatChangedSlot()
{
	if (strcmp(this->cpointLabelsFormatChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointLabelsFormatChangedEvent);
}

void GAreaSeries::pointLabelsVisibilityChangedSlot()
{
	if (strcmp(this->cpointLabelsVisibilityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointLabelsVisibilityChangedEvent);
}

void GAreaSeries::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GAreaSeries::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

