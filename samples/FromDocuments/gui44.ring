Load "guilib.ring"

New qApp {
        win1 = New qWidget()
        {
                resize(400,400)
                btn1 = new qPushbutton(win1)
                {
                        setText("Center")
                        move(100,100)
                        resize(100,30)
                        setClickEvent("pCenter()")
                }

                Show()
        }

        exec()
}

Func pCenter
        oDesktop  = new qDesktopWidget()
        oRect = oDesktop.screenGeometry( oDesktop.primaryScreen()  )
        win1.move((oRect.width()-win1.width()) /2 , (oRect.Height()-win1.Height())/2 )
        win1.show()
