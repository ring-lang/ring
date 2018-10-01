
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gprintpreviewdialog.h"

GPrintPreviewDialog::GPrintPreviewDialog(QPrinter *parent,VM *pVM)  : QPrintPreviewDialog(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cpaintRequestedEvent,"");

	QObject::connect(this, SIGNAL(paintRequested(QPrinter *)),this, SLOT(paintRequestedSlot()));

}

GPrintPreviewDialog::~GPrintPreviewDialog()
{
	ring_list_delete(this->pParaList);
}

void GPrintPreviewDialog::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GPrintPreviewDialog::setpaintRequestedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpaintRequestedEvent,cStr);
}

 
const char *GPrintPreviewDialog::getpaintRequestedEvent(void)
{
	return this->cpaintRequestedEvent;
}


void GPrintPreviewDialog::paintRequestedSlot()
{
	if (strcmp(this->cpaintRequestedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpaintRequestedEvent);
}

