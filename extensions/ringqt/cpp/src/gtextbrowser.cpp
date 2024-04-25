
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtextbrowser.h"

GTextBrowser::GTextBrowser(QWidget *parent,VM *pVM)  : QTextBrowser(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->canchorClickedEvent,"");
	strcpy(this->cbackwardAvailableEvent,"");
	strcpy(this->cforwardAvailableEvent,"");
	strcpy(this->chighlightedEvent,"");
	strcpy(this->chistoryChangedEvent,"");
	strcpy(this->csourceChangedEvent,"");

	QObject::connect(this, SIGNAL(anchorClicked(const QUrl)),this, SLOT(anchorClickedSlot()));
	QObject::connect(this, SIGNAL(backwardAvailable(bool)),this, SLOT(backwardAvailableSlot()));
	QObject::connect(this, SIGNAL(forwardAvailable(bool)),this, SLOT(forwardAvailableSlot()));
	QObject::connect(this, SIGNAL(highlighted(const QString)),this, SLOT(highlightedSlot()));
	QObject::connect(this, SIGNAL(historyChanged()),this, SLOT(historyChangedSlot()));
	QObject::connect(this, SIGNAL(sourceChanged(const QUrl)),this, SLOT(sourceChangedSlot()));

}

GTextBrowser::~GTextBrowser()
{
	ring_list_delete(this->pParaList);
}

void GTextBrowser::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GTextBrowser::setanchorClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->canchorClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTextBrowser::setbackwardAvailableEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbackwardAvailableEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTextBrowser::setforwardAvailableEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cforwardAvailableEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTextBrowser::sethighlightedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->chighlightedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTextBrowser::sethistoryChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->chistoryChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTextBrowser::setsourceChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csourceChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GTextBrowser::getanchorClickedEvent(void)
{
	return this->canchorClickedEvent;
}

const char *GTextBrowser::getbackwardAvailableEvent(void)
{
	return this->cbackwardAvailableEvent;
}

const char *GTextBrowser::getforwardAvailableEvent(void)
{
	return this->cforwardAvailableEvent;
}

const char *GTextBrowser::gethighlightedEvent(void)
{
	return this->chighlightedEvent;
}

const char *GTextBrowser::gethistoryChangedEvent(void)
{
	return this->chistoryChangedEvent;
}

const char *GTextBrowser::getsourceChangedEvent(void)
{
	return this->csourceChangedEvent;
}


void GTextBrowser::anchorClickedSlot()
{
	if (strcmp(this->canchorClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->canchorClickedEvent);
}

void GTextBrowser::backwardAvailableSlot()
{
	if (strcmp(this->cbackwardAvailableEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbackwardAvailableEvent);
}

void GTextBrowser::forwardAvailableSlot()
{
	if (strcmp(this->cforwardAvailableEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cforwardAvailableEvent);
}

void GTextBrowser::highlightedSlot()
{
	if (strcmp(this->chighlightedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->chighlightedEvent);
}

void GTextBrowser::historyChangedSlot()
{
	if (strcmp(this->chistoryChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->chistoryChangedEvent);
}

void GTextBrowser::sourceChangedSlot()
{
	if (strcmp(this->csourceChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csourceChangedEvent);
}

