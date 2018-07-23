func main 
	new Vectors {
		  	V { 1 2 3 }  
			V { 4 5 6 }
			V { 9 5 6 }  
			Sum Vectors 
			Print Vectors 
	}

class Array 

	aData = []

	func init aPara 
		if isList(aPara)
			aData = aPara 
		else 
			raise("To create new array, pass a list as parameter!")
		ok

	func operator cOperator,Para
	        result = self
	        switch cOperator
	                on "+"
	                        if isnumber(para)
					for t=1 to len(aData)
						result.aData[t] = aData[t] + Para 
					next 
				elseif isobject(para)
					if classname(para) = classname(self)
						for t=1 to len(aData)
							if t <= len(Para)
								result.aData[t] = aData[t] + Para[t] 
							ok
						next 
					else 
						raise("Bad object type, we expect " + classname(self))
					ok
	                        else
					raise("Bad object type")	                        
				ok
	                on "len"
	                        return len( aData )
	                on "[]"
	                        return &aData[para]
	        off
	        return result

	func print 
		see "["
		for t = 1 to len(aData) 
			see aData[t]
			if t != len(aData) 
				see ","
			ok
		next
		? "]" 

class Vector from Array 

	func braceexpreval vData
		if isNumber(vData)
			aData + vData 
		ok

class Vectors
	
	V Print Vectors Sum
	aVectors = []

	func getV
		aVectors + new Vector
		return aVectors[len(aVectors)]

	func drawline 
		? copy("=",17)

	func getprint
		drawline()
		? "Printing Vectors"
		drawline()
		for t = 1 to len(aVectors) 
			see "V[" + t + "] = "
			see aVectors[t].print()
		next 
		drawline()

	func getVectors
		
	func getSum 
		vSum = aVectors[1]
		for t=2 to len(aVectors)
			vSum = vSum + aVectors[t]
		next 
		aVectors + vSum 
