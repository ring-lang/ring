
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gbluetoothtransferreply.h"

GBluetoothTransferReply::GBluetoothTransferReply(QObject *parent,VM *pVM)  : QBluetoothTransferReply(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cerrorEvent,"");
	strcpy(this->cfinishedEvent,"");
	strcpy(this->ctransferProgressEvent,"");

	QObject::connect(this, SIGNAL(error(QBluetoothTransferReply::TransferError)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(finished(QBluetoothTransferReply *)),this, SLOT(finishedSlot()));
	QObject::connect(this, SIGNAL(transferProgress(qint64,qint64)),this, SLOT(transferProgressSlot()));

}

GBluetoothTransferReply::~GBluetoothTransferReply()
{
	ring_list_delete(this->pParaList);
}

void GBluetoothTransferReply::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GBluetoothTransferReply::seterrorEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cerrorEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBluetoothTransferReply::setfinishedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfinishedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBluetoothTransferReply::settransferProgressEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctransferProgressEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GBluetoothTransferReply::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GBluetoothTransferReply::getfinishedEvent(void)
{
	return this->cfinishedEvent;
}

const char *GBluetoothTransferReply::gettransferProgressEvent(void)
{
	return this->ctransferProgressEvent;
}


void GBluetoothTransferReply::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GBluetoothTransferReply::finishedSlot()
{
	if (strcmp(this->cfinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfinishedEvent);
}

void GBluetoothTransferReply::transferProgressSlot()
{
	if (strcmp(this->ctransferProgressEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctransferProgressEvent);
}

