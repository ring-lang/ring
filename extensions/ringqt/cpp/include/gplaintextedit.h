
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GPLAINTEXTEDIT_H
#define GPLAINTEXTEDIT_H
#include <QApplication>
#include <QPlainTextEdit>
extern "C" {
#include "ring.h"
}

class GPlainTextEdit : public QPlainTextEdit
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cblockCountChangedEvent[200];
    char ccopyAvailableEvent[200];
    char ccursorPositionChangedEvent[200];
    char cmodificationChangedEvent[200];
    char credoAvailableEvent[200];
    char cselectionChangedEvent[200];
    char ctextChangedEvent[200];
    char cundoAvailableEvent[200];
    char cupdateRequestEvent[200];


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

