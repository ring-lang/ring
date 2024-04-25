
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gvpiemodelmapper.h"

GVPieModelMapper::GVPieModelMapper(QObject * parent,VM *pVM)  : QtCharts::QVPieModelMapper(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cfirstRowChangedEvent,"");
	strcpy(this->clabelsColumnChangedEvent,"");
	strcpy(this->cmodelReplacedEvent,"");
	strcpy(this->crowCountChangedEvent,"");
	strcpy(this->cseriesReplacedEvent,"");
	strcpy(this->cvaluesColumnChangedEvent,"");

	QObject::connect(this, SIGNAL(firstRowChanged()),this, SLOT(firstRowChangedSlot()));
	QObject::connect(this, SIGNAL(labelsColumnChanged()),this, SLOT(labelsColumnChangedSlot()));
	QObject::connect(this, SIGNAL(modelReplaced()),this, SLOT(modelReplacedSlot()));
	QObject::connect(this, SIGNAL(rowCountChanged()),this, SLOT(rowCountChangedSlot()));
	QObject::connect(this, SIGNAL(seriesReplaced()),this, SLOT(seriesReplacedSlot()));
	QObject::connect(this, SIGNAL(valuesColumnChanged()),this, SLOT(valuesColumnChangedSlot()));

}

GVPieModelMapper::~GVPieModelMapper()
{
	ring_list_delete(this->pParaList);
}

void GVPieModelMapper::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GVPieModelMapper::setfirstRowChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfirstRowChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GVPieModelMapper::setlabelsColumnChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsColumnChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GVPieModelMapper::setmodelReplacedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmodelReplacedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GVPieModelMapper::setrowCountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->crowCountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GVPieModelMapper::setseriesReplacedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cseriesReplacedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GVPieModelMapper::setvaluesColumnChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvaluesColumnChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GVPieModelMapper::getfirstRowChangedEvent(void)
{
	return this->cfirstRowChangedEvent;
}

const char *GVPieModelMapper::getlabelsColumnChangedEvent(void)
{
	return this->clabelsColumnChangedEvent;
}

const char *GVPieModelMapper::getmodelReplacedEvent(void)
{
	return this->cmodelReplacedEvent;
}

const char *GVPieModelMapper::getrowCountChangedEvent(void)
{
	return this->crowCountChangedEvent;
}

const char *GVPieModelMapper::getseriesReplacedEvent(void)
{
	return this->cseriesReplacedEvent;
}

const char *GVPieModelMapper::getvaluesColumnChangedEvent(void)
{
	return this->cvaluesColumnChangedEvent;
}


void GVPieModelMapper::firstRowChangedSlot()
{
	if (strcmp(this->cfirstRowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfirstRowChangedEvent);
}

void GVPieModelMapper::labelsColumnChangedSlot()
{
	if (strcmp(this->clabelsColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsColumnChangedEvent);
}

void GVPieModelMapper::modelReplacedSlot()
{
	if (strcmp(this->cmodelReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmodelReplacedEvent);
}

void GVPieModelMapper::rowCountChangedSlot()
{
	if (strcmp(this->crowCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crowCountChangedEvent);
}

void GVPieModelMapper::seriesReplacedSlot()
{
	if (strcmp(this->cseriesReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cseriesReplacedEvent);
}

void GVPieModelMapper::valuesColumnChangedSlot()
{
	if (strcmp(this->cvaluesColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvaluesColumnChangedEvent);
}

