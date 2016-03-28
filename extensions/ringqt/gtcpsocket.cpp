
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtcpsocket.h"

GTcpSocket::GTcpSocket(QObject *parent,VM *pVM)  : QTcpSocket(parent)
{
	this->pVM = pVM;
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
 
void GTcpSocket::setconnectedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cconnectedEvent,cStr);
}

void GTcpSocket::setdisconnectedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cdisconnectedEvent,cStr);
}

void GTcpSocket::seterrorEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cerrorEvent,cStr);
}

void GTcpSocket::sethostFoundEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->chostFoundEvent,cStr);
}

void GTcpSocket::setproxyAuthenticationRequiredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cproxyAuthenticationRequiredEvent,cStr);
}

void GTcpSocket::setstateChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cstateChangedEvent,cStr);
}

void GTcpSocket::setaboutToCloseEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->caboutToCloseEvent,cStr);
}

void GTcpSocket::setbytesWrittenEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cbytesWrittenEvent,cStr);
}

void GTcpSocket::setreadChannelFinishedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->creadChannelFinishedEvent,cStr);
}

void GTcpSocket::setreadyReadEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->creadyReadEvent,cStr);
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

