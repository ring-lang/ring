
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtreeview.h"

GTreeView::GTreeView(QWidget *parent,VM *pVM)  : QTreeView(parent)
{
	this->pVM = pVM;
	strcpy(this->ccollapsedEvent,"");
	strcpy(this->cexpandedEvent,"");
	strcpy(this->cactivatedEvent,"");
	strcpy(this->cclickedEvent,"");
	strcpy(this->cdoubleClickedEvent,"");
	strcpy(this->centeredEvent,"");
	strcpy(this->cpressedEvent,"");
	strcpy(this->cviewportEnteredEvent,"");

	QObject::connect(this, SIGNAL(collapsed(QModelIndex)),this, SLOT(collapsedSlot()));
	QObject::connect(this, SIGNAL(expanded(QModelIndex)),this, SLOT(expandedSlot()));
	QObject::connect(this, SIGNAL(activated(QModelIndex)),this, SLOT(activatedSlot()));
	QObject::connect(this, SIGNAL(clicked(QModelIndex)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked(QModelIndex)),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(entered(QModelIndex)),this, SLOT(enteredSlot()));
	QObject::connect(this, SIGNAL(pressed(QModelIndex)),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(viewportEntered()),this, SLOT(viewportEnteredSlot()));

}
 
void GTreeView::setcollapsedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccollapsedEvent,cStr);
}

void GTreeView::setexpandedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cexpandedEvent,cStr);
}

void GTreeView::setactivatedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cactivatedEvent,cStr);
}

void GTreeView::setclickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cclickedEvent,cStr);
}

void GTreeView::setdoubleClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cdoubleClickedEvent,cStr);
}

void GTreeView::setenteredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->centeredEvent,cStr);
}

void GTreeView::setpressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpressedEvent,cStr);
}

void GTreeView::setviewportEnteredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cviewportEnteredEvent,cStr);
}


void GTreeView::collapsedSlot()
{
	if (strcmp(this->ccollapsedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ccollapsedEvent);
}

void GTreeView::expandedSlot()
{
	if (strcmp(this->cexpandedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cexpandedEvent);
}

void GTreeView::activatedSlot()
{
	if (strcmp(this->cactivatedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cactivatedEvent);
}

void GTreeView::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GTreeView::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GTreeView::enteredSlot()
{
	if (strcmp(this->centeredEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->centeredEvent);
}

void GTreeView::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GTreeView::viewportEnteredSlot()
{
	if (strcmp(this->cviewportEnteredEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cviewportEnteredEvent);
}

