load "stdlib.ring"

cStr = "        	Test	        "
? cStr 
? trim(cStr)
? trimAll(cStr)

func trim cStr 
	return trimAll(cStr)
