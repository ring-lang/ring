
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gnetworkconfigurationmanager.h"

GNetworkConfigurationManager::GNetworkConfigurationManager(QObject *parent,VM *pVM)  : QNetworkConfigurationManager(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cconfigurationAddedEvent,"");
	strcpy(this->cconfigurationChangedEvent,"");
	strcpy(this->cconfigurationRemovedEvent,"");
	strcpy(this->conlineStateChangedEvent,"");
	strcpy(this->cupdateCompletedEvent,"");

	QObject::connect(this, SIGNAL(configurationAdded(QNetworkConfiguration)),this, SLOT(configurationAddedSlot()));
	QObject::connect(this, SIGNAL(configurationChanged(QNetworkConfiguration)),this, SLOT(configurationChangedSlot()));
	QObject::connect(this, SIGNAL(configurationRemoved(QNetworkConfiguration)),this, SLOT(configurationRemovedSlot()));
	QObject::connect(this, SIGNAL(onlineStateChanged(bool)),this, SLOT(onlineStateChangedSlot()));
	QObject::connect(this, SIGNAL(updateCompleted()),this, SLOT(updateCompletedSlot()));

}

GNetworkConfigurationManager::~GNetworkConfigurationManager()
{
	ring_list_delete(this->pParaList);
}

void GNetworkConfigurationManager::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GNetworkConfigurationManager::setconfigurationAddedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cconfigurationAddedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GNetworkConfigurationManager::setconfigurationChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cconfigurationChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GNetworkConfigurationManager::setconfigurationRemovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cconfigurationRemovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GNetworkConfigurationManager::setonlineStateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->conlineStateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GNetworkConfigurationManager::setupdateCompletedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cupdateCompletedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GNetworkConfigurationManager::getconfigurationAddedEvent(void)
{
	return this->cconfigurationAddedEvent;
}

const char *GNetworkConfigurationManager::getconfigurationChangedEvent(void)
{
	return this->cconfigurationChangedEvent;
}

const char *GNetworkConfigurationManager::getconfigurationRemovedEvent(void)
{
	return this->cconfigurationRemovedEvent;
}

const char *GNetworkConfigurationManager::getonlineStateChangedEvent(void)
{
	return this->conlineStateChangedEvent;
}

const char *GNetworkConfigurationManager::getupdateCompletedEvent(void)
{
	return this->cupdateCompletedEvent;
}


void GNetworkConfigurationManager::configurationAddedSlot()
{
	if (strcmp(this->cconfigurationAddedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cconfigurationAddedEvent);
}

void GNetworkConfigurationManager::configurationChangedSlot()
{
	if (strcmp(this->cconfigurationChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cconfigurationChangedEvent);
}

void GNetworkConfigurationManager::configurationRemovedSlot()
{
	if (strcmp(this->cconfigurationRemovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cconfigurationRemovedEvent);
}

void GNetworkConfigurationManager::onlineStateChangedSlot()
{
	if (strcmp(this->conlineStateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->conlineStateChangedEvent);
}

void GNetworkConfigurationManager::updateCompletedSlot()
{
	if (strcmp(this->cupdateCompletedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cupdateCompletedEvent);
}

