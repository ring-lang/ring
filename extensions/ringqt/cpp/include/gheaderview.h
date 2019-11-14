
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
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

    char cgeometriesChangedEvent[200];
    char csectionClickedEvent[200];
    char csectionCountChangedEvent[200];
    char csectionDoubleClickedEvent[200];
    char csectionEnteredEvent[200];
    char csectionHandleDoubleClickedEvent[200];
    char csectionMovedEvent[200];
    char csectionPressedEvent[200];
    char csectionResizedEvent[200];
    char csortIndicatorChangedEvent[200];


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

