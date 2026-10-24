
/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GUNDOSTACK_H
#define GUNDOSTACK_H
#include "ringqt.h"
#include <QUndoStack>

extern "C" {
#include "ring.h"
}

class GUndoStack : public QUndoStack
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccanRedoChangedEvent[RINGQT_EVENT_SIZE];
    char ccanUndoChangedEvent[RINGQT_EVENT_SIZE];
    char ccleanChangedEvent[RINGQT_EVENT_SIZE];
    char cindexChangedEvent[RINGQT_EVENT_SIZE];
    char credoTextChangedEvent[RINGQT_EVENT_SIZE];
    char cundoTextChangedEvent[RINGQT_EVENT_SIZE];


    GUndoStack(QObject *parent,VM *pVM );

    ~GUndoStack();

    void geteventparameters(void) ;

    void setcanRedoChangedEvent(const char *cStr);
    void setcanUndoChangedEvent(const char *cStr);
    void setcleanChangedEvent(const char *cStr);
    void setindexChangedEvent(const char *cStr);
    void setredoTextChangedEvent(const char *cStr);
    void setundoTextChangedEvent(const char *cStr);


    const char *getcanRedoChangedEvent(void);
    const char *getcanUndoChangedEvent(void);
    const char *getcleanChangedEvent(void);
    const char *getindexChangedEvent(void);
    const char *getredoTextChangedEvent(void);
    const char *getundoTextChangedEvent(void);


  public slots:

    void canRedoChangedSlot();
    void canUndoChangedSlot();
    void cleanChangedSlot();
    void indexChangedSlot();
    void redoTextChangedSlot();
    void undoTextChangedSlot();



};

#endif

