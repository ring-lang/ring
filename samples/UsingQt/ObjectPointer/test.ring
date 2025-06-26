# This is a low-level example about using Pointers in the Event String
# The idea is presented by Mohannad Aldulaimi through the Adhkar application 
# Instead of typing the Object Name (Global variable/Array) or using the Objects Library
# In this example we use the next features
# 1- Each GUI object contains the pObject attribute (Pointer to the Widget)
# 2- Using NULLPointer() we can create a new pointer
# 3- Using getPointer()  we can get the pointer address as number
# 4- Using setPointer()  we can change the pointer address using a number (contains address)

# Note: This way is not the recommended way for Ring applications
# For small applications, Just use global variables for GUI widgets.
# For large applications, Just use the Objects Library. 

load "lightguilib.ring"

func main

	oApp = new QApp {
		oWin = new QWidget() {
			setWindowTitle("Welcome")
			resize(800,600)
			for t=1 to 10
				new QPushButton(oWin) {
					move(100,100+t*30)
					setText("Click Me")
					setClickEvent("myEvent("+btnPtr(self)+","+t+")")
				}
			next
			show()
		}
		exec()
	}

func myEvent nPtr, nIndex

	oTempBtn = btnObj(nPtr)
	oTempBtn.setText("Button: " + nIndex)

func btnPtr oBtn
	return getpointer(oBtn.pObject)	

func btnObj nPtr

	oTempPtr = NULLPointer()
	setPointer(oTempPtr,nPtr)
	oTempBtn = new QPushButton
	oTempBtn.pObject = oTempPtr
	return oTempBtn
