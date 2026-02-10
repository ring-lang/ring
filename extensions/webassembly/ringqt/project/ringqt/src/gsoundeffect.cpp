
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gsoundeffect.h"

GSoundEffect::GSoundEffect(QObject *parent,VM *pVM)  : QSoundEffect(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccategoryChangedEvent,"");
	strcpy(this->cloadedChangedEvent,"");
	strcpy(this->cloopCountChangedEvent,"");
	strcpy(this->cloopsRemainingChangedEvent,"");
	strcpy(this->cmutedChangedEvent,"");
	strcpy(this->cplayingChangedEvent,"");
	strcpy(this->csourceChangedEvent,"");
	strcpy(this->cstatusChangedEvent,"");
	strcpy(this->cvolumeChangedEvent,"");

	QObject::connect(this, SIGNAL(categoryChanged()),this, SLOT(categoryChangedSlot()));
	QObject::connect(this, SIGNAL(loadedChanged()),this, SLOT(loadedChangedSlot()));
	QObject::connect(this, SIGNAL(loopCountChanged()),this, SLOT(loopCountChangedSlot()));
	QObject::connect(this, SIGNAL(loopsRemainingChanged()),this, SLOT(loopsRemainingChangedSlot()));
	QObject::connect(this, SIGNAL(mutedChanged()),this, SLOT(mutedChangedSlot()));
	QObject::connect(this, SIGNAL(playingChanged()),this, SLOT(playingChangedSlot()));
	QObject::connect(this, SIGNAL(sourceChanged()),this, SLOT(sourceChangedSlot()));
	QObject::connect(this, SIGNAL(statusChanged()),this, SLOT(statusChangedSlot()));
	QObject::connect(this, SIGNAL(volumeChanged()),this, SLOT(volumeChangedSlot()));

}

GSoundEffect::~GSoundEffect()
{
	ring_list_delete(this->pParaList);
}

void GSoundEffect::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GSoundEffect::setcategoryChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccategoryChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSoundEffect::setloadedChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cloadedChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSoundEffect::setloopCountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cloopCountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSoundEffect::setloopsRemainingChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cloopsRemainingChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSoundEffect::setmutedChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmutedChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSoundEffect::setplayingChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cplayingChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSoundEffect::setsourceChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csourceChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSoundEffect::setstatusChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstatusChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSoundEffect::setvolumeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvolumeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GSoundEffect::getcategoryChangedEvent(void)
{
	return this->ccategoryChangedEvent;
}

const char *GSoundEffect::getloadedChangedEvent(void)
{
	return this->cloadedChangedEvent;
}

const char *GSoundEffect::getloopCountChangedEvent(void)
{
	return this->cloopCountChangedEvent;
}

const char *GSoundEffect::getloopsRemainingChangedEvent(void)
{
	return this->cloopsRemainingChangedEvent;
}

const char *GSoundEffect::getmutedChangedEvent(void)
{
	return this->cmutedChangedEvent;
}

const char *GSoundEffect::getplayingChangedEvent(void)
{
	return this->cplayingChangedEvent;
}

const char *GSoundEffect::getsourceChangedEvent(void)
{
	return this->csourceChangedEvent;
}

const char *GSoundEffect::getstatusChangedEvent(void)
{
	return this->cstatusChangedEvent;
}

const char *GSoundEffect::getvolumeChangedEvent(void)
{
	return this->cvolumeChangedEvent;
}


void GSoundEffect::categoryChangedSlot()
{
	if (strcmp(this->ccategoryChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccategoryChangedEvent);
}

void GSoundEffect::loadedChangedSlot()
{
	if (strcmp(this->cloadedChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cloadedChangedEvent);
}

void GSoundEffect::loopCountChangedSlot()
{
	if (strcmp(this->cloopCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cloopCountChangedEvent);
}

void GSoundEffect::loopsRemainingChangedSlot()
{
	if (strcmp(this->cloopsRemainingChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cloopsRemainingChangedEvent);
}

void GSoundEffect::mutedChangedSlot()
{
	if (strcmp(this->cmutedChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmutedChangedEvent);
}

void GSoundEffect::playingChangedSlot()
{
	if (strcmp(this->cplayingChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cplayingChangedEvent);
}

void GSoundEffect::sourceChangedSlot()
{
	if (strcmp(this->csourceChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csourceChangedEvent);
}

void GSoundEffect::statusChangedSlot()
{
	if (strcmp(this->cstatusChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstatusChangedEvent);
}

void GSoundEffect::volumeChangedSlot()
{
	if (strcmp(this->cvolumeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvolumeChangedEvent);
}

