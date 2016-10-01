
/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
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
	if (strlen(cStr)<100)
		strcpy(this->cgeometriesChangedEvent,cStr);
}

void GHeaderView::setsectionClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csectionClickedEvent,cStr);
}

void GHeaderView::setsectionCountChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csectionCountChangedEvent,cStr);
}

void GHeaderView::setsectionDoubleClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csectionDoubleClickedEvent,cStr);
}

void GHeaderView::setsectionEnteredEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csectionEnteredEvent,cStr);
}

void GHeaderView::setsectionHandleDoubleClickedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csectionHandleDoubleClickedEvent,cStr);
}

void GHeaderView::setsectionMovedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csectionMovedEvent,cStr);
}

void GHeaderView::setsectionPressedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csectionPressedEvent,cStr);
}

void GHeaderView::setsectionResizedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csectionResizedEvent,cStr);
}

void GHeaderView::setsortIndicatorChangedEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->csortIndicatorChangedEvent,cStr);
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

