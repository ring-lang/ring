
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GLINEEDIT_H
#define GLINEEDIT_H
#include "ringqt.h"
#include <QLineEdit>
extern "C" {
#include "ring.h"
}

class GLineEdit : public QLineEdit
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cTextChangedEvent[RINGQT_EVENT_SIZE];
    char ccursorPositionChangedEvent[RINGQT_EVENT_SIZE];
    char ceditingFinishedEvent[RINGQT_EVENT_SIZE];
    char creturnPressedEvent[RINGQT_EVENT_SIZE];
    char cselectionChangedEvent[RINGQT_EVENT_SIZE];
    char ctextEditedEvent[RINGQT_EVENT_SIZE];


    GLineEdit(QWidget *parent,VM *pVM );

    ~GLineEdit();

    void geteventparameters(void) ;

    void setTextChangedEvent(const char *cStr);
    void setcursorPositionChangedEvent(const char *cStr);
    void seteditingFinishedEvent(const char *cStr);
    void setreturnPressedEvent(const char *cStr);
    void setselectionChangedEvent(const char *cStr);
    void settextEditedEvent(const char *cStr);


    const char *getTextChangedEvent(void);
    const char *getcursorPositionChangedEvent(void);
    const char *geteditingFinishedEvent(void);
    const char *getreturnPressedEvent(void);
    const char *getselectionChangedEvent(void);
    const char *gettextEditedEvent(void);


  public slots:

    void textChangedSlot();
    void cursorPositionChangedSlot();
    void editingFinishedSlot();
    void returnPressedSlot();
    void selectionChangedSlot();
    void textEditedSlot();

};

#endif

