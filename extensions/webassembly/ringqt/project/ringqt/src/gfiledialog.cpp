
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gfiledialog.h"

GFileDialog::GFileDialog(QWidget *parent,VM *pVM)  : QFileDialog(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccurrentChangedEvent,"");
	strcpy(this->ccurrentUrlChangedEvent,"");
	strcpy(this->cdirectoryEnteredEvent,"");
	strcpy(this->cdirectoryUrlEnteredEvent,"");
	strcpy(this->cfileSelectedEvent,"");
	strcpy(this->cfilesSelectedEvent,"");
	strcpy(this->cfilterSelectedEvent,"");
	strcpy(this->curlSelectedEvent,"");
	strcpy(this->curlsSelectedEvent,"");

	QObject::connect(this, SIGNAL(currentChanged(const QString)),this, SLOT(currentChangedSlot()));
	QObject::connect(this, SIGNAL(currentUrlChanged(const QUrl)),this, SLOT(currentUrlChangedSlot()));
	QObject::connect(this, SIGNAL(directoryEntered(const QString)),this, SLOT(directoryEnteredSlot()));
	QObject::connect(this, SIGNAL(directoryUrlEntered(const QUrl)),this, SLOT(directoryUrlEnteredSlot()));
	QObject::connect(this, SIGNAL(fileSelected(const QString)),this, SLOT(fileSelectedSlot()));
	QObject::connect(this, SIGNAL(filesSelected(const QStringList)),this, SLOT(filesSelectedSlot()));
	QObject::connect(this, SIGNAL(filterSelected(const QString)),this, SLOT(filterSelectedSlot()));
	QObject::connect(this, SIGNAL(urlSelected(const QUrl)),this, SLOT(urlSelectedSlot()));
	QObject::connect(this, SIGNAL(urlsSelected(const QList<QUrl>)),this, SLOT(urlsSelectedSlot()));

}

GFileDialog::~GFileDialog()
{
	ring_list_delete(this->pParaList);
}

void GFileDialog::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GFileDialog::setcurrentChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GFileDialog::setcurrentUrlChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentUrlChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GFileDialog::setdirectoryEnteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdirectoryEnteredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GFileDialog::setdirectoryUrlEnteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdirectoryUrlEnteredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GFileDialog::setfileSelectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfileSelectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GFileDialog::setfilesSelectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfilesSelectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GFileDialog::setfilterSelectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfilterSelectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GFileDialog::seturlSelectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->curlSelectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GFileDialog::seturlsSelectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->curlsSelectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GFileDialog::getcurrentChangedEvent(void)
{
	return this->ccurrentChangedEvent;
}

const char *GFileDialog::getcurrentUrlChangedEvent(void)
{
	return this->ccurrentUrlChangedEvent;
}

const char *GFileDialog::getdirectoryEnteredEvent(void)
{
	return this->cdirectoryEnteredEvent;
}

const char *GFileDialog::getdirectoryUrlEnteredEvent(void)
{
	return this->cdirectoryUrlEnteredEvent;
}

const char *GFileDialog::getfileSelectedEvent(void)
{
	return this->cfileSelectedEvent;
}

const char *GFileDialog::getfilesSelectedEvent(void)
{
	return this->cfilesSelectedEvent;
}

const char *GFileDialog::getfilterSelectedEvent(void)
{
	return this->cfilterSelectedEvent;
}

const char *GFileDialog::geturlSelectedEvent(void)
{
	return this->curlSelectedEvent;
}

const char *GFileDialog::geturlsSelectedEvent(void)
{
	return this->curlsSelectedEvent;
}


void GFileDialog::currentChangedSlot()
{
	if (strcmp(this->ccurrentChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentChangedEvent);
}

void GFileDialog::currentUrlChangedSlot()
{
	if (strcmp(this->ccurrentUrlChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccurrentUrlChangedEvent);
}

void GFileDialog::directoryEnteredSlot()
{
	if (strcmp(this->cdirectoryEnteredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdirectoryEnteredEvent);
}

void GFileDialog::directoryUrlEnteredSlot()
{
	if (strcmp(this->cdirectoryUrlEnteredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdirectoryUrlEnteredEvent);
}

void GFileDialog::fileSelectedSlot()
{
	if (strcmp(this->cfileSelectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfileSelectedEvent);
}

void GFileDialog::filesSelectedSlot()
{
	if (strcmp(this->cfilesSelectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfilesSelectedEvent);
}

void GFileDialog::filterSelectedSlot()
{
	if (strcmp(this->cfilterSelectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfilterSelectedEvent);
}

void GFileDialog::urlSelectedSlot()
{
	if (strcmp(this->curlSelectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->curlSelectedEvent);
}

void GFileDialog::urlsSelectedSlot()
{
	if (strcmp(this->curlsSelectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->curlsSelectedEvent);
}

