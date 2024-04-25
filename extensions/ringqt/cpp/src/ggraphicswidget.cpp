
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "ggraphicswidget.h"

GGraphicsWidget::GGraphicsWidget(QGraphicsItem *x,Qt::WindowFlags parent,VM *pVM)  : QGraphicsWidget(x,parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cgeometryChangedEvent,"");
	strcpy(this->clayoutChangedEvent,"");

	QObject::connect(this, SIGNAL(geometryChanged()),this, SLOT(geometryChangedSlot()));
	QObject::connect(this, SIGNAL(layoutChanged()),this, SLOT(layoutChangedSlot()));

}

GGraphicsWidget::~GGraphicsWidget()
{
	ring_list_delete(this->pParaList);
}

void GGraphicsWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GGraphicsWidget::setgeometryChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cgeometryChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GGraphicsWidget::setlayoutChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clayoutChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GGraphicsWidget::getgeometryChangedEvent(void)
{
	return this->cgeometryChangedEvent;
}

const char *GGraphicsWidget::getlayoutChangedEvent(void)
{
	return this->clayoutChangedEvent;
}


void GGraphicsWidget::geometryChangedSlot()
{
	if (strcmp(this->cgeometryChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cgeometryChangedEvent);
}

void GGraphicsWidget::layoutChangedSlot()
{
	if (strcmp(this->clayoutChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clayoutChangedEvent);
}

