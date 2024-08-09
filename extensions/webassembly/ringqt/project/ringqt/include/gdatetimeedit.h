
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GDATETIMEEDIT_H
#define GDATETIMEEDIT_H
#include "ringqt.h"
#include <QDateTimeEdit>

extern "C" {
#include "ring.h"
}

class GDateTimeEdit : public QDateTimeEdit
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cdateChangedEvent[RINGQT_EVENT_SIZE];
    char cdateTimeChangedEvent[RINGQT_EVENT_SIZE];
    char ctimeChangedEvent[RINGQT_EVENT_SIZE];


    GDateTimeEdit(QWidget *parent,VM *pVM );

    ~GDateTimeEdit();

    void geteventparameters(void) ;

    void setdateChangedEvent(const char *cStr);
    void setdateTimeChangedEvent(const char *cStr);
    void settimeChangedEvent(const char *cStr);


    const char *getdateChangedEvent(void);
    const char *getdateTimeChangedEvent(void);
    const char *gettimeChangedEvent(void);


  public slots:

    void dateChangedSlot();
    void dateTimeChangedSlot();
    void timeChangedSlot();



};

#endif

