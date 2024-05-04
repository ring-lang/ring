
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GTREEWIDGET_H
#define GTREEWIDGET_H
#include "ringqt.h"
#include <QTreeWidget>
#include <QDrag>
extern "C" {
#include "ring.h"
}

class GTreeWidget : public QTreeWidget
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char ccollapsedEvent[RINGQT_EVENT_SIZE];
    char cexpandedEvent[RINGQT_EVENT_SIZE];
    char cactivatedEvent[RINGQT_EVENT_SIZE];
    char cclickedEvent[RINGQT_EVENT_SIZE];
    char cdoubleClickedEvent[RINGQT_EVENT_SIZE];
    char centeredEvent[RINGQT_EVENT_SIZE];
    char cpressedEvent[RINGQT_EVENT_SIZE];
    char cviewportEnteredEvent[RINGQT_EVENT_SIZE];
    char ccurrentItemChangedEvent[RINGQT_EVENT_SIZE];
    char citemActivatedEvent[RINGQT_EVENT_SIZE];
    char citemChangedEvent[RINGQT_EVENT_SIZE];
    char citemClickedEvent[RINGQT_EVENT_SIZE];
    char citemCollapsedEvent[RINGQT_EVENT_SIZE];
    char citemDoubleClickedEvent[RINGQT_EVENT_SIZE];
    char citemEnteredEvent[RINGQT_EVENT_SIZE];
    char citemExpandedEvent[RINGQT_EVENT_SIZE];
    char citemPressedEvent[RINGQT_EVENT_SIZE];
    char citemSelectionChangedEvent[RINGQT_EVENT_SIZE];


    GTreeWidget(QWidget *parent,VM *pVM );

    ~GTreeWidget();

    void geteventparameters(void) ;

    void setcollapsedEvent(const char *cStr);
    void setexpandedEvent(const char *cStr);
    void setactivatedEvent(const char *cStr);
    void setclickedEvent(const char *cStr);
    void setdoubleClickedEvent(const char *cStr);
    void setenteredEvent(const char *cStr);
    void setpressedEvent(const char *cStr);
    void setviewportEnteredEvent(const char *cStr);
    void setcurrentItemChangedEvent(const char *cStr);
    void setitemActivatedEvent(const char *cStr);
    void setitemChangedEvent(const char *cStr);
    void setitemClickedEvent(const char *cStr);
    void setitemCollapsedEvent(const char *cStr);
    void setitemDoubleClickedEvent(const char *cStr);
    void setitemEnteredEvent(const char *cStr);
    void setitemExpandedEvent(const char *cStr);
    void setitemPressedEvent(const char *cStr);
    void setitemSelectionChangedEvent(const char *cStr);


    const char *getcollapsedEvent(void);
    const char *getexpandedEvent(void);
    const char *getactivatedEvent(void);
    const char *getclickedEvent(void);
    const char *getdoubleClickedEvent(void);
    const char *getenteredEvent(void);
    const char *getpressedEvent(void);
    const char *getviewportEnteredEvent(void);
    const char *getcurrentItemChangedEvent(void);
    const char *getitemActivatedEvent(void);
    const char *getitemChangedEvent(void);
    const char *getitemClickedEvent(void);
    const char *getitemCollapsedEvent(void);
    const char *getitemDoubleClickedEvent(void);
    const char *getitemEnteredEvent(void);
    const char *getitemExpandedEvent(void);
    const char *getitemPressedEvent(void);
    const char *getitemSelectionChangedEvent(void);


  public slots:

    void collapsedSlot();
    void expandedSlot();
    void activatedSlot();
    void clickedSlot();
    void doubleClickedSlot();
    void enteredSlot();
    void pressedSlot();
    void viewportEnteredSlot();
    void currentItemChangedSlot();
    void itemActivatedSlot();
    void itemChangedSlot();
    void itemClickedSlot();
    void itemCollapsedSlot();
    void itemDoubleClickedSlot();
    void itemEnteredSlot();
    void itemExpandedSlot();
    void itemPressedSlot();
    void itemSelectionChangedSlot();




protected:

    void startDrag(Qt::DropActions supportedActions) override
    {

	QModelIndexList indexes = selectedIndexes();
	QList<QPersistentModelIndex> persistentIndexes;
 
	if (indexes.count() > 0) {

        	QMimeData *data = model()->mimeData(indexes);

      		if (!data)
            		return;

		for (int i = 0; i<indexes.count(); i++) {
    			QModelIndex idx = indexes.at(i);
    			persistentIndexes.append(QPersistentModelIndex(idx));
    		}
 
		QPixmap pixmap = indexes.first().data(Qt::DecorationRole).value<QPixmap>();
		QDrag *drag = new QDrag(this);
		drag->setPixmap(pixmap);
		drag->setMimeData(data);
		drag->setHotSpot(QPoint(pixmap.width()/2, pixmap.height()/2));
 
		Qt::DropAction defaultDropAction = Qt::IgnoreAction;
		if (supportedActions & Qt::MoveAction && dragDropMode() != QAbstractItemView::InternalMove)
			defaultDropAction = Qt::MoveAction;
 
		if ( drag->exec(supportedActions, defaultDropAction) == Qt::MoveAction ) {
			for (int i = 0; i<indexes.count(); i++) {
				QPersistentModelIndex idx = persistentIndexes.at(i);
				if (idx.isValid()) 
					model()->removeRow(idx.row(), idx.parent());
				else
					model()->removeRow(idx.row(), QModelIndex());
			}
		}
	}

    }


};

#endif

