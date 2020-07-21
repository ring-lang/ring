
/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gxyseries.h"

GXYSeries::GXYSeries(QtCharts::QXYSeriesPrivate &parent,VM *pVM)  : QtCharts::QXYSeries(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cclickedEvent,"");
	strcpy(this->ccolorChangedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->choveredEvent,"");
	strcpy(this->cpenChangedEvent,"");
	strcpy(this->cpointAddedEvent,"");
	strcpy(this->cpointLabelsClippingChangedEvent,"");
	strcpy(this->cpointLabelsColorChangedEvent,"");
	strcpy(this->cpointLabelsFontChangedEvent,"");
	strcpy(this->cpointLabelsFormatChangedEvent,"");
	strcpy(this->cpointLabelsVisibilityChangedEvent,"");
	strcpy(this->cpointRemovedEvent,"");
	strcpy(this->cpointReplacedEvent,"");
	strcpy(this->cpointsRemovedEvent,"");
	strcpy(this->cpointsReplacedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");

	QObject::connect(this, SIGNAL(clicked(const QPointF)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(colorChanged(QColor)),this, SLOT(colorChangedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked(const QPointF)),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(hovered(const QPointF,bool)),this, SLOT(hoveredSlot()));
	QObject::connect(this, SIGNAL(penChanged(const QPen)),this, SLOT(penChangedSlot()));
	QObject::connect(this, SIGNAL(pointAdded(int)),this, SLOT(pointAddedSlot()));
	QObject::connect(this, SIGNAL(pointLabelsClippingChanged(bool)),this, SLOT(pointLabelsClippingChangedSlot()));
	QObject::connect(this, SIGNAL(pointLabelsColorChanged(const QColor)),this, SLOT(pointLabelsColorChangedSlot()));
	QObject::connect(this, SIGNAL(pointLabelsFontChanged(const QFont)),this, SLOT(pointLabelsFontChangedSlot()));
	QObject::connect(this, SIGNAL(pointLabelsFormatChanged(const QString)),this, SLOT(pointLabelsFormatChangedSlot()));
	QObject::connect(this, SIGNAL(pointLabelsVisibilityChanged(bool)),this, SLOT(pointLabelsVisibilityChangedSlot()));
	QObject::connect(this, SIGNAL(pointRemoved(int)),this, SLOT(pointRemovedSlot()));
	QObject::connect(this, SIGNAL(pointReplaced(int)),this, SLOT(pointReplacedSlot()));
	QObject::connect(this, SIGNAL(pointsRemoved(int,int)),this, SLOT(pointsRemovedSlot()));
	QObject::connect(this, SIGNAL(pointsReplaced()),this, SLOT(pointsReplacedSlot()));
	QObject::connect(this, SIGNAL(pressed(const QPointF)),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released(const QPointF)),this, SLOT(releasedSlot()));

}

GXYSeries::~GXYSeries()
{
	ring_list_delete(this->pParaList);
}

void GXYSeries::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GXYSeries::setclickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cclickedEvent,cStr);
}

void GXYSeries::setcolorChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccolorChangedEvent,cStr);
}

void GXYSeries::setdoubleClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cdoubleClickedEvent,cStr);
}

void GXYSeries::sethoveredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->choveredEvent,cStr);
}

void GXYSeries::setpenChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpenChangedEvent,cStr);
}

void GXYSeries::setpointAddedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpointAddedEvent,cStr);
}

void GXYSeries::setpointLabelsClippingChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpointLabelsClippingChangedEvent,cStr);
}

void GXYSeries::setpointLabelsColorChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpointLabelsColorChangedEvent,cStr);
}

void GXYSeries::setpointLabelsFontChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpointLabelsFontChangedEvent,cStr);
}

void GXYSeries::setpointLabelsFormatChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpointLabelsFormatChangedEvent,cStr);
}

void GXYSeries::setpointLabelsVisibilityChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpointLabelsVisibilityChangedEvent,cStr);
}

void GXYSeries::setpointRemovedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpointRemovedEvent,cStr);
}

void GXYSeries::setpointReplacedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpointReplacedEvent,cStr);
}

void GXYSeries::setpointsRemovedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpointsRemovedEvent,cStr);
}

void GXYSeries::setpointsReplacedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpointsReplacedEvent,cStr);
}

void GXYSeries::setpressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpressedEvent,cStr);
}

void GXYSeries::setreleasedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->creleasedEvent,cStr);
}

 
const char *GXYSeries::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GXYSeries::getcolorChangedEvent(void)
{
	return this->ccolorChangedEvent;
}

const char *GXYSeries::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GXYSeries::gethoveredEvent(void)
{
	return this->choveredEvent;
}

const char *GXYSeries::getpenChangedEvent(void)
{
	return this->cpenChangedEvent;
}

const char *GXYSeries::getpointAddedEvent(void)
{
	return this->cpointAddedEvent;
}

const char *GXYSeries::getpointLabelsClippingChangedEvent(void)
{
	return this->cpointLabelsClippingChangedEvent;
}

const char *GXYSeries::getpointLabelsColorChangedEvent(void)
{
	return this->cpointLabelsColorChangedEvent;
}

const char *GXYSeries::getpointLabelsFontChangedEvent(void)
{
	return this->cpointLabelsFontChangedEvent;
}

const char *GXYSeries::getpointLabelsFormatChangedEvent(void)
{
	return this->cpointLabelsFormatChangedEvent;
}

const char *GXYSeries::getpointLabelsVisibilityChangedEvent(void)
{
	return this->cpointLabelsVisibilityChangedEvent;
}

const char *GXYSeries::getpointRemovedEvent(void)
{
	return this->cpointRemovedEvent;
}

const char *GXYSeries::getpointReplacedEvent(void)
{
	return this->cpointReplacedEvent;
}

const char *GXYSeries::getpointsRemovedEvent(void)
{
	return this->cpointsRemovedEvent;
}

const char *GXYSeries::getpointsReplacedEvent(void)
{
	return this->cpointsReplacedEvent;
}

const char *GXYSeries::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GXYSeries::getreleasedEvent(void)
{
	return this->creleasedEvent;
}


void GXYSeries::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GXYSeries::colorChangedSlot()
{
	if (strcmp(this->ccolorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccolorChangedEvent);
}

void GXYSeries::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GXYSeries::hoveredSlot()
{
	if (strcmp(this->choveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choveredEvent);
}

void GXYSeries::penChangedSlot()
{
	if (strcmp(this->cpenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpenChangedEvent);
}

void GXYSeries::pointAddedSlot()
{
	if (strcmp(this->cpointAddedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointAddedEvent);
}

void GXYSeries::pointLabelsClippingChangedSlot()
{
	if (strcmp(this->cpointLabelsClippingChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointLabelsClippingChangedEvent);
}

void GXYSeries::pointLabelsColorChangedSlot()
{
	if (strcmp(this->cpointLabelsColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointLabelsColorChangedEvent);
}

void GXYSeries::pointLabelsFontChangedSlot()
{
	if (strcmp(this->cpointLabelsFontChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointLabelsFontChangedEvent);
}

void GXYSeries::pointLabelsFormatChangedSlot()
{
	if (strcmp(this->cpointLabelsFormatChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointLabelsFormatChangedEvent);
}

void GXYSeries::pointLabelsVisibilityChangedSlot()
{
	if (strcmp(this->cpointLabelsVisibilityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointLabelsVisibilityChangedEvent);
}

void GXYSeries::pointRemovedSlot()
{
	if (strcmp(this->cpointRemovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointRemovedEvent);
}

void GXYSeries::pointReplacedSlot()
{
	if (strcmp(this->cpointReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointReplacedEvent);
}

void GXYSeries::pointsRemovedSlot()
{
	if (strcmp(this->cpointsRemovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointsRemovedEvent);
}

void GXYSeries::pointsReplacedSlot()
{
	if (strcmp(this->cpointsReplacedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpointsReplacedEvent);
}

void GXYSeries::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GXYSeries::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

