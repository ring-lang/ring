
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gfilesystemwatcher.h"

GFileSystemWatcher::GFileSystemWatcher(QObject *parent,VM *pVM)  : QFileSystemWatcher(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cdirectoryChangedEvent,"");
	strcpy(this->cfileChangedEvent,"");

	QObject::connect(this, SIGNAL(directoryChanged(QString)),this, SLOT(directoryChangedSlot()));
	QObject::connect(this, SIGNAL(fileChanged(QString)),this, SLOT(fileChangedSlot()));

}

GFileSystemWatcher::~GFileSystemWatcher()
{
	ring_list_delete(this->pParaList);
}

void GFileSystemWatcher::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GFileSystemWatcher::setdirectoryChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdirectoryChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GFileSystemWatcher::setfileChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfileChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GFileSystemWatcher::getdirectoryChangedEvent(void)
{
	return this->cdirectoryChangedEvent;
}

const char *GFileSystemWatcher::getfileChangedEvent(void)
{
	return this->cfileChangedEvent;
}


void GFileSystemWatcher::directoryChangedSlot()
{
	if (strcmp(this->cdirectoryChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdirectoryChangedEvent);
}

void GFileSystemWatcher::fileChangedSlot()
{
	if (strcmp(this->cfileChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfileChangedEvent);
}

