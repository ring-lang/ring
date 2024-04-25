
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gbluetoothlocaldevice.h"

GBluetoothLocalDevice::GBluetoothLocalDevice(QObject *parent,VM *pVM)  : QBluetoothLocalDevice(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cdeviceConnectedEvent,"");
	strcpy(this->cdeviceDisconnectedEvent,"");
	strcpy(this->cerrorEvent,"");
	strcpy(this->chostModeStateChangedEvent,"");
	strcpy(this->cpairingDisplayConfirmationEvent,"");
	strcpy(this->cpairingDisplayPinCodeEvent,"");
	strcpy(this->cpairingFinishedEvent,"");

	QObject::connect(this, SIGNAL(deviceConnected(const QBluetoothAddress)),this, SLOT(deviceConnectedSlot()));
	QObject::connect(this, SIGNAL(deviceDisconnected(const QBluetoothAddress)),this, SLOT(deviceDisconnectedSlot()));
	QObject::connect(this, SIGNAL(error(QBluetoothLocalDevice::Error)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(hostModeStateChanged(QBluetoothLocalDevice::HostMode)),this, SLOT(hostModeStateChangedSlot()));
	QObject::connect(this, SIGNAL(pairingDisplayConfirmation(const QBluetoothAddress,QString)),this, SLOT(pairingDisplayConfirmationSlot()));
	QObject::connect(this, SIGNAL(pairingDisplayPinCode(const QBluetoothAddress,QString)),this, SLOT(pairingDisplayPinCodeSlot()));
	QObject::connect(this, SIGNAL(pairingFinished(const QBluetoothAddress,QBluetoothLocalDevice::Pairing)),this, SLOT(pairingFinishedSlot()));

}

GBluetoothLocalDevice::~GBluetoothLocalDevice()
{
	ring_list_delete(this->pParaList);
}

void GBluetoothLocalDevice::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GBluetoothLocalDevice::setdeviceConnectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdeviceConnectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBluetoothLocalDevice::setdeviceDisconnectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdeviceDisconnectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBluetoothLocalDevice::seterrorEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cerrorEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBluetoothLocalDevice::sethostModeStateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->chostModeStateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBluetoothLocalDevice::setpairingDisplayConfirmationEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpairingDisplayConfirmationEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBluetoothLocalDevice::setpairingDisplayPinCodeEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpairingDisplayPinCodeEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GBluetoothLocalDevice::setpairingFinishedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpairingFinishedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GBluetoothLocalDevice::getdeviceConnectedEvent(void)
{
	return this->cdeviceConnectedEvent;
}

const char *GBluetoothLocalDevice::getdeviceDisconnectedEvent(void)
{
	return this->cdeviceDisconnectedEvent;
}

const char *GBluetoothLocalDevice::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GBluetoothLocalDevice::gethostModeStateChangedEvent(void)
{
	return this->chostModeStateChangedEvent;
}

const char *GBluetoothLocalDevice::getpairingDisplayConfirmationEvent(void)
{
	return this->cpairingDisplayConfirmationEvent;
}

const char *GBluetoothLocalDevice::getpairingDisplayPinCodeEvent(void)
{
	return this->cpairingDisplayPinCodeEvent;
}

const char *GBluetoothLocalDevice::getpairingFinishedEvent(void)
{
	return this->cpairingFinishedEvent;
}


void GBluetoothLocalDevice::deviceConnectedSlot()
{
	if (strcmp(this->cdeviceConnectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdeviceConnectedEvent);
}

void GBluetoothLocalDevice::deviceDisconnectedSlot()
{
	if (strcmp(this->cdeviceDisconnectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdeviceDisconnectedEvent);
}

void GBluetoothLocalDevice::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GBluetoothLocalDevice::hostModeStateChangedSlot()
{
	if (strcmp(this->chostModeStateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->chostModeStateChangedEvent);
}

void GBluetoothLocalDevice::pairingDisplayConfirmationSlot()
{
	if (strcmp(this->cpairingDisplayConfirmationEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpairingDisplayConfirmationEvent);
}

void GBluetoothLocalDevice::pairingDisplayPinCodeSlot()
{
	if (strcmp(this->cpairingDisplayPinCodeEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpairingDisplayPinCodeEvent);
}

void GBluetoothLocalDevice::pairingFinishedSlot()
{
	if (strcmp(this->cpairingFinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpairingFinishedEvent);
}

