
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "ggeoareamonitorsource.h"

GGeoAreaMonitorSource::GGeoAreaMonitorSource(QObject *parent,VM *pVM)  : QGeoAreaMonitorSource(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cEvent,"");
	strcpy(this->cEvent,"");
	strcpy(this->cEvent,"");
	strcpy(this->cEvent,"");

	QObject::connect(this, SIGNAL((QGeoAreaMonitorInfo,const QGeoPositionInfo)),this, SLOT(Slot()));
	QObject::connect(this, SIGNAL((QGeoAreaMonitorInfo,const QGeoPositionInfo)),this, SLOT(Slot()));
	QObject::connect(this, SIGNAL((areaMonitoringError)),this, SLOT(Slot()));
	QObject::connect(this, SIGNAL((QGeoAreaMonitorInfo)),this, SLOT(Slot()));

}

GGeoAreaMonitorSource::~GGeoAreaMonitorSource()
{
	ring_list_delete(this->pParaList);
}

void GGeoAreaMonitorSource::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GGeoAreaMonitorSource::setEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cEvent,cStr);
}

void GGeoAreaMonitorSource::setEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cEvent,cStr);
}

void GGeoAreaMonitorSource::setEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cEvent,cStr);
}

void GGeoAreaMonitorSource::setEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cEvent,cStr);
}

 
const char *GGeoAreaMonitorSource::getEvent(void)
{
	return this->cEvent;
}

const char *GGeoAreaMonitorSource::getEvent(void)
{
	return this->cEvent;
}

const char *GGeoAreaMonitorSource::getEvent(void)
{
	return this->cEvent;
}

const char *GGeoAreaMonitorSource::getEvent(void)
{
	return this->cEvent;
}


void GGeoAreaMonitorSource::Slot()
{
	if (strcmp(this->cEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cEvent);
}

void GGeoAreaMonitorSource::Slot()
{
	if (strcmp(this->cEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cEvent);
}

void GGeoAreaMonitorSource::Slot()
{
	if (strcmp(this->cEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cEvent);
}

void GGeoAreaMonitorSource::Slot()
{
	if (strcmp(this->cEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cEvent);
}

