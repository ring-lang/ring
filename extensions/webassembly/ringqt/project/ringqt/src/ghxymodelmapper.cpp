
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "ghxymodelmapper.h"

GHXYModelMapper::GHXYModelMapper(QObject *parent,VM *pVM)  : QtCharts::QHXYModelMapper(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccolumnCountChangedEvent,"");
	strcpy(this->cfirstColumnChangedEvent,"");
	strcpy(this->cmodelReplacedEvent,"");
	strcpy(this->cseriesReplacedEvent,"");
	strcpy(this->cxRowChangedEvent,"");
	strcpy(this->cyRowChangedEvent,"");

	QObject::connect(this, SIGNAL(columnCountChanged()),this, SLOT(columnCountChangedSlot()));
	QObject::connect(this, SIGNAL(firstColumnChanged()),this, SLOT(firstColumnChangedSlot()));
	QObject::connect(this, SIGNAL(modelReplaced()),this, SLOT(modelReplacedSlot()));
	QObject::connect(this, SIGNAL(seriesReplaced()),this, SLOT(seriesReplacedSlot()));
	QObject::connect(this, SIGNAL(xRowChanged()),this, SLOT(xRowChangedSlot()));
	QObject::connect(this, SIGNAL(yRowChanged()),this, SLOT(yRowChangedSlot()));

}

GHXYModelMapper::~GHXYModelMapper()
{
	ring_list_delete(this->pParaList);
}

void GHXYModelMapper::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GHXYModelMapper::setcolumnCountChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccolumnCountChangedEvent,cStr);
}

void GHXYModelMapper::setfirstColumnChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cfirstColumnChangedEvent,cStr);
}

void GHXYModelMapper::setmodelReplacedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cmodelReplacedEvent,cStr);
}

void GHXYModelMapper::setseriesReplacedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cseriesReplacedEvent,cStr);
}

void GHXYModelMapper::setxRowChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cxRowChangedEvent,cStr);
}

void GHXYModelMapper::setyRowChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cyRowChangedEvent,cStr);
}

 
const char *GHXYModelMapper::getcolumnCountChangedEvent(void)
{
	return this->ccolumnCountChangedEvent;
}

const char *GHXYModelMapper::getfirstColumnChangedEvent(void)
{
	return this->cfirstColumnChangedEvent;
}

const char *GHXYModelMapper::getmodelReplacedEvent(void)
{
	return this->cmodelReplacedEvent;
}

const char *GHXYModelMapper::getseriesReplacedEvent(void)
{
	return this->cseriesReplacedEvent;
}

const char *GHXYModelMapper::getxRowChangedEvent(void)
{
	return this->cxRowChangedEvent;
}

const char *GHXYModelMapper::getyRowChangedEvent(void)
{
	return this->cyRowChangedEvent;
}


void GHXYModelMapper::columnCountChangedSlot()
{
	if (strcmp(this->ccolumnCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccolumnCountChangedEvent);
}

void GHXYModelMapper::firstColumnChangedSlot()
{
	if (strcmp(this->cfirstColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfirstColumnChangedEvent);
}

void GHXYModelMapper::modelReplacedSlot()
{
	if (strcmp(this->cmodelReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmodelReplacedEvent);
}

void GHXYModelMapper::seriesReplacedSlot()
{
	if (strcmp(this->cseriesReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cseriesReplacedEvent);
}

void GHXYModelMapper::xRowChangedSlot()
{
	if (strcmp(this->cxRowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cxRowChangedEvent);
}

void GHXYModelMapper::yRowChangedSlot()
{
	if (strcmp(this->cyRowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cyRowChangedEvent);
}

