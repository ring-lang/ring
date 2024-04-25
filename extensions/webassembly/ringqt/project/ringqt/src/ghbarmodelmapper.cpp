
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "ghbarmodelmapper.h"

GHBarModelMapper::GHBarModelMapper(QObject *parent,VM *pVM)  : QtCharts::QHBarModelMapper(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccolumnCountChangedEvent,"");
	strcpy(this->cfirstBarSetRowChangedEvent,"");
	strcpy(this->cfirstColumnChangedEvent,"");
	strcpy(this->clastBarSetRowChangedEvent,"");
	strcpy(this->cmodelReplacedEvent,"");
	strcpy(this->cseriesReplacedEvent,"");

	QObject::connect(this, SIGNAL(columnCountChanged()),this, SLOT(columnCountChangedSlot()));
	QObject::connect(this, SIGNAL(firstBarSetRowChanged()),this, SLOT(firstBarSetRowChangedSlot()));
	QObject::connect(this, SIGNAL(firstColumnChanged()),this, SLOT(firstColumnChangedSlot()));
	QObject::connect(this, SIGNAL(lastBarSetRowChanged()),this, SLOT(lastBarSetRowChangedSlot()));
	QObject::connect(this, SIGNAL(modelReplaced()),this, SLOT(modelReplacedSlot()));
	QObject::connect(this, SIGNAL(seriesReplaced()),this, SLOT(seriesReplacedSlot()));

}

GHBarModelMapper::~GHBarModelMapper()
{
	ring_list_delete(this->pParaList);
}

void GHBarModelMapper::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GHBarModelMapper::setcolumnCountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccolumnCountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHBarModelMapper::setfirstBarSetRowChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfirstBarSetRowChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHBarModelMapper::setfirstColumnChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfirstColumnChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHBarModelMapper::setlastBarSetRowChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clastBarSetRowChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHBarModelMapper::setmodelReplacedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmodelReplacedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHBarModelMapper::setseriesReplacedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cseriesReplacedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GHBarModelMapper::getcolumnCountChangedEvent(void)
{
	return this->ccolumnCountChangedEvent;
}

const char *GHBarModelMapper::getfirstBarSetRowChangedEvent(void)
{
	return this->cfirstBarSetRowChangedEvent;
}

const char *GHBarModelMapper::getfirstColumnChangedEvent(void)
{
	return this->cfirstColumnChangedEvent;
}

const char *GHBarModelMapper::getlastBarSetRowChangedEvent(void)
{
	return this->clastBarSetRowChangedEvent;
}

const char *GHBarModelMapper::getmodelReplacedEvent(void)
{
	return this->cmodelReplacedEvent;
}

const char *GHBarModelMapper::getseriesReplacedEvent(void)
{
	return this->cseriesReplacedEvent;
}


void GHBarModelMapper::columnCountChangedSlot()
{
	if (strcmp(this->ccolumnCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccolumnCountChangedEvent);
}

void GHBarModelMapper::firstBarSetRowChangedSlot()
{
	if (strcmp(this->cfirstBarSetRowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfirstBarSetRowChangedEvent);
}

void GHBarModelMapper::firstColumnChangedSlot()
{
	if (strcmp(this->cfirstColumnChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfirstColumnChangedEvent);
}

void GHBarModelMapper::lastBarSetRowChangedSlot()
{
	if (strcmp(this->clastBarSetRowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clastBarSetRowChangedEvent);
}

void GHBarModelMapper::modelReplacedSlot()
{
	if (strcmp(this->cmodelReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmodelReplacedEvent);
}

void GHBarModelMapper::seriesReplacedSlot()
{
	if (strcmp(this->cseriesReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cseriesReplacedEvent);
}

