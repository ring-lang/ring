
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gbluetoothtransfermanager.h"

GBluetoothTransferManager::GBluetoothTransferManager(QObject *parent,VM *pVM)  : QBluetoothTransferManager(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cfinishedEvent,"");

	QObject::connect(this, SIGNAL(finished(QBluetoothTransferReply *)),this, SLOT(finishedSlot()));

}

GBluetoothTransferManager::~GBluetoothTransferManager()
{
	ring_list_delete(this->pParaList);
}

void GBluetoothTransferManager::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GBluetoothTransferManager::setfinishedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cfinishedEvent,cStr);
}

 
const char *GBluetoothTransferManager::getfinishedEvent(void)
{
	return this->cfinishedEvent;
}


void GBluetoothTransferManager::finishedSlot()
{
	if (strcmp(this->cfinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfinishedEvent);
}

