# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

mergemethods(:natural,:natural_hello)

class Natural_Hello from NaturalCommand

	func AddAttributes_Hello	
		AddAttribute(self,:hello)

	func GetHello   
		See  "Hello, Sire!" + nl + nl
