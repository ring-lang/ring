
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gprogressbar.h"

GProgressBar::GProgressBar(QWidget *parent,VM *pVM)  : QProgressBar(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cvalueChangedEvent,"");

	QObject::connect(this, SIGNAL(valueChanged(int)),this, SLOT(valueChangedSlot()));

}

GProgressBar::~GProgressBar()
{
	ring_list_delete(this->pParaList);
}

void GProgressBar::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GProgressBar::setvalueChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvalueChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GProgressBar::getvalueChangedEvent(void)
{
	return this->cvalueChangedEvent;
}


void GProgressBar::valueChangedSlot()
{
	if (strcmp(this->cvalueChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvalueChangedEvent);
}

