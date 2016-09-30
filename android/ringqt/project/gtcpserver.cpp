
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtcpserver.h"

GTcpServer::GTcpServer(QObject *parent,VM *pVM)  : QTcpServer(parent)
{
	this->pVM = pVM;
	strcpy(this->cacceptErrorEvent,"");
	strcpy(this->cnewConnectionEvent,"");

	QObject::connect(this, SIGNAL(acceptError(QAbstractSocket::SocketError)),this, SLOT(acceptErrorSlot()));
	QObject::connect(this, SIGNAL(newConnection()),this, SLOT(newConnectionSlot()));

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

