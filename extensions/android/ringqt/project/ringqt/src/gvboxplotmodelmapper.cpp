
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gvboxplotmodelmapper.h"

GVBoxPlotModelMapper::GVBoxPlotModelMapper(QObject * parent,VM *pVM)  : QtCharts::QVBoxPlotModelMapper(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cfirstBoxSetColumnChangedEvent,"");
	strcpy(this->cfirstRowChangedEvent,"");
	strcpy(this->clastBoxSetColumnChangedEvent,"");
	strcpy(this->cmodelReplacedEvent,"");
	strcpy(this->crowCountChangedEvent,"");
	strcpy(this->cseriesReplacedEvent,"");

	QObject::connect(this, SIGNAL(firstBoxSetColumnChanged()),this, SLOT(firstBoxSetColumnChangedSlot()));
	QObject::connect(this, SIGNAL(firstRowChanged()),this, SLOT(firstRowChangedSlot()));
	QObject::connect(this, SIGNAL(lastBoxSetColumnChanged()),this, SLOT(lastBoxSetColumnChangedSlot()));
	QObject::connect(this, SIGNAL(modelReplaced()),this, SLOT(modelReplacedSlot()));
	QObject::connect(this, SIGNAL(rowCountChanged()),this, SLOT(rowCountChangedSlot()));
	QObject::connect(this, SIGNAL(seriesReplaced()),this, SLOT(seriesReplacedSlot()));

}

GVBoxPlotModelMapper::~GVBoxPlotModelMapper()
{
	ring_list_delete(this->pParaList);
}

void GVBoxPlotModelMapper::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GVBoxPlotModelMapper::setfirstBoxSetColumnChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfirstBoxSetColumnChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GVBoxPlotModelMapper::setfirstRowChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfirstRowChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GVBoxPlotModelMapper::setlastBoxSetColumnChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clastBoxSetColumnChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GVBoxPlotModelMapper::setmodelReplacedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmodelReplacedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GVBoxPlotModelMapper::setrowCountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->crowCountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GVBoxPlotModelMapper::setseriesReplacedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cseriesReplacedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GVBoxPlotModelMapper::getfirstBoxSetColumnChangedEvent(void)
{
	return this->cfirstBoxSetColumnChangedEvent;
}

const char *GVBoxPlotModelMapper::getfirstRowChangedEvent(void)
{
	return this->cfirstRowChangedEvent;
}

const char *GVBoxPlotModelMapper::getlastBoxSetColumnChangedEvent(void)
{
	return this->clastBoxSetColumnChangedEvent;
}

const char *GVBoxPlotModelMapper::getmodelReplacedEvent(void)
{
	return this->cmodelReplacedEvent;
}

const char *GVBoxPlotModelMapper::getrowCountChangedEvent(void)
{
	return this->crowCountChangedEvent;
}

const char *GVBoxPlotModelMapper::getseriesReplacedEvent(void)
{
	return this->cseriesReplacedEvent;
}


void GVBoxPlotModelMapper::firstBoxSetColumnChangedSlot()
{
	if (strcmp(this->cfirstBoxSetColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfirstBoxSetColumnChangedEvent);
}

void GVBoxPlotModelMapper::firstRowChangedSlot()
{
	if (strcmp(this->cfirstRowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfirstRowChangedEvent);
}

void GVBoxPlotModelMapper::lastBoxSetColumnChangedSlot()
{
	if (strcmp(this->clastBoxSetColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clastBoxSetColumnChangedEvent);
}

void GVBoxPlotModelMapper::modelReplacedSlot()
{
	if (strcmp(this->cmodelReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmodelReplacedEvent);
}

void GVBoxPlotModelMapper::rowCountChangedSlot()
{
	if (strcmp(this->crowCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crowCountChangedEvent);
}

void GVBoxPlotModelMapper::seriesReplacedSlot()
{
	if (strcmp(this->cseriesReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cseriesReplacedEvent);
}

