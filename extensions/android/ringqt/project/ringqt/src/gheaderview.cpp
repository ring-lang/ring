
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gheaderview.h"

GHeaderView::GHeaderView(Qt::Orientation x, QWidget *parent,VM *pVM)  : QHeaderView(x,parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cgeometriesChangedEvent,"");
	strcpy(this->csectionClickedEvent,"");
	strcpy(this->csectionCountChangedEvent,"");
	strcpy(this->csectionDoubleClickedEvent,"");
	strcpy(this->csectionEnteredEvent,"");
	strcpy(this->csectionHandleDoubleClickedEvent,"");
	strcpy(this->csectionMovedEvent,"");
	strcpy(this->csectionPressedEvent,"");
	strcpy(this->csectionResizedEvent,"");
	strcpy(this->csortIndicatorChangedEvent,"");

	QObject::connect(this, SIGNAL(geometriesChanged()),this, SLOT(geometriesChangedSlot()));
	QObject::connect(this, SIGNAL(sectionClicked(int)),this, SLOT(sectionClickedSlot(int)));
	QObject::connect(this, SIGNAL(sectionCountChanged(int, int)),this, SLOT(sectionCountChangedSlot()));
	QObject::connect(this, SIGNAL(sectionDoubleClicked(int)),this, SLOT(sectionDoubleClickedSlot()));
	QObject::connect(this, SIGNAL(sectionEntered(int)),this, SLOT(sectionEnteredSlot()));
	QObject::connect(this, SIGNAL(sectionHandleDoubleClicked(int)),this, SLOT(sectionHandleDoubleClickedSlot()));
	QObject::connect(this, SIGNAL(sectionMoved(int, int, int)),this, SLOT(sectionMovedSlot()));
	QObject::connect(this, SIGNAL(sectionPressed(int)),this, SLOT(sectionPressedSlot()));
	QObject::connect(this, SIGNAL(sectionResized(int, int, int)),this, SLOT(sectionResizedSlot()));
	QObject::connect(this, SIGNAL(sortIndicatorChanged(int, Qt::SortOrder)),this, SLOT(sortIndicatorChangedSlot()));

}

GHeaderView::~GHeaderView()
{
	ring_list_delete(this->pParaList);
}

void GHeaderView::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GHeaderView::setgeometriesChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cgeometriesChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHeaderView::setsectionClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csectionClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHeaderView::setsectionCountChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csectionCountChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHeaderView::setsectionDoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csectionDoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHeaderView::setsectionEnteredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csectionEnteredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHeaderView::setsectionHandleDoubleClickedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csectionHandleDoubleClickedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHeaderView::setsectionMovedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csectionMovedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHeaderView::setsectionPressedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csectionPressedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHeaderView::setsectionResizedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csectionResizedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GHeaderView::setsortIndicatorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->csortIndicatorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GHeaderView::getgeometriesChangedEvent(void)
{
	return this->cgeometriesChangedEvent;
}

const char *GHeaderView::getsectionClickedEvent(void)
{
	return this->csectionClickedEvent;
}

const char *GHeaderView::getsectionCountChangedEvent(void)
{
	return this->csectionCountChangedEvent;
}

const char *GHeaderView::getsectionDoubleClickedEvent(void)
{
	return this->csectionDoubleClickedEvent;
}

const char *GHeaderView::getsectionEnteredEvent(void)
{
	return this->csectionEnteredEvent;
}

const char *GHeaderView::getsectionHandleDoubleClickedEvent(void)
{
	return this->csectionHandleDoubleClickedEvent;
}

const char *GHeaderView::getsectionMovedEvent(void)
{
	return this->csectionMovedEvent;
}

const char *GHeaderView::getsectionPressedEvent(void)
{
	return this->csectionPressedEvent;
}

const char *GHeaderView::getsectionResizedEvent(void)
{
	return this->csectionResizedEvent;
}

const char *GHeaderView::getsortIndicatorChangedEvent(void)
{
	return this->csortIndicatorChangedEvent;
}


void GHeaderView::geometriesChangedSlot()
{
	if (strcmp(this->cgeometriesChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cgeometriesChangedEvent);
}

void GHeaderView::sectionClickedSlot(int p1)
{
	if (strcmp(this->csectionClickedEvent,"")==0)
		return ;

		ring_list_deleteallitems(this->pParaList);
		ring_list_adddouble(this->pParaList, (double) p1 ) ;	
	
	ring_vm_runcode(this->pVM,this->csectionClickedEvent);
}

void GHeaderView::sectionCountChangedSlot()
{
	if (strcmp(this->csectionCountChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csectionCountChangedEvent);
}

void GHeaderView::sectionDoubleClickedSlot()
{
	if (strcmp(this->csectionDoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csectionDoubleClickedEvent);
}

void GHeaderView::sectionEnteredSlot()
{
	if (strcmp(this->csectionEnteredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csectionEnteredEvent);
}

void GHeaderView::sectionHandleDoubleClickedSlot()
{
	if (strcmp(this->csectionHandleDoubleClickedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csectionHandleDoubleClickedEvent);
}

void GHeaderView::sectionMovedSlot()
{
	if (strcmp(this->csectionMovedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csectionMovedEvent);
}

void GHeaderView::sectionPressedSlot()
{
	if (strcmp(this->csectionPressedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csectionPressedEvent);
}

void GHeaderView::sectionResizedSlot()
{
	if (strcmp(this->csectionResizedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csectionResizedEvent);
}

void GHeaderView::sortIndicatorChangedSlot()
{
	if (strcmp(this->csortIndicatorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->csortIndicatorChangedEvent);
}

