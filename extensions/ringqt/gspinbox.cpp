
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gspinbox.h"

GSpinBox::GSpinBox(QWidget *parent,VM *pVM)  : QSpinBox(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cvalueChangedEvent,"");

	QObject::connect(this, SIGNAL(valueChanged(int)),this, SLOT(valueChangedSlot()));

}

GSpinBox::~GSpinBox()
{
	ring_list_delete(this->pParaList);
}

void GSpinBox::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GSpinBox::setvalueChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cvalueChangedEvent,cStr);
}


void GSpinBox::valueChangedSlot()
{
	if (strcmp(this->cvalueChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvalueChangedEvent);
}

