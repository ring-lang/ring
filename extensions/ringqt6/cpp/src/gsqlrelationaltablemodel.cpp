
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gsqlrelationaltablemodel.h"

GSqlRelationalTableModel::GSqlRelationalTableModel(QObject *parent, QSqlDatabase dbparent,VM *pVM)  : QSqlRelationalTableModel(parent)
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

GSqlRelationalTableModel::~GSqlRelationalTableModel()
{
	ring_list_delete(this->pParaList);
}

void GSqlRelationalTableModel::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GSqlRelationalTableModel::setbeforeDeleteEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbeforeDeleteEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSqlRelationalTableModel::setbeforeInsertEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbeforeInsertEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSqlRelationalTableModel::setbeforeUpdateEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cbeforeUpdateEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GSqlRelationalTableModel::setprimeInsertEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cprimeInsertEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GSqlRelationalTableModel::getbeforeDeleteEvent(void)
{
	return this->cbeforeDeleteEvent;
}

const char *GSqlRelationalTableModel::getbeforeInsertEvent(void)
{
	return this->cbeforeInsertEvent;
}

const char *GSqlRelationalTableModel::getbeforeUpdateEvent(void)
{
	return this->cbeforeUpdateEvent;
}

const char *GSqlRelationalTableModel::getprimeInsertEvent(void)
{
	return this->cprimeInsertEvent;
}


void GSqlRelationalTableModel::beforeDeleteSlot()
{
	if (strcmp(this->cbeforeDeleteEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbeforeDeleteEvent);
}

void GSqlRelationalTableModel::beforeInsertSlot()
{
	if (strcmp(this->cbeforeInsertEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbeforeInsertEvent);
}

void GSqlRelationalTableModel::beforeUpdateSlot()
{
	if (strcmp(this->cbeforeUpdateEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cbeforeUpdateEvent);
}

void GSqlRelationalTableModel::primeInsertSlot()
{
	if (strcmp(this->cprimeInsertEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cprimeInsertEvent);
}

