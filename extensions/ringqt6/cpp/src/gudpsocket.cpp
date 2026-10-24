
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gudpsocket.h"

GUdpSocket::GUdpSocket(QObject *parent,VM *pVM)  : QUdpSocket(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cconnectedEvent,"");
	strcpy(this->cdisconnectedEvent,"");
	strcpy(this->cerrorEvent,"");
	strcpy(this->chostFoundEvent,"");
	strcpy(this->cstateChangedEvent,"");
	strcpy(this->creadyReadEvent,"");

	QObject::connect(this, SIGNAL(connected()),this, SLOT(connectedSlot()));
	QObject::connect(this, SIGNAL(disconnected()),this, SLOT(disconnectedSlot()));
	QObject::connect(this, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(hostFound()),this, SLOT(hostFoundSlot()));
	QObject::connect(this, SIGNAL(stateChanged(QAbstractSocket::SocketState)),this, SLOT(stateChangedSlot()));
	QObject::connect(this, SIGNAL(readyRead()),this, SLOT(readyReadSlot()));

}

GUdpSocket::~GUdpSocket()
{
	ring_list_delete(this->pParaList);
}

void GUdpSocket::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GUdpSocket::setconnectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cconnectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GUdpSocket::setdisconnectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdisconnectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GUdpSocket::seterrorEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cerrorEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GUdpSocket::sethostFoundEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->chostFoundEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GUdpSocket::setstateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GUdpSocket::setreadyReadEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creadyReadEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GUdpSocket::getconnectedEvent(void)
{
	return this->cconnectedEvent;
}

const char *GUdpSocket::getdisconnectedEvent(void)
{
	return this->cdisconnectedEvent;
}

const char *GUdpSocket::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GUdpSocket::gethostFoundEvent(void)
{
	return this->chostFoundEvent;
}

const char *GUdpSocket::getstateChangedEvent(void)
{
	return this->cstateChangedEvent;
}

const char *GUdpSocket::getreadyReadEvent(void)
{
	return this->creadyReadEvent;
}


void GUdpSocket::connectedSlot()
{
	if (strcmp(this->cconnectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cconnectedEvent);
}

void GUdpSocket::disconnectedSlot()
{
	if (strcmp(this->cdisconnectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdisconnectedEvent);
}

void GUdpSocket::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GUdpSocket::hostFoundSlot()
{
	if (strcmp(this->chostFoundEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->chostFoundEvent);
}

void GUdpSocket::stateChangedSlot()
{
	if (strcmp(this->cstateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstateChangedEvent);
}

void GUdpSocket::readyReadSlot()
{
	if (strcmp(this->creadyReadEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creadyReadEvent);
}

