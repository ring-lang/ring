
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPLAINTEXTEDIT_H
#define GPLAINTEXTEDIT_H
#include "ringqt.h"
#include <QPlainTextEdit>
extern "C" {
#include "ring.h"
}

class GPlainTextEdit : public QPlainTextEdit
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cblockCountChangedEvent[RINGQT_EVENT_SIZE];
    char ccopyAvailableEvent[RINGQT_EVENT_SIZE];
    char ccursorPositionChangedEvent[RINGQT_EVENT_SIZE];
    char cmodificationChangedEvent[RINGQT_EVENT_SIZE];
    char credoAvailableEvent[RINGQT_EVENT_SIZE];
    char cselectionChangedEvent[RINGQT_EVENT_SIZE];
    char ctextChangedEvent[RINGQT_EVENT_SIZE];
    char cundoAvailableEvent[RINGQT_EVENT_SIZE];
    char cupdateRequestEvent[RINGQT_EVENT_SIZE];


    GPlainTextEdit(QWidget *parent,VM *pVM );

    ~GPlainTextEdit();

    void geteventparameters(void) ;

    void setblockCountChangedEvent(const char *cStr);
    void setcopyAvailableEvent(const char *cStr);
    void setcursorPositionChangedEvent(const char *cStr);
    void setmodificationChangedEvent(const char *cStr);
    void setredoAvailableEvent(const char *cStr);
    void setselectionChangedEvent(const char *cStr);
    void settextChangedEvent(const char *cStr);
    void setundoAvailableEvent(const char *cStr);
    void setupdateRequestEvent(const char *cStr);


    const char *getblockCountChangedEvent(void);
    const char *getcopyAvailableEvent(void);
    const char *getcursorPositionChangedEvent(void);
    const char *getmodificationChangedEvent(void);
    const char *getredoAvailableEvent(void);
    const char *getselectionChangedEvent(void);
    const char *gettextChangedEvent(void);
    const char *getundoAvailableEvent(void);
    const char *getupdateRequestEvent(void);


  public slots:

    void blockCountChangedSlot();
    void copyAvailableSlot();
    void cursorPositionChangedSlot();
    void modificationChangedSlot();
    void redoAvailableSlot();
    void selectionChanged();
    void textChangedSlot();
    void undoAvailableSlot();
    void updateRequestSlot();

};

#endif

