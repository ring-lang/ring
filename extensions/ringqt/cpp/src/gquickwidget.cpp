
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gquickwidget.h"

GQuickWidget::GQuickWidget(QWidget *parent,VM *pVM)  : QQuickWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->csceneGraphErrorEvent,"");
	strcpy(this->cstatusChangedEvent,"");

	QObject::connect(this, SIGNAL(sceneGraphError(QQuickWindow::SceneGraphError,const QString)),this, SLOT(sceneGraphErrorSlot()));
	QObject::connect(this, SIGNAL(statusChanged(QQuickWidget::Status)),this, SLOT(statusChangedSlot()));

}

GQuickWidget::~GQuickWidget()
{
	ring_list_delete(this->pParaList);
}

void GQuickWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GQuickWidget::setsceneGraphErrorEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csceneGraphErrorEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GQuickWidget::setstatusChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cstatusChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GQuickWidget::getsceneGraphErrorEvent(void)
{
	return this->csceneGraphErrorEvent;
}

const char *GQuickWidget::getstatusChangedEvent(void)
{
	return this->cstatusChangedEvent;
}


void GQuickWidget::sceneGraphErrorSlot()
{
	if (strcmp(this->csceneGraphErrorEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csceneGraphErrorEvent);
}

void GQuickWidget::statusChangedSlot()
{
	if (strcmp(this->cstatusChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cstatusChangedEvent);
}

