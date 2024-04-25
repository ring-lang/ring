
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "glineedit.h"

GLineEdit::GLineEdit(QWidget *parent,VM *pVM)  : QLineEdit(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cTextChangedEvent,"");
	strcpy(this->ccursorPositionChangedEvent,"");
	strcpy(this->ceditingFinishedEvent,"");
	strcpy(this->creturnPressedEvent,"");
	strcpy(this->cselectionChangedEvent,"");
	strcpy(this->ctextEditedEvent,"");

	QObject::connect(this, SIGNAL(textChanged(QString)),this, SLOT(textChangedSlot()));
	QObject::connect(this, SIGNAL(cursorPositionChanged(int,int)),this, SLOT(cursorPositionChangedSlot()));
	QObject::connect(this, SIGNAL(editingFinished()),this, SLOT(editingFinishedSlot()));
	QObject::connect(this, SIGNAL(returnPressed()),this, SLOT(returnPressedSlot()));
	QObject::connect(this, SIGNAL(selectionChanged()),this, SLOT(selectionChangedSlot()));
	QObject::connect(this, SIGNAL(textEdited(QString)),this, SLOT(textEditedSlot()));

}

GLineEdit::~GLineEdit()
{
	ring_list_delete(this->pParaList);
}

void GLineEdit::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GLineEdit::setTextChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cTextChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLineEdit::setcursorPositionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccursorPositionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLineEdit::seteditingFinishedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ceditingFinishedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLineEdit::setreturnPressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creturnPressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLineEdit::setselectionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cselectionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GLineEdit::settextEditedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctextEditedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GLineEdit::getTextChangedEvent(void)
{
	return this->cTextChangedEvent;
}

const char *GLineEdit::getcursorPositionChangedEvent(void)
{
	return this->ccursorPositionChangedEvent;
}

const char *GLineEdit::geteditingFinishedEvent(void)
{
	return this->ceditingFinishedEvent;
}

const char *GLineEdit::getreturnPressedEvent(void)
{
	return this->creturnPressedEvent;
}

const char *GLineEdit::getselectionChangedEvent(void)
{
	return this->cselectionChangedEvent;
}

const char *GLineEdit::gettextEditedEvent(void)
{
	return this->ctextEditedEvent;
}


void GLineEdit::textChangedSlot()
{
	if (strcmp(this->cTextChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cTextChangedEvent);
}

void GLineEdit::cursorPositionChangedSlot()
{
	if (strcmp(this->ccursorPositionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccursorPositionChangedEvent);
}

void GLineEdit::editingFinishedSlot()
{
	if (strcmp(this->ceditingFinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ceditingFinishedEvent);
}

void GLineEdit::returnPressedSlot()
{
	if (strcmp(this->creturnPressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creturnPressedEvent);
}

void GLineEdit::selectionChangedSlot()
{
	if (strcmp(this->cselectionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cselectionChangedEvent);
}

void GLineEdit::textEditedSlot()
{
	if (strcmp(this->ctextEditedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctextEditedEvent);
}

