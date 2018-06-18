
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
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
	if (strlen(cStr)<100)
		strcpy(this->csceneGraphErrorEvent,cStr);
}

void GQuickWidget::setstatusChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cstatusChangedEvent,cStr);
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

