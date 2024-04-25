
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "ggraphicsview.h"

GGraphicsView::GGraphicsView(QWidget * parent,VM *pVM)  : QGraphicsView(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->crubberBandChangedEvent,"");

	QObject::connect(this, SIGNAL(rubberBandChanged(QRect,QPointF,QPointF)),this, SLOT(rubberBandChangedSlot()));

}

GGraphicsView::~GGraphicsView()
{
	ring_list_delete(this->pParaList);
}

void GGraphicsView::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GGraphicsView::setrubberBandChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->crubberBandChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GGraphicsView::getrubberBandChangedEvent(void)
{
	return this->crubberBandChangedEvent;
}


void GGraphicsView::rubberBandChangedSlot()
{
	if (strcmp(this->crubberBandChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crubberBandChangedEvent);
}

