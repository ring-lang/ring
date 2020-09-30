
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gbarcategoryaxis.h"

GBarCategoryAxis::GBarCategoryAxis(QObject *parent,VM *pVM)  : QtCharts::QBarCategoryAxis(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccategoriesChangedEvent,"");
	strcpy(this->ccountChangedEvent,"");
	strcpy(this->cmaxChangedEvent,"");
	strcpy(this->cminChangedEvent,"");
	strcpy(this->crangeChangedEvent,"");

	QObject::connect(this, SIGNAL(categoriesChanged()),this, SLOT(categoriesChangedSlot()));
	QObject::connect(this, SIGNAL(countChanged()),this, SLOT(countChangedSlot()));
	QObject::connect(this, SIGNAL(maxChanged(const QString)),this, SLOT(maxChangedSlot()));
	QObject::connect(this, SIGNAL(minChanged(const QString)),this, SLOT(minChangedSlot()));
	QObject::connect(this, SIGNAL(rangeChanged(const QString,const QString)),this, SLOT(rangeChangedSlot()));

}

GBarCategoryAxis::~GBarCategoryAxis()
{
	ring_list_delete(this->pParaList);
}

void GBarCategoryAxis::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GBarCategoryAxis::setcategoriesChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccategoriesChangedEvent,cStr);
}

void GBarCategoryAxis::setcountChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccountChangedEvent,cStr);
}

void GBarCategoryAxis::setmaxChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cmaxChangedEvent,cStr);
}

void GBarCategoryAxis::setminChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cminChangedEvent,cStr);
}

void GBarCategoryAxis::setrangeChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->crangeChangedEvent,cStr);
}

 
const char *GBarCategoryAxis::getcategoriesChangedEvent(void)
{
	return this->ccategoriesChangedEvent;
}

const char *GBarCategoryAxis::getcountChangedEvent(void)
{
	return this->ccountChangedEvent;
}

const char *GBarCategoryAxis::getmaxChangedEvent(void)
{
	return this->cmaxChangedEvent;
}

const char *GBarCategoryAxis::getminChangedEvent(void)
{
	return this->cminChangedEvent;
}

const char *GBarCategoryAxis::getrangeChangedEvent(void)
{
	return this->crangeChangedEvent;
}


void GBarCategoryAxis::categoriesChangedSlot()
{
	if (strcmp(this->ccategoriesChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccategoriesChangedEvent);
}

void GBarCategoryAxis::countChangedSlot()
{
	if (strcmp(this->ccountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccountChangedEvent);
}

void GBarCategoryAxis::maxChangedSlot()
{
	if (strcmp(this->cmaxChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmaxChangedEvent);
}

void GBarCategoryAxis::minChangedSlot()
{
	if (strcmp(this->cminChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminChangedEvent);
}

void GBarCategoryAxis::rangeChangedSlot()
{
	if (strcmp(this->crangeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crangeChangedEvent);
}

