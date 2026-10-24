
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gprogressdialog.h"

GProgressDialog::GProgressDialog(QWidget *parent,VM *pVM)  : QProgressDialog(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccanceledEvent,"");

	QObject::connect(this, SIGNAL(canceled()),this, SLOT(canceledSlot()));

}

GProgressDialog::~GProgressDialog()
{
	ring_list_delete(this->pParaList);
}

void GProgressDialog::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GProgressDialog::setcanceledEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccanceledEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GProgressDialog::getcanceledEvent(void)
{
	return this->ccanceledEvent;
}


void GProgressDialog::canceledSlot()
{
	if (strcmp(this->ccanceledEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccanceledEvent);
}

