
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gsslsocket.h"

GSslSocket::GSslSocket(QObject *parent,VM *pVM)  : QSslSocket(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cencryptedEvent,"");
	strcpy(this->cencryptedBytesWrittenEvent,"");
	strcpy(this->cmodeChangedEvent,"");
	strcpy(this->cpeerVerifyErrorEvent,"");
	strcpy(this->csslErrorsEvent,"");

	QObject::connect(this, SIGNAL(encrypted()),this, SLOT(encryptedSlot()));
	QObject::connect(this, SIGNAL(encryptedBytesWritten(qint64)),this, SLOT(encryptedBytesWrittenSlot()));
	QObject::connect(this, SIGNAL(modeChanged(QSslSocket::SslMode)),this, SLOT(modeChangedSlot()));
	QObject::connect(this, SIGNAL(peerVerifyError(QSslError)),this, SLOT(peerVerifyErrorSlot()));
	QObject::connect(this, SIGNAL(sslErrors(QList<QSslError>)),this, SLOT(sslErrorsSlot()));

}

GSslSocket::~GSslSocket()
{
	ring_list_delete(this->pParaList);
}

void GSslSocket::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GSslSocket::setencryptedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cencryptedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSslSocket::setencryptedBytesWrittenEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cencryptedBytesWrittenEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSslSocket::setmodeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmodeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSslSocket::setpeerVerifyErrorEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpeerVerifyErrorEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSslSocket::setsslErrorsEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csslErrorsEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GSslSocket::getencryptedEvent(void)
{
	return this->cencryptedEvent;
}

const char *GSslSocket::getencryptedBytesWrittenEvent(void)
{
	return this->cencryptedBytesWrittenEvent;
}

const char *GSslSocket::getmodeChangedEvent(void)
{
	return this->cmodeChangedEvent;
}

const char *GSslSocket::getpeerVerifyErrorEvent(void)
{
	return this->cpeerVerifyErrorEvent;
}

const char *GSslSocket::getsslErrorsEvent(void)
{
	return this->csslErrorsEvent;
}


void GSslSocket::encryptedSlot()
{
	if (strcmp(this->cencryptedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cencryptedEvent);
}

void GSslSocket::encryptedBytesWrittenSlot()
{
	if (strcmp(this->cencryptedBytesWrittenEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cencryptedBytesWrittenEvent);
}

void GSslSocket::modeChangedSlot()
{
	if (strcmp(this->cmodeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmodeChangedEvent);
}

void GSslSocket::peerVerifyErrorSlot()
{
	if (strcmp(this->cpeerVerifyErrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpeerVerifyErrorEvent);
}

void GSslSocket::sslErrorsSlot()
{
	if (strcmp(this->csslErrorsEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csslErrorsEvent);
}

