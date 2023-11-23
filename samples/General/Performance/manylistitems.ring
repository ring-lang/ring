load "guilib.ring"

C_ITEMSCOUNT = 60000

func main
	new qApp {
		win = new qWidget() { 
			move(100,100) resize(500,500)
			setWindowTitle("Many List Items - Testing Performance")
			tree = new qListWidget(win) { 
				blocksignals(True) setUpdatesEnabled(False)
				t1 = clock()
				for t = 1 to C_ITEMSCOUNT
					AddItem("Item " + t)
				next
				cTime = (clock()-t1)/clockspersecond()
				blocksignals(False) setUpdatesEnabled(True)
			}
			oLayout = new qVBoxLayout() {
				addWidget(tree)
			}
			setLayout(oLayout)
			show() 
		}
		? ("Adding "+C_ITEMSCOUNT+" items in " + cTime + " seconds.")
		exec()
	}
	
