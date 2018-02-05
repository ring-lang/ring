load "guilib.ring"

func main
	new qApp {
		win = new qWidget() { 
			move(100,100) resize(500,500)
			setWindowTitle("Many Tree Items - Testing Performance")
			tree = new qTreeWidget(win) { 
				blocksignals(True) setUpdatesEnabled(False)
				root = new qTreeWidgetItem()
				root.setText(0,"The Root Node")
				t1 = clock()
				for t = 1 to 5000
					oItem = new qTreeWidgetItem()
					oItem.settext(0,"Item " + t)
					root.addchild(oItem)
				next
				cTime = (clock()-t1)/clockspersecond()
				setHeaderLabel("Creating 5000 nodes in " + cTime + " seconds.")
				addTopLevelItem(root)
				expanditem(root)
				blocksignals(False) setUpdatesEnabled(True)
			}
			oLayout = new qVBoxLayout() {
				addWidget(tree)
			}
			setLayout(oLayout)
			show() 
		}
		exec()
	}
	
