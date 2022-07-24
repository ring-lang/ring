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
        win1.move((oDesktop.width()-win1.width()) /2 , (oDesktop.Height()-win1.Height())/2 )
        win1.show()
