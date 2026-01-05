# The Ring Natural Library
# 2025, Mahmoud Fayed <msfclipper@yahoo.com>

load "../tests/mylanguage.ring"

MyLanguage.setStartKeywordsWith("@")
MyLanguage.setMaskOperators(False) 

MyLanguage.runString('

	@for t=1 @to 10
 		i want window
		window title is "Hello World"
	@next


')
