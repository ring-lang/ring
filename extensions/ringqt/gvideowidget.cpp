
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gvideowidget.h"

GVideoWidget::GVideoWidget(QWidget *parent,VM *pVM)  : QVideoWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cbrightnessChangedEvent,"");
	strcpy(this->ccontrastChangedEvent,"");
	strcpy(this->cfullScreenChangedEvent,"");
	strcpy(this->chueChangedEvent,"");
	strcpy(this->csaturationChangedEvent,"");

	QObject::connect(this, SIGNAL(brightnessChanged(int)),this, SLOT(brightnessChangedSlot()));
	QObject::connect(this, SIGNAL(contrastChanged(int)),this, SLOT(contrastChangedSlot()));
	QObject::connect(this, SIGNAL(fullScreenChanged(bool)),this, SLOT(fullScreenChangedSlot()));
	QObject::connect(this, SIGNAL(hueChanged(int)),this, SLOT(hueChangedSlot()));
	QObject::connect(this, SIGNAL(saturationChanged(int)),this, SLOT(saturationChangedSlot()));

}

GVideoWidget::~GVideoWidget()
{
	ring_list_delete(this->pParaList);
}

void GVideoWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GVideoWidget::setbrightnessChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cbrightnessChangedEvent,cStr);
}

void GVideoWidget::setcontrastChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccontrastChangedEvent,cStr);
}

void GVideoWidget::setfullScreenChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cfullScreenChangedEvent,cStr);
}

void GVideoWidget::sethueChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->chueChangedEvent,cStr);
}

void GVideoWidget::setsaturationChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csaturationChangedEvent,cStr);
}

 
const char *GVideoWidget::getbrightnessChangedEvent(void)
{
	return this->cbrightnessChangedEvent;
}

const char *GVideoWidget::getcontrastChangedEvent(void)
{
	return this->ccontrastChangedEvent;
}

const char *GVideoWidget::getfullScreenChangedEvent(void)
{
	return this->cfullScreenChangedEvent;
}

const char *GVideoWidget::gethueChangedEvent(void)
{
	return this->chueChangedEvent;
}

const char *GVideoWidget::getsaturationChangedEvent(void)
{
	return this->csaturationChangedEvent;
}


void GVideoWidget::brightnessChangedSlot()
{
	if (strcmp(this->cbrightnessChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbrightnessChangedEvent);
}

void GVideoWidget::contrastChangedSlot()
{
	if (strcmp(this->ccontrastChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccontrastChangedEvent);
}

void GVideoWidget::fullScreenChangedSlot()
{
	if (strcmp(this->cfullScreenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfullScreenChangedEvent);
}

void GVideoWidget::hueChangedSlot()
{
	if (strcmp(this->chueChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->chueChangedEvent);
}

void GVideoWidget::saturationChangedSlot()
{
	if (strcmp(this->csaturationChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csaturationChangedEvent);
}

