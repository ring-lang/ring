
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gabstractaxis.h"

GAbstractAxis::GAbstractAxis(QtCharts::QAbstractAxisPrivate &parent,VM *pVM)  : QtCharts::QAbstractAxis(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->ccolorChangedEvent,"");
	strcpy(this->cgridLineColorChangedEvent,"");
	strcpy(this->cgridLinePenChangedEvent,"");
	strcpy(this->cgridVisibleChangedEvent,"");
	strcpy(this->clabelsAngleChangedEvent,"");
	strcpy(this->clabelsBrushChangedEvent,"");
	strcpy(this->clabelsColorChangedEvent,"");
	strcpy(this->clabelsEditableChangedEvent,"");
	strcpy(this->clabelsFontChangedEvent,"");
	strcpy(this->clabelsVisibleChangedEvent,"");
	strcpy(this->clinePenChangedEvent,"");
	strcpy(this->clineVisibleChangedEvent,"");
	strcpy(this->cminorGridLineColorChangedEvent,"");
	strcpy(this->cminorGridLinePenChangedEvent,"");
	strcpy(this->cminorGridVisibleChangedEvent,"");
	strcpy(this->creverseChangedEvent,"");
	strcpy(this->cshadesBorderColorChangedEvent,"");
	strcpy(this->cshadesBrushChangedEvent,"");
	strcpy(this->cshadesColorChangedEvent,"");
	strcpy(this->cshadesPenChangedEvent,"");
	strcpy(this->cshadesVisibleChangedEvent,"");
	strcpy(this->ctitleBrushChangedEvent,"");
	strcpy(this->ctitleFontChangedEvent,"");
	strcpy(this->ctitleTextChangedEvent,"");
	strcpy(this->ctitleVisibleChangedEvent,"");
	strcpy(this->cvisibleChangedEvent,"");

	QObject::connect(this, SIGNAL(colorChanged(QColor)),this, SLOT(colorChangedSlot()));
	QObject::connect(this, SIGNAL(gridLineColorChanged(const QColor)),this, SLOT(gridLineColorChangedSlot()));
	QObject::connect(this, SIGNAL(gridLinePenChanged(const QPen)),this, SLOT(gridLinePenChangedSlot()));
	QObject::connect(this, SIGNAL(gridVisibleChanged(bool)),this, SLOT(gridVisibleChangedSlot()));
	QObject::connect(this, SIGNAL(labelsAngleChanged(int)),this, SLOT(labelsAngleChangedSlot()));
	QObject::connect(this, SIGNAL(labelsBrushChanged(const QBrush)),this, SLOT(labelsBrushChangedSlot()));
	QObject::connect(this, SIGNAL(labelsColorChanged(QColor)),this, SLOT(labelsColorChangedSlot()));
	QObject::connect(this, SIGNAL(labelsEditableChanged(bool)),this, SLOT(labelsEditableChangedSlot()));
	QObject::connect(this, SIGNAL(labelsFontChanged(const QFont)),this, SLOT(labelsFontChangedSlot()));
	QObject::connect(this, SIGNAL(labelsVisibleChanged(bool)),this, SLOT(labelsVisibleChangedSlot()));
	QObject::connect(this, SIGNAL(linePenChanged(const QPen)),this, SLOT(linePenChangedSlot()));
	QObject::connect(this, SIGNAL(lineVisibleChanged(bool)),this, SLOT(lineVisibleChangedSlot()));
	QObject::connect(this, SIGNAL(minorGridLineColorChanged(const QColor)),this, SLOT(minorGridLineColorChangedSlot()));
	QObject::connect(this, SIGNAL(minorGridLinePenChanged(const QPen)),this, SLOT(minorGridLinePenChangedSlot()));
	QObject::connect(this, SIGNAL(minorGridVisibleChanged(bool)),this, SLOT(minorGridVisibleChangedSlot()));
	QObject::connect(this, SIGNAL(reverseChanged(bool)),this, SLOT(reverseChangedSlot()));
	QObject::connect(this, SIGNAL(shadesBorderColorChanged(QColor)),this, SLOT(shadesBorderColorChangedSlot()));
	QObject::connect(this, SIGNAL(shadesBrushChanged(const QBrush)),this, SLOT(shadesBrushChangedSlot()));
	QObject::connect(this, SIGNAL(shadesColorChanged(QColor)),this, SLOT(shadesColorChangedSlot()));
	QObject::connect(this, SIGNAL(shadesPenChanged(const QPen)),this, SLOT(shadesPenChangedSlot()));
	QObject::connect(this, SIGNAL(shadesVisibleChanged(bool)),this, SLOT(shadesVisibleChangedSlot()));
	QObject::connect(this, SIGNAL(titleBrushChanged(const QBrush)),this, SLOT(titleBrushChangedSlot()));
	QObject::connect(this, SIGNAL(titleFontChanged(const QFont)),this, SLOT(titleFontChangedSlot()));
	QObject::connect(this, SIGNAL(titleTextChanged(const QString)),this, SLOT(titleTextChangedSlot()));
	QObject::connect(this, SIGNAL(titleVisibleChanged(bool)),this, SLOT(titleVisibleChangedSlot()));
	QObject::connect(this, SIGNAL(visibleChanged(bool)),this, SLOT(visibleChangedSlot()));

}

GAbstractAxis::~GAbstractAxis()
{
	ring_list_delete(this->pParaList);
}

void GAbstractAxis::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GAbstractAxis::setcolorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccolorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setgridLineColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cgridLineColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setgridLinePenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cgridLinePenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setgridVisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cgridVisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setlabelsAngleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsAngleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setlabelsBrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsBrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setlabelsColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setlabelsEditableChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsEditableChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setlabelsFontChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsFontChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setlabelsVisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clabelsVisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setlinePenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clinePenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setlineVisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clineVisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setminorGridLineColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cminorGridLineColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setminorGridLinePenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cminorGridLinePenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setminorGridVisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cminorGridVisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setreverseChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->creverseChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setshadesBorderColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cshadesBorderColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setshadesBrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cshadesBrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setshadesColorChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cshadesColorChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setshadesPenChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cshadesPenChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setshadesVisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cshadesVisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::settitleBrushChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctitleBrushChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::settitleFontChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctitleFontChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::settitleTextChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctitleTextChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::settitleVisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctitleVisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GAbstractAxis::setvisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GAbstractAxis::getcolorChangedEvent(void)
{
	return this->ccolorChangedEvent;
}

const char *GAbstractAxis::getgridLineColorChangedEvent(void)
{
	return this->cgridLineColorChangedEvent;
}

const char *GAbstractAxis::getgridLinePenChangedEvent(void)
{
	return this->cgridLinePenChangedEvent;
}

const char *GAbstractAxis::getgridVisibleChangedEvent(void)
{
	return this->cgridVisibleChangedEvent;
}

const char *GAbstractAxis::getlabelsAngleChangedEvent(void)
{
	return this->clabelsAngleChangedEvent;
}

const char *GAbstractAxis::getlabelsBrushChangedEvent(void)
{
	return this->clabelsBrushChangedEvent;
}

const char *GAbstractAxis::getlabelsColorChangedEvent(void)
{
	return this->clabelsColorChangedEvent;
}

const char *GAbstractAxis::getlabelsEditableChangedEvent(void)
{
	return this->clabelsEditableChangedEvent;
}

const char *GAbstractAxis::getlabelsFontChangedEvent(void)
{
	return this->clabelsFontChangedEvent;
}

const char *GAbstractAxis::getlabelsVisibleChangedEvent(void)
{
	return this->clabelsVisibleChangedEvent;
}

const char *GAbstractAxis::getlinePenChangedEvent(void)
{
	return this->clinePenChangedEvent;
}

const char *GAbstractAxis::getlineVisibleChangedEvent(void)
{
	return this->clineVisibleChangedEvent;
}

const char *GAbstractAxis::getminorGridLineColorChangedEvent(void)
{
	return this->cminorGridLineColorChangedEvent;
}

const char *GAbstractAxis::getminorGridLinePenChangedEvent(void)
{
	return this->cminorGridLinePenChangedEvent;
}

const char *GAbstractAxis::getminorGridVisibleChangedEvent(void)
{
	return this->cminorGridVisibleChangedEvent;
}

const char *GAbstractAxis::getreverseChangedEvent(void)
{
	return this->creverseChangedEvent;
}

const char *GAbstractAxis::getshadesBorderColorChangedEvent(void)
{
	return this->cshadesBorderColorChangedEvent;
}

const char *GAbstractAxis::getshadesBrushChangedEvent(void)
{
	return this->cshadesBrushChangedEvent;
}

const char *GAbstractAxis::getshadesColorChangedEvent(void)
{
	return this->cshadesColorChangedEvent;
}

const char *GAbstractAxis::getshadesPenChangedEvent(void)
{
	return this->cshadesPenChangedEvent;
}

const char *GAbstractAxis::getshadesVisibleChangedEvent(void)
{
	return this->cshadesVisibleChangedEvent;
}

const char *GAbstractAxis::gettitleBrushChangedEvent(void)
{
	return this->ctitleBrushChangedEvent;
}

const char *GAbstractAxis::gettitleFontChangedEvent(void)
{
	return this->ctitleFontChangedEvent;
}

const char *GAbstractAxis::gettitleTextChangedEvent(void)
{
	return this->ctitleTextChangedEvent;
}

const char *GAbstractAxis::gettitleVisibleChangedEvent(void)
{
	return this->ctitleVisibleChangedEvent;
}

const char *GAbstractAxis::getvisibleChangedEvent(void)
{
	return this->cvisibleChangedEvent;
}


void GAbstractAxis::colorChangedSlot()
{
	if (strcmp(this->ccolorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccolorChangedEvent);
}

void GAbstractAxis::gridLineColorChangedSlot()
{
	if (strcmp(this->cgridLineColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cgridLineColorChangedEvent);
}

void GAbstractAxis::gridLinePenChangedSlot()
{
	if (strcmp(this->cgridLinePenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cgridLinePenChangedEvent);
}

void GAbstractAxis::gridVisibleChangedSlot()
{
	if (strcmp(this->cgridVisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cgridVisibleChangedEvent);
}

void GAbstractAxis::labelsAngleChangedSlot()
{
	if (strcmp(this->clabelsAngleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsAngleChangedEvent);
}

void GAbstractAxis::labelsBrushChangedSlot()
{
	if (strcmp(this->clabelsBrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsBrushChangedEvent);
}

void GAbstractAxis::labelsColorChangedSlot()
{
	if (strcmp(this->clabelsColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsColorChangedEvent);
}

void GAbstractAxis::labelsEditableChangedSlot()
{
	if (strcmp(this->clabelsEditableChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsEditableChangedEvent);
}

void GAbstractAxis::labelsFontChangedSlot()
{
	if (strcmp(this->clabelsFontChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsFontChangedEvent);
}

void GAbstractAxis::labelsVisibleChangedSlot()
{
	if (strcmp(this->clabelsVisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clabelsVisibleChangedEvent);
}

void GAbstractAxis::linePenChangedSlot()
{
	if (strcmp(this->clinePenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clinePenChangedEvent);
}

void GAbstractAxis::lineVisibleChangedSlot()
{
	if (strcmp(this->clineVisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clineVisibleChangedEvent);
}

void GAbstractAxis::minorGridLineColorChangedSlot()
{
	if (strcmp(this->cminorGridLineColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminorGridLineColorChangedEvent);
}

void GAbstractAxis::minorGridLinePenChangedSlot()
{
	if (strcmp(this->cminorGridLinePenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminorGridLinePenChangedEvent);
}

void GAbstractAxis::minorGridVisibleChangedSlot()
{
	if (strcmp(this->cminorGridVisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cminorGridVisibleChangedEvent);
}

void GAbstractAxis::reverseChangedSlot()
{
	if (strcmp(this->creverseChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->creverseChangedEvent);
}

void GAbstractAxis::shadesBorderColorChangedSlot()
{
	if (strcmp(this->cshadesBorderColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cshadesBorderColorChangedEvent);
}

void GAbstractAxis::shadesBrushChangedSlot()
{
	if (strcmp(this->cshadesBrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cshadesBrushChangedEvent);
}

void GAbstractAxis::shadesColorChangedSlot()
{
	if (strcmp(this->cshadesColorChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cshadesColorChangedEvent);
}

void GAbstractAxis::shadesPenChangedSlot()
{
	if (strcmp(this->cshadesPenChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cshadesPenChangedEvent);
}

void GAbstractAxis::shadesVisibleChangedSlot()
{
	if (strcmp(this->cshadesVisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cshadesVisibleChangedEvent);
}

void GAbstractAxis::titleBrushChangedSlot()
{
	if (strcmp(this->ctitleBrushChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctitleBrushChangedEvent);
}

void GAbstractAxis::titleFontChangedSlot()
{
	if (strcmp(this->ctitleFontChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctitleFontChangedEvent);
}

void GAbstractAxis::titleTextChangedSlot()
{
	if (strcmp(this->ctitleTextChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctitleTextChangedEvent);
}

void GAbstractAxis::titleVisibleChangedSlot()
{
	if (strcmp(this->ctitleVisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctitleVisibleChangedEvent);
}

void GAbstractAxis::visibleChangedSlot()
{
	if (strcmp(this->cvisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvisibleChangedEvent);
}

