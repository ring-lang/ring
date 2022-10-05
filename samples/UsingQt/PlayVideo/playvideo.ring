Load "guilib.ring"

new qapp {

	win1 = new qMainWindow() {

        	setwindowtitle("PlayVideo!")
		setgeometry(300,400,400,400)

		videowidget = new qvideowidget(win1) {
			setGeometry(10,50,300,300)
			setstylesheet("background-color: black")
		}

		player = new qmediaplayer() {
			setmedia(new qurl("m2000.avi")) 	
			setvideooutput(videowidget)               
		}
 
		q1 = new qpushbutton(win1) {
			setgeometry(50,10,100,30)
			settext("PlayVideo")
			setclickevent("player.play()")
		}

		show()

        }

    exec()

}
