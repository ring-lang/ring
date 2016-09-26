
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gplaintextedit.h"

GPlainTextEdit::GPlainTextEdit(QWidget *parent,VM *pVM)  : QPlainTextEdit(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cblockCountChangedEvent,"");
	strcpy(this->ccopyAvailableEvent,"");
	strcpy(this->ccursorPositionChangedEvent,"");
	strcpy(this->cmodificationChangedEvent,"");
	strcpy(this->credoAvailableEvent,"");
	strcpy(this->cselectionChangedEvent,"");
	strcpy(this->ctextChangedEvent,"");
	strcpy(this->cundoAvailableEvent,"");
	strcpy(this->cupdateRequestEvent,"");

	QObject::connect(this, SIGNAL(blockCountChanged(int newBlockCount)),this, SLOT(blockCountChangedSlot()));
	QObject::connect(this, SIGNAL(copyAvailable(bool)),this, SLOT(copyAvailableSlot()));
	QObject::connect(this, SIGNAL(cursorPositionChanged()),this, SLOT(cursorPositionChangedSlot()));
	QObject::connect(this, SIGNAL(modificationChanged(bool changed)),this, SLOT(modificationChangedSlot()));
	QObject::connect(this, SIGNAL(redoAvailable(bool)),this, SLOT(redoAvailableSlot()));
	QObject::connect(this, SIGNAL(selectionChanged()),this, SLOT(selectionChanged()));
	QObject::connect(this, SIGNAL(textChanged()),this, SLOT(textChangedSlot()));
	QObject::connect(this, SIGNAL(undoAvailable(bool)),this, SLOT(undoAvailableSlot()));
	QObject::connect(this, SIGNAL(updateRequest(const QRect &rect, int dy)),this, SLOT(updateRequestSlot()));

}

GPlainTextEdit::~GPlainTextEdit()
{
	ring_list_delete(this->pParaList);
}

void GPlainTextEdit::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GPlainTextEdit::setblockCountChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cblockCountChangedEvent,cStr);
}

void GPlainTextEdit::setcopyAvailableEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccopyAvailableEvent,cStr);
}

void GPlainTextEdit::setcursorPositionChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccursorPositionChangedEvent,cStr);
}

void GPlainTextEdit::setmodificationChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cmodificationChangedEvent,cStr);
}

void GPlainTextEdit::setredoAvailableEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->credoAvailableEvent,cStr);
}

void GPlainTextEdit::setselectionChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cselectionChangedEvent,cStr);
}

void GPlainTextEdit::settextChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ctextChangedEvent,cStr);
}

void GPlainTextEdit::setundoAvailableEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cundoAvailableEvent,cStr);
}

void GPlainTextEdit::setupdateRequestEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cupdateRequestEvent,cStr);
}


void GPlainTextEdit::blockCountChangedSlot()
{
	if (strcmp(this->cblockCountChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cblockCountChangedEvent);
}

void GPlainTextEdit::copyAvailableSlot()
{
	if (strcmp(this->ccopyAvailableEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ccopyAvailableEvent);
}

void GPlainTextEdit::cursorPositionChangedSlot()
{
	if (strcmp(this->ccursorPositionChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ccursorPositionChangedEvent);
}

void GPlainTextEdit::modificationChangedSlot()
{
	if (strcmp(this->cmodificationChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cmodificationChangedEvent);
}

void GPlainTextEdit::redoAvailableSlot()
{
	if (strcmp(this->credoAvailableEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->credoAvailableEvent);
}

void GPlainTextEdit::selectionChanged()
{
	if (strcmp(this->cselectionChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cselectionChangedEvent);
}

void GPlainTextEdit::textChangedSlot()
{
	if (strcmp(this->ctextChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ctextChangedEvent);
}

void GPlainTextEdit::undoAvailableSlot()
{
	if (strcmp(this->cundoAvailableEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cundoAvailableEvent);
}

void GPlainTextEdit::updateRequestSlot()
{
	if (strcmp(this->cupdateRequestEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cupdateRequestEvent);
}

