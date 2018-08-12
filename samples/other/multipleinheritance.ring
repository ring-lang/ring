# Ring uses Single Inheritance
# This example shows to get multiple inheritance using reflection and meta-programming

mergemethods(:CameraPhone,:MobilePhone)

o1 = new CameraPhone 
? o1
? o1.testCamera()
? o1.testMobilePhone()

func AddParentClassAttributes oObject,cClass
	# Add Attributes 
		cCode = "oTempObject = new " + cClass 
		eval(cCode)
		for cAttribute in Attributes(oTempObject)
			AddAttribute(oObject,cAttribute)
			cCode = "oObject." + cAttribute + " = oTempObject." + cAttribute
			eval(cCode)
		next 
			

class Camera
	Name = "Camera"
	func testCamera
		? "Message from testCamera"

class MobilePhone
	Type = "Android"
	func testMobilePhone 
		? "Message from MobilePhone"

class CameraPhone from Camera 

	# Add MobilePhone Attributes 
		AddParentClassAttributes(self,:MobilePhone)
