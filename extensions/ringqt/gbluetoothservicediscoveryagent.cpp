
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gbluetoothservicediscoveryagent.h"

GBluetoothServiceDiscoveryAgent::GBluetoothServiceDiscoveryAgent(QObject *parent,VM *pVM)  : QBluetoothServiceDiscoveryAgent(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccanceledEvent,"");
	strcpy(this->cerrorEvent,"");
	strcpy(this->cfinishedEvent,"");
	strcpy(this->cserviceDiscoveredEvent,"");

	QObject::connect(this, SIGNAL(canceled()),this, SLOT(canceledSlot()));
	QObject::connect(this, SIGNAL(error(QBluetoothServiceDiscoveryAgent::Error)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(finished()),this, SLOT(finishedSlot()));
	QObject::connect(this, SIGNAL(serviceDiscovered(const QBluetoothServiceInfo)),this, SLOT(serviceDiscoveredSlot()));

}

GBluetoothServiceDiscoveryAgent::~GBluetoothServiceDiscoveryAgent()
{
	ring_list_delete(this->pParaList);
}

void GBluetoothServiceDiscoveryAgent::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GBluetoothServiceDiscoveryAgent::setcanceledEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccanceledEvent,cStr);
}

void GBluetoothServiceDiscoveryAgent::seterrorEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cerrorEvent,cStr);
}

void GBluetoothServiceDiscoveryAgent::setfinishedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cfinishedEvent,cStr);
}

void GBluetoothServiceDiscoveryAgent::setserviceDiscoveredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cserviceDiscoveredEvent,cStr);
}

 
const char *GBluetoothServiceDiscoveryAgent::getcanceledEvent(void)
{
	return this->ccanceledEvent;
}

const char *GBluetoothServiceDiscoveryAgent::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GBluetoothServiceDiscoveryAgent::getfinishedEvent(void)
{
	return this->cfinishedEvent;
}

const char *GBluetoothServiceDiscoveryAgent::getserviceDiscoveredEvent(void)
{
	return this->cserviceDiscoveredEvent;
}


void GBluetoothServiceDiscoveryAgent::canceledSlot()
{
	if (strcmp(this->ccanceledEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccanceledEvent);
}

void GBluetoothServiceDiscoveryAgent::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GBluetoothServiceDiscoveryAgent::finishedSlot()
{
	if (strcmp(this->cfinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfinishedEvent);
}

void GBluetoothServiceDiscoveryAgent::serviceDiscoveredSlot()
{
	if (strcmp(this->cserviceDiscoveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cserviceDiscoveredEvent);
}

