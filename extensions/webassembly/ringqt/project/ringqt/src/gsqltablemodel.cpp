
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gsqltablemodel.h"

GSqlTableModel::GSqlTableModel(QObject *parent, QSqlDatabase dbparent,VM *pVM)  : QSqlTableModel(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cbeforeDeleteEvent,"");
	strcpy(this->cbeforeInsertEvent,"");
	strcpy(this->cbeforeUpdateEvent,"");
	strcpy(this->cprimeInsertEvent,"");

	QObject::connect(this, SIGNAL(beforeDelete(int)),this, SLOT(beforeDeleteSlot()));
	QObject::connect(this, SIGNAL(beforeInsert(QSqlRecord&)),this, SLOT(beforeInsertSlot()));
	QObject::connect(this, SIGNAL(beforeUpdate(int,QSqlRecord&)),this, SLOT(beforeUpdateSlot()));
	QObject::connect(this, SIGNAL(primeInsert(int,QSqlRecord&)),this, SLOT(primeInsertSlot()));

}

GSqlTableModel::~GSqlTableModel()
{
	ring_list_delete(this->pParaList);
}

void GSqlTableModel::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GSqlTableModel::setbeforeDeleteEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbeforeDeleteEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSqlTableModel::setbeforeInsertEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbeforeInsertEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSqlTableModel::setbeforeUpdateEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbeforeUpdateEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSqlTableModel::setprimeInsertEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cprimeInsertEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GSqlTableModel::getbeforeDeleteEvent(void)
{
	return this->cbeforeDeleteEvent;
}

const char *GSqlTableModel::getbeforeInsertEvent(void)
{
	return this->cbeforeInsertEvent;
}

const char *GSqlTableModel::getbeforeUpdateEvent(void)
{
	return this->cbeforeUpdateEvent;
}

const char *GSqlTableModel::getprimeInsertEvent(void)
{
	return this->cprimeInsertEvent;
}


void GSqlTableModel::beforeDeleteSlot()
{
	if (strcmp(this->cbeforeDeleteEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbeforeDeleteEvent);
}

void GSqlTableModel::beforeInsertSlot()
{
	if (strcmp(this->cbeforeInsertEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbeforeInsertEvent);
}

void GSqlTableModel::beforeUpdateSlot()
{
	if (strcmp(this->cbeforeUpdateEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbeforeUpdateEvent);
}

void GSqlTableModel::primeInsertSlot()
{
	if (strcmp(this->cprimeInsertEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cprimeInsertEvent);
}

