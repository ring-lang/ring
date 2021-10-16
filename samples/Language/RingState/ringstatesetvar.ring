load "guilib.ring"

myapp	= null
win	= null

func main
	myapp = new qApp {
		win = new qWidget() {
			setWindowTitle("Advanced Example on using ring_state_setvar()")
			move(100,100)
			resize(600,400)
			new qPushButton(win) {
				setText("Test")
				setClickEvent("Test()")
			}
			# We need this because using load 'guilib.ring' in the sub environment
			# Will create timers by Qt and closing the window will not be enough
			# To close the application
			oFilter = new qAllEvents(win)
			oFilter.setCloseEvent("myapp.quit()")
			win.installeventfilter(oFilter)
			show()
		}
		exec()
	}

func test
	pState = ring_state_init()
	ring_state_runcode(pstate,"load 'guilib.ring'")
	ring_state_runcode(pState,"x = NULL")
	# Pass String
		ring_state_setvar(pState,"x","hello")
		ring_state_runcode(pState,"? x")
	# Pass Number
		ring_state_setvar(pState,"x",100)
		ring_state_runcode(pState,"? x")
	# Pass List
		ring_state_setvar(pState,"x",["one","two","three"])
		ring_state_runcode(pState,"? x")
	# Pass Object
	# We can't pass the Ring Object (win)
	# Because Objects store pointers to the Class Information
	# And the class is related to the Parent Ring Environment
	# And the sub Ring environment can't access it
	# But we can pass C pointers like win.pObject
		ring_state_setvar(pState,"x",win.pObject)
	# Now we create the object again but using the same C pointer
	# So we have access to the Same window in the parent Ring environment
		ring_state_runcode(pState,"
			new qWidget {
				pObject = x
				setwindowtitle('Message from the Sub Ring Environment')
			}
		")
	ring_state_delete(pState)

