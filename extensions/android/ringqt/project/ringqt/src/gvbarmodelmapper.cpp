
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gvbarmodelmapper.h"

GVBarModelMapper::GVBarModelMapper(QObject * parent,VM *pVM)  : QtCharts::QVBarModelMapper(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cfirstBarSetColumnChangedEvent,"");
	strcpy(this->cfirstRowChangedEvent,"");
	strcpy(this->clastBarSetColumnChangedEvent,"");
	strcpy(this->cmodelReplacedEvent,"");
	strcpy(this->crowCountChangedEvent,"");
	strcpy(this->cseriesReplacedEvent,"");

	QObject::connect(this, SIGNAL(firstBarSetColumnChanged()),this, SLOT(firstBarSetColumnChangedSlot()));
	QObject::connect(this, SIGNAL(firstRowChanged()),this, SLOT(firstRowChangedSlot()));
	QObject::connect(this, SIGNAL(lastBarSetColumnChanged()),this, SLOT(lastBarSetColumnChangedSlot()));
	QObject::connect(this, SIGNAL(modelReplaced()),this, SLOT(modelReplacedSlot()));
	QObject::connect(this, SIGNAL(rowCountChanged()),this, SLOT(rowCountChangedSlot()));
	QObject::connect(this, SIGNAL(seriesReplaced()),this, SLOT(seriesReplacedSlot()));

}

GVBarModelMapper::~GVBarModelMapper()
{
	ring_list_delete(this->pParaList);
}

void GVBarModelMapper::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GVBarModelMapper::setfirstBarSetColumnChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cfirstBarSetColumnChangedEvent,cStr);
}

void GVBarModelMapper::setfirstRowChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cfirstRowChangedEvent,cStr);
}

void GVBarModelMapper::setlastBarSetColumnChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->clastBarSetColumnChangedEvent,cStr);
}

void GVBarModelMapper::setmodelReplacedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cmodelReplacedEvent,cStr);
}

void GVBarModelMapper::setrowCountChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->crowCountChangedEvent,cStr);
}

void GVBarModelMapper::setseriesReplacedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cseriesReplacedEvent,cStr);
}

 
const char *GVBarModelMapper::getfirstBarSetColumnChangedEvent(void)
{
	return this->cfirstBarSetColumnChangedEvent;
}

const char *GVBarModelMapper::getfirstRowChangedEvent(void)
{
	return this->cfirstRowChangedEvent;
}

const char *GVBarModelMapper::getlastBarSetColumnChangedEvent(void)
{
	return this->clastBarSetColumnChangedEvent;
}

const char *GVBarModelMapper::getmodelReplacedEvent(void)
{
	return this->cmodelReplacedEvent;
}

const char *GVBarModelMapper::getrowCountChangedEvent(void)
{
	return this->crowCountChangedEvent;
}

const char *GVBarModelMapper::getseriesReplacedEvent(void)
{
	return this->cseriesReplacedEvent;
}


void GVBarModelMapper::firstBarSetColumnChangedSlot()
{
	if (strcmp(this->cfirstBarSetColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfirstBarSetColumnChangedEvent);
}

void GVBarModelMapper::firstRowChangedSlot()
{
	if (strcmp(this->cfirstRowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfirstRowChangedEvent);
}

void GVBarModelMapper::lastBarSetColumnChangedSlot()
{
	if (strcmp(this->clastBarSetColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clastBarSetColumnChangedEvent);
}

void GVBarModelMapper::modelReplacedSlot()
{
	if (strcmp(this->cmodelReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmodelReplacedEvent);
}

void GVBarModelMapper::rowCountChangedSlot()
{
	if (strcmp(this->crowCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crowCountChangedEvent);
}

void GVBarModelMapper::seriesReplacedSlot()
{
	if (strcmp(this->cseriesReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cseriesReplacedEvent);
}

