aClasses +	[	:name = "GTreeWidget" ,
			:realname = "QTreeWidget" ,
			:events = [
					[ 	:signal = "collapsed(QModelIndex)" ,
						:slot = "collapsedSlot()" ,
						:event = "collapsed"
					] ,
					[ 	:signal = "expanded(QModelIndex)" ,
						:slot = "expandedSlot()" ,
						:event = "expanded"
					] ,
					[ 	:signal = "activated(QModelIndex)" ,
						:slot = "activatedSlot()" ,
						:event = "activated"
					] ,
					[ 	:signal = "clicked(QModelIndex)" ,
						:slot = "clickedSlot()" ,
						:event = "clicked"
					] ,
					[ 	:signal = "doubleClicked(QModelIndex)" ,
						:slot = "doubleClickedSlot()" ,
						:event = "doubleClicked"
					] ,
					[ 	:signal = "entered(QModelIndex)" ,
						:slot = "enteredSlot()" ,
						:event = "entered"
					] ,
					[ 	:signal = "pressed(QModelIndex)" ,
						:slot = "pressedSlot()" ,
						:event = "pressed"
					] ,
					[ 	:signal = "viewportEntered()" ,
						:slot = "viewportEnteredSlot()" ,
						:event = "viewportEntered"
					] ,
					[ 	:signal = "currentItemChanged(QTreeWidgetItem *,QTreeWidgetItem *)" ,
						:slot = "currentItemChangedSlot()" ,
						:event = "currentItemChanged"
					] ,
					[ 	:signal = "itemActivated(QTreeWidgetItem *,int)" ,
						:slot = "itemActivatedSlot()" ,
						:event = "itemActivated"
					] ,
					[ 	:signal = "itemChanged(QTreeWidgetItem *,int)" ,
						:slot = "itemChangedSlot()" ,
						:event = "itemChanged"
					] ,
					[ 	:signal = "itemClicked(QTreeWidgetItem *,int)" ,
						:slot = "itemClickedSlot()" ,
						:event = "itemClicked"
					] ,
					[ 	:signal = "itemCollapsed(QTreeWidgetItem *)" ,
						:slot = "itemCollapsedSlot()" ,
						:event = "itemCollapsed"
					] ,
					[ 	:signal = "itemDoubleClicked(QTreeWidgetItem * ,int)" ,
						:slot = "itemDoubleClickedSlot()" ,
						:event = "itemDoubleClicked"
					] ,
					[ 	:signal = "itemEntered(QTreeWidgetItem * ,int)" ,
						:slot = "itemEnteredSlot()" ,
						:event = "itemEntered"
					] ,
					[ 	:signal = "itemExpanded(QTreeWidgetItem *)" ,
						:slot = "itemExpandedSlot()" ,
						:event = "itemExpanded"
					] ,
					[ 	:signal = "itemPressed(QTreeWidgetItem * ,int)" ,
						:slot = "itemPressedSlot()" ,
						:event = "itemPressed"
					] ,
					[ 	:signal = "itemSelectionChanged()" ,
						:slot = "itemSelectionChangedSlot()" ,
						:event = "itemSelectionChanged"
					]
				  ],
			:CustomCodeAfterInclude = `#include <QDrag>`,
			:CustomCodeAtTheEnd = `

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

`
		] 
