
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gnetworkaccessmanager.h"

GNetworkAccessManager::GNetworkAccessManager(QObject *parent,VM *pVM)  : QNetworkAccessManager(parent)
{
	this->pVM = pVM;
	strcpy(this->cfinishedEvent,"");

	QObject::connect(this, SIGNAL(finished(QNetworkReply*)),this, SLOT(finishedSlot(QNetworkReply*)));

}
 
void GNetworkAccessManager::setfinishedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cfinishedEvent,cStr);
}


void GNetworkAccessManager::finishedSlot(QNetworkReply *pReply)
{
	List *pVar;
	List *pList  ;
	void *pPointer;
	List *pActiveMem;
	VM *pVM;
	pPointer = (void *) this->pVM;

	if (strcmp(this->cfinishedEvent,"")==0)
		return ;

	this->pVM->pRingState->pVM = this->pVM ;

	pActiveMem = this->pVM->pActiveMem;
	this->pVM->pActiveMem = ring_list_getlist(this->pVM->pMem,1);
	pVar = ring_state_newvar(this->pVM->pRingState,"preply");

	this->pVM->pActiveMem = pActiveMem ;

	/* Create the list */
	pList = ring_list_new(0) ;
	/* The variable value will be a list contains the pointer */
	ring_list_addpointer(pList,pReply);
	/* Add the pointer type */
	ring_list_addstring(pList,"QNetworkReply");
	/* Add the status number ( 0 = Not Copied ,1 = Copied  2 = Not Assigned yet) */
	ring_list_addint(pList,2);


	ring_list_setint(pVar,RING_VAR_TYPE,RING_VM_LIST);
	ring_list_setlist(pVar,RING_VAR_VALUE);
	pVar = ring_list_getlist(pVar,RING_VAR_VALUE);
	ring_list_copy(pVar,pList);

	
	ring_vm_runcode(this->pVM,this->cfinishedEvent);
}

