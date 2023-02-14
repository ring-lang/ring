# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

DefineNaturalCommand.SyntaxIsCommandString([
	:Package = "MyLanguage.Natural",
	:Command = "window title is", 
	:Function = func {
		See  "Command: Window title is " + Expr(1) + nl
	}
])
