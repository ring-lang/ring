
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gnetworkaccessmanager.h"

GNetworkAccessManager::GNetworkAccessManager(QObject *parent,VM *pVM)  : QNetworkAccessManager(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cfinishedEvent,"");

	QObject::connect(this, SIGNAL(finished(QNetworkReply*)),this, SLOT(finishedSlot(QNetworkReply*)));

}

GNetworkAccessManager::~GNetworkAccessManager()
{
	ring_list_delete(this->pParaList);
}

void GNetworkAccessManager::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GNetworkAccessManager::setfinishedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfinishedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GNetworkAccessManager::getfinishedEvent(void)
{
	return this->cfinishedEvent;
}


void GNetworkAccessManager::finishedSlot(QNetworkReply *p1)
{
	if (strcmp(this->cfinishedEvent,"")==0)
		return ;

		ring_list_deleteallitems(this->pParaList);
		ring_list_addcpointer(this->pParaList, p1, "QNetworkReply *" ) ;	
	
	ring_vm_runcode(this->pVM,this->cfinishedEvent);
}

