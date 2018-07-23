
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtextedit.h"

GTextEdit::GTextEdit(QWidget *parent,VM *pVM)  : QTextEdit(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccopyAvailableEvent,"");
	strcpy(this->ccurrentCharFormatChangedEvent,"");
	strcpy(this->ccursorPositionChangedEvent,"");
	strcpy(this->credoAvailableEvent,"");
	strcpy(this->cselectionChangedEvent,"");
	strcpy(this->ctextChangedEvent,"");
	strcpy(this->cundoAvailableEvent,"");

	QObject::connect(this, SIGNAL(copyAvailable(bool)),this, SLOT(copyAvailableSlot()));
	QObject::connect(this, SIGNAL(currentCharFormatChanged(QTextCharFormat)),this, SLOT(currentCharFormatChangedSlot()));
	QObject::connect(this, SIGNAL(cursorPositionChanged()),this, SLOT(cursorPositionChangedSlot()));
	QObject::connect(this, SIGNAL(redoAvailable(bool)),this, SLOT(redoAvailableSlot()));
	QObject::connect(this, SIGNAL(selectionChanged()),this, SLOT(selectionChanged()));
	QObject::connect(this, SIGNAL(textChanged()),this, SLOT(textChangedSlot()));
	QObject::connect(this, SIGNAL(undoAvailable(bool)),this, SLOT(undoAvailableSlot()));

}

GTextEdit::~GTextEdit()
{
	ring_list_delete(this->pParaList);
}

void GTextEdit::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GTextEdit::setcopyAvailableEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccopyAvailableEvent,cStr);
}

void GTextEdit::setcurrentCharFormatChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccurrentCharFormatChangedEvent,cStr);
}

void GTextEdit::setcursorPositionChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccursorPositionChangedEvent,cStr);
}

void GTextEdit::setredoAvailableEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->credoAvailableEvent,cStr);
}

void GTextEdit::setselectionChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cselectionChangedEvent,cStr);
}

void GTextEdit::settextChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ctextChangedEvent,cStr);
}

void GTextEdit::setundoAvailableEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cundoAvailableEvent,cStr);
}

 
const char *GTextEdit::getcopyAvailableEvent(void)
{
	return this->ccopyAvailableEvent;
}

const char *GTextEdit::getcurrentCharFormatChangedEvent(void)
{
	return this->ccurrentCharFormatChangedEvent;
}

const char *GTextEdit::getcursorPositionChangedEvent(void)
{
	return this->ccursorPositionChangedEvent;
}

const char *GTextEdit::getredoAvailableEvent(void)
{
	return this->credoAvailableEvent;
}

const char *GTextEdit::getselectionChangedEvent(void)
{
	return this->cselectionChangedEvent;
}

const char *GTextEdit::gettextChangedEvent(void)
{
	return this->ctextChangedEvent;
}

const char *GTextEdit::getundoAvailableEvent(void)
{
	return this->cundoAvailableEvent;
}


void GTextEdit::copyAvailableSlot()
{
	if (strcmp(this->ccopyAvailableEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccopyAvailableEvent);
}

void GTextEdit::currentCharFormatChangedSlot()
{
	if (strcmp(this->ccurrentCharFormatChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentCharFormatChangedEvent);
}

void GTextEdit::cursorPositionChangedSlot()
{
	if (strcmp(this->ccursorPositionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccursorPositionChangedEvent);
}

void GTextEdit::redoAvailableSlot()
{
	if (strcmp(this->credoAvailableEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->credoAvailableEvent);
}

void GTextEdit::selectionChanged()
{
	if (strcmp(this->cselectionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cselectionChangedEvent);
}

void GTextEdit::textChangedSlot()
{
	if (strcmp(this->ctextChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctextChangedEvent);
}

void GTextEdit::undoAvailableSlot()
{
	if (strcmp(this->cundoAvailableEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cundoAvailableEvent);
}

