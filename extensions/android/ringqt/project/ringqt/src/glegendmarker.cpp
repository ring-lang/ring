
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "glegendmarker.h"

GLegendMarker::GLegendMarker(QtCharts::QLegendMarkerPrivate &parent,VM *pVM)  : QtCharts::QLegendMarker(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cbrushChangedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->cfontChangedEvent,"");
	strcpy(this->choveredEvent,"");
	strcpy(this->clabelBrushChangedEvent,"");
	strcpy(this->clabelChangedEvent,"");
	strcpy(this->cpenChangedEvent,"");
	strcpy(this->cshapeChangedEvent,"");
	strcpy(this->cvisibleChangedEvent,"");

	QObject::connect(this, SIGNAL(brushChanged()),this, SLOT(brushChangedSlot()));
	QObject::connect(this, SIGNAL(clicked()),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(fontChanged()),this, SLOT(fontChangedSlot()));
	QObject::connect(this, SIGNAL(hovered(bool)),this, SLOT(hoveredSlot()));
	QObject::connect(this, SIGNAL(labelBrushChanged()),this, SLOT(labelBrushChangedSlot()));
	QObject::connect(this, SIGNAL(labelChanged()),this, SLOT(labelChangedSlot()));
	QObject::connect(this, SIGNAL(penChanged()),this, SLOT(penChangedSlot()));
	QObject::connect(this, SIGNAL(shapeChanged()),this, SLOT(shapeChangedSlot()));
	QObject::connect(this, SIGNAL(visibleChanged()),this, SLOT(visibleChangedSlot()));

}

GLegendMarker::~GLegendMarker()
{
	ring_list_delete(this->pParaList);
}

void GLegendMarker::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GLegendMarker::setbrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLegendMarker::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLegendMarker::setfontChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfontChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLegendMarker::sethoveredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->choveredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLegendMarker::setlabelBrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelBrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLegendMarker::setlabelChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLegendMarker::setpenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLegendMarker::setshapeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cshapeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLegendMarker::setvisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GLegendMarker::getbrushChangedEvent(void)
{
	return this->cbrushChangedEvent;
}

const char *GLegendMarker::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GLegendMarker::getfontChangedEvent(void)
{
	return this->cfontChangedEvent;
}

const char *GLegendMarker::gethoveredEvent(void)
{
	return this->choveredEvent;
}

const char *GLegendMarker::getlabelBrushChangedEvent(void)
{
	return this->clabelBrushChangedEvent;
}

const char *GLegendMarker::getlabelChangedEvent(void)
{
	return this->clabelChangedEvent;
}

const char *GLegendMarker::getpenChangedEvent(void)
{
	return this->cpenChangedEvent;
}

const char *GLegendMarker::getshapeChangedEvent(void)
{
	return this->cshapeChangedEvent;
}

const char *GLegendMarker::getvisibleChangedEvent(void)
{
	return this->cvisibleChangedEvent;
}


void GLegendMarker::brushChangedSlot()
{
	if (strcmp(this->cbrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbrushChangedEvent);
}

void GLegendMarker::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GLegendMarker::fontChangedSlot()
{
	if (strcmp(this->cfontChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfontChangedEvent);
}

void GLegendMarker::hoveredSlot()
{
	if (strcmp(this->choveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choveredEvent);
}

void GLegendMarker::labelBrushChangedSlot()
{
	if (strcmp(this->clabelBrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelBrushChangedEvent);
}

void GLegendMarker::labelChangedSlot()
{
	if (strcmp(this->clabelChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelChangedEvent);
}

void GLegendMarker::penChangedSlot()
{
	if (strcmp(this->cpenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpenChangedEvent);
}

void GLegendMarker::shapeChangedSlot()
{
	if (strcmp(this->cshapeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cshapeChangedEvent);
}

void GLegendMarker::visibleChangedSlot()
{
	if (strcmp(this->cvisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvisibleChangedEvent);
}

