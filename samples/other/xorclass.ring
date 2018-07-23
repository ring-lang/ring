o1 = new number(2345)
o2 = new number(1111)

o3 = o1 ^ o2

o3.print()

class number
	vValue = ""
	func init vPara
		if isString(vPara)
			vValue = vPara 
		elseif isnumber(vPara)
			vValue = "" + vPara
		ok
	func operator cOperator,vPara
		if cOperator = "^"
			cOutput = ""
			v1 = self.vValue	
			v2 = vPara.vValue
			if len(v1) = len(v2)
				for t=1 to len(v1)
					cOutput += v1[t] ^ v2[t]
				next
			ok			
			return new number(cOutput)
		ok
	func print 
		? vValue 
	
