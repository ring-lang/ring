# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

DefineNaturalCommand.SyntaxIsKeyword([
	:Package = "MyLanguage.Natural",
	:Keyword = :hello, 
	:Function = func {
		See  "Hello, Sir!" + nl + nl
	}
])
