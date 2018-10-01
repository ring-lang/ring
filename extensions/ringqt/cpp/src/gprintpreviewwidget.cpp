
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gprintpreviewwidget.h"

GPrintPreviewWidget::GPrintPreviewWidget(QPrinter *parent,VM *pVM)  : QPrintPreviewWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cpaintRequestedEvent,"");
	strcpy(this->cpreviewChangedEvent,"");

	QObject::connect(this, SIGNAL(paintRequested(QPrinter *)),this, SLOT(paintRequestedSlot()));
	QObject::connect(this, SIGNAL(previewChanged()),this, SLOT(previewChangedSlot()));

}

GPrintPreviewWidget::~GPrintPreviewWidget()
{
	ring_list_delete(this->pParaList);
}

void GPrintPreviewWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GPrintPreviewWidget::setpaintRequestedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpaintRequestedEvent,cStr);
}

void GPrintPreviewWidget::setpreviewChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpreviewChangedEvent,cStr);
}

 
const char *GPrintPreviewWidget::getpaintRequestedEvent(void)
{
	return this->cpaintRequestedEvent;
}

const char *GPrintPreviewWidget::getpreviewChangedEvent(void)
{
	return this->cpreviewChangedEvent;
}


void GPrintPreviewWidget::paintRequestedSlot()
{
	if (strcmp(this->cpaintRequestedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpaintRequestedEvent);
}

void GPrintPreviewWidget::previewChangedSlot()
{
	if (strcmp(this->cpreviewChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpreviewChangedEvent);
}

