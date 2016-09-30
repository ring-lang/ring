
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gprogressbar.h"

GProgressBar::GProgressBar(QWidget *parent,VM *pVM)  : QProgressBar(parent)
{
	this->pVM = pVM;
	strcpy(this->cvalueChangedEvent,"");

	QObject::connect(this, SIGNAL(valueChanged(int)),this, SLOT(valueChangedSlot()));

}
 
void GProgressBar::setvalueChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cvalueChangedEvent,cStr);
}


void GProgressBar::valueChangedSlot()
{
	if (strcmp(this->cvalueChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cvalueChangedEvent);
}

