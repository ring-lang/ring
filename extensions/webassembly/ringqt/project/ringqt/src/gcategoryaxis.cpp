
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gcategoryaxis.h"

GCategoryAxis::GCategoryAxis(QObject *parent,VM *pVM)  : QtCharts::QCategoryAxis(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccategoriesChangedEvent,"");
	strcpy(this->clabelsPositionChangedEvent,"");

	QObject::connect(this, SIGNAL(categoriesChanged()),this, SLOT(categoriesChangedSlot()));
	QObject::connect(this, SIGNAL(labelsPositionChanged(QCategoryAxis::AxisLabelsPosition)),this, SLOT(labelsPositionChangedSlot()));

}

GCategoryAxis::~GCategoryAxis()
{
	ring_list_delete(this->pParaList);
}

void GCategoryAxis::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GCategoryAxis::setcategoriesChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccategoriesChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GCategoryAxis::setlabelsPositionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsPositionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GCategoryAxis::getcategoriesChangedEvent(void)
{
	return this->ccategoriesChangedEvent;
}

const char *GCategoryAxis::getlabelsPositionChangedEvent(void)
{
	return this->clabelsPositionChangedEvent;
}


void GCategoryAxis::categoriesChangedSlot()
{
	if (strcmp(this->ccategoriesChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccategoriesChangedEvent);
}

void GCategoryAxis::labelsPositionChangedSlot()
{
	if (strcmp(this->clabelsPositionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsPositionChangedEvent);
}

