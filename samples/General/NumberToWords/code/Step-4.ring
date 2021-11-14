// *** step 4
// number to words (one hundred millions)

n = "1234567898"
//n = "1000067"


doGruppen(n)

func doGruppen(n)
	rtn = " "
	anz_gr = floor((len(n)+2)/3)    	// number of groups
	
	// group names - the "thousands"
	tsds = ["","thousand ", "million ", "billion ", "trillion ", "quadrillion ", "quintillion ", "sextillion",
    "septillion", "octillion", "nonillion", "decillion", "undecillion", "duodecillion", "tredecillion",
    "quattuordecillion", "sexdecillion", "septendecillion", "octodecillion", "novemdecillion", "vigintillion "]
	
	for x = 1 to anz_gr-1				// input process
		gr = right(n,3)					// determines group
		n = left( n,len(n)-3 )			// generates new nr
		if gr = "" gr = n end			// if gr is empty, take "n"
	  	rtn = gr+" "+ tsds[x] + rtn
	next  //end-for
	
	rtn = n +" "+ tsds[x] + rtn 
	? "In Words: "+ rtn				// result
return rtn
//end	doGruppen
