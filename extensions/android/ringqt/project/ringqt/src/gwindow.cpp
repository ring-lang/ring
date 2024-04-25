
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gwindow.h"

GWindow::GWindow(QScreen *parent,VM *pVM)  : QWindow(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cactiveChangedEvent,"");
	strcpy(this->ccontentOrientationChangedEvent,"");
	strcpy(this->cfocusObjectChangedEvent,"");
	strcpy(this->cheightChangedEvent,"");
	strcpy(this->cmaximumHeightChangedEvent,"");
	strcpy(this->cmaximumWidthChangedEvent,"");
	strcpy(this->cminimumHeightChangedEvent,"");
	strcpy(this->cminimumWidthChangedEvent,"");
	strcpy(this->cmodalityChangedEvent,"");
	strcpy(this->copacityChangedEvent,"");
	strcpy(this->cscreenChangedEvent,"");
	strcpy(this->cvisibilityChangedEvent,"");
	strcpy(this->cvisibleChangedEvent,"");
	strcpy(this->cwidthChangedEvent,"");
	strcpy(this->cwindowStateChangedEvent,"");
	strcpy(this->cwindowTitleChangedEvent,"");
	strcpy(this->cxChangedEvent,"");
	strcpy(this->cyChangedEvent,"");

	QObject::connect(this, SIGNAL(activeChanged()),this, SLOT(activeChangedSlot()));
	QObject::connect(this, SIGNAL(contentOrientationChanged(Qt::ScreenOrientation)),this, SLOT(contentOrientationChangedSlot()));
	QObject::connect(this, SIGNAL(focusObjectChanged(QObject *)),this, SLOT(focusObjectChangedSlot()));
	QObject::connect(this, SIGNAL(heightChanged(int)),this, SLOT(heightChangedSlot()));
	QObject::connect(this, SIGNAL(maximumHeightChanged(int)),this, SLOT(maximumHeightChangedSlot()));
	QObject::connect(this, SIGNAL(maximumWidthChanged(int)),this, SLOT(maximumWidthChangedSlot()));
	QObject::connect(this, SIGNAL(minimumHeightChanged(int)),this, SLOT(minimumHeightChangedSlot()));
	QObject::connect(this, SIGNAL(minimumWidthChanged(int)),this, SLOT(minimumWidthChangedSlot()));
	QObject::connect(this, SIGNAL(modalityChanged(Qt::WindowModality)),this, SLOT(modalityChangedSlot()));
	QObject::connect(this, SIGNAL(opacityChanged(qreal)),this, SLOT(opacityChangedSlot()));
	QObject::connect(this, SIGNAL(screenChanged(QScreen *)),this, SLOT(screenChangedSlot()));
	QObject::connect(this, SIGNAL(visibilityChanged(QWindow::Visibility)),this, SLOT(visibilityChangedSlot()));
	QObject::connect(this, SIGNAL(visibleChanged(bool)),this, SLOT(visibleChangedSlot()));
	QObject::connect(this, SIGNAL(widthChanged(int)),this, SLOT(widthChangedSlot()));
	QObject::connect(this, SIGNAL(windowStateChanged(Qt::WindowState)),this, SLOT(windowStateChangedSlot()));
	QObject::connect(this, SIGNAL(windowTitleChanged(const QString)),this, SLOT(windowTitleChangedSlot()));
	QObject::connect(this, SIGNAL(xChanged(int)),this, SLOT(xChangedSlot()));
	QObject::connect(this, SIGNAL(yChanged(int)),this, SLOT(yChangedSlot()));

}

GWindow::~GWindow()
{
	ring_list_delete(this->pParaList);
}

void GWindow::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GWindow::setactiveChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cactiveChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setcontentOrientationChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccontentOrientationChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setfocusObjectChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfocusObjectChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setheightChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cheightChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setmaximumHeightChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmaximumHeightChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setmaximumWidthChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmaximumWidthChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setminimumHeightChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cminimumHeightChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setminimumWidthChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cminimumWidthChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setmodalityChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cmodalityChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setopacityChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->copacityChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setscreenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cscreenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setvisibilityChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvisibilityChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setvisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setwidthChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cwidthChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setwindowStateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cwindowStateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setwindowTitleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cwindowTitleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setxChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cxChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWindow::setyChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cyChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GWindow::getactiveChangedEvent(void)
{
	return this->cactiveChangedEvent;
}

const char *GWindow::getcontentOrientationChangedEvent(void)
{
	return this->ccontentOrientationChangedEvent;
}

const char *GWindow::getfocusObjectChangedEvent(void)
{
	return this->cfocusObjectChangedEvent;
}

const char *GWindow::getheightChangedEvent(void)
{
	return this->cheightChangedEvent;
}

const char *GWindow::getmaximumHeightChangedEvent(void)
{
	return this->cmaximumHeightChangedEvent;
}

const char *GWindow::getmaximumWidthChangedEvent(void)
{
	return this->cmaximumWidthChangedEvent;
}

const char *GWindow::getminimumHeightChangedEvent(void)
{
	return this->cminimumHeightChangedEvent;
}

const char *GWindow::getminimumWidthChangedEvent(void)
{
	return this->cminimumWidthChangedEvent;
}

const char *GWindow::getmodalityChangedEvent(void)
{
	return this->cmodalityChangedEvent;
}

const char *GWindow::getopacityChangedEvent(void)
{
	return this->copacityChangedEvent;
}

const char *GWindow::getscreenChangedEvent(void)
{
	return this->cscreenChangedEvent;
}

const char *GWindow::getvisibilityChangedEvent(void)
{
	return this->cvisibilityChangedEvent;
}

const char *GWindow::getvisibleChangedEvent(void)
{
	return this->cvisibleChangedEvent;
}

const char *GWindow::getwidthChangedEvent(void)
{
	return this->cwidthChangedEvent;
}

const char *GWindow::getwindowStateChangedEvent(void)
{
	return this->cwindowStateChangedEvent;
}

const char *GWindow::getwindowTitleChangedEvent(void)
{
	return this->cwindowTitleChangedEvent;
}

const char *GWindow::getxChangedEvent(void)
{
	return this->cxChangedEvent;
}

const char *GWindow::getyChangedEvent(void)
{
	return this->cyChangedEvent;
}


void GWindow::activeChangedSlot()
{
	if (strcmp(this->cactiveChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cactiveChangedEvent);
}

void GWindow::contentOrientationChangedSlot()
{
	if (strcmp(this->ccontentOrientationChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccontentOrientationChangedEvent);
}

void GWindow::focusObjectChangedSlot()
{
	if (strcmp(this->cfocusObjectChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfocusObjectChangedEvent);
}

void GWindow::heightChangedSlot()
{
	if (strcmp(this->cheightChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cheightChangedEvent);
}

void GWindow::maximumHeightChangedSlot()
{
	if (strcmp(this->cmaximumHeightChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmaximumHeightChangedEvent);
}

void GWindow::maximumWidthChangedSlot()
{
	if (strcmp(this->cmaximumWidthChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmaximumWidthChangedEvent);
}

void GWindow::minimumHeightChangedSlot()
{
	if (strcmp(this->cminimumHeightChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminimumHeightChangedEvent);
}

void GWindow::minimumWidthChangedSlot()
{
	if (strcmp(this->cminimumWidthChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminimumWidthChangedEvent);
}

void GWindow::modalityChangedSlot()
{
	if (strcmp(this->cmodalityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cmodalityChangedEvent);
}

void GWindow::opacityChangedSlot()
{
	if (strcmp(this->copacityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->copacityChangedEvent);
}

void GWindow::screenChangedSlot()
{
	if (strcmp(this->cscreenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cscreenChangedEvent);
}

void GWindow::visibilityChangedSlot()
{
	if (strcmp(this->cvisibilityChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvisibilityChangedEvent);
}

void GWindow::visibleChangedSlot()
{
	if (strcmp(this->cvisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvisibleChangedEvent);
}

void GWindow::widthChangedSlot()
{
	if (strcmp(this->cwidthChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cwidthChangedEvent);
}

void GWindow::windowStateChangedSlot()
{
	if (strcmp(this->cwindowStateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cwindowStateChangedEvent);
}

void GWindow::windowTitleChangedSlot()
{
	if (strcmp(this->cwindowTitleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cwindowTitleChangedEvent);
}

void GWindow::xChangedSlot()
{
	if (strcmp(this->cxChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cxChangedEvent);
}

void GWindow::yChangedSlot()
{
	if (strcmp(this->cyChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cyChangedEvent);
}

