
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gcolumnview.h"

GColumnView::GColumnView(QWidget *parent,VM *pVM)  : QColumnView(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cupdatePreviewWidgetEvent,"");

	QObject::connect(this, SIGNAL(updatePreviewWidget(QModelIndex)),this, SLOT(updatePreviewWidgetSlot()));

}

GColumnView::~GColumnView()
{
	ring_list_delete(this->pParaList);
}

void GColumnView::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GColumnView::setupdatePreviewWidgetEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cupdatePreviewWidgetEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GColumnView::getupdatePreviewWidgetEvent(void)
{
	return this->cupdatePreviewWidgetEvent;
}


void GColumnView::updatePreviewWidgetSlot()
{
	if (strcmp(this->cupdatePreviewWidgetEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cupdatePreviewWidgetEvent);
}

