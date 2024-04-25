
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gpieslice.h"

GPieSlice::GPieSlice(QObject * parent,VM *pVM)  : QtCharts::QPieSlice(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cangleSpanChangedEvent,"");
	strcpy(this->cborderColorChangedEvent,"");
	strcpy(this->cborderWidthChangedEvent,"");
	strcpy(this->cbrushChangedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->ccolorChangedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->choveredEvent,"");
	strcpy(this->clabelBrushChangedEvent,"");
	strcpy(this->clabelChangedEvent,"");
	strcpy(this->clabelColorChangedEvent,"");
	strcpy(this->clabelFontChangedEvent,"");
	strcpy(this->clabelVisibleChangedEvent,"");
	strcpy(this->cpenChangedEvent,"");
	strcpy(this->cpercentageChangedEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->creleasedEvent,"");
	strcpy(this->cstartAngleChangedEvent,"");
	strcpy(this->cvalueChangedEvent,"");

	QObject::connect(this, SIGNAL(angleSpanChanged()),this, SLOT(angleSpanChangedSlot()));
	QObject::connect(this, SIGNAL(borderColorChanged()),this, SLOT(borderColorChangedSlot()));
	QObject::connect(this, SIGNAL(borderWidthChanged()),this, SLOT(borderWidthChangedSlot()));
	QObject::connect(this, SIGNAL(brushChanged()),this, SLOT(brushChangedSlot()));
	QObject::connect(this, SIGNAL(clicked()),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(colorChanged()),this, SLOT(colorChangedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked()),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(hovered(bool)),this, SLOT(hoveredSlot()));
	QObject::connect(this, SIGNAL(labelBrushChanged()),this, SLOT(labelBrushChangedSlot()));
	QObject::connect(this, SIGNAL(labelChanged()),this, SLOT(labelChangedSlot()));
	QObject::connect(this, SIGNAL(labelColorChanged()),this, SLOT(labelColorChangedSlot()));
	QObject::connect(this, SIGNAL(labelFontChanged()),this, SLOT(labelFontChangedSlot()));
	QObject::connect(this, SIGNAL(labelVisibleChanged()),this, SLOT(labelVisibleChangedSlot()));
	QObject::connect(this, SIGNAL(penChanged()),this, SLOT(penChangedSlot()));
	QObject::connect(this, SIGNAL(percentageChanged()),this, SLOT(percentageChangedSlot()));
	QObject::connect(this, SIGNAL(pressed()),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(released()),this, SLOT(releasedSlot()));
	QObject::connect(this, SIGNAL(startAngleChanged()),this, SLOT(startAngleChangedSlot()));
	QObject::connect(this, SIGNAL(valueChanged()),this, SLOT(valueChangedSlot()));

}

GPieSlice::~GPieSlice()
{
	ring_list_delete(this->pParaList);
}

void GPieSlice::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GPieSlice::setangleSpanChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cangleSpanChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setborderColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cborderColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setborderWidthChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cborderWidthChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setbrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setcolorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccolorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setdoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::sethoveredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->choveredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setlabelBrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelBrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setlabelChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setlabelColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setlabelFontChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelFontChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setlabelVisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelVisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setpenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setpercentageChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpercentageChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setreleasedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creleasedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setstartAngleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstartAngleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPieSlice::setvalueChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvalueChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GPieSlice::getangleSpanChangedEvent(void)
{
	return this->cangleSpanChangedEvent;
}

const char *GPieSlice::getborderColorChangedEvent(void)
{
	return this->cborderColorChangedEvent;
}

const char *GPieSlice::getborderWidthChangedEvent(void)
{
	return this->cborderWidthChangedEvent;
}

const char *GPieSlice::getbrushChangedEvent(void)
{
	return this->cbrushChangedEvent;
}

const char *GPieSlice::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GPieSlice::getcolorChangedEvent(void)
{
	return this->ccolorChangedEvent;
}

const char *GPieSlice::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GPieSlice::gethoveredEvent(void)
{
	return this->choveredEvent;
}

const char *GPieSlice::getlabelBrushChangedEvent(void)
{
	return this->clabelBrushChangedEvent;
}

const char *GPieSlice::getlabelChangedEvent(void)
{
	return this->clabelChangedEvent;
}

const char *GPieSlice::getlabelColorChangedEvent(void)
{
	return this->clabelColorChangedEvent;
}

const char *GPieSlice::getlabelFontChangedEvent(void)
{
	return this->clabelFontChangedEvent;
}

const char *GPieSlice::getlabelVisibleChangedEvent(void)
{
	return this->clabelVisibleChangedEvent;
}

const char *GPieSlice::getpenChangedEvent(void)
{
	return this->cpenChangedEvent;
}

const char *GPieSlice::getpercentageChangedEvent(void)
{
	return this->cpercentageChangedEvent;
}

const char *GPieSlice::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GPieSlice::getreleasedEvent(void)
{
	return this->creleasedEvent;
}

const char *GPieSlice::getstartAngleChangedEvent(void)
{
	return this->cstartAngleChangedEvent;
}

const char *GPieSlice::getvalueChangedEvent(void)
{
	return this->cvalueChangedEvent;
}


void GPieSlice::angleSpanChangedSlot()
{
	if (strcmp(this->cangleSpanChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cangleSpanChangedEvent);
}

void GPieSlice::borderColorChangedSlot()
{
	if (strcmp(this->cborderColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cborderColorChangedEvent);
}

void GPieSlice::borderWidthChangedSlot()
{
	if (strcmp(this->cborderWidthChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cborderWidthChangedEvent);
}

void GPieSlice::brushChangedSlot()
{
	if (strcmp(this->cbrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbrushChangedEvent);
}

void GPieSlice::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GPieSlice::colorChangedSlot()
{
	if (strcmp(this->ccolorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccolorChangedEvent);
}

void GPieSlice::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GPieSlice::hoveredSlot()
{
	if (strcmp(this->choveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->choveredEvent);
}

void GPieSlice::labelBrushChangedSlot()
{
	if (strcmp(this->clabelBrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelBrushChangedEvent);
}

void GPieSlice::labelChangedSlot()
{
	if (strcmp(this->clabelChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelChangedEvent);
}

void GPieSlice::labelColorChangedSlot()
{
	if (strcmp(this->clabelColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelColorChangedEvent);
}

void GPieSlice::labelFontChangedSlot()
{
	if (strcmp(this->clabelFontChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelFontChangedEvent);
}

void GPieSlice::labelVisibleChangedSlot()
{
	if (strcmp(this->clabelVisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelVisibleChangedEvent);
}

void GPieSlice::penChangedSlot()
{
	if (strcmp(this->cpenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpenChangedEvent);
}

void GPieSlice::percentageChangedSlot()
{
	if (strcmp(this->cpercentageChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpercentageChangedEvent);
}

void GPieSlice::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GPieSlice::releasedSlot()
{
	if (strcmp(this->creleasedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creleasedEvent);
}

void GPieSlice::startAngleChangedSlot()
{
	if (strcmp(this->cstartAngleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstartAngleChangedEvent);
}

void GPieSlice::valueChangedSlot()
{
	if (strcmp(this->cvalueChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvalueChangedEvent);
}

