
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gwizardpage.h"

GWizardPage::GWizardPage(QWidget *parent,VM *pVM)  : QWizardPage(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccompleteChangedEvent,"");

	QObject::connect(this, SIGNAL(completeChanged()),this, SLOT(completeChangedSlot()));

}

GWizardPage::~GWizardPage()
{
	ring_list_delete(this->pParaList);
}

void GWizardPage::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GWizardPage::setcompleteChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccompleteChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GWizardPage::getcompleteChangedEvent(void)
{
	return this->ccompleteChangedEvent;
}


void GWizardPage::completeChangedSlot()
{
	if (strcmp(this->ccompleteChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccompleteChangedEvent);
}

