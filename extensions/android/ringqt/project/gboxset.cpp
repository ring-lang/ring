
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gboxset.h"

GBoxSet::GBoxSet(QString x,QObject *parent,VM *pVM)  : QtCharts::QBoxSet(x,parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cbrushChangedEvent,"");
	strcpy(this->cclearedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->choveredEvent,"");
	strcpy(this->cpenChangedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");
	strcpy(this->cvalueChangedEvent,"");
	strcpy(this->cvaluesChangedEvent,"");

	QObject::connect(this, SIGNAL(brushChanged()),this, SLOT(brushChangedSlot()));
	QObject::connect(this, SIGNAL(cleared()),this, SLOT(clearedSlot()));
	QObject::connect(this, SIGNAL(clicked()),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked()),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(hovered(bool)),this, SLOT(hoveredSlot()));
	QObject::connect(this, SIGNAL(penChanged()),this, SLOT(penChangedSlot()));
	QObject::connect(this, SIGNAL(pressed()),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released()),this, SLOT(releasedSlot()));
	QObject::connect(this, SIGNAL(valueChanged(int)),this, SLOT(valueChangedSlot()));
	QObject::connect(this, SIGNAL(valuesChanged()),this, SLOT(valuesChangedSlot()));

}

GBoxSet::~GBoxSet()
{
	ring_list_delete(this->pParaList);
}

void GBoxSet::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GBoxSet::setbrushChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cbrushChangedEvent,cStr);
}

void GBoxSet::setclearedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cclearedEvent,cStr);
}

void GBoxSet::setclickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cclickedEvent,cStr);
}

void GBoxSet::setdoubleClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cdoubleClickedEvent,cStr);
}

void GBoxSet::sethoveredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->choveredEvent,cStr);
}

void GBoxSet::setpenChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpenChangedEvent,cStr);
}

void GBoxSet::setpressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpressedEvent,cStr);
}

void GBoxSet::setreleasedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->creleasedEvent,cStr);
}

void GBoxSet::setvalueChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cvalueChangedEvent,cStr);
}

void GBoxSet::setvaluesChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cvaluesChangedEvent,cStr);
}

 
const char *GBoxSet::getbrushChangedEvent(void)
{
	return this->cbrushChangedEvent;
}

const char *GBoxSet::getclearedEvent(void)
{
	return this->cclearedEvent;
}

const char *GBoxSet::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GBoxSet::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GBoxSet::gethoveredEvent(void)
{
	return this->choveredEvent;
}

const char *GBoxSet::getpenChangedEvent(void)
{
	return this->cpenChangedEvent;
}

const char *GBoxSet::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GBoxSet::getreleasedEvent(void)
{
	return this->creleasedEvent;
}

const char *GBoxSet::getvalueChangedEvent(void)
{
	return this->cvalueChangedEvent;
}

const char *GBoxSet::getvaluesChangedEvent(void)
{
	return this->cvaluesChangedEvent;
}


void GBoxSet::brushChangedSlot()
{
	if (strcmp(this->cbrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbrushChangedEvent);
}

void GBoxSet::clearedSlot()
{
	if (strcmp(this->cclearedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclearedEvent);
}

void GBoxSet::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GBoxSet::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GBoxSet::hoveredSlot()
{
	if (strcmp(this->choveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choveredEvent);
}

void GBoxSet::penChangedSlot()
{
	if (strcmp(this->cpenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpenChangedEvent);
}

void GBoxSet::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GBoxSet::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

void GBoxSet::valueChangedSlot()
{
	if (strcmp(this->cvalueChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvalueChangedEvent);
}

void GBoxSet::valuesChangedSlot()
{
	if (strcmp(this->cvaluesChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvaluesChangedEvent);
}

