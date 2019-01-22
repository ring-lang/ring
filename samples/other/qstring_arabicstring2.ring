load "guilib.ring"

new qApp 

oString = new ArabicString("سلس")
? len(oString)
for x = 1 to len(oString)
	? oString[x]
next

class ArabicString 
	Object = new QString()
	func init cString 
		Object.Append(cString)
	func operator cOperator,value 
		if cOperator = "[]"
			return Object.Mid(value-1,1)
		but cOperator = "len"
			return Object.Count()
		ok
