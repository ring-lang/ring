Load "guilib.ring"

New qApp {

        win1 = new qMainWindow() {
		setGeometry(100,100,700,400)
                setwindowtitle("QVideoWidget")

                btn1 = new qpushbutton(win1)    {
                        setGeometry(0,0,100,30)
                        settext("play")
                        setclickevent("player.play()")
                }

                videowidget = new qvideowidget(win1) {
                        setGeometry(50,50,600,300)
                        setstylesheet("background-color: black")
                }

                player = new qmediaplayer() {
                        setmedia(new qurl("test.avi"))
                        setvideooutput(videowidget)

                }

                
                show()

        }

        exec()

}