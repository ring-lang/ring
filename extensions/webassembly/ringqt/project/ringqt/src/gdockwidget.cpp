
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gdockwidget.h"

GDockWidget::GDockWidget(QWidget *x,Qt::WindowFlags parent,VM *pVM)  : QDockWidget(x,parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->callowedAreasChangedEvent,"");
	strcpy(this->cdockLocationChangedEvent,"");
	strcpy(this->cfeaturesChangedEvent,"");
	strcpy(this->ctopLevelChangedEvent,"");
	strcpy(this->cvisibilityChangedEvent,"");

	QObject::connect(this, SIGNAL(allowedAreasChanged(Qt::DockWidgetAreas)),this, SLOT(allowedAreasChangedSlot()));
	QObject::connect(this, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)),this, SLOT(dockLocationChangedSlot()));
	QObject::connect(this, SIGNAL(featuresChanged(QDockWidget::DockWidgetFeatures)),this, SLOT(featuresChangedSlot()));
	QObject::connect(this, SIGNAL(topLevelChanged(bool)),this, SLOT(topLevelChangedSlot()));
	QObject::connect(this, SIGNAL(visibilityChanged(bool)),this, SLOT(visibilityChangedSlot()));

}

GDockWidget::~GDockWidget()
{
	ring_list_delete(this->pParaList);
}

void GDockWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GDockWidget::setallowedAreasChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->callowedAreasChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDockWidget::setdockLocationChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdockLocationChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDockWidget::setfeaturesChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfeaturesChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDockWidget::settopLevelChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctopLevelChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GDockWidget::setvisibilityChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvisibilityChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GDockWidget::getallowedAreasChangedEvent(void)
{
	return this->callowedAreasChangedEvent;
}

const char *GDockWidget::getdockLocationChangedEvent(void)
{
	return this->cdockLocationChangedEvent;
}

const char *GDockWidget::getfeaturesChangedEvent(void)
{
	return this->cfeaturesChangedEvent;
}

const char *GDockWidget::gettopLevelChangedEvent(void)
{
	return this->ctopLevelChangedEvent;
}

const char *GDockWidget::getvisibilityChangedEvent(void)
{
	return this->cvisibilityChangedEvent;
}


void GDockWidget::allowedAreasChangedSlot()
{
	if (strcmp(this->callowedAreasChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->callowedAreasChangedEvent);
}

void GDockWidget::dockLocationChangedSlot()
{
	if (strcmp(this->cdockLocationChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdockLocationChangedEvent);
}

void GDockWidget::featuresChangedSlot()
{
	if (strcmp(this->cfeaturesChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfeaturesChangedEvent);
}

void GDockWidget::topLevelChangedSlot()
{
	if (strcmp(this->ctopLevelChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctopLevelChangedEvent);
}

void GDockWidget::visibilityChangedSlot()
{
	if (strcmp(this->cvisibilityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvisibilityChangedEvent);
}

