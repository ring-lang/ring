
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gtreewidget.h"

GTreeWidget::GTreeWidget(QWidget *parent,VM *pVM)  : QTreeWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
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

GTreeWidget::~GTreeWidget()
{
	ring_list_delete(this->pParaList);
}

void GTreeWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GTreeWidget::setcollapsedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccollapsedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setexpandedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cexpandedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setactivatedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cactivatedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setclickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cclickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setdoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cdoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setenteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->centeredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setpressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setviewportEnteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cviewportEnteredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setcurrentItemChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccurrentItemChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setitemActivatedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemActivatedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setitemChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setitemClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setitemCollapsedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemCollapsedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setitemDoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemDoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setitemEnteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemEnteredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setitemExpandedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemExpandedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setitemPressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemPressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GTreeWidget::setitemSelectionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->citemSelectionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GTreeWidget::getcollapsedEvent(void)
{
	return this->ccollapsedEvent;
}

const char *GTreeWidget::getexpandedEvent(void)
{
	return this->cexpandedEvent;
}

const char *GTreeWidget::getactivatedEvent(void)
{
	return this->cactivatedEvent;
}

const char *GTreeWidget::getclickedEvent(void)
{
	return this->cclickedEvent;
}

const char *GTreeWidget::getdoubleClickedEvent(void)
{
	return this->cdoubleClickedEvent;
}

const char *GTreeWidget::getenteredEvent(void)
{
	return this->centeredEvent;
}

const char *GTreeWidget::getpressedEvent(void)
{
	return this->cpressedEvent;
}

const char *GTreeWidget::getviewportEnteredEvent(void)
{
	return this->cviewportEnteredEvent;
}

const char *GTreeWidget::getcurrentItemChangedEvent(void)
{
	return this->ccurrentItemChangedEvent;
}

const char *GTreeWidget::getitemActivatedEvent(void)
{
	return this->citemActivatedEvent;
}

const char *GTreeWidget::getitemChangedEvent(void)
{
	return this->citemChangedEvent;
}

const char *GTreeWidget::getitemClickedEvent(void)
{
	return this->citemClickedEvent;
}

const char *GTreeWidget::getitemCollapsedEvent(void)
{
	return this->citemCollapsedEvent;
}

const char *GTreeWidget::getitemDoubleClickedEvent(void)
{
	return this->citemDoubleClickedEvent;
}

const char *GTreeWidget::getitemEnteredEvent(void)
{
	return this->citemEnteredEvent;
}

const char *GTreeWidget::getitemExpandedEvent(void)
{
	return this->citemExpandedEvent;
}

const char *GTreeWidget::getitemPressedEvent(void)
{
	return this->citemPressedEvent;
}

const char *GTreeWidget::getitemSelectionChangedEvent(void)
{
	return this->citemSelectionChangedEvent;
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

