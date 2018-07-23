
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gbluetoothdevicediscoveryagent.h"

GBluetoothDeviceDiscoveryAgent::GBluetoothDeviceDiscoveryAgent(QObject *parent,VM *pVM)  : QBluetoothDeviceDiscoveryAgent(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccanceledEvent,"");
	strcpy(this->cdeviceDiscoveredEvent,"");
	strcpy(this->cerrorEvent,"");
	strcpy(this->cfinishedEvent,"");

	QObject::connect(this, SIGNAL(canceled()),this, SLOT(canceledSlot()));
	QObject::connect(this, SIGNAL(deviceDiscovered(const QBluetoothDeviceInfo)),this, SLOT(deviceDiscoveredSlot()));
	QObject::connect(this, SIGNAL(error(QBluetoothDeviceDiscoveryAgent::Error)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(finished()),this, SLOT(finishedSlot()));

}

GBluetoothDeviceDiscoveryAgent::~GBluetoothDeviceDiscoveryAgent()
{
	ring_list_delete(this->pParaList);
}

void GBluetoothDeviceDiscoveryAgent::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GBluetoothDeviceDiscoveryAgent::setcanceledEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccanceledEvent,cStr);
}

void GBluetoothDeviceDiscoveryAgent::setdeviceDiscoveredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cdeviceDiscoveredEvent,cStr);
}

void GBluetoothDeviceDiscoveryAgent::seterrorEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cerrorEvent,cStr);
}

void GBluetoothDeviceDiscoveryAgent::setfinishedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cfinishedEvent,cStr);
}

 
const char *GBluetoothDeviceDiscoveryAgent::getcanceledEvent(void)
{
	return this->ccanceledEvent;
}

const char *GBluetoothDeviceDiscoveryAgent::getdeviceDiscoveredEvent(void)
{
	return this->cdeviceDiscoveredEvent;
}

const char *GBluetoothDeviceDiscoveryAgent::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GBluetoothDeviceDiscoveryAgent::getfinishedEvent(void)
{
	return this->cfinishedEvent;
}


void GBluetoothDeviceDiscoveryAgent::canceledSlot()
{
	if (strcmp(this->ccanceledEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccanceledEvent);
}

void GBluetoothDeviceDiscoveryAgent::deviceDiscoveredSlot()
{
	if (strcmp(this->cdeviceDiscoveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdeviceDiscoveredEvent);
}

void GBluetoothDeviceDiscoveryAgent::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GBluetoothDeviceDiscoveryAgent::finishedSlot()
{
	if (strcmp(this->cfinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfinishedEvent);
}

