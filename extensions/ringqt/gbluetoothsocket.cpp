
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gbluetoothsocket.h"

GBluetoothSocket::GBluetoothSocket(QBluetoothServiceInfo::Protocol x,QObject *parent,VM *pVM)  : QBluetoothSocket(x,parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cconnectedEvent,"");
	strcpy(this->cdisconnectedEvent,"");
	strcpy(this->cerrorEvent,"");
	strcpy(this->cstateChangedEvent,"");

	QObject::connect(this, SIGNAL(connected()),this, SLOT(connectedSlot()));
	QObject::connect(this, SIGNAL(disconnected()),this, SLOT(disconnectedSlot()));
	QObject::connect(this, SIGNAL(error(QBluetoothSocket::SocketError)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(stateChanged(QBluetoothSocket::SocketState)),this, SLOT(stateChangedSlot()));

}

GBluetoothSocket::~GBluetoothSocket()
{
	ring_list_delete(this->pParaList);
}

void GBluetoothSocket::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GBluetoothSocket::setconnectedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cconnectedEvent,cStr);
}

void GBluetoothSocket::setdisconnectedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cdisconnectedEvent,cStr);
}

void GBluetoothSocket::seterrorEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cerrorEvent,cStr);
}

void GBluetoothSocket::setstateChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cstateChangedEvent,cStr);
}

 
const char *GBluetoothSocket::getconnectedEvent(void)
{
	return this->cconnectedEvent;
}

const char *GBluetoothSocket::getdisconnectedEvent(void)
{
	return this->cdisconnectedEvent;
}

const char *GBluetoothSocket::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GBluetoothSocket::getstateChangedEvent(void)
{
	return this->cstateChangedEvent;
}


void GBluetoothSocket::connectedSlot()
{
	if (strcmp(this->cconnectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cconnectedEvent);
}

void GBluetoothSocket::disconnectedSlot()
{
	if (strcmp(this->cdisconnectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdisconnectedEvent);
}

void GBluetoothSocket::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GBluetoothSocket::stateChangedSlot()
{
	if (strcmp(this->cstateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstateChangedEvent);
}

