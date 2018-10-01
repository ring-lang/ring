
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gprintdialog.h"

GPrintDialog::GPrintDialog(QPrinter *,QWidget *parent,VM *pVM)  : QPrintDialog(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cacceptedEvent,"");

	QObject::connect(this, SIGNAL(accepted(QPrinter *)),this, SLOT(acceptedSlot()));

}

GPrintDialog::~GPrintDialog()
{
	ring_list_delete(this->pParaList);
}

void GPrintDialog::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GPrintDialog::setacceptedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cacceptedEvent,cStr);
}

 
const char *GPrintDialog::getacceptedEvent(void)
{
	return this->cacceptedEvent;
}


void GPrintDialog::acceptedSlot()
{
	if (strcmp(this->cacceptedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cacceptedEvent);
}

