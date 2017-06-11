# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

DefineNaturalCommand.SyntaxIsCommandExpressions([
	:Package = "MyLanguage.Natural",
	:Command = "window title is", 
	:Function = func {
		See  "Command: Window title is" + nl
		See  "Para : " + Expr(1) + nl
	}
],1)
