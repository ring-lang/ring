Load "guilib.ring"

MyApp = New qApp
{
    win1 = new qWidget()
    {
        resize(400,400)
        setWindowTitle("Hello World")
        new qPushButton(win1) {
          move(50,50)
          resize(300,100)
          SetText("Close")
          setClickEvent("MyApp.Quit()")
        }
        show()
    }
    exec()
}
