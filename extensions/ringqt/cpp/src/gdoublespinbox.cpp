
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gdoublespinbox.h"

GDoubleSpinBox::GDoubleSpinBox(QWidget *parent,VM *pVM)  : QDoubleSpinBox(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cvalueChangedEvent,"");

	QObject::connect(this, SIGNAL(valueChanged(double)),this, SLOT(valueChangedSlot()));

}

GDoubleSpinBox::~GDoubleSpinBox()
{
	ring_list_delete(this->pParaList);
}

void GDoubleSpinBox::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GDoubleSpinBox::setvalueChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvalueChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GDoubleSpinBox::getvalueChangedEvent(void)
{
	return this->cvalueChangedEvent;
}


void GDoubleSpinBox::valueChangedSlot()
{
	if (strcmp(this->cvalueChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvalueChangedEvent);
}

