load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
        startCache(:MyDSL)
        setPackageName("MyLanguage.Natural")
        syntaxIsCommandExpression([
                :Command = "textbox value to",
                :Function = func {
                        callerSetVar(expr(1),"very nice")
                }
        ])
        endCache()
}

MyLang = new NaturalLanguage {
        setLanguageName(:Chat)
        setPackageName("MyLanguage.Natural")
        loadCommand(:MyDSL)
        setMaskOperators(False)                 // So we can use ? and = operators
}

func main

        test1()
        test2()

func test1


        ? copy("=",30)

        new Chat {
		textbox value to :myvalue
        }

	? myvalue

        ? copy("=",30)


func test2

        MyLang.@(`

                ? copy("=",30)

		textbox value to :myvalue
		? myvalue

                ? copy("=",30)

        `)