
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gwebengineview.h"

GWebEngineView::GWebEngineView(QWidget *parent,VM *pVM)  : QWebEngineView(parent)
{
	this->pVM = pVM;
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
 
void GWebEngineView::setloadFinishedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cloadFinishedEvent,cStr);
}

void GWebEngineView::setloadProgressEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cloadProgressEvent,cStr);
}

void GWebEngineView::setloadStartedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cloadStartedEvent,cStr);
}

void GWebEngineView::setselectionChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cselectionChangedEvent,cStr);
}

void GWebEngineView::settitleChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ctitleChangedEvent,cStr);
}

void GWebEngineView::seturlChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->curlChangedEvent,cStr);
}


void GWebEngineView::loadFinishedSlot()
{
	if (strcmp(this->cloadFinishedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cloadFinishedEvent);
}

void GWebEngineView::loadProgressSlot()
{
	if (strcmp(this->cloadProgressEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cloadProgressEvent);
}

void GWebEngineView::loadStartedSlot()
{
	if (strcmp(this->cloadStartedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cloadStartedEvent);
}

void GWebEngineView::selectionChangedSlot()
{
	if (strcmp(this->cselectionChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cselectionChangedEvent);
}

void GWebEngineView::titleChangedSlot()
{
	if (strcmp(this->ctitleChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ctitleChangedEvent);
}

void GWebEngineView::urlChangedSlot()
{
	if (strcmp(this->curlChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->curlChangedEvent);
}

