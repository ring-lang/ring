load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand.startCache(:MyDSL)

DefineNaturalCommand {

        SyntaxIsCommand([
                :Package = "MyLanguage.Natural",
                :Command = "I want window",
                :Function = func {
                        ? "Command: I want window"
                }
        ])

        SyntaxIsCommand([
                :Package = "MyLanguage.Natural",
                :Command = "I want button",
                :Function = func {
                        ? "Command: I want button"
                }
        ])

        SyntaxIsCommand([
                :Package = "MyLanguage.Natural",
                :Command = "start gui",
                :Function = func {
                        ? "Command: start gui"
                }
        ])

        SyntaxIsCommandExpression([
                :Package = "MyLanguage.Natural",
                :Command = "window title is",
                :Function = func {
                        ? "Command: window title is " + Expr(1)
                }
        ])

        SyntaxIsCommandExpression([
                :Package = "MyLanguage.Natural",
                :Command = "button text is",
                :Function = func {
                        ? "Command: button text is " + Expr(1)
                }
        ])

}

DefineNaturalCommand.endCache()

MyLang = New NaturalLanguage {
        SetPackageName("MyLanguage.Natural")
        SetLanguageName(:MyLanguage)
        loadCommand(:MyDSL)
}

new MyLanguage {
        I want window and the window title is "Hello World"
        I want button and the button text  is "Save"
        start gui
}