
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gcolordialog.h"

GColorDialog::GColorDialog(QWidget *parent,VM *pVM)  : QColorDialog(parent)
{
	this->pVM = pVM;
	strcpy(this->ccolorSelectedEvent,"");
	strcpy(this->ccurrentColorChangedEvent,"");

	QObject::connect(this, SIGNAL(colorSelected(QColor)),this, SLOT(colorSelectedSlot()));
	QObject::connect(this, SIGNAL(currentColorChanged(QColor)),this, SLOT(currentColorChangedSlot()));

}
 
void GColorDialog::setcolorSelectedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccolorSelectedEvent,cStr);
}

void GColorDialog::setcurrentColorChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccurrentColorChangedEvent,cStr);
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

