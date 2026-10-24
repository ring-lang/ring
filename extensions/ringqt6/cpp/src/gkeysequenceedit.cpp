
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gkeysequenceedit.h"

GKeySequenceEdit::GKeySequenceEdit(QWidget *parent,VM *pVM)  : QKeySequenceEdit(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ceditingFinishedEvent,"");
	strcpy(this->ckeySequenceChangedEvent,"");

	QObject::connect(this, SIGNAL(editingFinished()),this, SLOT(editingFinishedSlot()));
	QObject::connect(this, SIGNAL(keySequenceChanged(QKeySequence)),this, SLOT(keySequenceChangedSlot()));

}

GKeySequenceEdit::~GKeySequenceEdit()
{
	ring_list_delete(this->pParaList);
}

void GKeySequenceEdit::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GKeySequenceEdit::seteditingFinishedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ceditingFinishedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GKeySequenceEdit::setkeySequenceChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ckeySequenceChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GKeySequenceEdit::geteditingFinishedEvent(void)
{
	return this->ceditingFinishedEvent;
}

const char *GKeySequenceEdit::getkeySequenceChangedEvent(void)
{
	return this->ckeySequenceChangedEvent;
}


void GKeySequenceEdit::editingFinishedSlot()
{
	if (strcmp(this->ceditingFinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ceditingFinishedEvent);
}

void GKeySequenceEdit::keySequenceChangedSlot()
{
	if (strcmp(this->ckeySequenceChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ckeySequenceChangedEvent);
}

