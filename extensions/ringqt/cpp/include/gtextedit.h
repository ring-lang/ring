
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTEXTEDIT_H
#define GTEXTEDIT_H
#include <QApplication>
#include <QTextEdit>
extern "C" {
#include "ring.h"
}

class GTextEdit : public QTextEdit
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char ccopyAvailableEvent[200];
    char ccurrentCharFormatChangedEvent[200];
    char ccursorPositionChangedEvent[200];
    char credoAvailableEvent[200];
    char cselectionChangedEvent[200];
    char ctextChangedEvent[200];
    char cundoAvailableEvent[200];


    GTextEdit(QWidget *parent,VM *pVM );

    ~GTextEdit();

    void geteventparameters(void) ;

    void setcopyAvailableEvent(const char *cStr);
    void setcurrentCharFormatChangedEvent(const char *cStr);
    void setcursorPositionChangedEvent(const char *cStr);
    void setredoAvailableEvent(const char *cStr);
    void setselectionChangedEvent(const char *cStr);
    void settextChangedEvent(const char *cStr);
    void setundoAvailableEvent(const char *cStr);


    const char *getcopyAvailableEvent(void);
    const char *getcurrentCharFormatChangedEvent(void);
    const char *getcursorPositionChangedEvent(void);
    const char *getredoAvailableEvent(void);
    const char *getselectionChangedEvent(void);
    const char *gettextChangedEvent(void);
    const char *getundoAvailableEvent(void);


  public slots:

    void copyAvailableSlot();
    void currentCharFormatChangedSlot();
    void cursorPositionChangedSlot();
    void redoAvailableSlot();
    void selectionChanged();
    void textChangedSlot();
    void undoAvailableSlot();

};

#endif

