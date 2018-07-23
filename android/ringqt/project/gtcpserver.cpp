
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtcpserver.h"

GTcpServer::GTcpServer(QObject *parent,VM *pVM)  : QTcpServer(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cacceptErrorEvent,"");
	strcpy(this->cnewConnectionEvent,"");

	QObject::connect(this, SIGNAL(acceptError(QAbstractSocket::SocketError)),this, SLOT(acceptErrorSlot()));
	QObject::connect(this, SIGNAL(newConnection()),this, SLOT(newConnectionSlot()));

}

GTcpServer::~GTcpServer()
{
	ring_list_delete(this->pParaList);
}

void GTcpServer::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GTcpServer::setacceptErrorEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cacceptErrorEvent,cStr);
}

void GTcpServer::setnewConnectionEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cnewConnectionEvent,cStr);
}

 
const char *GTcpServer::getacceptErrorEvent(void)
{
	return this->cacceptErrorEvent;
}

const char *GTcpServer::getnewConnectionEvent(void)
{
	return this->cnewConnectionEvent;
}


void GTcpServer::acceptErrorSlot()
{
	if (strcmp(this->cacceptErrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cacceptErrorEvent);
}

void GTcpServer::newConnectionSlot()
{
	if (strcmp(this->cnewConnectionEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cnewConnectionEvent);
}

