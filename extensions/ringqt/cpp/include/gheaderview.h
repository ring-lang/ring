
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GHEADERVIEW_H
#define GHEADERVIEW_H
#include "ringqt.h"
#include <QHeaderView>

extern "C" {
#include "ring.h"
}

class GHeaderView : public QHeaderView
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cgeometriesChangedEvent[RINGQT_EVENT_SIZE];
    char csectionClickedEvent[RINGQT_EVENT_SIZE];
    char csectionCountChangedEvent[RINGQT_EVENT_SIZE];
    char csectionDoubleClickedEvent[RINGQT_EVENT_SIZE];
    char csectionEnteredEvent[RINGQT_EVENT_SIZE];
    char csectionHandleDoubleClickedEvent[RINGQT_EVENT_SIZE];
    char csectionMovedEvent[RINGQT_EVENT_SIZE];
    char csectionPressedEvent[RINGQT_EVENT_SIZE];
    char csectionResizedEvent[RINGQT_EVENT_SIZE];
    char csortIndicatorChangedEvent[RINGQT_EVENT_SIZE];


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

