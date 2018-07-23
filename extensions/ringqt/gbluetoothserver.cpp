
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gbluetoothserver.h"

GBluetoothServer::GBluetoothServer(QBluetoothServiceInfo::Protocol x,QObject *parent,VM *pVM)  : QBluetoothServer(x,parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cerrorEvent,"");
	strcpy(this->cnewConnectionEvent,"");

	QObject::connect(this, SIGNAL(error(QBluetoothServer::Error)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(newConnection()),this, SLOT(newConnectionSlot()));

}

GBluetoothServer::~GBluetoothServer()
{
	ring_list_delete(this->pParaList);
}

void GBluetoothServer::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GBluetoothServer::seterrorEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cerrorEvent,cStr);
}

void GBluetoothServer::setnewConnectionEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cnewConnectionEvent,cStr);
}

 
const char *GBluetoothServer::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GBluetoothServer::getnewConnectionEvent(void)
{
	return this->cnewConnectionEvent;
}


void GBluetoothServer::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GBluetoothServer::newConnectionSlot()
{
	if (strcmp(this->cnewConnectionEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cnewConnectionEvent);
}

