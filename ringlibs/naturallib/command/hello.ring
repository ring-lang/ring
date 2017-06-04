# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

DefineNaturalCommand.SyntaxIsKeyword(
	"MyLanguage.Natural",
	:hello, 
	func {
		See  "Hello, Sire!" + nl + nl
	}
)
