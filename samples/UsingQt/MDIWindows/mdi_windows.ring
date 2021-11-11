# Author: Mansour Ayouni
# Inviting the RingQt library
load "guilib.ring"

# Creating an QApp object to hold your holle app
oApp = new QApp {

	# Creating a main workspace for your app, where you wan design
	# the GUI strutcure of your App (menu, toolbar, dockbars, status bar)...
	# and more importantly, for your case, a central region where you can
	# specify your MDI windows...

	oMainWin = new QMainWindow() {
		# There are many options available for describing your main window
		# but we set just the title for conciseness
		setWindowTitle("MultiStore Solution from Sipos")

		# Now, we design the MDI area of our workspace
		mdiArea = new QMDIArea(oMainWin) {

			# Inside it, we put any number of MDI subwindows
			# let's make two of them...

			# First MDI window
			mdiSubWin1 = new QMDISubWindow(mdiArea) {
				setWindowTitle("I'm MDI 1")
	
				# Inside our first MDI subwindow, we can put any
				# widget we need (texts, buttons, lists, images...)

				# For the sake of simplicity, we'll add just a button
				btn = new QPushButton(mdiSubWin1) {
					setText("Hi, I'm a button in MDI1")
				}

				# Than we tell to the sub window that it should
				# consider our button as a widget inside it
				setWidget(btn)
					
			}

			# Second MDI window: same logic!
			mdiSubWin2 = new QMDISubWindow(mdiArea) {
				setWindowTitle("I'm MDI 2")
	
				btn = new QPushButton(mdiSubWin2) {
					setText("Hi, I'm a button in MDI2")
				}

				setWidget(btn)		
			}
	
		}

		# Great, we've finished designing the MDI area of
		# our workspace/ Let's tell to our QMainWindow to
		# populate its central region with it:
		setCentralWidget(mdiArea)

		# Now, our design is ready, let's tell to RingQt to
		# display it on screen as soon as the App is executed
		show()
	}

	# Finally, we execute the app
	exec()
}
