
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
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

	QObject::connect(this, SIGNAL(blockCountChanged(int)),this, SLOT(blockCountChangedSlot()));
	QObject::connect(this, SIGNAL(copyAvailable(bool)),this, SLOT(copyAvailableSlot()));
	QObject::connect(this, SIGNAL(cursorPositionChanged()),this, SLOT(cursorPositionChangedSlot()));
	QObject::connect(this, SIGNAL(modificationChanged(bool)),this, SLOT(modificationChangedSlot()));
	QObject::connect(this, SIGNAL(redoAvailable(bool)),this, SLOT(redoAvailableSlot()));
	QObject::connect(this, SIGNAL(selectionChanged()),this, SLOT(selectionChanged()));
	QObject::connect(this, SIGNAL(textChanged()),this, SLOT(textChangedSlot()));
	QObject::connect(this, SIGNAL(undoAvailable(bool)),this, SLOT(undoAvailableSlot()));
	QObject::connect(this, SIGNAL(updateRequest(const QRect, int)),this, SLOT(updateRequestSlot()));

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
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cblockCountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPlainTextEdit::setcopyAvailableEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccopyAvailableEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPlainTextEdit::setcursorPositionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccursorPositionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPlainTextEdit::setmodificationChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmodificationChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPlainTextEdit::setredoAvailableEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->credoAvailableEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPlainTextEdit::setselectionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cselectionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPlainTextEdit::settextChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctextChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPlainTextEdit::setundoAvailableEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cundoAvailableEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GPlainTextEdit::setupdateRequestEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cupdateRequestEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GPlainTextEdit::getblockCountChangedEvent(void)
{
	return this->cblockCountChangedEvent;
}

const char *GPlainTextEdit::getcopyAvailableEvent(void)
{
	return this->ccopyAvailableEvent;
}

const char *GPlainTextEdit::getcursorPositionChangedEvent(void)
{
	return this->ccursorPositionChangedEvent;
}

const char *GPlainTextEdit::getmodificationChangedEvent(void)
{
	return this->cmodificationChangedEvent;
}

const char *GPlainTextEdit::getredoAvailableEvent(void)
{
	return this->credoAvailableEvent;
}

const char *GPlainTextEdit::getselectionChangedEvent(void)
{
	return this->cselectionChangedEvent;
}

const char *GPlainTextEdit::gettextChangedEvent(void)
{
	return this->ctextChangedEvent;
}

const char *GPlainTextEdit::getundoAvailableEvent(void)
{
	return this->cundoAvailableEvent;
}

const char *GPlainTextEdit::getupdateRequestEvent(void)
{
	return this->cupdateRequestEvent;
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

