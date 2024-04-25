
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gscatterseries.h"

GScatterSeries::GScatterSeries(QObject * parent,VM *pVM)  : QtCharts::QScatterSeries(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cborderColorChangedEvent,"");
	strcpy(this->ccolorChangedEvent,"");
	strcpy(this->cmarkerShapeChangedEvent,"");
	strcpy(this->cmarkerSizeChangedEvent,"");

	QObject::connect(this, SIGNAL(borderColorChanged(QColor)),this, SLOT(borderColorChangedSlot()));
	QObject::connect(this, SIGNAL(colorChanged(QColor)),this, SLOT(colorChangedSlot()));
	QObject::connect(this, SIGNAL(markerShapeChanged(QScatterSeries::MarkerShape)),this, SLOT(markerShapeChangedSlot()));
	QObject::connect(this, SIGNAL(markerSizeChanged(qreal)),this, SLOT(markerSizeChangedSlot()));

}

GScatterSeries::~GScatterSeries()
{
	ring_list_delete(this->pParaList);
}

void GScatterSeries::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GScatterSeries::setborderColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cborderColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GScatterSeries::setcolorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccolorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GScatterSeries::setmarkerShapeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmarkerShapeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GScatterSeries::setmarkerSizeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmarkerSizeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GScatterSeries::getborderColorChangedEvent(void)
{
	return this->cborderColorChangedEvent;
}

const char *GScatterSeries::getcolorChangedEvent(void)
{
	return this->ccolorChangedEvent;
}

const char *GScatterSeries::getmarkerShapeChangedEvent(void)
{
	return this->cmarkerShapeChangedEvent;
}

const char *GScatterSeries::getmarkerSizeChangedEvent(void)
{
	return this->cmarkerSizeChangedEvent;
}


void GScatterSeries::borderColorChangedSlot()
{
	if (strcmp(this->cborderColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cborderColorChangedEvent);
}

void GScatterSeries::colorChangedSlot()
{
	if (strcmp(this->ccolorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccolorChangedEvent);
}

void GScatterSeries::markerShapeChangedSlot()
{
	if (strcmp(this->cmarkerShapeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmarkerShapeChangedEvent);
}

void GScatterSeries::markerSizeChangedSlot()
{
	if (strcmp(this->cmarkerSizeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmarkerSizeChangedEvent);
}

