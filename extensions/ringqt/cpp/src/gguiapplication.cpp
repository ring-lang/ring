
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gguiapplication.h"

GGuiApplication::GGuiApplication(int argc,char **parent,VM *pVM)  : QGuiApplication(argc,parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->capplicationDisplayNameChangedEvent,"");
	strcpy(this->capplicationStateChangedEvent,"");
	strcpy(this->ccommitDataRequestEvent,"");
	strcpy(this->cfocusObjectChangedEvent,"");
	strcpy(this->cfocusWindowChangedEvent,"");
	strcpy(this->cfontDatabaseChangedEvent,"");
	strcpy(this->clastWindowClosedEvent,"");
	strcpy(this->clayoutDirectionChangedEvent,"");
	strcpy(this->cpaletteChangedEvent,"");
	strcpy(this->cprimaryScreenChangedEvent,"");
	strcpy(this->csaveStateRequestEvent,"");
	strcpy(this->cscreenAddedEvent,"");
	strcpy(this->cscreenRemovedEvent,"");

	QObject::connect(this, SIGNAL(applicationDisplayNameChanged()),this, SLOT(applicationDisplayNameChangedSlot()));
	QObject::connect(this, SIGNAL(applicationStateChanged(Qt::ApplicationState)),this, SLOT(applicationStateChangedSlot()));
	QObject::connect(this, SIGNAL(commitDataRequest(QSessionManager)),this, SLOT(commitDataRequestSlot()));
	QObject::connect(this, SIGNAL(focusObjectChanged(QObject *)),this, SLOT(focusObjectChangedSlot()));
	QObject::connect(this, SIGNAL(focusWindowChanged(QWindow *)),this, SLOT(focusWindowChangedSlot()));
	QObject::connect(this, SIGNAL(fontDatabaseChanged()),this, SLOT(fontDatabaseChangedSlot()));
	QObject::connect(this, SIGNAL(lastWindowClosed()),this, SLOT(lastWindowClosedSlot()));
	QObject::connect(this, SIGNAL(layoutDirectionChanged(Qt::LayoutDirection)),this, SLOT(layoutDirectionChangedSlot()));
	QObject::connect(this, SIGNAL(paletteChanged(const QPalette)),this, SLOT(paletteChangedSlot()));
	QObject::connect(this, SIGNAL(primaryScreenChanged(QScreen *)),this, SLOT(primaryScreenChangedSlot()));
	QObject::connect(this, SIGNAL(saveStateRequest(QSessionManager)),this, SLOT(saveStateRequestSlot()));
	QObject::connect(this, SIGNAL(screenAdded(QScreen *)),this, SLOT(screenAddedSlot()));
	QObject::connect(this, SIGNAL(screenRemoved(QScreen *)),this, SLOT(screenRemovedSlot()));

}

GGuiApplication::~GGuiApplication()
{
	ring_list_delete(this->pParaList);
}

void GGuiApplication::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GGuiApplication::setapplicationDisplayNameChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->capplicationDisplayNameChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setapplicationStateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->capplicationStateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setcommitDataRequestEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccommitDataRequestEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setfocusObjectChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfocusObjectChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setfocusWindowChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfocusWindowChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setfontDatabaseChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfontDatabaseChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setlastWindowClosedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clastWindowClosedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setlayoutDirectionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clayoutDirectionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setpaletteChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpaletteChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setprimaryScreenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cprimaryScreenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setsaveStateRequestEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csaveStateRequestEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setscreenAddedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cscreenAddedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGuiApplication::setscreenRemovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cscreenRemovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GGuiApplication::getapplicationDisplayNameChangedEvent(void)
{
	return this->capplicationDisplayNameChangedEvent;
}

const char *GGuiApplication::getapplicationStateChangedEvent(void)
{
	return this->capplicationStateChangedEvent;
}

const char *GGuiApplication::getcommitDataRequestEvent(void)
{
	return this->ccommitDataRequestEvent;
}

const char *GGuiApplication::getfocusObjectChangedEvent(void)
{
	return this->cfocusObjectChangedEvent;
}

const char *GGuiApplication::getfocusWindowChangedEvent(void)
{
	return this->cfocusWindowChangedEvent;
}

const char *GGuiApplication::getfontDatabaseChangedEvent(void)
{
	return this->cfontDatabaseChangedEvent;
}

const char *GGuiApplication::getlastWindowClosedEvent(void)
{
	return this->clastWindowClosedEvent;
}

const char *GGuiApplication::getlayoutDirectionChangedEvent(void)
{
	return this->clayoutDirectionChangedEvent;
}

const char *GGuiApplication::getpaletteChangedEvent(void)
{
	return this->cpaletteChangedEvent;
}

const char *GGuiApplication::getprimaryScreenChangedEvent(void)
{
	return this->cprimaryScreenChangedEvent;
}

const char *GGuiApplication::getsaveStateRequestEvent(void)
{
	return this->csaveStateRequestEvent;
}

const char *GGuiApplication::getscreenAddedEvent(void)
{
	return this->cscreenAddedEvent;
}

const char *GGuiApplication::getscreenRemovedEvent(void)
{
	return this->cscreenRemovedEvent;
}


void GGuiApplication::applicationDisplayNameChangedSlot()
{
	if (strcmp(this->capplicationDisplayNameChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->capplicationDisplayNameChangedEvent);
}

void GGuiApplication::applicationStateChangedSlot()
{
	if (strcmp(this->capplicationStateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->capplicationStateChangedEvent);
}

void GGuiApplication::commitDataRequestSlot()
{
	if (strcmp(this->ccommitDataRequestEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccommitDataRequestEvent);
}

void GGuiApplication::focusObjectChangedSlot()
{
	if (strcmp(this->cfocusObjectChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfocusObjectChangedEvent);
}

void GGuiApplication::focusWindowChangedSlot()
{
	if (strcmp(this->cfocusWindowChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfocusWindowChangedEvent);
}

void GGuiApplication::fontDatabaseChangedSlot()
{
	if (strcmp(this->cfontDatabaseChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfontDatabaseChangedEvent);
}

void GGuiApplication::lastWindowClosedSlot()
{
	if (strcmp(this->clastWindowClosedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clastWindowClosedEvent);
}

void GGuiApplication::layoutDirectionChangedSlot()
{
	if (strcmp(this->clayoutDirectionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clayoutDirectionChangedEvent);
}

void GGuiApplication::paletteChangedSlot()
{
	if (strcmp(this->cpaletteChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpaletteChangedEvent);
}

void GGuiApplication::primaryScreenChangedSlot()
{
	if (strcmp(this->cprimaryScreenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cprimaryScreenChangedEvent);
}

void GGuiApplication::saveStateRequestSlot()
{
	if (strcmp(this->csaveStateRequestEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csaveStateRequestEvent);
}

void GGuiApplication::screenAddedSlot()
{
	if (strcmp(this->cscreenAddedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cscreenAddedEvent);
}

void GGuiApplication::screenRemovedSlot()
{
	if (strcmp(this->cscreenRemovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cscreenRemovedEvent);
}

