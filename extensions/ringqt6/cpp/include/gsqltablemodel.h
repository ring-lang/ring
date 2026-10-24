
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSQLTABLEMODEL_H
#define GSQLTABLEMODEL_H
#include "ringqt.h"
#include <QSqlTableModel>

extern "C" {
#include "ring.h"
}

class GSqlTableModel : public QSqlTableModel
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cbeforeDeleteEvent[RINGQT_EVENT_SIZE];
    char cbeforeInsertEvent[RINGQT_EVENT_SIZE];
    char cbeforeUpdateEvent[RINGQT_EVENT_SIZE];
    char cprimeInsertEvent[RINGQT_EVENT_SIZE];


    GSqlTableModel(QObject *parent, QSqlDatabase dbparent,VM *pVM );

    ~GSqlTableModel();

    void geteventparameters(void) ;

    void setbeforeDeleteEvent(const char *cStr);
    void setbeforeInsertEvent(const char *cStr);
    void setbeforeUpdateEvent(const char *cStr);
    void setprimeInsertEvent(const char *cStr);


    const char *getbeforeDeleteEvent(void);
    const char *getbeforeInsertEvent(void);
    const char *getbeforeUpdateEvent(void);
    const char *getprimeInsertEvent(void);


  public slots:

    void beforeDeleteSlot();
    void beforeInsertSlot();
    void beforeUpdateSlot();
    void primeInsertSlot();



};

#endif

