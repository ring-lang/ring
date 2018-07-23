
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "giodevice.h"

GIODevice::GIODevice(QObject *parent,VM *pVM)  : QIODevice(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->caboutToCloseEvent,"");
	strcpy(this->cbytesWrittenEvent,"");
	strcpy(this->creadChannelFinishedEvent,"");
	strcpy(this->creadyReadEvent,"");

	QObject::connect(this, SIGNAL(aboutToClose()),this, SLOT(aboutToCloseSlot()));
	QObject::connect(this, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWrittenSlot()));
	QObject::connect(this, SIGNAL(readChannelFinished()),this, SLOT(readChannelFinishedSlot()));
	QObject::connect(this, SIGNAL(readyRead()),this, SLOT(readyReadSlot()));

}

GIODevice::~GIODevice()
{
	ring_list_delete(this->pParaList);
}

void GIODevice::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GIODevice::setaboutToCloseEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->caboutToCloseEvent,cStr);
}

void GIODevice::setbytesWrittenEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cbytesWrittenEvent,cStr);
}

void GIODevice::setreadChannelFinishedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->creadChannelFinishedEvent,cStr);
}

void GIODevice::setreadyReadEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->creadyReadEvent,cStr);
}

 
const char *GIODevice::getaboutToCloseEvent(void)
{
	return this->caboutToCloseEvent;
}

const char *GIODevice::getbytesWrittenEvent(void)
{
	return this->cbytesWrittenEvent;
}

const char *GIODevice::getreadChannelFinishedEvent(void)
{
	return this->creadChannelFinishedEvent;
}

const char *GIODevice::getreadyReadEvent(void)
{
	return this->creadyReadEvent;
}


void GIODevice::aboutToCloseSlot()
{
	if (strcmp(this->caboutToCloseEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->caboutToCloseEvent);
}

void GIODevice::bytesWrittenSlot()
{
	if (strcmp(this->cbytesWrittenEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbytesWrittenEvent);
}

void GIODevice::readChannelFinishedSlot()
{
	if (strcmp(this->creadChannelFinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creadChannelFinishedEvent);
}

void GIODevice::readyReadSlot()
{
	if (strcmp(this->creadyReadEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creadyReadEvent);
}

