
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
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
	if (strlen(cStr)<100)
		strcpy(this->cborderColorChangedEvent,cStr);
}

void GScatterSeries::setcolorChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccolorChangedEvent,cStr);
}

void GScatterSeries::setmarkerShapeChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cmarkerShapeChangedEvent,cStr);
}

void GScatterSeries::setmarkerSizeChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cmarkerSizeChangedEvent,cStr);
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

