
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gabstractsocket.h"

GAbstractSocket::GAbstractSocket(QAbstractSocket::SocketType x,QObject *parent,VM *pVM)  : QAbstractSocket(x,parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cconnectedEvent,"");
	strcpy(this->cdisconnectedEvent,"");
	strcpy(this->cerrorEvent,"");
	strcpy(this->chostFoundEvent,"");
	strcpy(this->cproxyAuthenticationRequiredEvent,"");
	strcpy(this->cstateChangedEvent,"");

	QObject::connect(this, SIGNAL(connected()),this, SLOT(connectedSlot()));
	QObject::connect(this, SIGNAL(disconnected()),this, SLOT(disconnectedSlot()));
	QObject::connect(this, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(hostFound()),this, SLOT(hostFoundSlot()));
	QObject::connect(this, SIGNAL(proxyAuthenticationRequired(QNetworkProxy,QAuthenticator *)),this, SLOT(proxyAuthenticationRequiredSlot()));
	QObject::connect(this, SIGNAL(stateChanged(QAbstractSocket::SocketState)),this, SLOT(stateChangedSlot()));

}

GAbstractSocket::~GAbstractSocket()
{
	ring_list_delete(this->pParaList);
}

void GAbstractSocket::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GAbstractSocket::setconnectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cconnectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractSocket::setdisconnectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdisconnectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractSocket::seterrorEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cerrorEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractSocket::sethostFoundEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->chostFoundEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractSocket::setproxyAuthenticationRequiredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cproxyAuthenticationRequiredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractSocket::setstateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GAbstractSocket::getconnectedEvent(void)
{
	return this->cconnectedEvent;
}

const char *GAbstractSocket::getdisconnectedEvent(void)
{
	return this->cdisconnectedEvent;
}

const char *GAbstractSocket::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GAbstractSocket::gethostFoundEvent(void)
{
	return this->chostFoundEvent;
}

const char *GAbstractSocket::getproxyAuthenticationRequiredEvent(void)
{
	return this->cproxyAuthenticationRequiredEvent;
}

const char *GAbstractSocket::getstateChangedEvent(void)
{
	return this->cstateChangedEvent;
}


void GAbstractSocket::connectedSlot()
{
	if (strcmp(this->cconnectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cconnectedEvent);
}

void GAbstractSocket::disconnectedSlot()
{
	if (strcmp(this->cdisconnectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdisconnectedEvent);
}

void GAbstractSocket::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GAbstractSocket::hostFoundSlot()
{
	if (strcmp(this->chostFoundEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->chostFoundEvent);
}

void GAbstractSocket::proxyAuthenticationRequiredSlot()
{
	if (strcmp(this->cproxyAuthenticationRequiredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cproxyAuthenticationRequiredEvent);
}

void GAbstractSocket::stateChangedSlot()
{
	if (strcmp(this->cstateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstateChangedEvent);
}

