Load "guilib.ring"

New qApp
{
        win1 = new qWidget()
        {
                setwindowtitle("LCD Number")
                setgeometry(100,100,250,120)

                new qLCDNumber(win1)
                {
                        setgeometry(10,10,100,40)
                        display(100)

                }

                new qLCDNumber(win1)
                {
                        setgeometry(10,60,100,40)
                        display(80)

                }

                show()
        }

        exec()
}
