Load "guilib.ring"

New qApp {

        win1 = new qMainWindow() {

                setwindowtitle("QVideoWidget")

                btn1 = new qpushbutton(win1)    {
                        setGeometry(0,0,100,30)
                        settext("play")
                        setclickevent("player.play() player2.play()
                                                   player3.play() player4.play()")
                }

                videowidget = new qvideowidget(win1) {
                        setGeometry(50,50,600,300)
                        setstylesheet("background-color: black")
                }

                videowidget2 = new qvideowidget(win1) {
                        setGeometry(700,50,600,300)
                        setstylesheet("background-color: black")
                }


                videowidget3 = new qvideowidget(win1) {
                        setGeometry(50,370,600,300)
                        setstylesheet("background-color: black")
                }

                videowidget4 = new qvideowidget(win1) {
                        setGeometry(700,370,600,300)
                        setstylesheet("background-color: black")
                }

                player = new qmediaplayer() {
                        setmedia(new qurl("1.mp4"))
                        setvideooutput(videowidget)
                        setposition(35*60*1000)

                }

                player2 = new qmediaplayer() {
                        setmedia(new qurl("2.mp4"))
                        setvideooutput(videowidget2)
                        setposition(23*60*1000)
                }

                player3 = new qmediaplayer() {
                        setmedia(new qurl("3.mp4"))
                        setvideooutput(videowidget3)
                        setposition(14.22*60*1000)
                }

                player4 = new qmediaplayer() {
                        setmedia(new qurl("4.avi"))
                        setvideooutput(videowidget4)
                        setposition(8*60*1000)
                }

                showfullscreen()

        }

        exec()

}
