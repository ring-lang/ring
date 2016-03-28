
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtabwidget.h"

GTabWidget::GTabWidget(QWidget *parent,VM *pVM)  : QTabWidget(parent)
{
	this->pVM = pVM;
	strcpy(this->ccurrentChangedEvent,"");
	strcpy(this->ctabCloseRequestedEvent,"");

	QObject::connect(this, SIGNAL(currentChanged(int)),this, SLOT(currentChangedSlot()));
	QObject::connect(this, SIGNAL(tabCloseRequested(int)),this, SLOT(tabCloseRequestedSlot()));

}
 
void GTabWidget::setcurrentChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccurrentChangedEvent,cStr);
}

void GTabWidget::settabCloseRequestedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ctabCloseRequestedEvent,cStr);
}


void GTabWidget::currentChangedSlot()
{
	if (strcmp(this->ccurrentChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ccurrentChangedEvent);
}

void GTabWidget::tabCloseRequestedSlot()
{
	if (strcmp(this->ctabCloseRequestedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ctabCloseRequestedEvent);
}

