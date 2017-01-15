/*
	Bug ID : 197
	Description : Calling wrong init() method 
	Status : Fixed
*/


new AnyClass {
	new mycontrol()
}
	
class AnyClass
	func init
		see "init anyclass" + nl

class MyControl
	new myfontclass()	
	func init 
		see "init mycontrol" + nl

class MyFontClass
	func init 
		see "init myfontclass" + nl