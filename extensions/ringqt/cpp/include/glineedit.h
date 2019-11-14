
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GLINEEDIT_H
#define GLINEEDIT_H
#include <QApplication>
#include <QLineEdit>
extern "C" {
#include "ring.h"
}

class GLineEdit : public QLineEdit
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cTextChangedEvent[200];
    char ccursorPositionChangedEvent[200];
    char ceditingFinishedEvent[200];
    char creturnPressedEvent[200];
    char cselectionChangedEvent[200];
    char ctextEditedEvent[200];


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

