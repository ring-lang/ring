package System.GUI

	class TableWidget from qTableWidget

		func column  p1
			return Super.column(p1) + 1

		func currentColumn 
			return Super.currentColumn() + 1

		func currentRow 
			return Super.currentRow() + 1

		func horizontalHeaderItem p1
			return Super.horizontalHeaderItem(p1-1)

		func item p1,p2
			return Super.Item(p1-1,p2-1)
	
		func itemat p1,p2
			return Super.ItemAt(p1-1,p2-1)

		func removeCellWidget p1,p2
			return Super.removeCellWidget(p1-1,p2-1)

		func row p1
			return Super.row(p1)+1

		func setCellWidget p1,p2,p3
			return Super.setCellWidget(p1-1,p2-1,p3)

		func setCurrentCell p1,p2
			return Super.setCurrentCell(p1-1,p2-1)

		func setColumnWidth P1,P2
			return Super.setColumnWidth(p1-1,p2)

		func setHorizontalHeaderItem p1,p2
			return Super.setHorizontalHeaderItem(p1-1,p2)

		func setItem p1,p2,p3
			return Super.setItem(p1-1,p2-1,p3)

		func setVerticalHeaderItem p1,p2
			return Super.setVerticalHeaderItem(p1-1,p2)

		func sortItems p1,p2
			return Super.sortItems(p1-1,p2)

		func takeHorizontalHeaderItem p1
			return Super.takeHorizontalHeaderItem(p1-1)

		func takeItem p1,p2
			return Super.takeItem(p1-1,p2-1)

		func takeVerticalHeaderItem p1
			return Super.takeVerticalHeaderItem(p1-1)

		func verticalHeaderItem p1
			return Super.verticalHeaderItem(p1-1)

		func visualColumn p1
			return Super.visualColumn(p1-1)

		func visualRow p1
			return Super.visualRow(p1-1)

		func insertColumn p1
			return Super.insertColumn(p1-1)

		func insertRow p1
			return Super.insertRow(p1-1)

		func removeColumn p1
			return Super.removeColumn(p1-1)

		func removeRow p1
			return Super.removeRow(p1-1)		

		func addList aList
			if ! isList(aList)
				? "Bad parameter type - The addList() method expect a List!"
				return
			ok
			if ! isList(aList[1])
				? "Bad parameter type - The List is not a Table!"
				return
			ok
			nRows = len(aList)
			if nRows = 0 return ok
			nRowStart = RowCount()
			setRowCount(nRowStart+nRows)
			nRow = 1
			for aRows in aList
				if isList(aRows)
					nCol = 1
					for vValue in aRows
						# We do this check here to allow records with different columns size
							if len(aRows) > ColumnCount()
								setColumnCount(len(aRows))
							ok
						# We Support Strings & Numbers
						if isString(vValue)
							oItem = new QTableWidgetItem(vValue)
						but isNumber(vValue)
							oItem = new QTableWidgetItem(""+vValue)
						else
							? "Bad parameter type - The List is not a Table!"
							return
						ok
						setItem(nRowStart+nRow,nCol,oItem)
						nCol++
					next
				ok				
				nRow++				
			next
			setcurrentcell(nRowStart+1,1)
