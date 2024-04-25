
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTEXTEDIT_H
#define GTEXTEDIT_H
#include "ringqt.h"
#include <QTextEdit>
extern "C" {
#include "ring.h"
}

class GTextEdit : public QTextEdit
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccopyAvailableEvent[RINGQT_EVENT_SIZE];
    char ccurrentCharFormatChangedEvent[RINGQT_EVENT_SIZE];
    char ccursorPositionChangedEvent[RINGQT_EVENT_SIZE];
    char credoAvailableEvent[RINGQT_EVENT_SIZE];
    char cselectionChangedEvent[RINGQT_EVENT_SIZE];
    char ctextChangedEvent[RINGQT_EVENT_SIZE];
    char cundoAvailableEvent[RINGQT_EVENT_SIZE];


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

