
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gwebview.h"

GWebView::GWebView(QWidget *parent,VM *pVM)  : QWebView(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cloadFinishedEvent,"");
	strcpy(this->cloadProgressEvent,"");
	strcpy(this->cloadStartedEvent,"");
	strcpy(this->cselectionChangedEvent,"");
	strcpy(this->ctitleChangedEvent,"");
	strcpy(this->curlChangedEvent,"");

	QObject::connect(this, SIGNAL(loadFinished(bool)),this, SLOT(loadFinishedSlot()));
	QObject::connect(this, SIGNAL(loadProgress(int)),this, SLOT(loadProgressSlot()));
	QObject::connect(this, SIGNAL(loadStarted()),this, SLOT(loadStartedSlot()));
	QObject::connect(this, SIGNAL(selectionChanged()),this, SLOT(selectionChangedSlot()));
	QObject::connect(this, SIGNAL(titleChanged(QString)),this, SLOT(titleChangedSlot()));
	QObject::connect(this, SIGNAL(urlChanged(QUrl)),this, SLOT(urlChangedSlot()));

}

GWebView::~GWebView()
{
	ring_list_delete(this->pParaList);
}

void GWebView::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GWebView::setloadFinishedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cloadFinishedEvent,cStr);
}

void GWebView::setloadProgressEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cloadProgressEvent,cStr);
}

void GWebView::setloadStartedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cloadStartedEvent,cStr);
}

void GWebView::setselectionChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cselectionChangedEvent,cStr);
}

void GWebView::settitleChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ctitleChangedEvent,cStr);
}

void GWebView::seturlChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->curlChangedEvent,cStr);
}

 
const char *GWebView::getloadFinishedEvent(void)
{
	return this->cloadFinishedEvent;
}

const char *GWebView::getloadProgressEvent(void)
{
	return this->cloadProgressEvent;
}

const char *GWebView::getloadStartedEvent(void)
{
	return this->cloadStartedEvent;
}

const char *GWebView::getselectionChangedEvent(void)
{
	return this->cselectionChangedEvent;
}

const char *GWebView::gettitleChangedEvent(void)
{
	return this->ctitleChangedEvent;
}

const char *GWebView::geturlChangedEvent(void)
{
	return this->curlChangedEvent;
}


void GWebView::loadFinishedSlot()
{
	if (strcmp(this->cloadFinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cloadFinishedEvent);
}

void GWebView::loadProgressSlot()
{
	if (strcmp(this->cloadProgressEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cloadProgressEvent);
}

void GWebView::loadStartedSlot()
{
	if (strcmp(this->cloadStartedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cloadStartedEvent);
}

void GWebView::selectionChangedSlot()
{
	if (strcmp(this->cselectionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cselectionChangedEvent);
}

void GWebView::titleChangedSlot()
{
	if (strcmp(this->ctitleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctitleChangedEvent);
}

void GWebView::urlChangedSlot()
{
	if (strcmp(this->curlChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->curlChangedEvent);
}

