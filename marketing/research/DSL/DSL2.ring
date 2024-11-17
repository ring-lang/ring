new PickPrice {
	Name		    		Price 
	Computer1   			7000	  				Acceptable 
	Computer2  			4400 					Acceptable 
	Computer3   			9000 
}

class PickPrice from DSL
	Acceptable func getAcceptable() getImportant() 
	func braceEnd
		load "guilib.ring"  
		import System.GUI
		app = new App {
			win = new Window() {
				setWindowTitle("Acceptable Prices") 
				resize(400,200) setWinIcon(self,"bestprice.png")
				list = new ListWidget(win) { addList(Sort(this.aImportant)) }
				setLayout( new VBoxLayout() { addWidget(list) } )
				show()
			}
			exec()
		}
	func braceError

class DSL

	nSum = 0		lastvalue  
	stop = False		important	aImportant = []

	func getStop()			stop       = True
	func getImportant()		if !stop   aImportant + lastvalue	end
	func braceExprEval(value)	if !stop   nSum += value   		end 	lastvalue = value 
	func braceEnd()			? "Sum: "+nSum ? "Important: " ? aImportant 
