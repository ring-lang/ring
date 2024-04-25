
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gcolordialog.h"

GColorDialog::GColorDialog(QWidget *parent,VM *pVM)  : QColorDialog(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccolorSelectedEvent,"");
	strcpy(this->ccurrentColorChangedEvent,"");

	QObject::connect(this, SIGNAL(colorSelected(const QColor)),this, SLOT(colorSelectedSlot()));
	QObject::connect(this, SIGNAL(currentColorChanged(const QColor)),this, SLOT(currentColorChangedSlot()));

}

GColorDialog::~GColorDialog()
{
	ring_list_delete(this->pParaList);
}

void GColorDialog::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GColorDialog::setcolorSelectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccolorSelectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GColorDialog::setcurrentColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GColorDialog::getcolorSelectedEvent(void)
{
	return this->ccolorSelectedEvent;
}

const char *GColorDialog::getcurrentColorChangedEvent(void)
{
	return this->ccurrentColorChangedEvent;
}


void GColorDialog::colorSelectedSlot()
{
	if (strcmp(this->ccolorSelectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccolorSelectedEvent);
}

void GColorDialog::currentColorChangedSlot()
{
	if (strcmp(this->ccurrentColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentColorChangedEvent);
}

