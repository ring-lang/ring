
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtcpsocket.h"

GTcpSocket::GTcpSocket(QObject *parent,VM *pVM)  : QTcpSocket(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cconnectedEvent,"");
	strcpy(this->cdisconnectedEvent,"");
	strcpy(this->cerrorEvent,"");
	strcpy(this->chostFoundEvent,"");
	strcpy(this->cproxyAuthenticationRequiredEvent,"");
	strcpy(this->cstateChangedEvent,"");
	strcpy(this->caboutToCloseEvent,"");
	strcpy(this->cbytesWrittenEvent,"");
	strcpy(this->creadChannelFinishedEvent,"");
	strcpy(this->creadyReadEvent,"");

	QObject::connect(this, SIGNAL(connected()),this, SLOT(connectedSlot()));
	QObject::connect(this, SIGNAL(disconnected()),this, SLOT(disconnectedSlot()));
	QObject::connect(this, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(hostFound()),this, SLOT(hostFoundSlot()));
	QObject::connect(this, SIGNAL(proxyAuthenticationRequired(QNetworkProxy,QAuthenticator *)),this, SLOT(proxyAuthenticationRequiredSlot()));
	QObject::connect(this, SIGNAL(stateChanged(QAbstractSocket::SocketState)),this, SLOT(stateChangedSlot()));
	QObject::connect(this, SIGNAL(aboutToClose()),this, SLOT(aboutToCloseSlot()));
	QObject::connect(this, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWrittenSlot()));
	QObject::connect(this, SIGNAL(readChannelFinished()),this, SLOT(readChannelFinishedSlot()));
	QObject::connect(this, SIGNAL(readyRead()),this, SLOT(readyReadSlot()));

}

GTcpSocket::~GTcpSocket()
{
	ring_list_delete(this->pParaList);
}

void GTcpSocket::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GTcpSocket::setconnectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cconnectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTcpSocket::setdisconnectedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdisconnectedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTcpSocket::seterrorEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cerrorEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTcpSocket::sethostFoundEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->chostFoundEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTcpSocket::setproxyAuthenticationRequiredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cproxyAuthenticationRequiredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTcpSocket::setstateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTcpSocket::setaboutToCloseEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->caboutToCloseEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTcpSocket::setbytesWrittenEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbytesWrittenEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTcpSocket::setreadChannelFinishedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creadChannelFinishedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTcpSocket::setreadyReadEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creadyReadEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GTcpSocket::getconnectedEvent(void)
{
	return this->cconnectedEvent;
}

const char *GTcpSocket::getdisconnectedEvent(void)
{
	return this->cdisconnectedEvent;
}

const char *GTcpSocket::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GTcpSocket::gethostFoundEvent(void)
{
	return this->chostFoundEvent;
}

const char *GTcpSocket::getproxyAuthenticationRequiredEvent(void)
{
	return this->cproxyAuthenticationRequiredEvent;
}

const char *GTcpSocket::getstateChangedEvent(void)
{
	return this->cstateChangedEvent;
}

const char *GTcpSocket::getaboutToCloseEvent(void)
{
	return this->caboutToCloseEvent;
}

const char *GTcpSocket::getbytesWrittenEvent(void)
{
	return this->cbytesWrittenEvent;
}

const char *GTcpSocket::getreadChannelFinishedEvent(void)
{
	return this->creadChannelFinishedEvent;
}

const char *GTcpSocket::getreadyReadEvent(void)
{
	return this->creadyReadEvent;
}


void GTcpSocket::connectedSlot()
{
	if (strcmp(this->cconnectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cconnectedEvent);
}

void GTcpSocket::disconnectedSlot()
{
	if (strcmp(this->cdisconnectedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdisconnectedEvent);
}

void GTcpSocket::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GTcpSocket::hostFoundSlot()
{
	if (strcmp(this->chostFoundEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->chostFoundEvent);
}

void GTcpSocket::proxyAuthenticationRequiredSlot()
{
	if (strcmp(this->cproxyAuthenticationRequiredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cproxyAuthenticationRequiredEvent);
}

void GTcpSocket::stateChangedSlot()
{
	if (strcmp(this->cstateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstateChangedEvent);
}

void GTcpSocket::aboutToCloseSlot()
{
	if (strcmp(this->caboutToCloseEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->caboutToCloseEvent);
}

void GTcpSocket::bytesWrittenSlot()
{
	if (strcmp(this->cbytesWrittenEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbytesWrittenEvent);
}

void GTcpSocket::readChannelFinishedSlot()
{
	if (strcmp(this->creadChannelFinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creadChannelFinishedEvent);
}

void GTcpSocket::readyReadSlot()
{
	if (strcmp(this->creadyReadEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creadyReadEvent);
}

