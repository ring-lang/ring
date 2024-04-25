
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gbarset.h"

GBarSet::GBarSet(const QString x,QObject *parent,VM *pVM)  : QtCharts::QBarSet(x,parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cborderColorChangedEvent,"");
	strcpy(this->cbrushChangedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->ccolorChangedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->choveredEvent,"");
	strcpy(this->clabelBrushChangedEvent,"");
	strcpy(this->clabelChangedEvent,"");
	strcpy(this->clabelColorChangedEvent,"");
	strcpy(this->clabelFontChangedEvent,"");
	strcpy(this->cpenChangedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");
	strcpy(this->cvalueChangedEvent,"");
	strcpy(this->cvaluesAddedEvent,"");
	strcpy(this->cvaluesRemovedEvent,"");

	QObject::connect(this, SIGNAL(borderColorChanged(QColor)),this, SLOT(borderColorChangedSlot()));
	QObject::connect(this, SIGNAL(brushChanged()),this, SLOT(brushChangedSlot()));
	QObject::connect(this, SIGNAL(clicked(int)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(colorChanged(QColor)),this, SLOT(colorChangedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked(int)),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(hovered(bool,int)),this, SLOT(hoveredSlot()));
	QObject::connect(this, SIGNAL(labelBrushChanged()),this, SLOT(labelBrushChangedSlot()));
	QObject::connect(this, SIGNAL(labelChanged()),this, SLOT(labelChangedSlot()));
	QObject::connect(this, SIGNAL(labelColorChanged(QColor)),this, SLOT(labelColorChangedSlot()));
	QObject::connect(this, SIGNAL(labelFontChanged()),this, SLOT(labelFontChangedSlot()));
	QObject::connect(this, SIGNAL(penChanged()),this, SLOT(penChangedSlot()));
	QObject::connect(this, SIGNAL(pressed(int)),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released(int)),this, SLOT(releasedSlot()));
	QObject::connect(this, SIGNAL(valueChanged(int)),this, SLOT(valueChangedSlot()));
	QObject::connect(this, SIGNAL(valuesAdded(int,int)),this, SLOT(valuesAddedSlot()));
	QObject::connect(this, SIGNAL(valuesRemoved(int,int)),this, SLOT(valuesRemovedSlot()));

}

GBarSet::~GBarSet()
{
	ring_list_delete(this->pParaList);
}

void GBarSet::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GBarSet::setborderColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cborderColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setbrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setcolorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccolorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setdoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::sethoveredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->choveredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setlabelBrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelBrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setlabelChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setlabelColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setlabelFontChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelFontChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setpenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setreleasedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creleasedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setvalueChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvalueChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setvaluesAddedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvaluesAddedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBarSet::setvaluesRemovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvaluesRemovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GBarSet::getborderColorChangedEvent(void)
{
	return this->cborderColorChangedEvent;
}

const char *GBarSet::getbrushChangedEvent(void)
{
	return this->cbrushChangedEvent;
}

const char *GBarSet::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GBarSet::getcolorChangedEvent(void)
{
	return this->ccolorChangedEvent;
}

const char *GBarSet::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GBarSet::gethoveredEvent(void)
{
	return this->choveredEvent;
}

const char *GBarSet::getlabelBrushChangedEvent(void)
{
	return this->clabelBrushChangedEvent;
}

const char *GBarSet::getlabelChangedEvent(void)
{
	return this->clabelChangedEvent;
}

const char *GBarSet::getlabelColorChangedEvent(void)
{
	return this->clabelColorChangedEvent;
}

const char *GBarSet::getlabelFontChangedEvent(void)
{
	return this->clabelFontChangedEvent;
}

const char *GBarSet::getpenChangedEvent(void)
{
	return this->cpenChangedEvent;
}

const char *GBarSet::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GBarSet::getreleasedEvent(void)
{
	return this->creleasedEvent;
}

const char *GBarSet::getvalueChangedEvent(void)
{
	return this->cvalueChangedEvent;
}

const char *GBarSet::getvaluesAddedEvent(void)
{
	return this->cvaluesAddedEvent;
}

const char *GBarSet::getvaluesRemovedEvent(void)
{
	return this->cvaluesRemovedEvent;
}


void GBarSet::borderColorChangedSlot()
{
	if (strcmp(this->cborderColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cborderColorChangedEvent);
}

void GBarSet::brushChangedSlot()
{
	if (strcmp(this->cbrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbrushChangedEvent);
}

void GBarSet::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GBarSet::colorChangedSlot()
{
	if (strcmp(this->ccolorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccolorChangedEvent);
}

void GBarSet::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GBarSet::hoveredSlot()
{
	if (strcmp(this->choveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choveredEvent);
}

void GBarSet::labelBrushChangedSlot()
{
	if (strcmp(this->clabelBrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelBrushChangedEvent);
}

void GBarSet::labelChangedSlot()
{
	if (strcmp(this->clabelChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelChangedEvent);
}

void GBarSet::labelColorChangedSlot()
{
	if (strcmp(this->clabelColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelColorChangedEvent);
}

void GBarSet::labelFontChangedSlot()
{
	if (strcmp(this->clabelFontChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelFontChangedEvent);
}

void GBarSet::penChangedSlot()
{
	if (strcmp(this->cpenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpenChangedEvent);
}

void GBarSet::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GBarSet::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

void GBarSet::valueChangedSlot()
{
	if (strcmp(this->cvalueChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvalueChangedEvent);
}

void GBarSet::valuesAddedSlot()
{
	if (strcmp(this->cvaluesAddedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvaluesAddedEvent);
}

void GBarSet::valuesRemovedSlot()
{
	if (strcmp(this->cvaluesRemovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvaluesRemovedEvent);
}

