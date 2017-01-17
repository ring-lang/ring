
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GHEADERVIEW_H
#define GHEADERVIEW_H
#include <QApplication>
#include <QHeaderView>
extern "C" {
#include "ring.h"
}

class GHeaderView : public QHeaderView
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cgeometriesChangedEvent[100];
    char csectionClickedEvent[100];
    char csectionCountChangedEvent[100];
    char csectionDoubleClickedEvent[100];
    char csectionEnteredEvent[100];
    char csectionHandleDoubleClickedEvent[100];
    char csectionMovedEvent[100];
    char csectionPressedEvent[100];
    char csectionResizedEvent[100];
    char csortIndicatorChangedEvent[100];


    GHeaderView(Qt::Orientation x, QWidget *parent,VM *pVM );

    ~GHeaderView();

    void geteventparameters(void) ;

    void setgeometriesChangedEvent(const char *cStr);
    void setsectionClickedEvent(const char *cStr);
    void setsectionCountChangedEvent(const char *cStr);
    void setsectionDoubleClickedEvent(const char *cStr);
    void setsectionEnteredEvent(const char *cStr);
    void setsectionHandleDoubleClickedEvent(const char *cStr);
    void setsectionMovedEvent(const char *cStr);
    void setsectionPressedEvent(const char *cStr);
    void setsectionResizedEvent(const char *cStr);
    void setsortIndicatorChangedEvent(const char *cStr);


    const char *getgeometriesChangedEvent(void);
    const char *getsectionClickedEvent(void);
    const char *getsectionCountChangedEvent(void);
    const char *getsectionDoubleClickedEvent(void);
    const char *getsectionEnteredEvent(void);
    const char *getsectionHandleDoubleClickedEvent(void);
    const char *getsectionMovedEvent(void);
    const char *getsectionPressedEvent(void);
    const char *getsectionResizedEvent(void);
    const char *getsortIndicatorChangedEvent(void);


  public slots:

    void geometriesChangedSlot();
    void sectionClickedSlot(int p1);
    void sectionCountChangedSlot();
    void sectionDoubleClickedSlot();
    void sectionEnteredSlot();
    void sectionHandleDoubleClickedSlot();
    void sectionMovedSlot();
    void sectionPressedSlot();
    void sectionResizedSlot();
    void sortIndicatorChangedSlot();

};

#endif

