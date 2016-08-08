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
                playlist = new QMediaPlaylist() 
                {
                        addMedia(new QUrl("test.avi"))
                        addMedia(new QUrl("test.avi"))
                        addMedia(new qurl("test.avi"))
                        setCurrentIndex(1)
                }                       
                player = new qmediaplayer() {
			setPlaylist(playlist)
                        setvideooutput(videowidget)
                }                
                show()
        }
        exec()
}