func main 
	a1 = new Array( [1,2,3] )
	? "Print a1"
	a1.print()
	a2 = a1 + 3
	? "Print a2=a1+3"
	a2.print()
	a3 = a1 + a2
	? "Print a3=a1+a2"
	a3.print()

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
		? aData
