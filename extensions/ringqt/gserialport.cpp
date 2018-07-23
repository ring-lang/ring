
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gserialport.h"

GSerialPort::GSerialPort(QObject *parent,VM *pVM)  : QSerialPort(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cbaudRateChangedEvent,"");
	strcpy(this->cbreakEnabledChangedEvent,"");
	strcpy(this->cdataBitsChangedEvent,"");
	strcpy(this->cdataTerminalReadyChangedEvent,"");
	strcpy(this->cerrorEvent,"");
	strcpy(this->cflowControlChangedEvent,"");
	strcpy(this->cparityChangedEvent,"");
	strcpy(this->crequestToSendChangedEvent,"");
	strcpy(this->cstopBitsChangedEvent,"");

	QObject::connect(this, SIGNAL(baudRateChanged(qint32,QSerialPort::Directions)),this, SLOT(baudRateChangedSlot()));
	QObject::connect(this, SIGNAL(breakEnabledChanged(bool)),this, SLOT(breakEnabledChangedSlot()));
	QObject::connect(this, SIGNAL(dataBitsChanged(QSerialPort::DataBits)),this, SLOT(dataBitsChangedSlot()));
	QObject::connect(this, SIGNAL(dataTerminalReadyChanged(bool)),this, SLOT(dataTerminalReadyChangedSlot()));
	QObject::connect(this, SIGNAL(error(QSerialPort::SerialPortError)),this, SLOT(errorSlot()));
	QObject::connect(this, SIGNAL(flowControlChanged(QSerialPort::FlowControl)),this, SLOT(flowControlChangedSlot()));
	QObject::connect(this, SIGNAL(parityChanged(QSerialPort::Parity)),this, SLOT(parityChangedSlot()));
	QObject::connect(this, SIGNAL(requestToSendChanged(bool)),this, SLOT(requestToSendChangedSlot()));
	QObject::connect(this, SIGNAL(stopBitsChanged(QSerialPort::StopBits)),this, SLOT(stopBitsChangedSlot()));

}

GSerialPort::~GSerialPort()
{
	ring_list_delete(this->pParaList);
}

void GSerialPort::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GSerialPort::setbaudRateChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cbaudRateChangedEvent,cStr);
}

void GSerialPort::setbreakEnabledChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cbreakEnabledChangedEvent,cStr);
}

void GSerialPort::setdataBitsChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cdataBitsChangedEvent,cStr);
}

void GSerialPort::setdataTerminalReadyChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cdataTerminalReadyChangedEvent,cStr);
}

void GSerialPort::seterrorEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cerrorEvent,cStr);
}

void GSerialPort::setflowControlChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cflowControlChangedEvent,cStr);
}

void GSerialPort::setparityChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cparityChangedEvent,cStr);
}

void GSerialPort::setrequestToSendChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->crequestToSendChangedEvent,cStr);
}

void GSerialPort::setstopBitsChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cstopBitsChangedEvent,cStr);
}

 
const char *GSerialPort::getbaudRateChangedEvent(void)
{
	return this->cbaudRateChangedEvent;
}

const char *GSerialPort::getbreakEnabledChangedEvent(void)
{
	return this->cbreakEnabledChangedEvent;
}

const char *GSerialPort::getdataBitsChangedEvent(void)
{
	return this->cdataBitsChangedEvent;
}

const char *GSerialPort::getdataTerminalReadyChangedEvent(void)
{
	return this->cdataTerminalReadyChangedEvent;
}

const char *GSerialPort::geterrorEvent(void)
{
	return this->cerrorEvent;
}

const char *GSerialPort::getflowControlChangedEvent(void)
{
	return this->cflowControlChangedEvent;
}

const char *GSerialPort::getparityChangedEvent(void)
{
	return this->cparityChangedEvent;
}

const char *GSerialPort::getrequestToSendChangedEvent(void)
{
	return this->crequestToSendChangedEvent;
}

const char *GSerialPort::getstopBitsChangedEvent(void)
{
	return this->cstopBitsChangedEvent;
}


void GSerialPort::baudRateChangedSlot()
{
	if (strcmp(this->cbaudRateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbaudRateChangedEvent);
}

void GSerialPort::breakEnabledChangedSlot()
{
	if (strcmp(this->cbreakEnabledChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbreakEnabledChangedEvent);
}

void GSerialPort::dataBitsChangedSlot()
{
	if (strcmp(this->cdataBitsChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdataBitsChangedEvent);
}

void GSerialPort::dataTerminalReadyChangedSlot()
{
	if (strcmp(this->cdataTerminalReadyChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cdataTerminalReadyChangedEvent);
}

void GSerialPort::errorSlot()
{
	if (strcmp(this->cerrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cerrorEvent);
}

void GSerialPort::flowControlChangedSlot()
{
	if (strcmp(this->cflowControlChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cflowControlChangedEvent);
}

void GSerialPort::parityChangedSlot()
{
	if (strcmp(this->cparityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cparityChangedEvent);
}

void GSerialPort::requestToSendChangedSlot()
{
	if (strcmp(this->crequestToSendChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crequestToSendChangedEvent);
}

void GSerialPort::stopBitsChangedSlot()
{
	if (strcmp(this->cstopBitsChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstopBitsChangedEvent);
}

