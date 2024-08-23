load "guilib.ring"

C_NODESCOUNT = 60000

func main
	new QApp {
		win = new QWidget() { 
			move(100,100) resize(500,500)
			setWindowTitle("Many Tree Items - Testing Performance")
			tree = new QTreeWidget(win) { 
				blocksignals(True) setUpdatesEnabled(False)
				root = new qTreeWidgetItem()
				root.setText(0,"The Root Node")
				t1 = clock()
				for t = 1 to C_NODESCOUNT
					oItem = new qTreeWidgetItem()
					oItem.settext(0,"Item " + t)
					root.addchild(oItem)
				next
				cTime = (clock()-t1)/clockspersecond()
				setHeaderLabel("Creating "+C_NODESCOUNT+" nodes in " + cTime + " seconds.")
				addTopLevelItem(root)
				expanditem(root)
				blocksignals(False) setUpdatesEnabled(True)
			}
			oLayout = new QVBoxLayout() {
				addWidget(tree)
			}
			setLayout(oLayout)
			show() 
		}
		exec()
	}
	
