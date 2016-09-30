
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "giodevice.h"

GIODevice::GIODevice(QObject *parent,VM *pVM)  : QIODevice(parent)
{
	this->pVM = pVM;
	strcpy(this->caboutToCloseEvent,"");
	strcpy(this->cbytesWrittenEvent,"");
	strcpy(this->creadChannelFinishedEvent,"");
	strcpy(this->creadyReadEvent,"");

	QObject::connect(this, SIGNAL(aboutToClose()),this, SLOT(aboutToCloseSlot()));
	QObject::connect(this, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWrittenSlot()));
	QObject::connect(this, SIGNAL(readChannelFinished()),this, SLOT(readChannelFinishedSlot()));
	QObject::connect(this, SIGNAL(readyRead()),this, SLOT(readyReadSlot()));

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

