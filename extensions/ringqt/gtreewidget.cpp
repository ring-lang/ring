
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtreewidget.h"

GTreeWidget::GTreeWidget(QWidget *parent,VM *pVM)  : QTreeWidget(parent)
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
	strcpy(this->ccurrentItemChangedEvent,"");
	strcpy(this->citemActivatedEvent,"");
	strcpy(this->citemChangedEvent,"");
	strcpy(this->citemClickedEvent,"");
	strcpy(this->citemCollapsedEvent,"");
	strcpy(this->citemDoubleClickedEvent,"");
	strcpy(this->citemEnteredEvent,"");
	strcpy(this->citemExpandedEvent,"");
	strcpy(this->citemPressedEvent,"");
	strcpy(this->citemSelectionChangedEvent,"");

	QObject::connect(this, SIGNAL(collapsed(QModelIndex)),this, SLOT(collapsedSlot()));
	QObject::connect(this, SIGNAL(expanded(QModelIndex)),this, SLOT(expandedSlot()));
	QObject::connect(this, SIGNAL(activated(QModelIndex)),this, SLOT(activatedSlot()));
	QObject::connect(this, SIGNAL(clicked(QModelIndex)),this, SLOT(clickedSlot()));
	QObject::connect(this, SIGNAL(doubleClicked(QModelIndex)),this, SLOT(doubleClickedSlot()));
	QObject::connect(this, SIGNAL(entered(QModelIndex)),this, SLOT(enteredSlot()));
	QObject::connect(this, SIGNAL(pressed(QModelIndex)),this, SLOT(pressedSlot()));
	QObject::connect(this, SIGNAL(viewportEntered()),this, SLOT(viewportEnteredSlot()));
	QObject::connect(this, SIGNAL(currentItemChanged(QTreeWidgetItem *,QTreeWidgetItem *)),this, SLOT(currentItemChangedSlot()));
	QObject::connect(this, SIGNAL(itemActivated(QTreeWidgetItem *,int)),this, SLOT(itemActivatedSlot()));
	QObject::connect(this, SIGNAL(itemChanged(QTreeWidgetItem *,int)),this, SLOT(itemChangedSlot()));
	QObject::connect(this, SIGNAL(itemClicked(QTreeWidgetItem *,int)),this, SLOT(itemClickedSlot()));
	QObject::connect(this, SIGNAL(itemCollapsed(QTreeWidgetItem *)),this, SLOT(itemCollapsedSlot()));
	QObject::connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem * ,int)),this, SLOT(itemDoubleClickedSlot()));
	QObject::connect(this, SIGNAL(itemEntered(QTreeWidgetItem * ,int)),this, SLOT(itemEnteredSlot()));
	QObject::connect(this, SIGNAL(itemExpanded(QTreeWidgetItem *)),this, SLOT(itemExpandedSlot()));
	QObject::connect(this, SIGNAL(itemPressed(QTreeWidgetItem * ,int)),this, SLOT(itemPressedSlot()));
	QObject::connect(this, SIGNAL(itemSelectionChanged()),this, SLOT(itemSelectionChangedSlot()));

}
 
void GTreeWidget::setcollapsedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccollapsedEvent,cStr);
}

void GTreeWidget::setexpandedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cexpandedEvent,cStr);
}

void GTreeWidget::setactivatedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cactivatedEvent,cStr);
}

void GTreeWidget::setclickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cclickedEvent,cStr);
}

void GTreeWidget::setdoubleClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cdoubleClickedEvent,cStr);
}

void GTreeWidget::setenteredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->centeredEvent,cStr);
}

void GTreeWidget::setpressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cpressedEvent,cStr);
}

void GTreeWidget::setviewportEnteredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cviewportEnteredEvent,cStr);
}

void GTreeWidget::setcurrentItemChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->ccurrentItemChangedEvent,cStr);
}

void GTreeWidget::setitemActivatedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemActivatedEvent,cStr);
}

void GTreeWidget::setitemChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemChangedEvent,cStr);
}

void GTreeWidget::setitemClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemClickedEvent,cStr);
}

void GTreeWidget::setitemCollapsedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemCollapsedEvent,cStr);
}

void GTreeWidget::setitemDoubleClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemDoubleClickedEvent,cStr);
}

void GTreeWidget::setitemEnteredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemEnteredEvent,cStr);
}

void GTreeWidget::setitemExpandedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemExpandedEvent,cStr);
}

void GTreeWidget::setitemPressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemPressedEvent,cStr);
}

void GTreeWidget::setitemSelectionChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->citemSelectionChangedEvent,cStr);
}


void GTreeWidget::collapsedSlot()
{
	if (strcmp(this->ccollapsedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ccollapsedEvent);
}

void GTreeWidget::expandedSlot()
{
	if (strcmp(this->cexpandedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cexpandedEvent);
}

void GTreeWidget::activatedSlot()
{
	if (strcmp(this->cactivatedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cactivatedEvent);
}

void GTreeWidget::clickedSlot()
{
	if (strcmp(this->cclickedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cclickedEvent);
}

void GTreeWidget::doubleClickedSlot()
{
	if (strcmp(this->cdoubleClickedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cdoubleClickedEvent);
}

void GTreeWidget::enteredSlot()
{
	if (strcmp(this->centeredEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->centeredEvent);
}

void GTreeWidget::pressedSlot()
{
	if (strcmp(this->cpressedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cpressedEvent);
}

void GTreeWidget::viewportEnteredSlot()
{
	if (strcmp(this->cviewportEnteredEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cviewportEnteredEvent);
}

void GTreeWidget::currentItemChangedSlot()
{
	if (strcmp(this->ccurrentItemChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->ccurrentItemChangedEvent);
}

void GTreeWidget::itemActivatedSlot()
{
	if (strcmp(this->citemActivatedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->citemActivatedEvent);
}

void GTreeWidget::itemChangedSlot()
{
	if (strcmp(this->citemChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->citemChangedEvent);
}

void GTreeWidget::itemClickedSlot()
{
	if (strcmp(this->citemClickedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->citemClickedEvent);
}

void GTreeWidget::itemCollapsedSlot()
{
	if (strcmp(this->citemCollapsedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->citemCollapsedEvent);
}

void GTreeWidget::itemDoubleClickedSlot()
{
	if (strcmp(this->citemDoubleClickedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->citemDoubleClickedEvent);
}

void GTreeWidget::itemEnteredSlot()
{
	if (strcmp(this->citemEnteredEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->citemEnteredEvent);
}

void GTreeWidget::itemExpandedSlot()
{
	if (strcmp(this->citemExpandedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->citemExpandedEvent);
}

void GTreeWidget::itemPressedSlot()
{
	if (strcmp(this->citemPressedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->citemPressedEvent);
}

void GTreeWidget::itemSelectionChangedSlot()
{
	if (strcmp(this->citemSelectionChangedEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->citemSelectionChangedEvent);
}

